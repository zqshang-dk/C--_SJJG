// 一个正整数的倒数仍然是整数，但是数字的顺序是倒序的，第一位数字变为最后一位，
// 例如，1245的倒数是5421，注意所有的前导0均被省略例如1200的倒数是21.
// 将两个倒数相加并且求出其和的倒数

#include<iostream>
#include<string>
#include<stack>
using namespace std;

string reverseNum(string num){
    stack<char> st;
    for (int i = 0; i < num.size();i++){
        st.push(num[i]);
    }

    string reversed = "";
    while(!st.empty()){
        reversed += st.top();
        st.pop();
    }

    int start = 0;
    while (start < reversed.size() && reversed[start] == '0'){
        start++;
    }

    if (start == reversed.size())
    {
        return "0";
    }

    return reversed.substr(start);
}

string add_num(string num1,string num2){
    int n1 = stoi(num1);
    int n2 = stoi(num2);

    return to_string(n1 + n2);
}

int main(){
    cout << "请输入两个正整数" << endl;

    string a, b;
    cin >> a >> b;

    cout << reverseNum(add_num(a, b)) << endl;

    return 0;
}