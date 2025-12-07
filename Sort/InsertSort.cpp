#include <iostream>
using namespace std;

void InsertSort(int *a,int n){
    for(int i=1;i<n;i++){
        int temp=a[i];
        int j=i;
        while(j>0&&temp<a[j-1]){
            a[j]=a[j-1];
            j=j-1;
        }
        a[j]=temp;
    }
}

int main(){
    int n;
    cout<<"how many nums?"<<endl;
    cin>>n;

    int *a=new int [n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    
    InsertSort(a,n);

    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
    delete[]a;
    return 0;
}