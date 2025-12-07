/*
---------------题目描述开始---------------
题目：
定义一个 doubleEendedStack 模板类。
数据成员有stack对象的内存区指针，内存区容量，两个迎面增长栈的栈顶位置变量。
成员函数有
1. 构造函数: 为栈对象分配内存区，并初始化各个成员变量。
2. 析构函数
3. void push1(...)
   void push2(...), 分别对两个栈进行压栈操作
4. void pop1()
   void pop2(), 分别对两个栈进行出栈操作
5. _Type top1()
   _Type top2(), 分别读取两个栈的栈顶元素
6. bool empty1()
   bool empty1(), 分别判断两个栈是否为空，为空返回true，非空返回false
7. bool erase(int pos) 将顺序表中index为pos的位置上的数据对象删除。


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

//---------------定义 Vector 模板类---------------
/*
template<...>
class doubleEendedStack
{
    //数据成员有
    //stack对象的内存区指针，
    //内存区容量，
    //两个迎面增长栈的栈顶位置变量。

};
*/
template<typename T>
class doubleEendedStack{
    
}
//定义Vector类的成员函数
/*
doubleEendedStack() { }
~doubleEendedStack() { }

void push1(...){ }   //如果栈已满，则输出"Stack1 Overflow\n"
void push2(...){ }   //如果栈已满，则输出"Stack2 Overflow\n"

void pop1() { }
void pop2() { }

_Type top1() { }
_Type top2() { }

bool empty1() { }
bool empty1() { }

*/

//---------------定义 Vector 模板类定义 结束---------------

int main() {
    int n, m;
    cin >> n;  //栈1的设计容量
    cin >> m;  //栈2的设计容量
    //--------------在本行下方编程程序代码，不要修改main()函数中本行及以上的内容----------------------

    //1. 定义一个能同时容下栈1和栈2的迎面增长栈对象


    //定义一个float类型的Vector对象 fvb    
    int tmp;
    for (int i = 0; i < n; ++i) {
        //使用push1函数向栈1压栈   
        //(每次从键盘输入一个数到tmp, 然后用push1方法压栈)
    }
    	
	for (int i = 0; i < m; ++i){
        //使用push2函数向栈2压栈   
        //(每次从键盘输入一个数到tmp, 然后用push2方法压栈)
    }

    //继续输入一个数到tmp，然后使用push1和push2方法对两个栈进行压栈操作


    
    for (int i = 0; i <=n; ++i){
        //对栈1中的对象逐个输出，并出栈，如果执行出栈操作时发现栈已空，则输出"\nStack1 is empty\n"
    }
    
    for (int i = 0; i <=m; ++i){
        //对栈2中的对象逐个输出，并出栈，如果执行出栈操作时发现栈已空，则输出"\nStack2 is empty\n"
    }

    //--------------代码编辑结束，不要修改本行及以下的内容----------------------
    return 0;
}
*/


