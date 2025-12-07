#include<iostream>
using namespace std;

void ShellSort(int *a,int n){
    int gap=n/1.3;
    while(gap>0){
        for(int i=gap;i<n;i++){
            int temp=a[i];
            int j=i;
            while(j-gap>=0&&temp<a[j-gap]){
                a[j]=a[j-gap];
                j=j-gap;
            }
            a[j]=temp;
        }
        gap/=1.3;
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
    ShellSort(a,n);
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;

    delete []a;
    return 0;
}