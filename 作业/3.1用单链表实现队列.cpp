/*
---------------题目描述开始---------------
题目：
实现一个链表队列类 linkedQueue 
实现对队列操作的方法，包括：
a. push() 
   入队列 
b. pop()
   出队列 
c. front()   
   获取队首元素
d. empty()
   判断队列是否为空
e. clearqueue()
   删除整个队列
f. displayQueue() 
   整个队列
输入格式：
数据1 数据2 数据3 ...
输出格式
数据1 数据2 数据3 ...
---------------题目描述结束---------------
*/
//在下方写出程序应该包含的头文件
/*
一个完全正确的版本
#include<iostream>
using namespace std;

template<typename T>
class linkedQueue {
private:
    struct Node {
        T data;
        Node* next;
        Node(T d) : data(d), next(nullptr) {}
    };

    Node* frontPtr;  // 队首
    Node* rearPtr;   // 队尾

public:

    linkedQueue() : frontPtr(nullptr), rearPtr(nullptr) {}

    ~linkedQueue() {
        clearQueue();
    }

    // 入队
    void push(T x) {
        Node* node = new Node(x);
        if (rearPtr == nullptr) {
            frontPtr = rearPtr = node;
        } else {
            rearPtr->next = node;
            rearPtr = node;
        }
    }

    // 出队
    void pop() {
        if (empty()) return;
        Node* p = frontPtr;
        frontPtr = frontPtr->next;
        delete p;
        if (frontPtr == nullptr)
            rearPtr = nullptr;
    }

    // 队首元素
    T front() {
        if (!empty())
            return frontPtr->data;
        return T();  // 返回默认值
    }

    // 判断是否为空
    bool empty() {
        return frontPtr == nullptr;
    }

    // 输出整个队列
    void displayQueue() {
        Node* p = frontPtr;
        while (p) {
            cout << p->data << " ";
            p = p->next;
        }
        cout << endl;
    }

    // 删除整个队列
    void clearQueue() {
        while (!empty()) {
            pop();
        }
    }
};

*/

#include<iostream>
using namespace std;

//---------------定义 linkedQueue 模板类---------------
/*
template<...>
class linkedQueue
{
};
*/
template<typename T>
class linkedQueue{
public:
    T *data;
    int f;   //front 指的是队首元素的索引
    int t;   //tail 指的是队尾元素的索引
    int capacity;   //容量

    //构造函数
    linkedQueue() : f(-1), t(-1),capacity(100){
        data = new T[capacity];
    }
    //含参数的重载构造函数
    linkedQueue(int cap):f(-1),t(-1){
        capaciyu = cap;
        data = new T[capacity];
    }

    //析构函数
    ~linkedQueue(){
        delete[] data;
    }

    //入队列
    void push(T element){
        if(f<t){
            data[++t] = element;
        }
    }

    //出队列
    void pop(){
        if(f<t){
            f++;
        }
    }

    //获取队首元素
    T front (){
        if(f<t){
            return data[f];
        }
    }

    //判断队列是否为空
    bool empty(){
        if(f==t){
            return true;
        }

        else{
            return false;
        }
    }

    //输出整个队列
    void displayQueue(){
        if(f<t)
        {
            for (int i = f; i < t;i++){
                cout << data[i] << " ";
            }
            cout << endl;
        }
    }

    //删除整个队列
    void clearQueue(){
        f = 0;
        t = 0;
        delete[] data;
    }
};
//定义linkedQueue类的成员函数
/*
linkedQueue() { }
~linkedQueue() { }

push() { }
pop() { }
front() { }
empty() { }
displayQueue() { }
clearQueue() { }

......//根据需要编写其它的成员函数

*/
//---------------定义 linkedQueue 模板类 结束---------------



 //--------------不要修改main()函数中的内容----------------------
 //--------------不要修改main()函数中的内容----------------------
 //--------------不要修改main()函数中的内容----------------------

int main() {

    //定义一个int类型的 linkedQueue 对象 lqueue
    linkedQueue<int> lqueue;
    
    int n, x, val;
    cin >> n;
      
    //通过insertValue()建立链表

    for (int i = 0; i < n; ++i) {
        cin >> x;		
        lqueue.push(x);
    }

    lqueue.displayQueue();
    //测试pop()
    lqueue.pop();

    //测试empty()
    if(!lqueue.empty())
      cout<<"not empty ";

   //测试front()
    while(!lqueue.empty()){
       cout<< lqueue.front() <<" ";
       lqueue.pop();
    }

    cout<<endl;

   //测试 clearQueue()

    lqueue.clearQueue();
    if(lqueue.empty())
      cout<<"empty";
    
    return 0;
}










