//把直接插入排序算法想象成是扑克牌整理牌的过程，这样的话比较好记住！！！
#include<iostream>
using namespace std;

void Insertsort(int *a,int n){
    //这个循环我想的是可以从第二个元素开始往后移动，因为第一个元素默认是有序区
    for (int i = 1; i < n;i++){
        int temp = a[i];        //每次都需要先把这个元素存到temp里面，相当于就是一个备份吧
        //这个循环我想的是用于把temp和前面每个元素进行比大小，如果大于，就放在后面，小于就放在前面
        int j = i - 1;
        while(j>=0 && temp<a[j]){
            a[j + 1] = a[j];
            j--;
        }
        a[j+1] = temp;
    }
}


int main(){
    int n;
    cin >> n;
    int *a = new int [n];
    for (int i = 0; i < n;i++){
        cin >> a[i];
    }

    Insertsort(a, n);
    for (int i = 0; i < n;i++){
        cout << a[i] << " ";
    }
    cout << endl;

    delete[] a;
    return 0;
}