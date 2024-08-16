struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
  ListNode *swapPairs(ListNode *head) {
    ListNode *dummy = new ListNode(-1, head);
    ListNode *n = dummy;

    while (head) {
      if (!head->next) {
        break;
      }

      ListNode *next = head->next->next;
      ListNode *tmp = head->next;
      
      head->next = next;
      tmp->next = head;
      n->next = tmp;
      n = n->next->next;

      head = next;
    }
    return dummy->next;
  }
};

int main() {}