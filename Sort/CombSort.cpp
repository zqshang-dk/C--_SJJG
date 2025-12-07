#include<iostream>
using namespace std;

void CombSort(int *a,int n){
    float factor=1.3;
    int gap=n,swapped=1;
    while(gap>1 || swapped){
        gap=gap>1?gap/factor:gap;
        swapped=0;
        int i=0;
        while(i+gap<n){
            int temp;
            if(a[i]>a[i+gap]){
                temp=a[i];
                a[i]=a[i+gap];
                a[i+gap]=temp;
                swapped=1;
            }
            i++;
        }
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
    CombSort(a,n);
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;

    delete []a;
    return 0;
}