#include<iostream>
#include<string>
#include<vector>
using namespace std;
string build(string s1,string s2){
    if(s1.size()>1){
        char t = s1[0];
        int it = s2.find(t);
        string l2 = s2.substr(0,it);
        string r2 = s2.substr(it+1,s2.size());
        string l1,r1;
        l1 = s1.substr(1,l2.size());
        r1 = s1.substr(s1.size()-r2.size(),s1.size());
        //cout<<t<<" s1 "<<s1<<" s2 "<<s2<<" l2 "<<l2<<" r2 "<<r2<<" l1 "<<l1<<" r1 "<<r1<<endl;
        return build(l1,l2) + build(r1,r2) +t;
    }else if(s1.size() == 1){
        return s1;
    }else{
        return "";
    }
}
int main(){
    string s1,s2;
    cin >> s2 >> s1;
    cout << build(s1,s2);
}

/*

SFAELOG
GOLEAFS

*/