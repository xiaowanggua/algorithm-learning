#include<cstdio>
#include<cstdio>
#include<vector>
#include<string>
#include<algorithm>
struct BigNumber
{
    private:
    std::vector<short> _content;
    public:
    BigNumber(){};
    BigNumber(long long int number){
        std::string s = std::to_string(number);
        for(auto it = s.rbegin();it != s.rend(); ++it)
        {
            _content.push_back(*it - '0');
        }

    }
    void read(){
        char ch = ' ';
        while((ch = getchar())!='\n' && ch != EOF){
            _content.push_back(short(ch - '0'));
        }
        std::reverse(_content.begin(),_content.end());
    }
    BigNumber operator+(BigNumber b){
        int size = this->size() >= b.size()?this->size():b.size();
        int ssize = this->size() <= b.size()?this->size():b.size();
        BigNumber temp1 = this->size() >= b.size()?*this:b;
        BigNumber temp2 = this->size() <= b.size()?b:*this;
        short nextadd = 0; 
        for(short i = 0;i<size;i++){
            short num = 0;
            if(i < ssize){
                //printf("%hd %hd",this->_content[i],b._content[i]);
                num = nextadd + this->_content[i] + b._content[i];
                //printf(" %hd",num);
                nextadd = num / 10;
                //printf(" %hd",nextadd);
                num %= 10;
                //printf(" %hd",num);
                temp1._content[i] = num;
            }else{
                num = nextadd + temp1._content[i];
                nextadd = num / 10;
                num %= 10;
                //printf("%hd %hd %hd",temp1._content[i],nextadd,num);
                temp1._content[i] = num;
            }
            if( i == size - 1){
                if(nextadd != 0){
                    temp1._content.push_back(nextadd);
                }
            }
            //printf(" %hd\n",num);
        }
        return temp1;
    }

    void out(){
        std::reverse(_content.begin(),_content.end());
        for(auto num:_content){
            printf("%hd",num);
        }
        std::reverse(_content.begin(),_content.end());
    }
    int size(){
        return _content.size();
    }
    
};
int main(){
    int n;
    BigNumber dp[5000];
    scanf("%d",&n);
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 2;
    for(int i = 3;i <= n;i++){
        dp[i] = dp[i-1] + dp[i-2];
    } 
   dp[n].out();
}