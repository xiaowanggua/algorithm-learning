#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
struct t {
  int s = 0;
  int e = 0;
};
bool compareend(t a, t b) { return a.e < b.e; }
int main() {
  int n;
  cin >> n;
  vector<t> times;
  for (int i = 0; i < n; i++) {
    int a, b;
    cin >> a >> b;
    t temp = {a, b};
    times.push_back(temp);
  }
  sort(times.begin(), times.end(), compareend);
  int point = 0;
  int tempend = 0;
  int r = 0;
  while (point < times.size()) {
    if (times[point].s >= tempend) {
      r += 1;
      tempend = times[point].e;
    }
    point++;
  }
  cout << r;
}
