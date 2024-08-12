#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
  int maxArea(vector<int> &height) {
    int res = 0;

    int i = 0, j = height.size() - 1;
    while (i < j) {
      int cur = (j - i) * std::min(height[i], height[j]);
      res = std::max(res, cur);

      if (height[i] < height[j]) {
        i++;
      } else {
        j--;
      }
    }
    return res;
  }
};

int main() {
  Solution s;

  std::vector<int> nums = {1, 8, 6, 2, 5, 4, 8, 3, 7};
  int res = s.maxArea(nums);

  nums = {1, 1};
  res = s.maxArea(nums);
}