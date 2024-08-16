struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
  ListNode *removeNthFromEnd(ListNode *head, int n) {
    ListNode *dummy = new ListNode(-1, head);
    ListNode *fast = head;
    ListNode *slow = dummy;

    while (n-- > 0) {
      fast = fast->next;
    }

    while (fast) {
      fast = fast->next;
      slow = slow->next;
    }

    slow->next = slow->next ? slow->next->next : nullptr;
    return dummy->next;
  }
};

int main() {}