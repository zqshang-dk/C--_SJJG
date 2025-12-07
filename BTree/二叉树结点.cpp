struct BTNode{
    char data;          //数据元素
    BTNode* left;        //指向左子树结点
    BTNode* right;       //指向右子树结点
    BTNode():left(nullptr),right(nullptr){}
    BTNode(char d){
        data = d;
        left = right = nullptr;
    }
}