#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
void sort2(vector<long long int> *num) {
  long long int temp = (*num)[0];
  (*num).erase((*num).begin());
  int point = 0;
  for (auto i : *num) {
    if (temp < i) {
      (*num).insert((*num).begin() + point, temp);
      return;
    }
    point++;
  }
  (*num).push_back(temp);
}
int main() {
  int n;
  cin >> n;
  vector<long long int> apples;
  while (n > 0) {
    long long int t;
    cin >> t;
    apples.push_back(t);
    n--;
  }
  int r = 0;
  sort(apples.begin(), apples.end());
  while (apples.size() > 1) {
    sort2(&apples);
    int weight = apples[0] + apples[1];
    r += weight;
    apples.erase(apples.begin());
    apples[0] = weight;
  }
  cout << r;
}
