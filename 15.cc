#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
  vector<vector<int>> threeSum(vector<int> &nums) {
    std::sort(nums.begin(), nums.end());

    std::vector<std::vector<int>> res;

    int i = 0;
    while (i < nums.size()) {
      if (nums[i] > 0) {
        break;
      }

      int j = i + 1, k = nums.size() - 1;

      while (j < k) {
        int sum = nums[i] + nums[j] + nums[k];

        if (sum > 0) {
          while (j < k - 1 && nums[k - 1] == nums[k]) {
            k--;
          }
          k--;
        } else if (sum < 0) {
          while (j + 1 < k && nums[j] == nums[j + 1]) {
            j++;
          }
          j++;
        } else {
          res.push_back({nums[i], nums[j], nums[k]});

          while (j < k - 1 && nums[k - 1] == nums[k]) {
            k--;
          }
          k--;

          while (j + 1 < k && nums[j] == nums[j + 1]) {
            j++;
          }
          j++;
        }
      }

      while (i + 1 < nums.size() && nums[i] == nums[i + 1]) {
        i++;
      }
      i++;
    }
    return res;
  }
};

int main() {
  Solution s;

  std::vector<int> nums = {-1, 0, 1, 2, -1, -4};
  auto res = s.threeSum(nums);

  nums = {0, 1, 1};
  res = s.threeSum(nums);

  nums = {0, 0, 0};
  res = s.threeSum(nums);

  nums = {0, 0, 0, 0};
  res = s.threeSum(nums);
}