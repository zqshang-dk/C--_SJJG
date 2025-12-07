//堆排序
#include<iostream>
using namespace std;

void heapSort(int *a,int n){
    for (int i = n / 2 - 1; i >= 0;i--){
        int p = i;
        int tmp = a[i];

        while((2*p+1)<n){
            int child = 2 * p + 1;

            if(2*p+2<n && a[2*p+2]>a[2*p+1]){
                child += 1;
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
    cout << endl;

    for (int i = n - 1; i > 0;i--){
        int tmp1 = a[0];
        a[0]=a[i];
        a[i]=tmp1;

        int p=0;
        int tmp = a[0];
        while((2*p+1)<i){
            int child = 2 * p + 1;
            if((child+1)<i && a[child+1]>a[child]){
                child += 1;
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

        for (int j = 0; j < n;j++){
            cout << a[j] << " ";
        }
        cout << endl;
    }
}

int  main(){
    int n;
    cin >> n;
    int *arr = new int[n];

    for (int i = 0; i < n;i++){
        cin >> arr[i];
    }
    heapSort(arr, n);
    delete[] arr;
    return 0;
}