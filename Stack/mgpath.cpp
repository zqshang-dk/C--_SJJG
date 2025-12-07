//迷宫问题
#include<iostream>
#include<stack>
#include<vector>
#include<algorithm>  // 添加 reverse 函数需要的头文件
using namespace std;

struct Box{
    int i;
    int j;
    int di;
    Box(){}
    Box(int i1, int j1, int d1) : i(i1),j(j1),di(d1){}
};

void disppath(stack<Box> &st);  // 添加函数声明

bool mgpath(int xi,int yi,int xe,int ye){    //从(xi,yi)到(xe,ye)找一条迷宫路径
    int MAX = 4;
    int mg[MAX][MAX] = {{0, 1, 0, 0}, {0, 0, 1, 1}, {0, 1, 0, 0}, {0, 0, 0, 0}};
    int m = MAX, n = MAX;  // 初始化 m 和 n
    int dx[] = {-1, 0, 1, 0};
    int dy[] = {0, 1, 0, -1};
    int i, j, di, i1, j1;
    bool find;
    Box b, b1;
    stack<Box> st;
    b = Box(xi, yi, -1);
    st.push(b);
    mg[xi][yi] = -1;
    while(!st.empty()){
        b = st.top();
        if(b.i==xe && b.j==ye){
            disppath(st);
            return true;
        }
        find = false;
        di = b.di;
        while (di < 3 && find == false){
            di++;
            i = b.i + dx[di];  // 使用 dx 和 dy 数组
            j = b.j + dy[di];  // 修正：这里原来是 dx[di]，应该是 dy[di]
            if (i >= 0 && i < m && j >= 0 && j < n && mg[i][j] == 0){
                find = true;
            }
        }
        if(find){
            st.top().di = di;
            b1 = Box(i, j, -1);
            st.push(b1);
            mg[i][j] = -1;
        }
        else{
            mg[b.i][b.j] = 0;
            st.pop();
        }
    }
    return false;
}

void disppath(stack<Box> &st){
    Box b;
    vector<Box> apath;
    while(!st.empty()){
        b = st.top();
        st.pop();
        apath.push_back(b);
    }
    reverse(apath.begin(), apath.end());

    cout << "一条迷宫路径" << endl;
    for (int i = 0; i < apath.size();i++){
        cout << "[" << apath[i].i << "," << apath[i].j << "]";
        if (i < apath.size() - 1) {
            cout << " -> ";
        }
    }
    cout << endl;
}

int main() {
    // 测试代码
    if (mgpath(0, 0, 3, 3)) {
        cout << "找到路径！" << endl;
    } else {
        cout << "未找到路径！" << endl;
    }
    return 0;
}