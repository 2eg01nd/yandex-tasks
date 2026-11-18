#include "two_sum.h"
#include <unordered_map>

std::vector<int> Solution::twoSum(const std::vector<int> &nums, int target)
{
    std::unordered_map<int, int> seen;
    for (int i = 0; i < static_cast<int>(nums.size()); ++i) {
        auto comp = target - nums[i];
        if (seen.find(comp) != seen.end()) {
            return {seen[comp], i};
        }
        seen[nums[i]] = i;
    }
    return {};
}
