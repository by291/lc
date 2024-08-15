#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
private:
  using CharMap = std::unordered_map<char, int>;

  bool is_equal(CharMap o, CharMap m) {
    for (auto it = o.begin(); it != o.end(); ++it) {
      if (m[it->first] != it->second) {
        return false;
      }
    }
    return true;
  }

public:
  vector<int> findAnagrams(string s, string p) {
    if (s.size() < p.size()) {
      return {};
    }

    CharMap o;
    CharMap m;
    std::vector<int> res;

    for (int i = 0; i < p.size(); i++) {
      o[p[i]]++;
      m[s[i]]++;
    }

    int l = 0, r = p.size() - 1;
    while (r < s.size()) {
      if (is_equal(o, m)) {
        res.push_back(l);
      }

      m[s[l++]]--;
      m[s[++r]]++;
    }
    return res;
  }
};

int main() {
  Solution s;

  std::string str = "cbaebabacd";
  std::string p = "abc";
  auto res = s.findAnagrams(str, p);

  str = "abab";
  p = "ab";
  res = s.findAnagrams(str, p);
}