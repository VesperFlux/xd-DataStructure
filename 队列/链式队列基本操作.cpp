//

//链式队列的基本操作

//定义结点
typedef struct QNode {
    int data;
    struct QNode* next; 
}QNode, *QueuePtr;
//定义链式队列
typedef struct {
    QNode* front;
    QNode* rear;
}LinkQueue;

//初始化(带头结点)
bool InitQueue(LinkQueue &Q){
    Q.front = Q.rear = new QNode;
    return true;
}
//入队(带头结点) 从队尾
bool EnQueue1(LinkQueue &Q, int e){
    QNode* s = new QNode;                   //创建一个新结点
    s->data = e;                            //新结点数据域设为e
    s->next = nullptr;                      //新结点的next指针设为NULL
    Q.rear->next = s;                       //连接原先的尾结点与新结点
    Q.rear = s;                             //修改尾指针为s
    return true;
}
//出队(带头结点) 从队头
bool DeQueue1(LinkQueue& Q ,int& e){
    QNode* s = Q.front->next;               //第一个正式结点记为s
    e = s->data;                            //提前记录即将出队的结点元素
    if (s->next == nullptr)                 //如果出队前只有一个元素
        Q.rear = Q.front;                   //则修改尾指针与头指针相同(都指向头结点)
    Q.front->next = s->next;                //修改头结点的下一个结点为(原先的)第二个结点
    delete s;                               //释放出队结点的内存
    return true;
}
//入队(不带头结点) 从队尾
bool EnQueue2(LinkQueue &Q, int e){
    QNode* s = new QNode;                   //创建新结点s
    s->data = e;                            //新结点的数据域设为e
    s->next = nullptr;                      //新结点的next指针设为NULL
    if (Q.front == nullptr){                //若队列为空     
        Q.front = s;           
        Q.rear = s;                         //前指针和后指针都指向s
    }
    Q.rear->next = s;                       //将原队尾结点连到新结点上
    Q.rear = s;                             //修改队尾指针指向s
    return true;
}
//出队（不带头结点）
bool DeQueue(LinkQueue &Q, int &e){
    if (Q.front == nullptr)                 
        return false;                       //若队为空 返回错误
    e = Q.front->data;                      //先把队头元素传出给e
    QNode* s = Q.front;                     //令头结点为s
    if (s->next == nullptr)                 //若只有一个结点
        Q.front = Q.rear = nullptr;         //则出队后前指针后指针均设为NULL
    Q.front = s->next;                      //修改前指针指向第二个结点
    delete s;                               //释放第一个结点s
    return true;
}