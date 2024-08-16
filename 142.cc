#include <unordered_set>

using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
  ListNode *detectCycle(ListNode *head) {
    unordered_set<ListNode *> s;

    while (head) {
      if (s.find(head) != s.end()) {
        return head;
      }

      s.insert(head);
      head = head->next;
    }
    return nullptr;
  }
};

int main() {}