#include<cstdio>
int main(){
    int d = 0;
    int dtime = 0;
    for(int i = 0;i < 7;i++){
        int a,b;
        scanf("%d%d",&a,&b);
        a = a + b;
        if(a > 8){
            if(a > dtime){
                dtime = a;
                d = i+1;
            }
        }
    }
    printf("%d\n",d);
}