/* #include<cstdio>
int find_min(int* n,int length,int end){
    length--;
    int i = length;
    while(length >= end){
        if(n[i]>n[length]){
           i = length;
        }
        length--;
    }
    return i;
}
void swap(int* n,int a,int b){
    int temp = n[a];
    n[a] = n[b];
    n[b] = temp;
}
int main(){
    int a,b;
    int* number = new int[a];
    scanf("%d%d",&a,&b);
    for(int i = 0;i < a;i++){
        scanf("%d",&number[i]);
    }
    for(int i = 0;i <= b;i++){
        swap(number,find_min(number,a-i,i),i);
    }
    printf("%d",number[b]);
}*/

#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;
int main() {
  int n, m;
  vector<int> a;
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; i++) {
  }
}
