#include <spdlog/spdlog.h>
#include <spdlog/sinks/stdout_color_sinks.h>

#include <boost/asio.hpp>

int main() {
    auto logger = spdlog::stdout_color_mt("console");
    logger->info("build <unknown>");
}
