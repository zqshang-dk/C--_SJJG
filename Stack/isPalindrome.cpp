//设计算法判断输入的字符串是否为回文序列
#include<iostream>
#include<string>
#include<stack>
using namespace std;

bool isPalindrome(string str){
    stack<char> st;
    char e;
    int i = 0;

    while(i<str.length()/2){
        st.push(str[i]);
        i++;
    }
    if(str.length()%2==1){
        i++;                      //如果str的长度为奇数，那么跳过中间的字符
    }
    while(i<str.length()){
        if(st.empty())
            return false;

        e = st.top();
        st.pop();
        if(e!=str[i]){
            return false;
        }
        i++;
    }
    return true;
}

int main(){
    string str;
    cin >> str;
    if(isPalindrome(str)){
        cout << "yes !"<< endl;
    }

    else{
        cout << "no" << endl;
    }
    return 0;
}