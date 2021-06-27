#include "game.h"

#include <iostream>

#include <spdlog/spdlog.h>

int main() {
  try {
    Game g{};
    g.Run(180);
  } catch (const std::exception& e) {
    spdlog::error("Exception: {}", e.what());
    return EXIT_FAILURE;
  }

  return EXIT_SUCCESS;
}
