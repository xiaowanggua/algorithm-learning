#include <cstdio>
#include <algorithm>

int main(){
    
    int counts = 0;
    scanf("%d",&counts);
    int* num = new int[counts];
    for(int i = 0;i < counts;i++){
        scanf("%d",&num[i]);
    }
    std::sort(num,num + counts);
    for(int i = 0;i < counts;i++){
        if(i == (counts - 1)){
            printf("%d\n",num[i]);
        }else{
            printf("%d ",num[i]);
        }
    }
}