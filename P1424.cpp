#include<cstdio>
int main(){
    int x,n;
    scanf("%d%d",&x,&n);
    int result = 0;
    while ( n > 0)
    {
        if(x == 8){
            x = 1;
        }
        if(x != 6&&x != 7){
            result += 250;   
            //printf("z:%dr:%d\n",x,result);

        }
        x++;
        n--;
    }
    printf("%d\n",result);
}