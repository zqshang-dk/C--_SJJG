#include<iostream>
using namespace std;

const int initcap=5;            //顺序表的初始容量为5
template<typename T>
class SqList{
public:
    T* data;                 //存放顺序表元素空间的指针
    int capacity;            //顺序表的容量
    int length;              //存放顺序表的长度
private:
    //设计私有成员函数将data数组的容量改为newcap
    void recap(int newcap){
        if(new<=0) return;
        T* olddata=data;
        data = new T[newcap];              //分配新空间
        capacity=newcap;                   //更新容量
        for(int i=0;i<length;i++){
            data[i]=olddata[i];            //复制元素
        }
        delete [ olddata]
    }

    //整体建立顺序表
    // 该运算从一个空顺序表开始，依次将a中的元素添加到data数组的末尾，当出现溢出时将容量扩倍
    void CreateList(T a[],int n){
        for(int i=0;i<n;i++){
            if(length==capacity){
                recap(2*length);
            }
            data[length]=a[i];
            length++;             //添加后元素个数+1
        }
    }

    //构造函数
    SqList(){
        data=new T[initcap];
        capacity=initcap;
        length=0;
    }

    //初始化复制构造函数
    SqList(const SqList<T> & s){
        capacity=s.capacity;             //复制容量
        length=s.length;                 //复制长度
        data = new T[capacity];          //为当前顺序表分配空间
        for(int i=0;i<length;i++){
            data[i]=s->data[i];
        }
    }

    //析构函数
    ~SqList(){
        delete [] data;
    }

    //将元素e添加到顺序表末尾
    void Add(T e){
        if(length==capacity){
            recap(2*length);
        }
        data[length]=e;
        length++;
    }

    //求顺序表的长度
    int Getlength(){
        return length;
    }

    //求顺序表中序号为i的元素值
    bool GetElem(int i,T &e){
        if(i<0 || i>=length){
            return false;
        }
        e=data[i];                 //取元素值
        return true;
    }

    //设置顺序表中序号为i的元素值
    bool SetElem(int i,T e){
        if(i<0 || i>=length){
            return false;
        }
        data[i]=e;
        return true;
    }

    //求顺序表中第一个值为e的元素的序号
    int GetNo(T e){
        int i=0;
        while(i<length && data[i]!=e)
            i++;
        if(i>=length){ 
            return -1;                  //没有找到时返回-1
        }
        else return i;
    }

    //在顺序表中插入e作为第i个元素
    bool Insert(int i,T e){
        if(i<0 || i>=length){
            return false;
        }
        if(length==capacity){
            recap(2*length);
        }
        for(int j=length;j>i;j--){
            data[j]=data[j-1];            //将data[i]及后面的元素后移一个位置
        }
        data[i]=e;
        length++;
        return true;
    }
    
    //在顺序表中删除第i个数据元素
    bool Delete(int i,T e){
        if(i<0 || i>=length){
            return false;
        }
        if(length==capacity){
            recap(2*length);
        }
        for(int j=length;j>i;j--){
            data[j-1]=data[j];            //将data[i]及后面的元素前移一个位置
        }
        length--;
        if(capacity>initcap && length<=capacity){
            recap(capacity/2);                //满足缩容条件则容量减半
        }
        return true;
    }

    //输出顺序表中的所有元素
    void DispList(){
        for(int i=0;i<length;i++){
            cout<<data[i]<<"  ";
        }
        cout<<endl;
    }

};



