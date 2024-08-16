struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
  bool isPalindrome(ListNode *head) {
    ListNode *rev = nullptr;

    ListNode *n = head;
    while (n) {
      ListNode *newNode = new ListNode(n->val, rev);
      rev = newNode;
      n = n->next;
    }

    while (rev) {
      if (rev->val != head->val) {
        return false;
      }

      rev = rev->next;
      head = head->next;
    }
    return true;
  }
};

int main() {}