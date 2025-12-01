#include<string>
using namespace std;
bool isPalindrome(string s){
    int n = s.size();
    if(n <= 1) return true;
    int left = 0, right = n-1;
    while (left < right){
        if (s[left] != s[right])
            return false;
        ++left; --right;
    }
    return true;
}