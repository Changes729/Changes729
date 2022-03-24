#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2) {
    const size_t LENGTH1 = nums1.size();
    const size_t LENGTH2 = nums2.size();
    const bool IS_ODD = (LENGTH1 + LENGTH2) & 0x01;

    vector<int> merge_arr;
    merge_arr.reserve(LENGTH1 + LENGTH2);
    merge_arr.insert(merge_arr.end(), nums1.begin(), nums1.end());
    merge_arr.insert(merge_arr.end(), nums2.begin(), nums2.end());

    sort(merge_arr.begin(), merge_arr.end());

    auto mid_index = (LENGTH1 + LENGTH2) / 2;
    return IS_ODD ? merge_arr[mid_index]
                  : (merge_arr[mid_index] + merge_arr[mid_index - 1]) * 1.0 / 2;
  }
};