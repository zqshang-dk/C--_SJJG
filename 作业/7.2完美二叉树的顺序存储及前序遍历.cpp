/*题目：
在一维字符数组 A 中存储了一棵高度为 d 的二叉树，其结点的个数为 n=2^d-1 ，
存储方式是按层次周游逐个结点顺序存入到数组A中。
请利用一个栈结构，写出算法将该二叉树的前序遍历结果存储在数组 B 中。
本题中二叉树节点中的数据用字符类型表示。
输入格式：
字符1 字符2 字符3 ... 字符n
输出格式
字符1 字符2 字符3 ... 字符n
*/
#include<iostream>
#include<stack>
using namespace std;

int main() {

	int n; 
	cin >> n;  //输入数据的长度
	char * data = new char[n];

	for (int i = 0; i < n; ++i) //输入n个数据
		cin >> data[i];

    //不要修改main()函数中以上部分的内容---------------------------
    stack<char> st;
    st.push(0);   //第一个数一定是根节点，也一定是前序遍历的第一个元素！！！

    //应该会还要考虑完美二叉树的特殊性质！
    char *new_data = new char[n];
    int i = 0;
    while(!st.empty()){
        int tmp = st.top();
        st.pop();

        new_data[i] = data[tmp];
        i++;

        int r = 2 * tmp + 2;
        int l = 2 * tmp + 1;

        if(r<n){
            st.push(r);
        }
        if(l<n){
            st.push(l);
        }
    }
    for (int i = 0; i < n;i++){
        cout << new_data[i] << " ";
    }
    cout << endl;
    delete[] new_data;

    // 不要修改main()函数中以下部分的内容---------------------------

    delete[] data; 
    return 0;  
}  


