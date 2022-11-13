#include <boost/asio.hpp>
#include <spdlog/spdlog.h>
#include <string>
#include <array>
#include <thread>

using namespace std::string_literals;
using string = std::string;

namespace asio = boost::asio;
using asio::ip::tcp;

void client_session(tcp::socket sock) {
    const auto endpoint = sock.remote_endpoint();
    spdlog::info("New connection {}:{}", endpoint.address().to_string(), endpoint.port());

    try {
        std::array<char, 1024> buffer{};
        const auto length = sock.read_some(asio::buffer(buffer));
        spdlog::info("received {} = {}", length, string(buffer.data(), length));
    } catch (const std::exception &error) {
        spdlog::error(error.what());
        throw;
    }
}

int main() {
    spdlog::info("Hello from sync_server.cpp");

    asio::io_service service;
    tcp::endpoint ep(tcp::v4(), 9999);
    tcp::acceptor acc(service, ep);

    spdlog::info("Server is running...");

    try {
        while (true) {
            auto sock = tcp::socket(service);
            acc.accept(sock);

            std::thread(client_session, std::move(sock)).detach();
        }

    } catch (boost::system::system_error &error) {
        spdlog::error(error.what());
    }

    return 0;
}
