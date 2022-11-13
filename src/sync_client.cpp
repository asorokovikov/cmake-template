#include <boost/asio.hpp>
#include <spdlog/spdlog.h>
#include <string>
#include <array>

using namespace std::string_literals;
using string = std::string;

namespace asio = boost::asio;

int main() {
    spdlog::info("Hello from sync_client.cpp");

    asio::io_service service;
    asio::ip::tcp::socket sock(service);
    asio::ip::tcp::endpoint ep(asio::ip::address::from_string("127.0.0.1"s), 9999);

    std::array<char, 255> buffer{};

    try {
        sock.connect(ep);
        asio::write(sock, asio::buffer("ping", 4));

        const auto len = sock.read_some(asio::buffer(buffer));
        spdlog::info("received {} = {}", len, string(buffer.data(), len));

    } catch (boost::system::system_error &error) {
        spdlog::error(error.what());
    }

    return 0;
}
