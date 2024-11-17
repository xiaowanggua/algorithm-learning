#include<cstdio>
#include<vector>
#include<string>
#include<iostream>
using namespace std;
typedef struct BigNumber
{
    std::vector<int> content;
    BigNumber(int number){
        std::string temp = std::to_string(number);
    }
    int size(){
        return content.size();
    }
    BigNumber operator>(BigNumber b){
        if(b.size()<size()){
            return true;
        }else{
            false;
        }

    }
    BigNumber operator+(BigNumber b){

    }
    
};

unsigned long long int jc(int n){
    unsigned long long int result = 1;
    for(;n>=1;n--){
        result*=n;
    }
    return result;
}
int main(){
    int n;
    scanf("%d",&n);
    BigNumber s(n);
}
