struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
  ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
    ListNode *dummy = new ListNode;
    ListNode *n = dummy;
    int t = 0;

    while (l1 && l2) {
      int s = l1->val + l2->val + t;
      t = s / 10;
      n->next = new ListNode(s % 10);

      n = n->next;
      l1 = l1->next;
      l2 = l2->next;
    }

    while (l1) {
      int s = l1->val + t;
      t = s / 10;
      n->next = new ListNode(s % 10);

      n = n->next;
      l1 = l1->next;
    }

    while (l2) {
      int s = l2->val + t;
      t = s / 10;
      n->next = new ListNode(s % 10);

      n = n->next;
      l2 = l2->next;
    }

    if (t) {
      n->next = new ListNode(t);
    }
    return dummy->next;
  }
};

int main() {}