#include "Engine.h"

#include <iostream>

namespace {

const char *gOnwardPrompt = "ONWARD> ";

} // namespace

int main(int argc, char **argv) {
  static_cast<void>(argc);
  static_cast<void>(argv);
  onward::Engine engine;
  std::string line;
  while (std::cout << gOnwardPrompt, std::getline(std::cin, line)) {
    engine.ExecWords(line);
  }
  return 0;
}
