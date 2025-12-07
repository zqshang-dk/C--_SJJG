#include<iostream>
using namespace std;

// void BubbleSort(int *a,int n){
//     //这第一个循环，我的想法是，相当于是在遍历整个数组
//     for (int i = 0; i < n-1;i++){
//         //这第二个循环，相当于是
//         for (int j = i; j < n;j++){
//             if(a[j]>a[j+1]){
//                 int temp = a[j];
//                 a[j] = a[j + 1];
//                 a[j + 1] = temp;
//             }
//         }
//     }
// }

//我去，犯大错了，对冒泡法的理解完全有误啊！！！
//冒泡法，是说每次把最大的项移到最后，所以每次应该都是从头开始，而不是从中间元素开始，真是晕了！！
void BubbleSort(int *a,int n){
    for (int i = 0; i < n - 1;i++){
        for (int j = 0; j < n - i - 1;j++){
            if(a[j]>a[j+1]){
                int tmp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = tmp;
            }
        }
    }
}

int main(){
    int n;
    cin >> n;

    int *a = new int[n];
    for (int i = 0; i < n;i++){
        cin >> a[i];
    }

    BubbleSort(a, n);
    for (int i = 0; i < n;i++){
        cout << a[i] << " ";
    }

    cout << endl;
    delete[] a;
    return 0;
}