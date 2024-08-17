#include <queue>
#include <vector>

using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
private:
  struct Cmp {
    bool operator()(ListNode *a, ListNode *b) { return a->val > b->val; }
  };

public:
  ListNode *mergeKLists(vector<ListNode *> &lists) {
    priority_queue<ListNode *, std::vector<ListNode *>, Cmp> pq;
    for (ListNode *n : lists) {
      if (n) {
        pq.push(n);
      }
    }

    ListNode *dummy = new ListNode, *n = dummy;
    while (!pq.empty()) {
      ListNode *node = pq.top();
      pq.pop();

      n->next = node;
      n = n->next;

      if (node->next) {
        pq.push(node->next);
      }
    }
    return dummy->next;
  }
};

int main() {}