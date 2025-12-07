//先给我记住一句话：希尔排序是对直接插入排序的优化！！！！
//这也就意味着，主要还是要掌握插入排序的逻辑
#include<iostream>
using namespace std;

// void ShellSort(int *a ,int n){
//     int gap = n ;
//     while(gap > 1){
//         gap = gap / 1.3;
//         if(gap<1){
//             gap = 1;
//         }
//         for (int i = gap; i < n;i++){
//             int temp = a[i];
//             int j=i-gap;
//             while(j>=0 && temp<a[j]){
//                 a[j + gap] = a[j];
//                 j -= gap;
//             }
//             a[j + gap] = temp;
//         }
//     }
// }

void ShellSort(int *a,int n){
    int gap = n;
    while(gap>1){
        gap = gap / 1.3;
        if(gap<1){
            gap = 1;
        }
        for (int i = gap; i < n;i++){
            int tmp = a[i];
            int j = i-gap;
            while(j>=0 && tmp<a[j]){
                a[j + gap] = a[j];
                j -= gap;
            }
            a[j + gap] = tmp;
        }
    }
}













int main(){
    int n;
    cin >> n;
    int *a = new int [n];
    for (int i = 0; i < n;i++){
        cin >> a[i];
    }

    ShellSort(a, n);
    for (int i = 0; i < n;i++){
        cout << a[i] << " ";
    }
    cout << endl;

    delete[] a;
    return 0;
}