#include<iostream>
using namespace std;




template<typename T>
struct LinkNode{
    T data;
    LinkNode<T>* next;    //下一个结点指针
    LinkNode():next(nullptr){}    //构造函数
    LinkNode(T d):data(d),next(nullptr){}   //重载构造函数
};
template<typename T>
class LinkList{
public:
    T data;
    LinkNode <T>*head;     //单链表头结点
    
    //单链表的初始化
    LinkList(){
        head=new LinkNode<T>();
    }

    //单链表的销毁
    ~LinkList(){
        LinkNode<T>*pre,*p;
        pre=head;
        p=pre->next;
        while(p!=NULL){
            delete pre;
            pre=p;p=p->next;          //pre、p同步后移一个结点
        }
        delete pre;
    }


    //返回序号为i的结点
    LinkNode<T>* geti(int i){
        if(i<-1){
            return NULL;
        }
        LinkNode<T>*p=head;      //首先p指向头结点
        int j=-1;                //j置为-1，可以认为头结点的序号为-1
        while(j<i&&p!=NULL){     //指针p移动i+1个结点
            j++;
            p=p->next;
        }
        return p;
    }
    
    //插入结点操作:将元素e的结点添加到单链表末尾
    void Add(T e){
        LinkNode<T> *s=new LinkNode<T>(e);
        LinkNode<T> *p=head;
        while(p->next!=NULL){
            p=p->next;
        }
        p->next=s;
    }

    //求链表的长度
    int Getlength(){
        LinkNode<T>*p=head;
        int cnt=0;
        while(p->next!=NULL){
            cnt++;
            p=p->next;
        }
        return cnt;
    }

    //求单链表中序号为i的结点值
    bool GetElem(int i,T &e){
        if(i<0)return false;
        LinkNode<T>*p=geti(i);
        if(p!=NULL){
            e=p->data;
            return true;
        }
        else return false;
    }

    //设置单链表中序号为i的值
    bool SetElem(int i,T e){
        if(i<0)return false;
        LinkNode<T>*p=geti(i);
        if(p!=NULL){
            p->data=e;
            return true;
        }
        else return false;
    }



    //删除结点操作

    //整体建立单链表
    //用头插法建表
    void CreateListF(T a[],int n){
        for(int i=0;i<n;i++){                          //循环建立数据结点
            LinkNode<T>*s = new LinkNode<T>(a[i]);     //创建数据结点s
            s->next=head->next;                        //将结点s插入head结点的后面
            head->next=s;
        }
    }
    //用尾插法建表
    void CreateListR(T a[],int n){
        LinkNode<T> *s,*r;
        r=head;                                        //r始终指向尾结点，开始时指向头结点
        for(int i=0;i<n;i++){
            s=new LinkNode<T>(a[i]);                   //创建数据结i
            r->next=s;
            r=s;
        }
        r->next=NULL;
    }


};





//双链表
/*
    //插入元素
    bool insertValue(int i,T e){
        if(i<0) return false;
        node<T>*s=new node<T>(e);
        node<T>*p=find(i-1);
        if(p!=NULL){
            s->next=p->next;
            if(p->next!=NULL){
                p->next->prior=s;
            }
            p->next=s;
            s->prior=p;
            return ture;
        }
        else return false;
    }

*/