//
//  main.c
//  QuickSort
//
//  Created by 唐薪薪 on 2025/10/24.
//

#include <stdlib.h>
#include <stdio.h>

//快速排序算法

//划分
//用第一个元素作为枢轴（基准），把待排序列划分为左右两个部分，左边的比枢轴小，右边的比枢轴大

int Partition(int A[],int low,int high){
    int pivot=A[low];//把第一个元素作为基准(pivot)
//用low和high从两边向中间扫描，确定基准的最终位置
    while (low<high) {
        while (low<high&&A[high]>=pivot){
            high--;
        }//用high寻找比基准小但是在右边的元素
        A[low]=A[high];//把这个元素放在左端
        while (low<high&&A[low]<=pivot) {
            low++;
        }//用low寻找比基准大但是在左边的元素
        A[high]=A[low];//把这个元素放在右端
    }
    A[low]=pivot;//把基准元素放回最终位置上
    return low;//返回基准元素的下标
}

//递归，分而治之的思想
void QuickSort(int *A,int low,int high){
    if (low<high) {//跳出划分的条件
        int pivotpos=Partition(A, low, high);//进行一次划分，得到第一个基准的位置，用于接下来的递归
        QuickSort(A, low, pivotpos-1);//划分左子列
        QuickSort(A, pivotpos+1, high);//划分右子列
    }
}

int main(int argc, const char * argv[]) {
    // insert code here...
    int A[10];
    for (int i=0; i<10;i++ ) {
        scanf("%d",&A[i]);
    }
    QuickSort(A, 0, 9);
    for (int i=0; i<10; i++) {
        printf("%d ",A[i]);
    }
    printf("\n");
    printf("Hello, World!\n");
    return EXIT_SUCCESS;
}

