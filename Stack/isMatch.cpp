//设计一个算法，利用顺序栈判断用户输入的表达式中的括号是否配对
#include<iostream>
#include<stack>
#include<string>
using namespace std;

bool isMatch(string str){
    stack<char> st;
    int i = 0;
    char e;

    while(i<str.length()){
        if (str[i] == '[' || str[i] == '(' || str[i] == '{'){
            st.push(str[i]);
        }

        else{
            if(str[i]==')'){
                if(st.empty()){
                    return false;
                }
                else {
                    e = st.top();
                    st.pop();
                    if(e!='(')
                        return false;
                }
            }

            if(str[i]==']'){
                if(st.empty()){
                    return false;
                }
                else {
                    e = st.top();
                    st.pop();
                    if(e!='[')
                        return false;
                }
            }

            if(str[i]=='}'){
                if(st.empty()){
                    return false;
                }
                else {
                    e = st.top();
                    st.pop();
                    if(e!='{')
                        return false;
                }
            }
        }
        i++;
    }
    return st.empty();
}


int main(){
    cout << "test1:";
    string str1 = "([)}";
    if(isMatch(str1)){
        cout << str1 << "yes" << endl;
    }
    else{
        cout << str1 << "错" << endl;
    }
    return 0;
}