#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  size_t IMG_X;
  size_t IMG_Y;

  vector<vector<int>> imageSmoother(vector<vector<int>> &img) {
    IMG_X = img.size();
    IMG_Y = img[0].size();
    vector<vector<int>> smooth_img(IMG_X, std::vector<int>(IMG_Y));

    for (int index_x = 0; index_x < IMG_X; index_x++) {
      for (int index_y = 0; index_y < IMG_Y; index_y++) {
        smooth_img[index_x][index_y] = count_avarage(img, index_x, index_y);
      }
    }

    return smooth_img;
  }

  int count_avarage(vector<vector<int>> &img, int X, int Y) {
    int sum = 0;
    int count = 0;
    for (int x = X - 1; x <= X + 1; x++) {
      for (int y = Y - 1; y <= Y + 1; y++) {
        if (x >= 0 && y >= 0 && x < IMG_X && y < IMG_Y) {
          sum = sum + img[x][y];
          count++;
        }
      }
    }

    return sum / count;
  }
};