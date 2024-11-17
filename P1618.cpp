#include<iostream>
#include<set>
using namespace std;
int main(){
    int a,b,c;
    int hasresult = 0;
    scanf("%d %d %d",&a,&b,&c);
    for (int i = 1; i <= 9; i++)
    {
         for (int j = 1; j <= 9; j++)
        {
            
            for (int k = 1; k <= 9; k++)
            {
                if(a==0||b==0||c==0){
                    break;
                }
                //cout<<i<<j<<k<<endl;
                if((i==j)||(i==k)||(j==k)){
                    continue;
                }
                int num1 = i * 100 + j * 10 + k;
                if((num1*b)%a!=0 || (num1 * b / a)>999){
                    continue;
                }
                int num2 = num1 * b / a;
                if((num2*c)%b!=0 || (num2 * c / b)>999){
                    continue;
                }
                int num3 = num2 * c / b;
                int numbers[10] = {0};
                string s1 = std::to_string(num1)+std::to_string(num2)+std::to_string(num3);
                for(auto i:s1){
                    numbers[i-'0']+=1;
                }
                if(numbers[0]>0){
                    continue;
                }
                numbers[0]=1;
                int found = 0;
                for(auto i:numbers){
                    //cout<<"1:"<<i<<endl;
                    if(i != 1){
                        found = 1;
                        break;
                    }
                }

                if(found == 1){
                    continue;
                }
                cout<<num1<<" "<<num2<<" "<<num3<<endl; 
                hasresult+=1;
            }

        }
    }
    if(hasresult==0){
        cout<<"No!!!";
    }
}