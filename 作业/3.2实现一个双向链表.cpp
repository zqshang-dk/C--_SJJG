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
public:
    //定义结点类型
    //template<typename T>  不需要重新模板化，因为node本身就在doublyLinkedList里面
    struct node{
        T data;
        node *next;
        node *prior;
        node():data(T()), next(nullptr), prior(nullptr) {}   // 必须有！这点确实不知道应该怎么理解了，先记住这里吧！！！！
        //注意，这里node中也要新增构造函数！！！
        node(T val):data(val),next(nullptr),prior(nullptr){}
    };
    node *head;
    node *tail;
    //T *arr;要的是链表而不是数组，所以根本不应该出现arr
    
    
    
    //构造函数
    //doublyLinkedList():phead(nullptr),next(nullptr),prior(nullptr){}
    //phead 是指向 node 的指针，但是你初始化了 next/prior，而你的类里面根本没有 next 或 prior 成员
    //正确的结构应该是：
    //head->next指向第一个结点
    //tail->prior指向最后一个节点
    //head,tail本身不存储任何数据
    doublyLinkedList(){
        head = new node();
        tail = new node();
        head->prior = nullptr;
        tail->next = nullptr;
        head->next = tail;
        tail->prior = head;
    }
    
    //析构函数
    ~doublyLinkedList(){
        //delete[] head;
        clearList();
        delete head;
        delete tail;
    }

    // a. find() 
    // 判断链表中是否有值为value的结点, 
    // 如没有，返回nullptr，
    // 如有，返回数据对象为value的结点的指针
    //T* find(T value)  错误，返回的应该是节点类型，而不是T类型，这里格外需要注意！！！
    node* find(T value)   //这里是因为题目上说是值为x的结点
    {
        // for (int i = 0;i<n;i++){
        //     if(a[i]==value){
        //         return *value;
        //     }
        //     else
        //         return nullptr;
        // }
        //完全错误，这是数组的写法，而现在我们考察的是链表结构
        node *p = head->next;
        while(p!=tail){
            if(p->data==value){
                return p;
            }
            p = p->next;
        }
        return nullptr;
    }

    // b. insertValue() 
    // 插入值为value的结点到链表中，作为值为x的结点的后继结点（设链表中的值不重复），
    // 如果链表为空，则插入到头结点后。插入成功返回1，
    // 没找到值为x的结点导致插入失败，返回0。
    // 这里通过调用find()找到插入点
    int insertValue(T x ,T value){
        //还有空结点的情况没有考虑！！！！
        if(empty()){
            node *p = new node(value);
            p->next = tail;
            p->prior=head;
            head->next = p;
            tail->prior = p;
            return 1;
        }
        
        
        //这里我们需要先建一个结点
        node *px = find(x);
        if(px!=nullptr){
            //双链表的插入应该还是没有完全弄懂啊我看！！！！！
            // value->next = x->next;
            // if(x->next!=nullptr){
            //     x->next->prior = value;
            // }
            // x = value->prior;
            // x->next = value;
            node *p = new node(value);

            //p->data = ;    //因为现在我们只知道一个结点的值为value，但我们并不知道这个节点是什么呀，所以这里需要先手动创建一个结点，存放value值！！
            
            //建议直接把这个顺序给我记死了！！！！！
            p->next = px->next;
            p->prior = px;
            px->next->prior = p;
            px->next = p;


            return 1;
        }
        else{
            return 0;
        }
    }

    // c. deleteValue()   
    // 删除链表中值为value的结点
    // 这里通过调用find()找到删除点
    void deleteValue(T value){
        // if(find(value)!=nullptr){
        //     value = value->next->data;
        //     value->next = value->next->next;
        //     value->next->prior = value;
        // }
        //根据insert函数里面修改的部分，先自己写一下
        node *p = find(value);
        if(p==nullptr){
            return;
        }
        p->prior->next = p->next;
        p->next->prior = p->prior;
        delete p;
    }

    // d. empty()
    // 判断链表是否为空
    bool empty(){
        if(head->next==tail&& tail->prior==head){
            return true;
        }
        else
            return false;
    }

    // e. displayList()
    // 输出整个链表
    void displayList(){
        // cout << head.data << " ";
        // head = head->next;

        //这里还是不能再用数组的用法来求解了
        node *p = head->next;
        while(p!=tail){
            cout << p->data << " ";
            p = p->next;
        }
        cout << endl;
    }

    // f. clearList()
    // 删除整个链表, 只保留头结点和尾节点
    void clearList(){
        node *p = head->next;

        while(p!=tail){
            node *tmp = p;
            p = p->next;
            delete tmp;
        }

        head->next = tail;
        tail->prior = head;
    }
};
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










