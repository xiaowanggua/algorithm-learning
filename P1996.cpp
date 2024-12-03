#include <cstddef>
#include <system_error>
#include <type_traits>
template <typename T> struct node {
  node *nextNode;
  node *frontNode;
  T content;
  node(T content, node<T> *frontNode) {
    this->content = content;
    this->nextNode = nullptr;
    this->frontNode = frontNode;
  }
  node *operator+(std::size_t a) {
    node *rNode = this;
    while (a > 0) {
      rNode = rNode->nextNode;
      a--;
    }
    return rNode;
  }
};
template <typename T> struct nodetree {
  node<T> *rootNode;
  node<T> *currentNode;
  int len = 0;
  nodetree<T>() {}
  nodetree<T>(T content) {
    node<T> *Node = new node<T>(content, nullptr);
    currentNode = Node;
    rootNode = Node;
    len++;
  }
  void add_node(T content) {
    len++;
    node<T> *newNode = new node<T>(content, currentNode);
    currentNode->nextNode = newNode;
    currentNode = newNode;
  }
  void connect_circle() {
    rootNode->frontNode = currentNode;
    currentNode->nextNode = rootNode;
  }
  T get(size_t index) {
    if (index > len - 1) {
      return NULL;
    }
    return (*(this->rootNode) + index)->content;
  }
  void erase(node<T> *rNode) {
    if (rNode == rootNode) {
      rootNode = rNode->nextNode;
    }
    if (rNode->frontNode != nullptr) {
      rNode->frontNode->nextNode = rNode->nextNode;
    }
    if (rNode->nextNode != nullptr) {
      rNode->nextNode->frontNode = rNode->frontNode;
    }
    len--;
    delete rNode;
  }
  void erase(size_t index) {
    if (index > len - 1) {
      return;
    }
    node<T> *rNode = (*(this->rootNode) + index);
    if (rNode == rootNode) {
      rootNode = rNode->nextNode;
    }
    if (rNode->frontNode != nullptr) {
      rNode->frontNode->nextNode = rNode->nextNode;
    }
    if (rNode->nextNode != nullptr) {
      rNode->nextNode->frontNode = rNode->frontNode;
    }
    len--;
    delete rNode;
  }
};
#include <cstdio>
int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  nodetree<int> t(1);
  for (int i = 2; i <= n; i++) {
    t.add_node(i);
  }
  t.connect_circle();
  node<int> *rNode = t.rootNode;
  while (t.len > 0) {
    rNode = (*rNode + m);
    printf("%d ", rNode->frontNode->content);
    t.erase(rNode->frontNode);
  }
}
