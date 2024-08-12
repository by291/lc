#include <algorithm>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
public:
  int longestConsecutive(vector<int> &nums) {
    std::unordered_set<int> s(nums.begin(), nums.end());
    int res = 0;

    for (int n : nums) {
      if (s.find(n + 1) == s.end()) {
        int cur = 1;

        while (s.find(--n) != s.end()) {
          cur++;
        }
        res = std::max(cur, res);
      }
    }
    return res;
  }
};

int main() {
  Solution s;

  std::vector<int> nums = {100, 4, 200, 1, 3, 2};
  auto res = s.longestConsecutive(nums);

  nums = {0, 3, 7, 2, 5, 8, 4, 6, 0, 1};
  res = s.longestConsecutive(nums);
}