#include "Engine.h"

#include <filesystem>
#include <fstream>
#include <iostream>

namespace {

const char *gOnwardPrompt = "ONWARD> ";
const char *gUsage = "Usage: onward [file]";

void ExecEngine(onward::Engine &engine, std::istream &is) {
  std::string line;
  while (std::cout << gOnwardPrompt, std::getline(is, line)) {
    engine.ExecWords(line);
  }
}

} // namespace

int main(int argc, char **argv) {
  onward::Engine engine;
  if (argc == 1) {
    // Interactive mode
    ExecEngine(engine, std::cin);
  } else if (argc == 2) {
    // Execute a FORTH script
    const char *file = argv[1];
    const std::filesystem::path file_path(file);
    if (!std::filesystem::exists(file_path)) {
      std::cerr << "Could not find file: " << file_path << "\n";
      std::cerr << gUsage << std::endl;
      return -1;
    }
    std::ifstream fs(file_path);
    ExecEngine(engine, fs);
  } else {
    std::cerr << gUsage << std::endl;
    return -1;
  }
  return 0;
}
