#include <string>
#include <cstring>

const int MAX = 100;
// 利用线性表实现串的存储结构
typedef struct
{
    int length;
    char ch[MAX];
} SString;

// KMP模式匹配算法
int Index_KMP(SString &S, SString &T, int next[])
{
    int i = 1; // i 主串指针
    int j = 1; // j 模式串指针
    while (i <= S.length && j <= T.length)
    {
        if (S.ch[i] == T.ch[j] || j == 0)
        {
            ++i;
            ++j; // 继续比较后续字符
        }
        else
            j = next[j]; // 模式串向右移动
    } // 匹配失败时 主串指针i不回溯
    if (j > T.length)
        return i - T.length; // 匹配成功
    else
        return 0;
}
//求next数组
void get_next(SString T, int next[])
{
    next[1] = 0;
    int i=1, j=0;
    while (i < T.length)
    {
        if (j==0 || T.ch[i]==T.ch[j])
        {
            ++i; ++j;
            next[i] = j;
        }
        else
            j = next[j];
    }
}
// 求nextval数组
void get_nextval(SString T, int nextval[], int next[])
{
    nextval[1] = 0;
    for (int j = 2; j <= T.length; ++j)
    {
        if (T.ch[j] == T.ch[next[j]])
        {
            nextval[j] = nextval[next[j]];
        }
        else
            nextval[j] = next[j];
    }
}
// 朴素模式匹配算法
int Index(SString S, SString T)
{
    int i = 1, j = 1;
    while (i <= S.length && j <= T.length)
    {
        if (S.ch[i] == T.ch[j])
        {
            ++i;
            ++j; // 继续比较后续字符
        }
        else
        {
            i = i - j + 2;
            j = 1; // 指针回溯 重新开始匹配
        } // 匹配失败时 主串指针i疯狂回溯
    }
    if (j > T.length)
        return i - T.length;
    else
        return 0;
}