/*

题目：
在一维字符数组 A 中存储了一棵高度为 d 的二叉树，其结点的个数为 2^d-1 ，
存储方式是按中序逐个将结点顺序存入到数组A中。
请写出递归算法将该二叉树的前序遍历结果存储在数组 B 中。


输入格式：
字符1 字符2 字符3 ... 字符n

输出格式
字符1 字符2 字符3 ... 字符n

*/
//中序转化为前序

#include<iostream>
using namespace std;

void convert(char *a,char *b,int n){
    if(n<=0)return;

    int temp=n/2;
    *b=a[temp];
    convert(a,b+1,temp);
    convert(a+temp+1,b+temp+1,n-temp-1);
}

int main() {

	int n; 
	cin >> n;  //输入数据的长度
	char* data = new char[n];

	for (int i = 0; i < n; ++i) //输入n个数据
		cin >> data[i];

    //不要修改main()函数中以上部分的内容---------------------------
    //使用递归算法
    char *data_1=new char[n] ;
    convert(data,data_1,n);
    for(int i=0;i<n;i++){
        cout<<data_1[i]<<" ";
    }
    cout<<endl;

    delete [] data_1;
    //不要修改main()函数中以下部分的内容---------------------------

	delete [] data; 
    return 0;  
}  


