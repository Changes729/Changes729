#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
  int lengthOfLongestSubstring(string s) {
    int begin_index = 0;
    int end_index = 0;
    size_t max_length = 0;

    auto update_max_length = [&](const auto sub_length) {
      if (sub_length > max_length) {
        max_length = sub_length;
      }
    };

    auto find_sub_char = [](const string &s, int begin_index,
                            const int end_index, const char find) {
      bool is_find = false;
      for (; begin_index < end_index; begin_index++) {
        if (s[begin_index] == find) {
          is_find = true;
          break;
        }
      }

      return is_find;
    };

    for (end_index = begin_index; end_index < s.length(); end_index++) {
      while (end_index != begin_index &&
             find_sub_char(s, begin_index, end_index, s[end_index])) {
        update_max_length(end_index - begin_index);
        begin_index++;
      }
    }
    update_max_length(end_index - begin_index);
    return max_length;
  }
};