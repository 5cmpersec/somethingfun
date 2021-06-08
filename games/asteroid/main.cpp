#include "Game.hpp"

#include <iostream>

#include <spdlog/spdlog.h>

int main() {
  try {
    Game g{};
    g.run(180);
  } catch (const std::exception& e) {
    spdlog::error("Exception: {}", e.what());
    return EXIT_FAILURE;
  }

  return EXIT_SUCCESS;
}
