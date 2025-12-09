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
#include<iostream>
#include<stack>
using namespace std;

int main() {

    //--------------在本行下方编程程序代码，不要修改main()函数中本行及以上的内容----------------------
    stack<int> st;
    int n;
    cin >> n;
    
    if (n >= 1){
        st.push(0);
    }
    if(n>=2){
        st.push(1);
    }
    for (int i = 2; i < n;i++){
        int a = st.top();
        st.pop();
        int b = st.top();
        st.push(a);
        st.push(a + b);
    }
        
    
    int *data = new int[n];
    for (int i = n-1; i>=0 ;i--){
        data[i] = st.top();
        st.pop();
    }
    for (int i = 0; i < n;i++){
        cout << data[i] << " ";
    }
    cout << endl;
    delete[] data;

    //--------------代码编辑结束，不要修改本行及以下的内容----------------------
    return 0;
}



