
/*

题目：
在一维字符数组 A 中存储了一棵高度为 d 的二叉树，其结点的个数为  2^d-1  ，->完美二叉树
存储方式是按中序逐个将结点顺序存入到数组A中。
要求实现：

1. class node{ };
   实现二叉树结点类

2. node * buildTree(int A[], int n) 
   在函数中实现算法，将保存在数组中的二叉树转换为链式存储保存，返回根结点的指针

3. void inorderTraversal(node* root) 
   在函数中实现中序遍历算法，并输出遍历结果。

输入格式：
字符1 字符2 字符3 ... 字符n

输出格式
字符1 字符2 字符3 ... 字符n


*/

#include<queue>
#include<iostream>
#include<stack>
using namespace std;

// 实现 class node 
template<typename T>
class node{
public:
    T x;
    node<T> *left;
    node<T> *right;

};

// 实现 buildTree(...) 
node<char> * buildTree(char data[], int n) {
    int temp=n/2;
    if(temp==0){
        node<char> *cur = new node<char>;
        cur->x = data[temp];
        cur->left == nullptr;
        cur->right == nullptr;
        return cur;
    }
    node<char> *cur = new node<char>;
    cur->x = data[temp];
    cur->left = buildTree(data, temp);
    cur->right = buildTree(data + temp + 1, n - temp - 1);
    return cur;
}

// 实现 inorderTraversal(...) 
void inorderTraversal(node<char> * root) {
    if(root->left==nullptr){
        cout << root->x << " ";
        return;
    }
    inorderTraversal(root->left);
    cout << root->x << " ";
    inorderTraversal(root->right);
}


int main() {

	int n; 
	std::cin >> n;  //输入数据的长度
	char * data = new char[n];

	for (int i = 0; i < n; ++i) //输入n个数据
		std::cin >> data[i];

	node<char>* bt = buildTree(data, n);	 //调用buildTree函数创建二叉树的链式存储

	inorderTraversal(bt);  //以中序遍历显示二叉树
}