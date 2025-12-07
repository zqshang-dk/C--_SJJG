//请问你还记得堆排序的流程吗？
//估计太长时间没学数据结构，你对堆排序也是忘得差不多了吧
#include<iostream>
using namespace std;

//堆排序的核心思路
//先建立一个大根堆
//再把堆顶元素取出来，并且重新建堆
//如此重复下去便可以找到想要的排好序的列表
void HeapSort(int *a,int n){
    //建堆过程
    //错误写法：for (int i = (n + 1) / 2 - 1; i >= 0;i--)典型的没有理解n的具体含义，n不是下标索引，而是元素个数啊！！！！
    for (int i = n / 2 - 1; i >= 0;i--){
        int p = i;
        int tmp = a[i];   //先记录这个根节点

        while((2*p+1)<n){
            int child = 2 * p + 1;
            if((2*p+2)<n && a[2*p+2]>a[2*p+1]){
                child += 1;
            }

            if(tmp>a[child]){
                break;   //如果父亲结点大于儿子节点
            }

            a[p] = a[child];
            p = child;    //继续向下调整
        }

        a[p] = tmp;
    }


    //取最大值并重新调整堆
    for (int i = n - 1; i > 0;i--){
        swap(a[0], a[i]);

        int p = 0;
        int tmp = a[0];

        while((2*p+1)<i){
            int child = 2 * p + 1;
            if((2*p+2)<n && a[2*p+1]<a[2*p+2]){
                
            }
        }
    }
}