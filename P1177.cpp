//快速排序
#include<iostream>
int counts;
void printnum(int* num){
    using namespace std;
    for(int i = 0;i < counts;i++){
        cout<<num[i]<<" ";
    }
    cout<<endl;
}
void swap(int* a,int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
int sort(int* num,int first,int second){
    int i = first;
    int j = second;
    int r = first;
    //printf("r:%d\n",r);
    while (i<j){
        while(i<j && num[j] >= num[r]){
            j--;
            //printf("%d-- ",j+1);
        }
        while(i<j && num[i] <= num[r]){
            i++;
           // printf("%d-- ",i-1);
        }
        //printf("swap %d:%d %d:%d\n",i,num[i],j,num[j]);
        swap(&num[i],&num[j]);
        //printnum(num);
    }
    //printf("fswap %d:%d %d:%d\n",r,num[r],j,num[j]);

    swap(&num[r],&num[j]);
    //printnum(num);
    return j;
}
void quicksort(int* num,int first,int second){
    if(first >= second){
        return;
    }

    int i = sort(num,first,second);
    quicksort(num,first,i-1);
    quicksort(num,i+1,second);

}
int main(){
    using namespace std;
    cin>>counts;
    int* num = new int[counts];
    for(int i = 0;i < counts;i++){
        cin>>num[i];
    }
    quicksort(num,0,counts-1);
    printnum(num);
}