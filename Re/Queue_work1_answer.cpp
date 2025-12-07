
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


//#include _________
//...
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
class linkedQueue
{
public:
   T *data;
   int front;
   int rear;
   int capacity;
public:
   //构造函数
   linkedQueue(){
      front = -1;
      rear = -1;
      capacity = 100; //默认容量
      data = new T[capacity];
   }

   //带参数的构造函数
   linkedQueue(int cap){
      front = -1;
      rear = -1;
      capacity = cap;
      data = new T[capacity];
   }

   //析构函数
   ~linkedQueue(){
      delete[] data;
   }

   //入队列
   void push(T value){
      if(rear==capacity-1){
         return;
      }
      if(empty()){
         rear=0;
         front=0;
      }
      data[rear++] = value;
   }

   //出队列
   void pop(){
      if(empty()){
         return;
      }
      if(front==rear){
         front = -1;
         rear = -1;
      }
      else
         front += 1;
   }

   //判断是否为空
   bool empty(){
      if(rear== front){
         return true;
      }
      
      else{
         return false;
      }
   }

   //获取队首元素
   T getfront(){
      if (front==rear){
         return T();
      }
      if(front!=-1){
         return data[front];
      }
   }

   //输出整个队列
   void displayQueue(){
      if(empty())return;
      for (int i = front; i < rear;i++){
         cout << data[i] << " ";
      }
      cout<<endl;
   }

   //删除整个队列
   void clearQueue(){
      front = -1;
      rear = -1;
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
       cout<< lqueue.getfront() <<" ";
       lqueue.pop();
    }

    cout<<endl;

   //测试 clearQueue()

    lqueue.clearQueue();
    if(lqueue.empty())
      cout<<"empty";
    
    return 0;
}










