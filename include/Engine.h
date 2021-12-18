#pragma once

#include "Dictionary.h"

#include <string_view>
#include <vector>

namespace onward {

class Engine {
public:
  Engine();
  virtual ~Engine() = default;

  void ExecWords(std::string_view);

private:
  void ExecWord(const std::string &);
  std::vector<uint64_t> stack;
  Dictionary dict;
};

} // namespace onward
