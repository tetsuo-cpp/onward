#pragma once

#include "Dictionary.h"

namespace onward {

extern std::vector<
    std::pair<std::string, std::function<void(std::vector<uint64_t> &)>>>
    intrinsic_words;

} // namespace onward
