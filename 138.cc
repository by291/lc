#include <unordered_map>

using namespace std;

class Node {
public:
  int val;
  Node *next;
  Node *random;

  Node(int _val) {
    val = _val;
    next = nullptr;
    random = nullptr;
  }
};

class Solution {
public:
  Node *copyRandomList(Node *head) {
    Node *dummy = new Node(-1);
    Node *n = dummy;

    Node *t = head;
    unordered_map<Node *, Node *> m;
    while (t) {
      Node *tmp = new Node(t->val);
      m[t] = tmp;

      n->next = tmp;
      n = n->next;
      t = t->next;
    }

    n = dummy->next;
    t = head;
    while (n) {
      n->random = m[t->random];

      n = n->next;
      t = t->next;
    }
    return dummy->next;
  }
};

int main() {}