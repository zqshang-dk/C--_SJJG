/*

题目：
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
	std::cin >> n;  //输入数据的长度
	char * data = new char[n];

	for (int i = 0; i < n; ++i) //输入n个数组
		std::cin >> data[i];

    //不要修改main()函数中以上部分的内容---------------------------
    stack<int>st;
    char* data_1=new char[n];
    int i=0;
    st.push(0);
    while(!st.empty()){
        int temp=st.top();
        st.pop();

        data_1[i]=data[temp];
        i++;

        int right=2*temp+2;
        int left=2*temp+1;

        if(right<n) st.push(right);
        if(left<n) st.push(left);
    }

    for(int i=0;i<n;i++){
        cout<<data_1[i]<<" ";
    }
    cout<<endl;

    delete[]data_1;


    //不要修改main()函数中以下部分的内容---------------------------

	delete [] data; 
    return 0;  
}  

