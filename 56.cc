#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
  vector<vector<int>> merge(vector<vector<int>> &intervals) {
    std::sort(intervals.begin(), intervals.end(),
              [](const auto &a, const auto &b) { return a[0] < b[0]; });

    vector<vector<int>> res;
    vector<int> tmp = intervals[0];
    for (int i = 1; i < intervals.size(); i++) {
      auto cur = intervals[i];

      if (tmp[1] >= cur[0]) {
        tmp[1] = max(tmp[1], cur[1]);
      } else {
        res.push_back(tmp);
        tmp = cur;
      }
    }
    res.push_back(tmp);
    return res;
  };
};

int main() {
  Solution s;

  vector<vector<int>> intervals = {{1, 3}, {2, 6}, {8, 10}, {15, 18}};
  auto res = s.merge(intervals);

  intervals = {{1, 4}, {4, 5}};
  res = s.merge(intervals);
}