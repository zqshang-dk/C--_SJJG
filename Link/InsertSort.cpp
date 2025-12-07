#include<iostream>
using namespace std;

// void InsertSort(int *a,int n){
//     int tmp;
//     for (int i = 1; i < n; i++){
//         tmp = a[i];
//         int j = i - 1;

//         while(j>=0 && tmp<a[j]){
//             a[j + 1] = a[j];
//             --j;
//         }
//         a[j + 1] = tmp;
//     }
// }

void InsertSort(int *a,int n){
    int tmp;
    for (int i = 1; i < n;i++){
        tmp = a[i];
        int j = i - 1;
        while(j>=0 && tmp<a[j]){
            a[j + 1] = a[j];
            --j;
        }
        a[j + 1] = tmp;
    }
}