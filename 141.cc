
struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
  bool hasCycle(ListNode *head) {
    ListNode *fast = head, *slow = head;

    while (fast) {
      fast = fast->next ? fast->next->next : nullptr;
      slow = slow->next;

      if (fast && fast == slow) {
        return true;
      }
    }
    return false;
  }
};

int main() {}