#include <iostream>
#include <cstring>
using namespace std;

// 步骤1：构建1-based的next数组（next[1]=0，贴合你的习惯）
void buildNext_1based(const char* pattern, int* next, int patLen) {
    // 模式串实际字符：pattern[0]~pattern[patLen-1]（C++数组0-based）
    // next数组：next[1]~next[patLen]（1-based，共patLen个位置）
    next[1] = 0; // 第1位固定为0（无前后缀）
    int i = 1;   // 模式串指针（1-based）
    int j = 0;   // 前缀匹配指针

    while (i < patLen) {
        if (j == 0 || pattern[i-1] == pattern[j-1]) { // 映射到0-based字符数组
            i++;
            j++;
            // 优化版：避免无效回溯（可选，基础版直接next[i]=j）
            next[i] = (pattern[i-1] == pattern[j-1]) ? next[j] : j;
        } else {
            j = next[j]; // 回溯到上一个匹配的前缀位置
        }
    }
}

// 步骤2：KMP统计匹配次数（适配1-based next数组）
int kmpCount_1based(const char* text, const char* pattern, bool allowOverlap = false) {
    int textLen = strlen(text);
    int patLen = strlen(pattern);
    int count = 0;

    // 边界处理
    if (patLen == 0 || patLen > textLen) return 0;

    // 构建1-based next数组（长度patLen+1，用next[1]~next[patLen]）
    int* next = new int[patLen + 1];
    buildNext_1based(pattern, next, patLen);

    // KMP核心匹配（主串0-based，模式串逻辑1-based）
    int i = 0; // 主串指针（0-based，永不回溯）
    int j = 1; // 模式串指针（1-based，初始指向第1位）
    while (i < textLen) {
        if (j == 0 || text[i] == pattern[j-1]) { // j=0表示需重新匹配
            i++;
            j++;
        } else {
            j = next[j]; // 匹配失败，回溯到next[j]
        }

        // 找到一次完整匹配（j超出模式串长度）
        if (j > patLen) {
            count++;
            
            if (allowOverlap) {
                // 重叠匹配：回溯到next[j]（即next[patLen+1]，等价于next[patLen]）
                j = next[j];
            } else {
                // 非重叠匹配：重置模式串指针，主串跳过已匹配部分
                j = 1;
                i = i - patLen + 1;
            }
        }
    }

    delete[] next;
    return count;
}

// 测试示例（和之前一致，验证逻辑正确性）
int main() {
    const char* text1 = "ABABABA";
    const char* pattern1 = "ABA";
    cout << "非重叠匹配次数：" << kmpCount_1based(text1, pattern1, false) << endl; // 输出2
    cout << "重叠匹配次数：" << kmpCount_1based(text1, pattern1, true) << endl;   // 输出3

    const char* text2 = "AAAAAABAAAAAABAAAAAA";
    const char* pattern2 = "AAAAAB";
    cout << "长串非重叠匹配次数：" << kmpCount_1based(text2, pattern2) << endl; // 输出2

    return 0;
}