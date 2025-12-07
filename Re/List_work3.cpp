/*
题目：
顺序表中有n 个元素, 现从第 s 个元素开始从1报数，
报到 m 的元素被移出顺序表，然后继续从下一个元素开始从1报数，
报到第 m 个元素又将其移出顺序表，如到达顺序表的尾部，则调头从表头元素继续报数。
如此重复，直到所有的元素都被移出。请输出按出列次序得到的n个元素的顺序表

输入格式：
数据1 数据2 数据3 ...
输出格式
数据1 数据2 数据3...

*/


//在下方写出程序应该包含的头文件


//#include _________
//...
#include<iostream>
using namespace std;

//完成Josephus(/*arg lists*/)函数，将参数数组中的顺序表转换成出列元素顺序表

void Josephus(int* a,int n,int s,int m)    // 注意: 这里要完成参数表
{
    //在本行下方编程程序代码，不要修改本函数中本行及以上的内容
    int current=s;
    for(int count=0;count<n;count++){
        for(int i=1;i<m;i++){
            current=(current+1)%n;

            while(a[current]==-1){
                current=(current+1)%n;
            }
        }
        
        cout<<a[current]<<" ";

        a[current]=-1;

        if(count<n-1){
            current=(current+1)%n;

            while (a[current] == -1) {
                current = (current + 1) % n;
            }
        }
    }
    cout<<endl;
    //代码编辑结束，不要修改本函数中本行及以下的内容
}

int main(){

    int* a, n;
    std::cin >> n;               //输入数组大小n
    a = new int[n];
    for (int i = 0; i < n; ++i)
    	cin >> a[i];           //输入n个数据     
    int s, m;                  
    cin >> s;                  //s表示从哪个元素开始计数，s是数组下标，从0开始计数
    cin >> m;                  //m表示报数到第几个数，对应的元素出列，从1开始报数

//在本行下方编程程序代码，不要修改main()函数中本行及以上的内容
    

    //1. 调用Josephus()函数，对数组a进行处理
    Josephus(a,n,s,m);


    //2. 按格式要求输出数组a中的序列


//代码编辑结束，不要修改本行及以下的内容
    return 0;
}