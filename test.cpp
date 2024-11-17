#include<stdio.h>
int* sbzty(){
    int a[] = {1,2,3};
    return a;
}
int main(){
    printf("%d",sbzty()[1]);
}