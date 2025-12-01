//
//
//
// 顺序队列
//
#define MaxSize 10

//顺序队列的定义
typedef struct{
    int data[MaxSize];  // 静态数组存放队列元素
    int front,rear;     // 头指针指向队头元素 尾指针指向队尾元素的下一个位置
}SqQueue;

//顺序队列的初始化
bool InitQueue(SqQueue &Q){
    Q.front = Q.rear = 0;
    return true;
}
//求队列长度
int QueueLength(SqQueue &Q){
    return (Q.rear - Q.front + MaxSize) % MaxSize;
}
//入队
bool EnQueue(int e, SqQueue &Q){
    //队满(留一个元素用于区分队空和队满)
    if ((Q.rear + 1) % MaxSize == Q.front)
        return false;
    Q.data[Q.rear] = e;
    Q.rear = (Q.rear + 1)% MaxSize;
    return true;
}
//出队
bool DeQueue(SqQueue &Q, int &e){
    //队空
    if (Q.front == Q.rear)
        return false;
    e = Q.data[Q.front];
    Q.front = (Q.front + 1) % MaxSize;
}
//取队头元素
int GetHead(SqQueue Q){
    if(Q.front != Q.rear)
        return Q.data[Q.front];
}