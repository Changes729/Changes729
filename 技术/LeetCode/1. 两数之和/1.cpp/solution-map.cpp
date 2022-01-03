#include <iostream>
#include <map>
#include <vector>

using namespace std;

class Solution {
public:
  vector<int> twoSum(vector<int> &nums, int target) {
    map<int, int> record;
    int i;
    size_t nums_length = nums.size();
    for (i = 0; i < nums_length; ++i) {
      if (record.count(target - nums[i]) > 0) {
        break;
      }

      record[nums[i]] = i;
    }

    return (i == nums_length) ? vector<int>{}
                              : vector<int>{record[target - nums[i]], i};
  }
};
