#include <spdlog/spdlog.h>
#include <spdlog/sinks/stdout_color_sinks.h>
#include "lib/lib.h"

int main() {
    auto logger = spdlog::stdout_color_mt("console");
    logger->info("build {}", lib::version());
}
