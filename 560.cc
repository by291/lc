#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
  int subarraySum(vector<int> &nums, int k) {
    vector<int> preSum(nums.size() + 1, 0);

    for (int i = 0; i < nums.size(); i++) {
      preSum[i + 1] = preSum[i] + nums[i];
    }

    unordered_map<int, int> m;
    m[0] = 1;
    int res = 0;
    for (int i = 1; i <= nums.size(); i++) {
      if (m.find(preSum[i] - k) != m.end()) {
        res += m[preSum[i] - k];
      }
      m[preSum[i]]++;
    }
    return res;
  }
};

int main() {
  Solution s;

  vector<int> nums = {1, 1, 1};
  int k = 2;
  auto res = s.subarraySum(nums, k);

  nums = {1, 2, 3};
  k = 3;
  res = s.subarraySum(nums, k);
}