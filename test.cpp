#include<string>
#include<iostream>
using namespace std;
int main(){
    string s = "123";
    cout << s.substr(s.find("2"),3);
}