#include <unordered_map>

using namespace std;

class LRUCache {
private:
  struct Node {
    int key;
    int val;

    Node *next;
    Node *prev;
  };

  Node *head;
  unordered_map<int, Node *> m;
  int cap;

  Node *_get(int key) {
    if (m.find(key) == m.end()) {
      return nullptr;
    }

    Node *n = m[key];

    n->prev->next = n->next;
    n->next->prev = n->prev;

    n->next = head->next;
    n->prev = head;
    head->next->prev = n;
    head->next = n;
    return n;
  }

public:
  LRUCache(int capacity) : cap(capacity) {
    head = new Node;
    head->next = head;
    head->prev = head;
  }

  int get(int key) {
    Node *n = _get(key);
    return n ? n->val : -1;
  }

  void put(int key, int value) {
    if (m.find(key) != m.end()) {
      _get(key)->val = value;
      return;
    }

    if (m.size() == cap) {
      Node *n = head->prev;

      n->prev->next = n->next;
      n->next->prev = n->prev;

      m.erase(n->key);
    }

    Node *n = new Node;
    n->key = key;
    n->val = value;

    n->next = head->next;
    n->prev = head;
    head->next->prev = n;
    head->next = n;

    m[key] = n;
  }
};

int main() {}