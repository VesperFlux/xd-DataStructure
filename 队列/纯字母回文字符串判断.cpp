#include<iostream>
#include<string>
#include<stack>
using namespace std;
//判断纯字母字符串是否为回文字符串
bool isPalindrome(string s){
    stack<char> stk;
    int n = s.size(); 
    if(n <= 1) return true;
    for(int i=0; i<n/2; ++i){
        stk.push(s[i]);
    }
    for(int i=(n+1)/2; i<n; ++i){
        char ch = stk.top();
        if (s[i] != ch) return false;
        stk.pop();
    }
    return true;
}
int main(){
    string s;
    cin >> s;
    bool val = isPalindrome(s);
    cout << "val的值是" << val << endl;
    return 0;
}