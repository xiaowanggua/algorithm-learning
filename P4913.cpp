#include<cstdio>
#include<vector>
#include<iostream>
using namespace std;

int dfs(int k,vector<pair<int,int>>& nodes,int depth){
    pair<int,int> now =  nodes[k];
    depth+=1;
    int a = depth,b = depth;
    if(now.first!=0){
        a = dfs(now.first-1,nodes,depth);
    }
    if(now.second!=0){
        b = dfs(now.second-1,nodes,depth);
    }
    return a>=b?a:b;
}
int main(){
    int t;
    scanf("%d",&t);
    vector<pair<int,int>> nodes;
    while(t!=0){
        int a,b;
        pair<int,int> temp;
        scanf("%d%d",&a,&b);
        temp.first = a;
        temp.second = b;
        nodes.emplace_back(temp);
        t--;
    }
    printf("%d",dfs(0,nodes,0));
    return 0;
}