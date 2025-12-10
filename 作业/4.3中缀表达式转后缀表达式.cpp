/*---------------题目描述开始---------------
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

#include<iostream>
#include<stack>
#include<string>
using namespace std;

void PostExp(const string& expstr, string& pexpstr){
    //在中缀表达式转为后缀表达式这个函数中，栈是用来存储运算符的！！
    stack<char> st;
    char ch;
    for (int i = 0; i < expstr.length();i++){
        ch = expstr[i];

        if(ch=='('){
            st.push(ch);
        }

        else if(ch==')'){          //这个地方非常重要！！！一定是else if而不能写if，写if算出来的结果是错的！！！！！
            while(!st.empty()&& st.top()!='('){
                pexpstr += st.top();
                st.pop();
            }
            st.pop();
        }

        else if (ch == '*' || ch == '/'){
            //st.push(ch);      这是我原来写的，感觉过于简单了，这里重新写一下！
            while(!st.empty() && (st.top()=='*'||st.top()=='/')){
                pexpstr += st.top();
                st.pop();
            }
            st.push(ch);
        }

        else if(ch=='+'||ch=='-'){
            while(!st.empty()&&(st.top()=='*'||st.top()=='/'||st.top()=='+'||st.top()=='-')){
                pexpstr += st.top();
                st.pop();
            }
            st.push(ch);
        }
        else{
            pexpstr += ch;
        }
    }
    while(!st.empty()){
        pexpstr += st.top();
        st.pop();
    }
}


int calc(const string& pexpstr){
    //后缀表达式的计算中，栈只用来暂时存储数字！！！！！
    stack<int> cal;
    char ch;
    for (int i = 0; i < pexpstr.length();i++){
        ch = pexpstr[i];
        if(isdigit(ch)){     //isdigit可以判断是否为数字
            cal.push(ch-'0');    //此时数字还是一个字符形式，要改为int型，所以需要减去0的ASCII码值！！！！！！
        }
        else if(ch=='+'){
            int a = cal.top();
            cal.pop();
            int b = cal.top();
            cal.pop();
            cal.push(b + a);
        }

        else if(ch=='-'){
            int a = cal.top();
            cal.pop();
            int b = cal.top();
            cal.pop();
            cal.push(b - a);
        }

        else if(ch=='*'){
            int a = cal.top();
            cal.pop();
            int b = cal.top();
            cal.pop();
            cal.push(b * a);
        }

        else if(ch=='/'){
            int a = cal.top();
            cal.pop();
            int b = cal.top();
            cal.pop();
            cal.push(b / a);
        }
    }
    return cal.top();
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



