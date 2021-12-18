#include "Engine.h"
#include "Intrinsics.h"

#include <string>

namespace onward {

namespace {

std::vector<std::string> ParseWords(std::string_view word_str) {
  std::vector<std::string> words;
  std::string cur_word;
  for (const auto c : word_str) {
    if (::isspace(c)) {
      if (!cur_word.empty()) {
        words.push_back(cur_word);
        cur_word.clear();
      }
    } else {
      cur_word.push_back(c);
    }
  }
  if (!cur_word.empty()) {
    words.push_back(std::move(cur_word));
  }
  return words;
}

} // namespace

Engine::Engine() {
  for (const auto &intrinsic : intrinsic_words) {
    dict.RegisterIntrinsic(intrinsic.first, intrinsic.second);
  }
}

void Engine::ExecWords(std::string_view src) {
  const auto words = ParseWords(src);
  for (const auto &word : words) {
    ExecWord(word);
  }
}

void Engine::ExecWord(const std::string &word) {
  // Check the dictionary first
  auto entry = dict.GetWord(word);
  if (entry) {
    if (const auto *compound = std::get_if<CompoundWord>(*entry)) {
      for (const auto &word : compound->words) {
        ExecWord(word);
      }
    } else if (auto *intrinsic = std::get_if<IntrinsicWord>(*entry)) {
      intrinsic->func(stack);
    } else {
      // TODO: Return an error
    }
  } else {
    // TODO: Handle literals properly
    const auto val = std::stoi(std::string{word});
    stack.push_back(val);
  }
}

} // namespace onward
