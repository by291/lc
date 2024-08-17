struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
  ListNode *sortList(ListNode *head) {
    if (!head || !head->next) {
      return head;
    }

    ListNode *fast = head, *slow = new ListNode(-1, head);
    while (fast) {
      fast = fast->next ? fast->next->next : nullptr;
      slow = slow->next;
    }
    ListNode *rh = slow->next;
    slow->next = nullptr;

    ListNode *left = sortList(head), *right = sortList(rh);
    ListNode *dummy = new ListNode, *n = dummy;

    while (left && right) {
      if (left->val < right->val) {
        n->next = left;
        left = left->next;
      } else {
        n->next = right;
        right = right->next;
      }
      n = n->next;
    }

    while (left) {
      n->next = left;
      left = left->next;
      n = n->next;
    }
    while (right) {
      n->next = right;
      right = right->next;
      n = n->next;
    }
    return dummy->next;
  }
};

int main() {}