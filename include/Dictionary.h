#pragma once

#include <optional>
#include <string>
#include <unordered_map>
#include <variant>
#include <vector>

namespace onward {

struct CompoundWord {
  std::vector<std::string> words;
};

struct IntrinsicWord {
  std::function<void(std::vector<uint64_t> &)> func;
};

using Entry = std::variant<CompoundWord, IntrinsicWord>;

class Dictionary {
public:
  Dictionary() = default;

  void RegisterWord(std::string &&word_name, std::vector<std::string> &&impl);
  void
  RegisterIntrinsic(std::string word_name,
                    std::function<void(std::vector<uint64_t> &)> intrinsic);
  std::optional<const Entry *> GetWord(const std::string &word_name) const;

private:
  std::unordered_map<std::string, Entry> dict;
};

} // namespace onward
