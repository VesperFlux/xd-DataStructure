#include<string>
#include<stack>
using namespace std;
class Solution {
public:
    bool isPalindrome(string s) {
        stack<char> stk;
        string validS;
        for(char ch : s){
            if (isalnum(ch))
                validS += tolower(ch);
        }
        int n = validS.size();
        for(int i=0; i<n/2; ++i){
            stk.push(validS[i]);
        }
        for(int i=(n+1)/2; i<n; i++){
            if(validS[i] != stk.top())
                return false;
            stk.pop();
        }
        return true;
    }
};