#include <array>
#include <cstdio>
#include <vector>
#include <cmath>
#include <iostream>
using namespace std;
int n;
vector<pair<int,int>> numbers;
vector<int> visited;

vector<vector<int>> results;
int check(int x,int y){
  for(auto i:numbers){
    if(abs((i.first - x)/float(i.second - y)) == 1){
      return 0;
    }
  }
  return 1;
}
void dfs(int y){
  for(int i = 0;i<n;i++){
    int flag = 0;
    for(auto j:visited){
      if(j==i){
        flag = 1;
        break;
      }
    }
    if(flag){
      continue;
    }
    if(check(i,y)){
      pair<int,int> t(i,y);
      visited.emplace_back(i);
      numbers.push_back(t);
      if(y<n-1){
        dfs(y+1);
      }else{
        results.emplace_back(visited);
      }
      visited.pop_back();
      numbers.pop_back();
    }
  }
}

int main(){
  scanf("%d",&n);
  dfs(0);
  for(int i =0;i<3;i++){
    vector<int> r = results[i];
    for(int j = 0;j < r.size();j++){
      if(j!= r.size()-1){
        cout << r[j]+1 << " ";  
      }
      else{
        cout << r[j]+1 << endl;
      }
    }
  }
  printf("%ld\n",results.size());

}