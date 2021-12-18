#include "Intrinsics.h"

#include <iostream>

namespace onward {

std::vector<
    std::pair<std::string, std::function<void(std::vector<uint64_t> &)>>>
    intrinsic_words = {{"+",
                        [](std::vector<uint64_t> &stack) {
                          const auto lhs_operand = stack.back();
                          stack.pop_back();
                          const auto rhs_operand = stack.back();
                          stack.pop_back();
                          const auto add_val = lhs_operand + rhs_operand;
                          stack.push_back(add_val);
                        }},
                       {".",
                        [](std::vector<uint64_t> &stack) {
                          const auto top = stack.back();
                          stack.pop_back();
                          std::cout << top << std::endl;
                        }},
                       {".s", [](std::vector<uint64_t> &stack) {
                          for (const auto v : stack) {
                            std::cout << "[" << v << "]";
                          }
                          std::cout << std::endl;
                        }}};

} // namespace onward
