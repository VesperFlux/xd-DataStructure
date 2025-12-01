#include<iostream>
using namespace std;

//定长顺序存储表示
const int MAX = 100;  //串的最大长度
typedef struct {
    int length;       //串的实际长度
    char ch[MAX];     //每个分量存储一个字符
}SString;

//堆内存存储表示
typedef struct
{
    char *ch;         //按串长分配存储区 ch指向串的基地址
    int length;       //串的长度
}HString;
