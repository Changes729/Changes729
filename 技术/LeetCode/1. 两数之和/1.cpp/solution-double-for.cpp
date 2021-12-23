#include <iostream>
#include <vector>

class Solution {
public:
  vector<int> twoSum(vector<int> &nums, int target) {
    // calculate vector.
    int i, j;
    size_t nums_length = nums.size();
    for (i = 0; i < nums_length; ++i) {
      for (j = i + 1; j < nums_length; ++j) {
        if (nums[i] + nums[j] == target) {
          // find target.
          goto result;
        }
      }
    }

  result:
    return vector<int>{i, j};
  }
};