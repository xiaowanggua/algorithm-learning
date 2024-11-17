#include<cstdio>
#include<algorithm>
#include<vector>
#include<iostream>
using namespace std;
struct moneys
{
    int weight;
    int value;
    float avg;
    moneys(int weight,int value,float avg){
        this->weight = weight;
        this->value = value;
        this->avg = avg;
    }
};
bool compare(moneys a,moneys b){
    return a.avg > b.avg;
}
int main(){
    int N,T;
    vector<moneys> money;
    scanf("%d%d",&N,&T);
    for(int i = 0;i < N;i++){
        int weight,value;
        scanf("%d%d",&weight,&value);
        money.push_back(moneys(weight,value,(float)value/weight));
    }
    std::sort(money.begin(),money.end(),compare);
    float value = 0;
    int bag = 0;
    int i = 0;
    while(true){
        if(i>N-1){
            break;
        }
        bag+=money[i].weight;
        if((bag - T) > 0){
            int w = money[i].weight - (bag - T);
            value+= money[i].avg*w;
            //cout<<"final"<<bag<<value<<endl;
            break;
        }else{
            value+=money[i].value;
            //cout<<i<<":"<<bag<<value<<endl;
            i++;
        }
    }
    printf("%.2f",value);
}