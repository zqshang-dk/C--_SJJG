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
#include<iostream>
#include<string>
#include<stack>
using namespace std;

//中缀表达式转化为后缀表达式
string PostExp(string &exp){
    stack<char> opor;//用于存储运算符

    char ch;//当前读取到的字符
    string pexp;

    for (int i = 0; i < exp.length();i++){
        ch = exp[i];  //重点，这里一开始没有注意！！！！！！！

        if(ch>='0' && ch<='9'){
            pexp += ch;
        }
        else if(ch=='('){
            opor.push(ch);
        }

        else if(ch==')'){
            //这里要先检查栈是否为空，如果是空，opor.top()会导致运行时错误
            while(!opor.empty()&&opor.top()!='(' ){  //添加空栈检查
                pexp += opor.top();
                opor.pop();
            }
            opor.pop();
        }

        else if(ch=='+' ||ch =='-'){
            while(!opor.empty() && opor.top()!='(' &&
            (opor.top()=='+' || opor.top()=='-' ||
            opor.top()=='*'|| opor.top()=='/'))
            {
                pexp += opor.top();
                opor.pop();
            }
            // if(opor.top()!='*' && opor.top()!='/'){
            //     opor.push(ch);
            // }
            // else {
            //     pexp += opor.top();
            //     opor.pop();
            // }
            opor.push(ch);
        }

        else if(ch=='*' ||ch=='/'){
            //此时要先处理栈中还剩下来的*/
            while(!opor.empty() && (opor.top()=='*'||opor.top()=='/')){
                pexp += opor.top();
                opor.pop();
            }
            opor.push(ch);
        }
    }

    //最后一定要记得把栈清空！！！
    while(!opor.empty()){
        pexp += opor.top();
        opor.pop();
    }

    return pexp;
}


int Calpexp(string pexp){
    stack<int> opand;

    for (int i = 0; i < pexp.length(); i++){
        char ch = pexp[i];

        if(ch>='0' && ch <='9'){
            opand.push(ch - '0');
        }

        else if(ch=='+'){
            int a = opand.top();
            opand.pop();
            int b = opand.top();
            opand.pop();
            opand.push(b + a);
        }

        else if(ch=='-'){
            int a = opand.top();
            opand.pop();
            int b = opand.top();
            opand.pop();
            opand.push(b - a);
        }

        else if(ch=='*'){
            int a = opand.top();
            opand.pop();
            int b = opand.top();
            opand.pop();
            opand.push(b * a);
        }

        else if(ch=='/'){
            int a = opand.top();
            opand.pop();
            int b = opand.top();
            opand.pop();
            opand.push(b / a);
        }

    }

    return opand.top();
}



int main(){
    string exp;
    cin >> exp;

    cout << Calpexp(PostExp(exp)) << endl;
    return 0;
}