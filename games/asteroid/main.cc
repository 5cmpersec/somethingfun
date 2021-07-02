#include "game.h"

#include <iostream>

#include <spdlog/spdlog.h>

int main() {
  spdlog::set_pattern("[%Y-%m-%d %H:%M:%S.%e] %P %t [%^%l%$] %v");
  try {
    Game g{};
    g.Run(180);
  } catch (const std::exception& e) {
    spdlog::error("Exception: {}", e.what());
    return EXIT_FAILURE;
  }

  return EXIT_SUCCESS;
}
