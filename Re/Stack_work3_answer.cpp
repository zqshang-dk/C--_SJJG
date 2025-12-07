/*
---------------题目描述开始---------------
题目：
利用栈将一个中缀表达式转换为后缀表达式，并计算该后缀表达式的值
实现函数void PostExp(const string& expstr, string& pexpstr)
将字符串expstr中的中缀表达式，转换为后缀表达式，放入字符串pexpstr中


本题可以使用STL中的stack容器类

输入格式：
中缀表达式字符序列

输出格式
后缀表达式字符序列
数据1

---------------题目描述结束---------------
*/

//在下方写出程序应该包含的头文件


//#include _________
//...
#include <iostream>
#include<stack>
#include<string>
using namespace std;


void PostExp(const string& expstr, string& pexpstr) {
    stack<char> opor;
    char ch;
    int i = 0;

    while (i < expstr.length()) {
        ch = expstr[i];
        
        if (ch == '(') {
            opor.push(ch);
        }
        else if (ch == ')') {
            while (!opor.empty() && opor.top() != '(') {
                pexpstr += opor.top();
                opor.pop();
            }
            opor.pop(); // 弹出左括号
        }
        else if (ch == '+' || ch == '-') {
            while (!opor.empty() && opor.top() != '(') {
                pexpstr += opor.top();
                opor.pop();
            }
            opor.push(ch);
        }
        else if (ch == '*' || ch == '/') {
            while (!opor.empty() && opor.top() != '(' && 
                   (opor.top() == '*' || opor.top() == '/')) {
                pexpstr += opor.top();
                opor.pop();
            }
            opor.push(ch);
        }
        else { 
            pexpstr += ch;
        }
        i++;
    }
    
    while (!opor.empty()) {
        pexpstr += opor.top();
        opor.pop();
    }
}


int calc(const string& pexpstr) {
    stack<int> opand;
    int i = 0;
    int a, b;

    while (i < pexpstr.length()) {
        char ch = pexpstr[i];
        
        if (ch == '+') {
            a = opand.top(); opand.pop();
            b = opand.top(); opand.pop();
            opand.push(b + a);
        }
        else if (ch == '-') {
            a = opand.top(); opand.pop();
            b = opand.top(); opand.pop();
            opand.push(b - a);
        }
        else if (ch == '*') {
            a = opand.top(); opand.pop();
            b = opand.top(); opand.pop();
            opand.push(b * a);
        }
        else if (ch == '/') {
            a = opand.top(); opand.pop();
            b = opand.top(); opand.pop();
            opand.push(b / a);
        }
        else { 
            opand.push(ch - '0');
        }
        i++;
    }
    return opand.top();
}


int main() {

    //--------------不要修改main()函数中的内容----------------------

    string exp, pexp;

    cin >> exp;

    PostExp(exp, pexp);

    cout << pexp << endl;

    cout << calc(pexp);

    //-------------------------------------------------------------
    return 0;
}



