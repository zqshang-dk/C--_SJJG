/*题目：
在一维字符数组 A 中存储了一棵高度为 d 的二叉树，其结点的个数为  2^d-1  ，
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
//template<typename T>
class node{
public:
    char x;
    node *lchild;
    node *rchild;
    //以后构建完成员之后一定要对成员进行初始化处理！
    node(char val) : x(val), lchild(nullptr), rchild(nullptr) {}
};

//二叉树的链式存储，就是要把每个元素加上两个指针区域
//注意区分链式存储和线索化，链式存储并不是线索化！！！
//也就是说链式存储就是加指针，线索化才需要找前驱与后继。

// 实现 buildTree(...) 
node * buildTree(char data[], int n) {
    //建堆的过程，实际上是把二叉树结点给用上
    int tmp = n / 2;   //怎么说你得先找到根节点是谁吧
    // if(tmp==0){    //递归的终止条件不能省略
    //     node *current = new node();
    //     current->x = data[tmp];
    //     current->lchild = nullptr;
    //     current->rchild = nullptr;
    // }
    if(n<=0)
        return nullptr;
    //我真服了，为了让这行不报错，我们做出了如下的操作
    //1.补充构造函数（含参）
    //2.public必须有，不然的话默认是private，啥都干不了啊！
    node *current = new node (data[tmp]);

    current->lchild = buildTree(data, tmp);
    current->rchild = buildTree(data + tmp + 1, n - tmp - 1);

    return current;
}

// 实现 inorderTraversal(...) 
void inorderTraversal(node * root) {
    //遍历的时候先往左找，找到最左边的结点
    //递归的终止条件
    if(root->lchild==nullptr){
        cout << root->x << " ";
        return;
    }

    inorderTraversal(root->lchild);
    cout << root->x << " ";
    inorderTraversal(root->rchild);
}


int main() {

	int n; 
	std::cin >> n;  //输入数据的长度
	char * data = new char[n];

	for (int i = 0; i < n; ++i) //输入n个数据
		std::cin >> data[i];

	node* bt = buildTree(data, n);	 //调用buildTree函数创建二叉树的链式存储

	inorderTraversal(bt);  //以中序遍历显示二叉树
}