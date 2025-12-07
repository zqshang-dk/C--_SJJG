
/*
---------------题目描述开始---------------
题目：
实现一个双向链表类 doublyLinkedList ，
链表有头指针指向头结点，有尾指针指向尾结点，
头结点和尾结点没有数据负载，作用仅为指向后继结点和前驱结点。

实现对链表操作的方法，包括：
a. find() 
   判断链表中是否有值为value的结点, 
   如没有，返回nullptr，
   如有，返回数据对象为value的结点的指针

b. insertValue() 
   插入值为value的结点到链表中，作为值为x的结点的后继结点（设链表中的值不重复），
   如果链表为空，则插入到头结点后。插入成功返回1，
   没找到值为x的结点导致插入失败，返回0。
   这里通过调用find()找到插入点

c. deleteValue()   
   删除链表中值为value的结点
   这里通过调用find()找到删除点
   
d. empty()
   判断链表是否为空

e. displayList()
   输出整个链表

f. clearList()
   删除整个链表, 只保留头结点和尾节点。

输入格式：
数据1 数据2 数据3 ...

输出格式
数据1 数据2 数据3 ...
数据1 数据2 数据3 ...

(displayList()函数每次输出链表后，以回车结束)

---------------题目描述结束---------------
*/

//在下方写出程序应该包含的头文件


//#include _________
//...
#include<iostream>
using namespace std;

//---------------定义 doublyLinkedList 模板类---------------
/*
template<...>
class doublyLinkedList
{
    //定义节点类型
    struct node{};
};
*/
template<typename T>
class doublyLinkedList{
    struct node{
        T data;
        node* next;     //指向后继结点的指针
        node* prior;    //指向前驱结点的指针

        node():next(nullptr),prior(nullptr){}
        node(T d):data(d),next(nullptr),prior(nullptr){}
    };
    node* dhead;        //双链表头结点
    node* dtail;        //双链表尾结点

    //构造函数
    doublyLinkedList(){
        dhead=new node();
        dtail=new node();
        dhead->next=dtail;
        dtail->prior=dhead;
    }

    //析构函数
    ~doublyLinkedList{
        clearList();
        delete dhead;
        delete dtail;
        delete []data;
    }

    // find() 
    // 判断链表中是否有值为value的结点, 
    // 如没有，返回nullptr，
    // 如有，返回数据对象为value的结点的指针
    T find(T value){
        node*p=dhead->next;
        while(p!=dtail){
            if(p->data==value){
                return p;
            }
            else if(p->data!=value){
                p=p->next;
            }
        }
        return nullptr;
    }

    //insertValue() 
    //插入值为value的结点到链表中，作为值为x的结点的后继结点（设链表中的值不重复），
    //如果链表为空，则插入到头结点后。插入成功返回1，
    //没找到值为x的结点导致插入失败，返回0。
    //这里通过调用find()找到插入点
    int insertValue(T x,T value){
        if(empty()){
            
        }
    }



}
//定义doublyLinkedList类的成员函数
/*
doublyLinkedList() { }
~doublyLinkedList() { }

insertValue() { }
find() { }
deleteValue() { }
empty() { }
displayList() { }
clearList() { }

......//根据需要编写其它的成员函数

*/
//---------------定义 doublyLinkedList 模板类 结束---------------



 //--------------不要修改main()函数中的内容----------------------
 //--------------不要修改main()函数中的内容----------------------
 //--------------不要修改main()函数中的内容----------------------

int main() {

    //定义一个int类型的 doublyLinkedList 对象 DLlist
    doublyLinkedList<int> DLlist;
    
    int n, x, val;
    cin >> n;
    
    //测试insertValue
    cin >> x;
    cin >> val;
    if (DLlist.insertValue(x, val))
        DLlist.displayList();
    
    //通过insertValue()建立链表
    int data;
    for (int i = 0; i < n; ++i) {
        cin >> data;		
        DLlist.insertValue(val, data);
        val = data;
    }
    //测试displayList()
    DLlist.displayList();

    //测试deleteValue()
    cin >> val;
    DLlist.deleteValue(val);
    DLlist.displayList();

    cin >> val;
    DLlist.deleteValue(val);
    DLlist.displayList();

    //测试clearList()
    DLlist.clearList();
    //测试empty()
    if(DLlist.empty())
        DLlist.displayList();
    
    return 0;
}










