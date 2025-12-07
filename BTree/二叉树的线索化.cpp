

/*

题目：
输入为一棵二叉树的层次遍历序列，其中空结点用特殊字符 `'#'` 表示。
例如，输入 "ABC#D#E##F" 表示如下二叉树
               A
             /   \
            B     C
           / \   / \
          #   D #   E
         / \ /
        #  # F

下列函数，大家根据题目要求和初始代码的上下文，自行设计其参数与返回值

1. 实现函数buildtree(), 生成该二叉树的链式存储

2. 实现函数thread(), 将该二叉树按中序遍历线索化

3. 实现函数inorderTraversal(), 对线索二叉树进行中序遍历，输出遍历结点序列。
   当使用某节点的线索指针进行遍历时，输出"Thread_in_node_X", 这里X为该结点对应字符
   
4. 实现函数getSuccessorInPreorder(), 在线索化二叉树中寻找某个结点在前序遍历中的后继结点。
   在main()函数中生成中序遍历结点序列，顺次输出序列中每个结点的在前序遍历中的后继结点
   
5. 实现函数getPredecessorInPostorder()，在该线索化二叉树中寻找某个结点在后序遍历中的前驱结点。
   在main()函数中生成中序遍历结点序列，顺次输出序列中每个结点的在后序遍历中的前驱结点


输入格式：
字符串

输出格式
字符1 字符2 ... 字符n-1 字符n
字符1 字符2 ... 字符n-1
字符1 字符2 ... 字符n-1

例如:
输入 : ABC#D#E##F

输出 : 
B F Thread_in_node_F D Thread_in_node_D A C E
D C F B E
D F C E B

*/
/*
广度优先搜索用队列，深度优先搜索用栈

层次遍历是广度优先搜索，符合先进先出的特性->先遇到的结点，他的孩子也应该先被处理；

*/



#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <string>
using namespace std;

struct node
{
	char data;
	int ltag, rtag;
	node* lchild, * rchild;
};

// 实现 buildtree()函数，实现二叉树的链式存储-----------------------
// node* buildtree(string str){         //结果返回根结点指针
//     if(str.empty() || str[0]=='#'){
//         return nullptr;
//     }

//     //创建根节点并初始化
//     node *root = new node();
//     root->data = str[0];
//     root->lchild = nullptr;
//     root->rchild = nullptr;
//     root->ltag = 0;
//     root->rtag = 0;

//     //利用队列辅助
//     queue<node*> q;
//     q.push(root);

//     int i = 1;
//     while(i<str.length() && !q.empty()){
//         node *current = q.front();
//         q.pop();

//         //先处理左节点
//         if(i<str.length()){
//             if(str[i]!='#'){
//                 node *lnode = new node();
//                 lnode->data = str[i];
//                 lnode->lchild = nullptr;
//                 lnode->rchild = nullptr;
//                 lnode->ltag = 0;
//                 lnode->rtag = 0;

//                 //连接结点并入队
//                 current->lchild = lnode;
//                 q.push(lnode);
//             }

//             else{
//                 current->lchild = nullptr;
//             }
//             i++;
//         }

//         //左孩子添加完了接着是右孩子
//         if(i<str.length()){
//             if(str[i]!='#'){
//                 node *rnode = new node();
//                 rnode->data = str[i];
//                 rnode->lchild = nullptr;
//                 rnode->ltag = 0;
//                 rnode->rchild = nullptr;
//                 rnode->rtag = 0;

//                 current->rchild = rnode;
//                 q.push(rnode);
//             }

//             else{
//                 current->rchild = nullptr;
//             }
//             i++;
//         }
//     }
//     return root;
// }
node* buildtree(string str) {
    if (str.empty() || str[0] == '#') {
        return nullptr;
    }

    int len = str.length();
    
    // 1. 创建一个容器暂存所有的结点指针
    // 初始化大小为字符串长度，内容全为 nullptr
    vector<node*> nodeList(len, nullptr);

    // 2. 第一轮循环：根据字符串创建所有非空结点
    for (int i = 0; i < len; i++) {
        if (str[i] != '#') {
            node* newNode = new node();
            newNode->data = str[i];
            newNode->lchild = nullptr;
            newNode->rchild = nullptr;
            newNode->ltag = 0;
            newNode->rtag = 0;
            
            // 将创建好的结点存入对应下标的位置
            nodeList[i] = newNode;
        }
    }

    // 3. 第二轮循环：根据数组下标关系连接结点 (i 的孩子是 2*i+1 和 2*i+2)
    for (int i = 0; i < len; i++) {
        // 如果当前位置有结点，尝试连接它的孩子
        if (nodeList[i] != nullptr) {
            
            // 连接左孩子 (索引 2*i + 1)
            int leftIdx = 2 * i + 1;
            if (leftIdx < len) {
                nodeList[i]->lchild = nodeList[leftIdx];
            }

            // 连接右孩子 (索引 2*i + 2)
            int rightIdx = 2 * i + 2;
            if (rightIdx < len) {
                nodeList[i]->rchild = nodeList[rightIdx];
            }
        }
    }

    // 返回根结点（也就是下标为0的结点）
    return nodeList[0];
}
// ---------------buildtree()  end---------------------------
// 实现 thread()函数，将该二叉树实现中序线索遍历(非递归方法)---------------
//非递归方法——用栈来模拟递归过程
void thread(node *root){
    if(root==nullptr){
        return;
    }

    node *p = root;
    node *pre = nullptr;
    stack<node *> st;
    while(p!=nullptr || !st.empty()){
        //一直往左下方走
        while(p!=nullptr){
            st.push(p);
            p = p->lchild;
        }

        //此时已经走到头了，出栈访问
        p = st.top();
        st.pop();

        //线索化操作开始
        //先找前驱
        if(p->lchild==nullptr){
            p->ltag = 1;
            p->lchild = pre;
        }
        //再找后继
        if(pre!=nullptr &&pre->rchild==nullptr){
            pre->rtag = 1;
            pre->rchild = p;
        }

        pre = p;

        //转向右子树
        p = p->rchild;
    }

    //处理最后一个结点的后继
    if(pre!=nullptr){
        pre->rtag = 1;
        pre->rchild = nullptr;
    }
}

// ---------------thread()  end---------------------------

// 实现 inorderTraversal()函数---------------------------------------
// 实现函数inorderTraversal(), 对线索二叉树进行中序遍历，输出遍历结点序列。
// 当使用某节点的线索指针进行遍历时，输出"Thread_in_node_X", 这里X为该结点对应字符
void inorderTraversal(node*root){
    //找到起点
    if(root==nullptr){
        return;
    }

    node *p = root;
    while(p->ltag==0 && p->lchild!=nullptr){
        p = p->lchild;
    }

    //循环直到p为空
    while(p!=nullptr){
        cout << p->data << " ";

        //寻找后继节点
        //①rtag=1，则此时rchild指向的就是后继节点
        if(p->rtag==1){
            if(p->rchild!=nullptr){
                cout << "Thread_in_node_" << p->data << " ";
            }
            p = p->rchild;
        }

        //②rtag=0，后继为右子树的最左下结点
        else if(p->rtag==0){
            p = p->rchild;
            while(p!=nullptr && p->ltag==0){
                p = p->lchild;
            }
        }
    }
    cout << endl;
}



// ---------------inorderTraversal()  end---------------------------

// 实现 getSuccessorInPreorder()函数---------------------------------------
// 实现函数getSuccessorInPreorder(), 在线索化二叉树中寻找某个结点在前序遍历中的后继结点。
// 在main()函数中生成中序遍历结点序列，顺次输出序列中每个结点的在前序遍历中的后继结点

// 由于我们只有中序线索，要找到前序后继比较麻烦，最稳妥的办法是传入root重新进行一次前序遍历
node* getSuccessorInPreorder(node* p,node* root){
    if(root==nullptr || p==nullptr){
        return nullptr;
    }

    stack<node *> st;
    st.push(root);

    int found = 0;

    while(!st.empty()){
        node *current = st.top();
        st.pop();

        //如果上一次循环找到了p，那么current就是p的前序后继；
        if(found)
            return current;
        
        //如果当前就是p，标记一下，下一个出栈访问就是后继
        if(current==p){
            found = 1;
        }

        //前序遍历压栈顺序：先右后左，这样的话出栈就是先左后右了
        if(current->rtag==0 && current->rchild!=nullptr){
            st.push(current->rchild);
        }

        if(current->ltag==0 && current->lchild!=nullptr){
            st.push(current->lchild);
        }
    }
    return nullptr;
}




// ---------------getSuccessorInPreorder()  end---------------------------

// 实现 getPredecessorInPostorder()函数---------------------------------------
//实现函数getPredecessorInPostorder()，在该线索化二叉树中寻找某个结点在后序遍历中的前驱结点。
//在main()函数中生成中序遍历结点序列，顺次输出序列中每个结点的在后序遍历中的前驱结点
// 优化思路：
// 后序遍历：左 -> 右 -> 根
// 反向后序：根 -> 右 -> 左
// 也就是：我们在 "根->右->左" 的遍历中找到 p，那么下一个访问的结点就是 p 在后序中的前驱。

node* getPredecessorInPostorder(node* p, node* root){
    if(root==nullptr || p==nullptr){
        return nullptr;
    }

    stack<node *> st;
    st.push(root);

    int found = 0;

    while(!st.empty()){
        node *current = st.top();
        st.pop();

        // 【关键点1】逻辑和前序完全一样：
        // 如果上一次循环标记了found，说明刚刚访问过了p，那现在的current就是我们要找的人
        if(found)
            return current;
        
        // 如果当前就是p，标记一下，下一个出栈访问的就是答案
        if(current == p){
            found = 1;
        }

        // 【关键点2】入栈顺序调整：
        // 我们要实现 "根->右->左" 的访问顺序
        // 根据栈的后进先出，我们必须 "先压左，后压右"
        // 这样出栈的时候，就是 "先出右，后出左"
        
        // 1. 先压左孩子
        if(current->ltag == 0 && current->lchild != nullptr){
            st.push(current->lchild);
        }

        // 2. 后压右孩子 (这样下次top取出来的就是右孩子)
        if(current->rtag == 0 && current->rchild != nullptr){
            st.push(current->rchild);
        }
    }
    
    return nullptr; // 没找到或者p是第一个结点（无前驱）
}

// ---------------getPredecessorInPostorder()  end---------------------------

int main()
{	
	
	string str;
	cin >> str;
	node* root = buildtree(str.c_str());

	//不要修改main()函数中以上部分的内容---------------------------


    //1、调用thread()函数线索化二叉树
    thread(root);

    //2、调用inorderTraversal()遍历输出二叉树
    inorderTraversal(root);

    //3、编写程序, 使用getSuccessorInPreorder()
    //输出二叉树中各个结点在前序序列中的后继结点

    // 为了完成题目要求的顺次输出，我们需要先生成中序遍历的节点序列
    // 这里重新遍历一次把节点存入 vector，方便后续查询
    vector<node*> inorderNodes;
    node* p = root;
    // 找中序起点
    while(p != nullptr && p->ltag == 0) p = p->lchild;
    
    // 收集节点
    while(p != nullptr){
        inorderNodes.push_back(p);
        if(p->rtag == 1) p = p->rchild;
        else {
            p = p->rchild;
            while(p != nullptr && p->ltag == 0) p = p->lchild;
        }
    }

    for(int i = 0; i < inorderNodes.size(); i++){
        node* succ = getSuccessorInPreorder(inorderNodes[i], root);
        if(succ != NULL) cout << succ->data<<" ";
        // 如果是最后一个且没找到(理论上不应该输出null字符)，题目样例最后没有多余空格
    }
    cout << endl;

    //4、编写程序, 使用getPredecessorInPostorder()
    //输出二叉树中各个结点在后序序列中的前驱结点
    for(int i = 0; i < inorderNodes.size(); i++){
        node* pred = getPredecessorInPostorder(inorderNodes[i], root);
        if(pred != NULL) cout << pred->data<<" ";
    }
    cout << endl;




    //不要修改main()函数中以下部分的内容---------------------------

	
	return 0;
}

