#include <vector>

using namespace std;

class Solution {
public:
  vector<int> productExceptSelf(vector<int> &nums) {
    int n = nums.size();
    vector<int> leftProduct(n + 1), rightProduct(n + 1);
    leftProduct[0] = 1, rightProduct[n] = 1;

    for (int i = 0; i < n; i++) {
      leftProduct[i + 1] = leftProduct[i] * nums[i];
      rightProduct[n - i - 1] = rightProduct[n - i] * nums[n - i - 1];
    }

    vector<int> res(nums.size());
    for (int i = 0; i < nums.size(); i++) {
      res[i] = leftProduct[i] * rightProduct[i + 1];
    }
    return res;
  }
};

int main() {
  Solution s;

  vector<int> nums = {1, 2, 3, 4};
  auto res = s.productExceptSelf(nums);

  nums = {-1, 1, 0, -3, 3};
  res = s.productExceptSelf(nums);
}