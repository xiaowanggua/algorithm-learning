#include <cmath>
#include <cstdio>
#include <vector>
struct mark {
  int a;
  int b;
  int type;

public:
  void addA() { a += 1; }
  void addB() { b += 1; }
  void reset() {
    a = 0;
    b = 0;
  }
  bool check_end() {
    if ((a >= type || b >= type) && (abs(a - b) >= 2)) {
      return true;
    } else {
      return false;
    }
  }
};

int main() {
  char c;
  std::vector<mark> mark11;
  std::vector<mark> mark21;
  mark mark1 = mark{0, 0, 11};
  mark mark2 = mark{0, 0, 21};
  while ((c = getchar()) != 'E') {
    if (c == 'W') {
      mark1.addA();
      mark2.addA();
    } else if (c == 'L') {
      mark1.addB();
      mark2.addB();
    }
    if (mark1.check_end()) {
      mark11.push_back(mark1);
      mark1.reset();
    }
    if (mark2.check_end()) {
      mark21.push_back(mark2);
      mark2.reset();
    }
  }
  mark11.push_back(mark1);
  mark21.push_back(mark2);
  for (auto i : mark11) {
    printf("%d:%d\n", i.a, i.b);
  }
  printf("\n");
  for (auto i : mark21) {
    printf("%d:%d\n", i.a, i.b);
  }
}
