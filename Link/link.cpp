#include<iostream>
using namespace std;


struct node{
    int data;
    node *pnext;
};
void displayList(node *pnode){
    while (pnode->pnext != nullptr){
        pnode = pnode->pnext;
        cout << pnode->data << " ";
    }
}

//插入结点
int insert(node *phead, int pos, node *pele){
    node *p = phead;
    int i = 0;
    while(p->pnext!=nullptr && i<pos){
        i++;
        p = p->pnext;
    }

    if(p==nullptr && i<pos){
        return 0;
    }

    else{
        pele->pnext = p->pnext;
        p->pnext = pele;
        return 1;
    }
}

//删除结点
void deleteNode(node *&phead, int pos){
    int i = 0;
    node *p = phead;

    while (p->pnext != nullptr && i<pos){
        i++;
        p = p->pnext;
    }

    if(p->pnext==nullptr){
        return;
    }

    else{
        node *tmp = p->pnext;
        p->pnext = tmp->pnext;
        delete tmp;
    }
}

//删除整个列表
int DeleteList(node *&phead){
    //p 指向链表的“第一个数据节点”（头节点的下一个节点）
    node *p = phead->pnext;  

    //如果第一个数据节点为nullptr，表示无节点可删
    if(!p){
        return 0;
    }

    //tmp暂存当前要删除的结点
    node *tmp = p;

    //当p不为nullptr时循环
    //这是一个“先找后继，再删除当前”的循环
    while(p){
        p = tmp->pnext;
        delete tmp; //释放当前结点
        tmp = p;   //tmp更新为新的当前结点
    }
    phead->pnext = nullptr;
    return 1;
}

//单链表的插入排序
void InsertSort(node *&phead){
    node *p1,*p2,*tmp,*pre;
    //p1指向第一个数据节点，也就是此时的已排序部分
    p1 = phead->pnext;      
    if(p1==nullptr){
        return;
    }
    //p2先指向第二个数据结点，也就是此时的未排序部分的第一个元素
    p2 = p1->pnext;
    p1->pnext = nullptr;

    while(p2!=nullptr){      //未排序部分还有结点
        p1 = phead->pnext;
        pre = phead;
        tmp = p2->pnext;

        while(p1!=nullptr && p1->data < p2->data){
            pre = p1;
            p1 = p1->pnext;
        }

        p2->pnext = p1;
        pre->pnext = p2;
        p2 = tmp;
    }
}



int main(){
    node *phead = new node();
    phead->pnext = nullptr;
    int d[] = {9, 6, 3, 2};
    for (int i = 0; i < 4; i++){
        node *p = new node();
        if(p){
            p->data = d[i];
            p->pnext = nullptr;
            insert(phead, i + 1, p);
        }
    }

    displayList(phead);
    return 0;
}