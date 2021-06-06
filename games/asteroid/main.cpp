#include "Game.hpp"

#include <iostream>

int main() {
  try {
    Game g{};
    g.run(180);
  } catch (const std::exception& e) {
    std::cerr << "Exception: " << e.what() << std::endl;
    return EXIT_FAILURE;
  }

  return EXIT_SUCCESS;
}
