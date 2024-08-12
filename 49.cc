#include <algorithm>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
  vector<vector<string>> groupAnagrams(vector<string> &strs) {
    std::unordered_map<std::string, std::vector<std::string>> m;

    for (const auto &s : strs) {
      auto sorted = s;
      std::sort(sorted.begin(), sorted.end());

      m[sorted].push_back(s);
    }

    std::vector<std::vector<std::string>> res;
    for (auto it = m.begin(); it != m.end(); ++it) {
      res.push_back(it->second);
    }
    return res;
  }
};

int main() {
  Solution s;

  std::vector<std::string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};
  auto res = s.groupAnagrams(strs);

  strs = {""};
  res = s.groupAnagrams(strs);

  strs = {"a"};
  res = s.groupAnagrams(strs);
}