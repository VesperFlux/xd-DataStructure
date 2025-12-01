#include <stack>
using namespace std;
bool isPalindrome(string s){
    stack<char> stk0;
    stack<char> stk1;
    int n = 0;
    for (char ch : s){
        if (ch>='0'&&ch<='9' || ch>='a'&&ch<='z' || ch>='A'&&ch<='Z'){
            stk0.push(ch);
            n++;
        }
    }
    for (int i = 0; i < n / 2; i++){
        stk1.push(stk0.top());
        stk0.pop();
    }
    if (n % 2 == 1) stk0.pop();
    for (int i = 0; i < n / 2; i++){
        char ch0 = stk0.top(); stk0.pop();
        char ch1 = stk1.top(); stk1.pop();
        if (!(ch0==ch1 || ch0>='A'&&ch0<='Z'&&ch1==ch0+32 || ch0>='a'&&ch0<='z'&&ch1==ch0-32))
            return false;
    }
    return true;
}
