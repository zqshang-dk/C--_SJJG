// P1114 “非常男女”计划
// 题目描述
//这种选择方式实现起来很简单。他让学校的所有人按照身高排成一排，然后从中选出连续的若干个人，
//使得这些人中男女人数相等。为了使活动更热闹，`XXX` 当然希望他能选出的人越多越好。
// 请编写程序告诉他，他最多可以选出多少人来。
// ## 输入格式
// 第一行有一个正整数 n,代表学校的人数。
// 第二行有 n个用空格隔开的数，这些数只能是 0 或 1，其中,0代表是一个女生，1代表是一个男生。
// ## 输出格式
// 输出一个非负整数。这个数表示在输入数据中最长的一段男女人数相等的子区间的长度。
// 如果不存在男女人数相等的子区间，请输出0。
// ## 输入输出样例 #1
// ### 输入 #1
// 9
// 0 1 0 0 0 1 1 0 0
// ### 输出 #1
// 6

// #include<iostream>
// using namespace std;

// int main(){
//     int n;
//     cin >> n;

//     int *a = new int[n];

//     for (int i = 0; i < n;i++){
//         cin >> a[i];
//     }

//     int count_m = 0;
//     int count_f = 0;

//     for (int i = 0; i < n;i++){
//         if(a[i]==0){
//             count_f += 1;
//         }
//         else if(a[i]==1){
//             count_m += 1;
//         }
//     }

//     if (count_m == 0 || count_f == 0){
//         cout<< 0;
//     }
//     else if(count_m>=count_f){
//         cout << count_f * 2;
//     }
//     else if(count_m<count_f){
//         cout << count_m * 2;
//     }
//     return 0;
// }

//标答

#include<iostream>
#include<algorithm>
using namespace std;

int l[200010], r[200010], sum1, sum0, ans, n;
int main(){
    cin >> n;
    for (int i = 0; i < n;i++){
        int x;
        cin >> x;

        sum1 += (x == 1);
        sum0 += (x == 0);

        int t = sum0 - sum1 + n;
        if(!l[t] && t!=n){
            l[t] = i;
        }
        else{
            r[t] = i;
        }
    }

    for (int i = 0; i < 2 * n; i++){
        ans = max(ans, r[i] - l[i]);
    }
    cout << ans<< endl;
    return 0;
}