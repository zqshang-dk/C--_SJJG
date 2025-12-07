//从键盘上输入一个英文字母
//生成一个以该字母为两段的回文字符串
//eg.‘e’ ，生成edcbabcde

#include<iostream>
#include<stack>
#include<string>
using namespace std;

void Huiwen(char alp){
    stack<char> st;

    // st.push(alp);
    // for (int i = 0; i < alp - 'a';i++){
    //     st.push(alp + i);
    // }

    // for (int j = alp - 'a'; j < 2 * alp - 1;j++){
    //     st.push('a' + j);
    // }

    // for (int i = 0; i < alp - 'a'; i++)
    // {
    //     cout << st.top() << " ";
    //     st.pop();
    // }

    for (char ch = alp; ch >= 'a';ch--){
        st.push(ch);
    }

    for (char ch = 'b'; ch <= alp;ch++){
        st.push(ch);
    }

    while(!st.empty()){
        cout << st.top() << " ";
        st.pop();
    }
}

int main(){
    char x;
    cin >> x;

    Huiwen(x);
    return 0;
}