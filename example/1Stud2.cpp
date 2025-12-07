/*
#include<iostream>
using namespace std;

struct Stud2{
    int no;                        //存放学号
    string name;                   //存放姓名
    int score;                     //存放分数
    Stud2* next;                   //存放下一个结点指针
    Stud2(int no1,string name1,int score1){   //重载构造函数
        no=no1;
        name=name1;
        score=score1;
        next=nullptr;
    }
};

void Create(){
    Stud2* p2,*head,*p3;
    head = new Stud2(2018001,"shangzhiqi",90);         //单链表首结点
    p2=new Stud2(2018002,"SZQ",92);
    p3=new Stud2(2018003,"dk",93);  
    head->next=p2;
    p2->next=p3;
    p3->next=nullptr;

}
int main(){

}*/

#include<iostream>
using namespace std;

struct Stud2{
    int no;                        //存放学号
    string name;                   //存放姓名
    int score;                     //存放分数
    Stud2* next;                   //存放下一个结点指针
    Stud2(int no1,string name1,int score1){   //重载构造函数
        no=no1;
        name=name1;
        score=score1;
        next=nullptr;
    }
};

Stud2* Create(){
    Stud2* p2,*head,*p3;
    head = new Stud2(2018001,"shangzhiqi",90);         //单链表首结点
    p2=new Stud2(2018002,"SZQ",92);
    p3=new Stud2(2018003,"dk",93);  
    head->next=p2;
    p2->next=p3;
    p3->next=nullptr;
    return head;  // 返回链表头指针
}

void Display(Stud2* head){
    Stud2* p = head;
    cout << "学号\t\t姓名\t\t分数" << endl;
    cout << "--------------------------------" << endl;
    while(p != nullptr){
        cout << p->no << "\t\t" << p->name << "\t\t" << p->score << endl;
        p = p->next;
    }
}

int main(){
    // 创建链表
    Stud2* head = Create();
    
    // 显示链表内容
    Display(head);
    
    return 0;
}