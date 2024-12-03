// #include "datareader.hpp"
#include <algorithm>
#include <cstdio>
#include <iostream>
#include <ostream>
#include <vector>
using namespace std;
struct number {
  int content;
  int p;
};
bool campare(number a, number b) {
  if (a.content >= b.content) {
    return false;
  } else {
    return true;
  }
}
int main() {
  int n;
  vector<number> numbers;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int temp;
    cin >> temp;
    number tempNumber = {temp, i + 1};
    numbers.push_back(tempNumber);
  }
  sort(numbers.begin(), numbers.end(), campare);
  long long int times = 0;
  long int waitingtimes = 0;
  for (int i = 0; i < n; i++) {
    times += waitingtimes;
    if (i != n - 1)
      cout << numbers[i].p << ' ';
    else
      cout << numbers[i].p << endl;
    waitingtimes += numbers[i].content;
  }
  printf("%.2lf", times / (double)n);
}
