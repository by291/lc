#include <algorithm>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
  int lengthOfLongestSubstring(string s) {
    std::unordered_map<char, int> m;
    int res = 0;

    int l = 0, r = 0;
    while (r < s.size()) {
      while (l < r && m[s[r]] > 0) {
        m[s[l++]]--;
      }

      int cur = r - l + 1;
      res = std::max(res, cur);
      m[s[r++]]++;
    }
    return res;
  }
};

int main() {
  Solution s;

  std::string str = "abcabcbb";
  auto res = s.lengthOfLongestSubstring(str);

  str = "bbbbb";
  res = s.lengthOfLongestSubstring(str);

  str = "pwwkew";
  res = s.lengthOfLongestSubstring(str);
}