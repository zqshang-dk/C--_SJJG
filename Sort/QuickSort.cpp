#include<iostream>
using namespace std;

void QuickSort(int *a,int left,int right){
    if(left>=right)return;

    int l=left,r=right,temp=a[left];
    while(l<r){
        while(l<r&& a[r]>=temp){
            r--;
        }
        if(l<r)a[l++]=a[r];
        while(l<r &&a[l]<=temp){
            l++;
        }
        if(l<r)a[r--]=a[l];
    }
    a[l]=temp;
    if(left<right){
        QuickSort(a,left,l-1);
        QuickSort(a,l+1,right);
    }
}

int main(){
    int n;

    cout<<"how many nums?"<<endl;
    cin>>n;

    //要先为a数组分配内存
    int *a=new int[n];

    
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    cout<<endl;
    QuickSort(a,0,n-1);
    
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;

    delete []a;
    return 0;
}