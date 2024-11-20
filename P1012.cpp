#include <algorithm>
#include <cstdio>
#include <string>
#include <vector>
using namespace std;
bool compare(int a, int b) {
  string s1 = to_string(a);
  string s2 = to_string(b);
  bool True = true;
  if (s1.size() < s2.size()) {
    swap(s1, s2);
    True = !True;
  }
  for (int i = 0; i < s1.size(); i++) {
    if (s2.size() - 1 >= i) {
      int a1 = s1[i] - '0';
      int b1 = s2[i] - '0';
      //    printf("%d %d\n", a1, b1);
      if (a1 > b1) {
        return True;
      } else if (a1 < b1) {
        return !True;
      } else {
        continue;
      }
    } else {
      if (s1[i] > s2[0]) {
        return True;
      } else {
        return !True;
      }
    }
  }
}
#include <iostream>
int main() {

  int n;
  scanf("%d", &n);

  vector<int> numbers;
  for (int i = 0; i < n; i++) {
    int temp;
    scanf("%d", &temp);
    numbers.push_back(temp);
  }
  sort(numbers.begin(), numbers.end(), compare);
  for (auto i : numbers) {
    printf("%d", i);
  }
}
