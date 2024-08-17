#include <stack>
#include <vector>

using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

class Solution {
private:
  vector<int> res;

  void inOrder(TreeNode *root) {
    if (!root) {
      return;
    }

    inOrder(root->left);
    res.push_back(root->val);
    inOrder(root->right);
  }

  vector<int> inOrder2(TreeNode *root) {
    if (!root) {
      return {};
    }

    vector<int> res;
    stack<TreeNode *> s;
    TreeNode *n = root;

    while (n || !s.empty()) {
      while (n) {
        s.push(n);
        n = n->left;
      }

      n = s.top();
      s.pop();
      res.push_back(n->val);
      n = n->right;
    }
    return res;
  }

public:
  vector<int> inorderTraversal(TreeNode *root) { return inOrder2(root); }
};

int main() {}