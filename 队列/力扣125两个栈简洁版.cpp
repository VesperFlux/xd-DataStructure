#include<stack>
#include<cctype>
using namespace std;
bool isPalindrome(string s){
    stack<char> stk0;                 
    stack<char> stk1;
    int n = 0;                                       //记录有效字符个数
    for (char ch : s){
        if (isalnum(ch)){                            //isalnum()函数直接判断是否为字母或数字
            stk0.push(ch);
            ++n;
        }
    }
    for(int i=0; i<n/2; ++i){
        stk1.push(stk0.top());
        stk0.pop();
    }
    if (n%2 == 1) stk0.pop();
    for (int i=0; i <n/2; ++i){
        char ch0 = tolower(stk0.top()); stk0.pop(); //tolwer()函数直接实现大写转小写
        char ch1 = tolower(stk1.top()); stk1.pop();
        if(ch0 != ch1) return false;
    }
    return true;
}