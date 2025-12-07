/*
题目：
输入为一棵二叉树的层次遍历序列，其中空结点用特殊字符 `'#'` 表示。
例如，输入 "ABC#D#E##F" 表示如下二叉树
               A
             /   \
            B     C
             \     \
              D     E
             /
            F

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

#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <string>
using namespace std;

struct node
{
    char data;
    char ltag, rtag;
    node* lchild, * rchild;
};

// 实现 buildtree()函数---------------------------------------

node* buildtree(char *arr) {
    if (arr == nullptr || arr[0] == '\0' || arr[0] == '#') {
        return nullptr;
    }
   
    queue<node*> q; // 用于层次构建的队列

    // 创建根节点
    node* root = new node;
    root->data = arr[0];
    root->ltag = 0; // 初始化为0，表示指向孩子
    root->rtag = 0;
    root->lchild = nullptr;
    root->rchild = nullptr;
    q.push(root);

    int i = 1; // 从第二个字符开始处理
    while (!q.empty() && arr[i] != '\0') {
        node* current = q.front();
        q.pop();

        // 处理左孩子
        if (arr[i] != '#') {
            node* left = new node;
            left->data = arr[i];
            left->ltag = 0;
            left->rtag = 0;
            left->lchild = nullptr;
            left->rchild = nullptr;
            current->lchild = left;
            q.push(left);
        }
        else {
            current->lchild = nullptr; // 空节点标记
        }
        i++;

        // 处理右孩子（若还有字符）
        if (arr[i] == '\0') break;
        if (arr[i] != '#') {
            node* right = new node;
            right->data = arr[i];
            right->ltag = 0;
            right->rtag = 0;
            right->lchild = nullptr;
            right->rchild = nullptr;
            current->rchild = right;
            q.push(right);
        }
        else {
            current->rchild = nullptr; // 空节点标记
        }
        i++;
    }

    return root;
}



// ---------------buildtree()  end---------------------------
// 实现 thread()函数---------------------------------------


void thread(node* root) {
    if (root == nullptr) return;
    
    static node* pre = nullptr;
    
    // 递归线索化左子树
    if (root->ltag == 0) {
        thread(root->lchild);
    }
    
    // 处理当前节点
    if (root->lchild == nullptr) {
        root->ltag = 1;
        root->lchild = pre;
    }
    
    if (pre != nullptr && pre->rchild == nullptr) {
        pre->rtag = 1;
        pre->rchild = root;
    }
    
    pre = root;
    
    // 递归线索化右子树
    if (root->rtag == 0) {
        thread(root->rchild);
    }
}




// ---------------thread()  end---------------------------

// 实现 inorderTraversal()函数---------------------------------------
void inorderTraversal(node* root) {
    if (root == nullptr) return;
    
    // 找到中序遍历的第一个节点
    node* current = root;
    while (current->ltag == 0 && current->lchild != nullptr) {
        current = current->lchild;
    }
    
    bool first = true;
    while (current != nullptr) {
        if (!first) {
            cout << " ";
        }
        first = false;
        
        cout << current->data;
        
        // 检查是否通过线索到达
        if (current->rtag == 1) {
            cout << " Thread_in_node_" << current->data;
        }
        
        // 移动到下一个节点
        if (current->rtag == 1) {
            current = current->rchild;
        } else {
            current = current->rchild;
            while (current != nullptr && current->ltag == 0 && current->lchild != nullptr) {
                current = current->lchild;
            }
        }
    }
    cout << endl;
}


// ---------------inorderTraversal()  end---------------------------

// 实现 getSuccessorInPreorder()函数---------------------------------------
node* getSuccessorInPreorder(node* p, node* root) {
    if (p == nullptr || root == nullptr) return nullptr;
    
    // 前序遍历：根->左->右
    // 如果p有左孩子，左孩子就是后继
    if (p->ltag == 0 && p->lchild != nullptr) {
        return p->lchild;
    }
    
    // 如果p有右孩子，右孩子就是后继
    if (p->rtag == 0 && p->rchild != nullptr) {
        return p->rchild;
    }
    
    // 如果p是叶子节点，需要找到最近的祖先，该祖先有右孩子且p在它的左子树中
    stack<node*> st;
    node* current = root;
    bool found = false;
    
    // 前序遍历找p
    while (!st.empty() || current != nullptr) {
        while (current != nullptr) {
            if (found && current != p) {
                return current; // 找到p后的第一个节点就是后继
            }
            if (current == p) {
                found = true;
            }
            st.push(current);
            if (current->ltag == 0) {
                current = current->lchild;
            } else {
                current = nullptr;
            }
        }
        
        if (!st.empty()) {
            current = st.top();
            st.pop();
            if (current->rtag == 0) {
                current = current->rchild;
            } else {
                current = nullptr;
            }
        }
    }
    
    return nullptr; 

}




// ---------------getSuccessorInPreorder()  end---------------------------

// 实现 getPredecessorInPostorder()函数---------------------------------------
node* getPredecessorInPostorder(node* p, node* root) {
    if (p == nullptr || root == nullptr) return nullptr;
    
    // 后序遍历：左->右->根
    // 如果p有右孩子，右孩子就是前驱
    if (p->rtag == 0 && p->rchild != nullptr) {
        return p->rchild;
    }
    
    // 如果p有左孩子，左孩子就是前驱
    if (p->ltag == 0 && p->lchild != nullptr) {
        return p->lchild;
    }
    
    // 如果p是叶子节点，需要找到p在后序遍历中的前一个节点
    stack<node*> st;
    vector<node*> postorder;
    node* current = root;
    node* lastVisited = nullptr;
    
    // 后序遍历收集所有节点
    while (!st.empty() || current != nullptr) {
        if (current != nullptr) {
            st.push(current);
            if (current->ltag == 0) {
                current = current->lchild;
            } else {
                current = nullptr;
            }
        } else {
            node* peekNode = st.top();
            if (peekNode->rtag == 0 && peekNode->rchild != nullptr && peekNode->rchild != lastVisited) {
                current = peekNode->rchild;
            } else {
                postorder.push_back(peekNode);
                lastVisited = peekNode;
                st.pop();
            }
        }
    }
    
    // 在后序序列中找p的前驱
    for (int i = 0; i < (int)postorder.size(); i++) {
        if (postorder[i] == p && i > 0) {
            return postorder[i-1];
        }
    }
    
    return nullptr; 
}




// ---------------getPredecessorInPostorder()  end---------------------------



int main()
{

    string str;
    cin >> str;
    node* root = buildtree((char*)str.c_str());

    //不要修改main()函数中以上部分的内容---------------------------


    //1、调用thread()函数线索化二叉树
    thread(root);


    //2、调用inorderTraversal()遍历输出二叉树
    inorderTraversal(root);

    //3、编写程序, 使用getSuccessorInPreorder()
    //输出二叉树中各个结点在前序序列中的后继结点
    vector<node*> inorderNodes;
    node* current = root;
    while (current != nullptr && current->ltag == 0 && current->lchild != nullptr) {
        current = current->lchild;
    }
    while (current != nullptr) {
        inorderNodes.push_back(current);
        if (current->rtag == 1) {
            current = current->rchild;
        } else {
            current = current->rchild;
            while (current != nullptr && current->ltag == 0 && current->lchild != nullptr) {
                current = current->lchild;
            }
        }
    }

    // 输出前序遍历后继（去掉#号，正确处理空格）
    bool first1 = true;
    for (int i = 0; i < inorderNodes.size(); i++) {
        node* successor = getSuccessorInPreorder(inorderNodes[i], root);
        if (successor != nullptr) {
            if (!first1) {
                cout << " ";
            }
            cout << successor->data;
            first1 = false;
        }
    }
    cout << endl;

    // 输出后序遍历前驱（去掉#号，正确处理空格）
    bool first2 = true;
    for (int i = 0; i < inorderNodes.size(); i++) {
        node* predecessor = getPredecessorInPostorder(inorderNodes[i], root);
        if (predecessor != nullptr) {
            if (!first2) {
                cout << " ";
            }
            cout << predecessor->data;
            first2 = false;
        }
    }
    cout << endl;

    return 0;
}

