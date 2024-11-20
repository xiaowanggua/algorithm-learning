#include <algorithm>
#include <iostream>
#include <istream>
#include <ostream>
#include <string>
#include <vector>
using namespace std;
struct BigNumber {
  vector<int> content;

public:
  BigNumber() {}
  BigNumber(long long int n) {
    string s = to_string(n);
    reverse(s.begin(), s.end());
    for (auto i : s) {
      int a = i - '0';
      content.push_back(a);
    }
  }
  bool operator>(BigNumber b) {
    if (content.size() > b.content.size()) {
      return true;
    } else if (content.size() < b.content.size()) {
      return false;
    } else {
      for (int i = content.size() - 1; i >= 0; i--) {
        if (content[i] > b.content[i]) {
          return true;
        } else if (content[i] < b.content[i]) {
          return false;
        }
        if (i == 0) {
          return false;
        }
      }
    }
  }
  BigNumber operator+(BigNumber in) {
    BigNumber number = BigNumber();
    BigNumber a = BigNumber();
    BigNumber b = BigNumber();
    if (*this > b) {
      a = *this;
      b = in;
    } else {
      a = in;
      b = *this;
    }
    int next_add = 0;
    for (int i = 0; i < a.content.size(); i++) {
      int r = 0;
      if (i < b.content.size()) {
        r = a.content[i] + b.content[i] + next_add;
        // cout << a.content[i] << '+' << b.content[i] << '+' << next_add << '='
        //     << r << endl;
      } else {
        r = a.content[i] + next_add;
      }
      next_add = r / 10;
      r %= 10;
      number.content.push_back(r);
    }
    if (next_add != 0) {
      number.content.push_back(next_add);
    }
    return number;
  }
  BigNumber operator*(BigNumber b) { return *this; }
  friend ostream &operator<<(ostream &out, const BigNumber &n);
  friend istream &operator>>(istream &in, const BigNumber &n);
};
ostream &operator<<(ostream &out, const BigNumber &n) {
  for (int i = n.content.size() - 1; i >= 0; i--) {
    out << n.content[i];
  }
  return out;
}
istream &operator>>(istream &in, BigNumber &n) {
  string s;
  in >> s;
  reverse(s.begin(), s.end());
  for (auto i : s) {
    n.content.push_back(i - '0');
  }
  return in;
}
#define test
#ifdef test
#include <iostream>
int main() {
  BigNumber a;
  BigNumber b;
  cin >> a;
  cin >> b;
  a = a + b;
  cout << a;
}
#endif
