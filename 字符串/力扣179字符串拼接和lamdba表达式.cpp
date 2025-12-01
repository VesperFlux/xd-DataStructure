#include<vector>
using namespace std;
class Solution {
public:
    string largestNumber(vector<int>& nums) {
        // 1. 自定义排序：按拼接后的字符串降序排列
        sort(nums.begin(), nums.end(), [](const int &x, const int &y) {
            // 拼接x+y和y+x，比较大小
            return to_string(x) + to_string(y) > to_string(y) + to_string(x);
        });

        // 2. 处理全0情况：排序后第一个元素为0，说明所有数都是0
        if (nums[0] == 0) {
            return "0";
        }

        // 3. 拼接所有数字为最终字符串
        string ret;
        for (int &x : nums) {
            ret += to_string(x);
        }
        return ret;
    }
};