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
    int f;
    int r;
    int n;

    //构造函数
    linkedQueue(int cap=10){
        f = -1;
        r = -1;
        n = cap;
        data = new T [n];
    }
    //析构函数
    ~linkedQueue(){
        delete[] data;
    }

    //入队列
    void push(T element){
        if(r<n-1){
            r++;
            data[r] = element;
        }
    }

    //出队列
    void pop(){
        if(!empty()){
            f++;
        }
    }

    //查看队首元素
    T front(){
        if(!empty()){
            return data[f+1];
        }
    }

    //判断是否为空
    bool empty(){
        return f == r;
    }

    //整个队列
    void displayQueue(){
        if(empty()){
            return;
        }
        else{
            for (int i = f+1; i <= r;i++){
                cout << data[i] << " ";
            }
        }
        cout << endl;
    }

    //清除整个队列
    void clearQueue(){
        f = -1;
        r = -1;
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










