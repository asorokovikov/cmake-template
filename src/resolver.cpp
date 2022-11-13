#include <boost/asio.hpp>
#include <spdlog/spdlog.h>

namespace asio = boost::asio;

int main() {
    spdlog::info("Hello from resolver.cpp");

    asio::io_service service;
    asio::io_context context;
    asio::ip::tcp::resolver resolver(service);

    const auto query = asio::ip::tcp::resolver::query{"yandex.ru", "http"};
    const auto it = resolver.resolve(query);
    asio::ip::tcp::endpoint endpoint = *it;

    spdlog::info("endpoint: {}:{}", endpoint.address().to_string(), endpoint.port());

    for (const auto &x: it) {
        spdlog::info("endpoint: {}:{}", x.endpoint().address().to_string(), x.endpoint().port());
    }

    return 0;
}
