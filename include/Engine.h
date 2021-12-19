#pragma once

#include "Dictionary.h"

#include <string_view>
#include <vector>

namespace onward {

enum class EngineState {
  kInterpretationState,
  kCompilationState,
};

class Engine {
public:
  Engine();
  virtual ~Engine() = default;

  void ExecWords(std::string_view);

private:
  void ExecWord(const std::string &);
  std::vector<uint64_t> stack;
  Dictionary dict;
  EngineState state;
  std::vector<std::string> compile_words;
};

} // namespace onward
