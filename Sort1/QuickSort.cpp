//快速排序中，我们一般会选取第一个元素作为基准，一个个地把每个元素移动到相应的位置上
// 在这个算法中，还主要需要体会递归的思想

//再提醒一个地方，这个快速排序使用的需要的参数和其他的是不太一样的！！


#include<iostream>
using namespace std;

void QuickSort(int *a,int n){
    if(n<=1)
        return;
    
    int temp = a[0];  //把a[0]作为基准，先把a[0]移动到它对应的位置上面
    int l = 0;
    int r = n - 1;
    while(l<r){
        while(l<r&&a[r]>temp){
            r--;
        }
        if(l<r){
            a[l] = a[r];
            l++;
        }
        
        while(l<r && a[l]<=temp){
            l++;
        }
        if(l<r){
            a[r] = a[l];
            r--;
        }
        
    }
    a[l] = temp;
    QuickSort(a, l);
    QuickSort(a + l + 1, n - l - 1);
}

int main(){
    int n;
    cin >> n;
    int *a = new int[n];
    for (int i = 0; i < n;i++){
        cin >> a[i];
    }

    QuickSort(a, n);
    for (int i = 0; i < n;i++){
        cout << a[i] << " ";
    }
    cout << endl;
    delete[] a;

    return 0;
}