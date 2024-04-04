#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <array>
using namespace std;
//题目链接 https://www.luogu.com.cn/paste/vjf2z3hi

#if 0
// 跳台阶
int f(int n)
{
    if (n < 3)
        return n; // 一个台阶有一种，两个台阶有两种，没有台阶返回0
    return f(n - 1) + f(n - 2);
}

// 递归实现指数型枚举
// DFS最重要的是顺序
const int N = 20;

int n;
int st[N]={}; // 记录元素的状态 0表示还没考虑 1表示选择这个数 2表示不选这个数


void dfs_index(int x){    //x为当前枚举到的位置
    if(x>n){
        for(int i=1;i<=n;i++){
            if(st[i]==1){
                cout<<i<<' ';
            }
        }
        cout<<endl;
        return;
    }

    //选
    st[x]=1;
    dfs_index(x+1);
    st[x]=0;    //恢复现场

    //不选
    st[x]=2;
    dfs_index(x+1);
    st[x]=0;
}
#endif

#if 0
//递归实现排列型枚举
const int N = 20;

int n;
bool st[N]={};  //true表示已经选了这个数 false表示没有选这个数
int arr[N]={};

void dfs_arrange(int x){    //x表示枚举到了哪一个位置
    if(x>n){
        for(int i=1;i<=n;i++){
            cout<<arr[i];
        }
        cout<<endl;
        return;
    }
    for(int i=1;i<=n;i++){
        if(!st[i]){
            st[i]=true;
            arr[x]=i;
            dfs_arrange(x+1);
            st[i]=false;
            arr[x]=0;

        }
    }
}
#endif

#if 0
//递归实现组合型枚举
//顺序 依次枚举1-n每位置放哪个数
const int N = 20;

int n,r; 
int arr[N]={};
void dfs(int x,int start){  //x为当前位置 start为当前数的位置
    if(x>r){    //控制归的条件
        for(int i=1;i<=r;i++){
            printf("%3d",arr[i]);
        }
        cout<<endl;
        return;
    }
    for(int i=start;i<=n;i++){
        arr[x]=i;
        dfs(x+1,i+1);
        arr[x]=0;
    }
}
#endif

#if 0
//P1036 选数
const int N=30;

int n,r;
int nums[N]={3,7,12,19};
int _count=0;    //计数
int arr[N]={}; //记录选择结果

bool ifPrim(int sum){
    //当 n 小于等于 1 时，其定义范围通常是自然数集合，而素数的定义范围是大于 1 的自然数
    if(sum<2)   return false;
    //如果在 2 到 sqrt(sum) 的范围内没有找到能整除 sum 的因数，则 sum 是素数
    for(int i=2;i<=sum/i;i++){
        if(sum%i==0){
            return false;
        }
    }

    return true;
}
void dfs(const int* nums,int x,int start){  //x为位置 start为当前开始枚举的数
    //枝剪 已选的数+还可以选的数小于空时 返回
    if(x-1+n-start+1<r) return; 
    
    if(x>r){
        int sum=0;
        for(int i=1;i<=r;i++){

            cout<<nums[arr[i]-1]<<" ";   //打印所有的结果
            sum+=nums[arr[i]-1];
        }
        cout<<endl;
        if(ifPrim(sum))  _count++;

        return;
    }
    for(int i=start;i<=n;i++){

        arr[x]=i;
        dfs(nums,x+1,i+1);
        arr[x]=0;
    }
}
void text(){

    cout<<"import: ";
    cin >> n >>r;
    // for(int i=0;i<n;i++){
    //     cout<<"import number "<<i+1<<": "<<endl;
    //     cin>>nums[i];
    // }
    dfs(nums,1,1); //从第一个数开始
    printf("%d",_count);
}
#endif

#if 0
//烤鸡  指数
int n;  // 总的克数
const int N = 10; // 调料的种类数量
std::array<int, N> arr = {}; // 记录每种调料的克数，0为不选，1,2,3表示不同的克数
std::vector<decltype(arr)> v; // 记录总的方案
int numCount = 0; // 记录方案个数

void dfs(int x) { // x为当前调料种类

    if (x >= N) {
        int sum = 0;
        for (int i = 0; i < N; i++) {
            sum += arr[i];
        }
        if (sum == n) {
            numCount++;
            v.push_back(arr);
        }
        return;
    }

    arr[x] = 1;
    dfs(x + 1);
    arr[x] = 0;

    arr[x] = 2;
    dfs(x + 1);
    arr[x] = 0;

    arr[x] = 3;
    dfs(x + 1);
    arr[x] = 0;
}

void test() {
    std::cout << "input: ";
    std::cin >> n;
    dfs(0); // 从第一个调料开始
    std::cout << numCount << std::endl;
    for (const auto& it : v) {
        for (int i = 0; i < N; i++) {
            std::cout << it[i] << " ";
        }
        std::cout << std::endl;
    }
}
#endif

#if 1
//火星人 全排列
const int N=10000;
int n;  //指头数
int m;  //要加上去的小整数
int res;
array<int,N> _arr;   //外星人的表示
array<int,N> arr;   //记录方案
array<bool,N> st;  //true表示已经选了这个数 false表示没有选这个数
void dfs(int x){

    if(res==m+1)    return;
    if(x>=n){
        res++;
        if(res==m+1){
           for (auto it = arr.begin(); it != arr.begin() + 5;it++) {
                printf("%d ", *it);
            }
        }
        return;
    }
    for(int i=1;i<=n;i++){
        if(res==0){
            i=_arr[x];
        }
        if(!st[i]){
            arr[x]=i;
            st[i]=true;
            dfs(x+1);
            arr[x]=0;   //恢复状态
            st[i]=false;            
        }
    }
}

void test(){
    cout<<"import: ";
    cin>>n>>m;
    cout<<endl;
    

    for(int i=0;i<n;i++){
        cout<<"import "<<i+1<<" number: ";
        cin>>_arr[i];
        cout<<endl;
    }
    dfs(0);   //从第一个数开始枚举
}
#endif


int main(){
    
    test();
    return 0;
}