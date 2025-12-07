// 题目：堆排序

// 描述：
// 编写函数 void heapSort()，
// 使用堆排序算法对一个整数数组进行升序排序，
// 要求在排序过程中，在每次将数组中的数据调整为堆后，将整个数组输出一次
#include<iostream>
using namespace std;


void heapSort(int *a,int n){
    //首先，2个过程，建堆和排序
    int i = 1;  

    for (int i = n / 2 - 1; i >= 0; i--)
    {
        int p = i;
        int tmp = a[i];

        while(2*p+1<n){
            int child = 2 * p + 1;
            if(2*p+2<n && a[2*p+1]<a[2*p+2]){
                child = 2 * p + 2;
            }

            if(tmp>a[child]){
                break;
            }

            else{
                a[p] = a[child];
                p = child;
            }
        }
        a[p] = tmp;
    }

    for (int i = 0; i < n;i++){
        cout << a[i] << " ";
    }

    for (int i = n-1; i >0;i--){
        int tmp = a[n];
        a[n] = a[0];
        a[0] = tmp;

        int p = 0;
        int tmp = a[0];

        while(2*p+1<i){
            int child = 2 * p + 1;
            if(2*p+2<n && a[2*p+2]>a[2*p+1]){
                child = 2 * p + 2;
            }

            if(tmp>a[child]){
                break;
            }

            a[p] = a[child];
            p = child;
        }
        a[p] = tmp;

        for (int i = 0; i < n;i++){
            cout << a[i] << " ";
        }
    }
}
