// 约瑟夫环问题
// 顺序表有n个元素
// 现在从第s个元素开始计数
// 数到m的元素移出顺序表
// 然后从下一个元素开始计数
// 数到第m个元素又将其移出顺序表
// 如此重复，知道所有的元素都被移出

#include<iostream>
#include<queue>
#include<vector>
using namespace std;

//数组法
void Josephus1(int *x,int n,int s,int m){
    for (int i = n; i >= 2;i--){   //i表示当前剩余人数，从n递减到2
        s = (s + m - 1) % i;   // 从当前位置s开始，数m个人（包含自己）
                               // %i 取模运算实现环形结构
        int tmp = x[s];        //暂存被淘汰者的编号 
        for (int j = s; j < i - 1;j++){
            x[j] = x[j + 1];   //后面的人向前移动填补空位
        }
        x[i - 1] = tmp;        //将被淘汰者放到数组末尾
    }

    for (int i = 0; i < n / 2;i++){
        int tmp = x[i];
        x[i] = x[n - 1 - i];
        x[n - 1 - i] = tmp;
    }
}

//递归法：只能求出最后幸存者的编号，无法求出前几次淘汰者的编号
int Josephus2(int n,int m){   //从0开始编号，n个人是最后存活者的位置
    if(n==1){
        return 0;
    }

    else {
        // Josephus(n-1,m)淘汰一个人后剩下n-1个人时存活者的位置
        // +m 由于淘汰了1个人，位置需要增加m

        return (Josephus2(n - 1, m)+m)%n;
    }
}


//链表法
struct ListNode{
    int num;
    ListNode *next;
    ListNode(int val):num(val),next(nullptr){}
};
ListNode *Josephus3(int n, int m){
    if(n<=0 || m<=0)
        return nullptr;
    
    //创建头结点
    ListNode *phead = new ListNode(-1);
    ListNode *p = phead;

    for (int i = 1; i <= n;i++){
        ListNode *node = new ListNode(i);
        p->next = node;
        p = p->next;
    }
    p->next = phead->next;   //尾结点指向头结点形成循环链表

    p = phead->next;
    int count = 1;

    cout << "出局顺序为：" << endl;

    while (p->next != p){   //只剩一个结点时结束
        if (count == m - 1){ //出局结点的前一个结点
            cout << p->next->num << " ";  //输出出局者编号

            ListNode *tmp = p->next;  //临时保存出局者结点
            p->next = p->next->next;
            count = 0;
            delete tmp;
        }

        count++;
        p = p->next;
    }

    cout << "\n幸存者" << p -> num << endl;

    delete phead;
    return p;
}



int main()
{
    int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    Josephus1(a, 9, 0, 4);
    for (int i = 0; i < 9;i++){
        cout << a[i] << " ";
    }

    int n, m;
    cin >> n >> m;
    ListNode *survivor = Josephus3(n, m);
    return 0;
}



void Josephus4(int *a,int n,int s,int m){
    //从s开始，数到第m个剔除

    for (int i = n; i >= 2;i--){
        s = (s + m - 1) % i;
        int tmp = a[s];

        for (int j = 0; j < i-1; j++){
            a[j] = a[j + 1];
        }
        a[i - 1] = tmp;
    }

    for (int i = n; i > 1;i--){
        int tmp;
        tmp = a[n - i - 1];
        a[n - i - 1] = a[n];
        a[n] = tmp;
    }
}


//队列法
void Josephus5(int x[],int n,int s,int m){
    queue<int> q;
    int count = 1;

    for (int i = 0; i < n;i++){
        q.push(x[i]);         //初始化队列
    }

    //调整起始位置
    for (int i = 1; i < s;i++){
        int tmp = q.front();
        q.pop();
        q.push(tmp);
    }

    while(!q.empty()){  //还有人的时候
        int tmp = q.front();
        q.pop();

        if((s+count-1)%m){  //判断是否淘汰
            q.push(tmp);    //安全，重新入队
        }
        else{
            *x++ = tmp;    //淘汰，存入结果数组
        }
        count++;
    }
}