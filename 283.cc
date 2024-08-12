#include <utility>
#include <vector>

using namespace std;

class Solution {
public:
  void moveZeroes(vector<int> &nums) {
    int idx = 0;

    while (idx < nums.size() && nums[idx] != 0) {
      idx++;
    }

    for (int i = idx; i < nums.size();) {
      if (nums[i] != 0) {
        std::swap(nums[i], nums[idx++]);
      }

      i++;
    }
  }
};

int main() {
  Solution s;

  std::vector<int> nums = {0, 1, 0, 3, 12};
  s.moveZeroes(nums);

  nums = {0};
  s.moveZeroes(nums);

  nums = {1};
  s.moveZeroes(nums);
}