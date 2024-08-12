#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
  vector<int> twoSum(vector<int> &nums, int target) {
    std::unordered_map<int, int> m;

    for (int i = 0; i < nums.size(); i++) {
      int n = nums[i];
      if (m.find(target - n) != m.end()) {
        return {m[target - n], i};
      }

      m[n] = i;
    }
    return {};
  }
};

int main() {
  Solution s;

  std::vector<int> nums = {2, 7, 11, 15};
  int target = 9;
  auto res = s.twoSum(nums, target);

  nums = {3, 2, 4};
  target = 6;
  res = s.twoSum(nums, target);

  nums = {3, 3};
  target = 6;
  res = s.twoSum(nums, target);
}