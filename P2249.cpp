#include<cstdio>
#include<vector>
#include<string>
using namespace std;
inline int read(){
	char ch;
	int number = 0;
	while((ch = getchar())!=' ' && ch!='\n'){
		number = number * 10 + (ch-'0');
	}
	return number;
}
/*  //递归版本TLE
int find(vector<int> numbers,int left,int right,int n){
	if(left >= right){
		if(numbers[left] != n){
			return -1;
		}
		return right + 1;
	}
	int mid = (left+right)/2;
	if(n <= numbers[mid]){
		right = mid;
	}else if(n > numbers[mid]){
		left = mid + 1;
	}
	//printf("find %d %d\n",left,right);
	return find(numbers,left,right,n);
}
int search(vector<int> numbers,int n){
	return find(numbers,0,numbers.size()-1,n);
} 
*/

int search(int* numbers,int n,int size){
	int i = 0;
	int j = size - 1;
	while(i<j){
		int mid = (i+j)/2;
		if(n <= numbers[mid]){
			j = mid;
		}else{
			i = mid + 1;
		}
	}
	if(numbers[i] != n){
		return -1;
	}
	return i+1;
} 
int main(){
	int MAX[1000001];
	int m,n;
	scanf("%d%d",&m,&n);
	for(int i = 0;i<m;i++){
		scanf("%d",&MAX[i]);
	}
	for(int i = 0;i<n;i++){
		int ans;
		scanf("%d",&ans);
		printf("%d ",search(MAX,ans,m));
	}
}