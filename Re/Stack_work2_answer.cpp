/*
---------------题目描述开始---------------
题目：
利用一个栈计算并输出Fibonacci数列的前n项。
Fibonacci数列：F[n] = F[n-1] + F[n-2](n>=2, F[0]=0, F[1]=1

输入格式：
数据n

输出格式
数据1 数据2 ... 数据n

---------------题目描述结束---------------
*/

//在下方写出程序应该包含的头文件


//#include _________
//...
#include<iostream>
#include<stack>
using namespace std;


int main() {

    //--------------在本行下方编程程序代码，不要修改main()函数中本行及以上的内容----------------------
    int n;
    //cout << "请输入Fibonacci的项数：" << endl;
    cin >> n;

    stack<int> fibstack;
    if (n == 0) {
        return 0;
    }

    if (n >= 1)fibstack.push(0);  //F(0)=0
    if (n >= 2)fibstack.push(1);  //F(1)=1

    for (int i = 2; i < n; ++i) {
        int a = fibstack.top();
        fibstack.pop();
        int b = fibstack.top();
        fibstack.push(a);
        fibstack.push(a + b);
    }

    stack<int> storestack;
    //顺序是反的
    while (!fibstack.empty()) {
        storestack.push(fibstack.top());
        fibstack.pop();
    }
    //cout << "前n项为：" << endl;
    while (!storestack.empty()) {
        cout << storestack.top() << " ";
        storestack.pop();
    }

    cout << endl;




        //--------------代码编辑结束，不要修改本行及以下的内容----------------------
    return 0;
}




