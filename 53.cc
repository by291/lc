#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
  int maxSubArray(vector<int> &nums) {
    vector<int> dp(nums.size());
    dp[0] = nums[0];

    int res = nums[0];
    for (int i = 1; i < nums.size(); i++) {
      dp[i] = max(dp[i - 1] + nums[i], nums[i]);
      res = max(res, dp[i]);
    }
    return res;
  }
};

int main() {
  Solution s;

  vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
  auto res = s.maxSubArray(nums);

  nums = {1};
  res = s.maxSubArray(nums);

  nums = {5, 4, -1, 7, 8};
  res = s.maxSubArray(nums);
}