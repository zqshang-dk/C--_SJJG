#include<iostream>
#include<queue>
using namespace std;

// //再试一下常规数组的写法，看还会不会了！！！！
// void Josephus(int *a,int n,int s,int m){
//     //我好像又忘记常规写法的思路了，我不行了啊！！！
//     for (int i = n ; i >= 1;i--){
//         s = (s + m - 1) % i;
//         int tmp = a[s];
//         for (int j = s+1; j <= i-1;j++){
//             a[j - 1] = a[j];
            
//         }
//         a[i-1] = tmp;
//     }

//     for (int i = 0; i < n/2;i++){
//         int tmp = a[i];
//         a[i] = a[n - i - 1];
//         a[n - i - 1] = tmp;
//     }
// }
//基本写法我完全掌握了，爽！！！！

void Josephus(int *a,int n,int s,int m){      //下面尝试用队列的方法来实现约瑟夫环问题，其实我现在完全没有任何思路啊！
    queue<int> q;  //还是那个问题，我建立的队列有什么作用，应该存放什么东西？
    //是不是要把淘汰的数直接放入队列？——ohno并非啊
    //现在有一个这样的好思路：
    //每次都更新s值，让q从s开始开始存储
    //之后，每次操作都是将前m-1个元素从队首移到队尾，再把第m个元素放在数组a中！！！！！妙！
    int count = 0;
    for (int i = 0; i < n;i++){
        q.push(a[(s + i) % n]);
    }
    //这个地方的循环没有设置正确！！！
    while(!q.empty()){
         for (int i = 0; i < m - 1; i++){
            q.push(q.front());
            q.pop();
        }
        a[count++] = q.front();
        q.pop();
    }
   
    
}



int main(){
    int n;
    cin >> n;

    int *a = new int[n];
    for (int i = 0; i < n;i++){
        cin >> a[i];
    }
    int s, m;
    cin >> s;
    cin >> m;
    Josephus(a, n, s, m);
    for (int i = 0; i < n; i++){
        cout << a[i] << " ";
    }
    cout << endl;
    delete[] a;

    return 0;
}