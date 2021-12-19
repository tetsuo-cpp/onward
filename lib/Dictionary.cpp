#include "Dictionary.h"

namespace onward {

void Dictionary::RegisterWord(std::string &&word_name,
                              std::vector<std::string> impl) {
  dict.emplace(std::move(word_name), CompoundWord({std::move(impl)}));
}

void Dictionary::RegisterIntrinsic(
    std::string word_name,
    std::function<void(std::vector<uint64_t> &)> intrinsic) {
  dict.emplace(std::move(word_name), IntrinsicWord({std::move(intrinsic)}));
}

std::optional<const Entry *>
Dictionary::GetWord(const std::string &word_name) const {
  const auto iter = dict.find(word_name);
  if (iter == dict.end()) {
    return {};
  }
  return &iter->second;
}

} // namespace onward
