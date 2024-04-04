#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

// 递归
/*
1.明确函数想要什么
2.寻找递归结束条件
3.找出函数的等价关系式
*/

// 1.计算n的阶乘
int f(int n)
{
    return (n == 0 || n == 1) ? 1 : f(n - 1) * n;
}

//2.递归输出
void h(int n){
    if(n==0)    return;
    h(n/10);    //123 入栈顺序 123 12 1
    cout<<n%10<<'-'; //出栈顺序 1 12 123
}

//3.递归倒置字符数组
int n; //记录字符数组的大小
void exchangeArray(char* a,int began,int end){
    if(began>=end)  return;
    swap(a[began],a[end]);

    for(int i=0;a[i]!='\0';i++){
        cout<<a[i];
    }

    cout<<endl;

    exchangeArray(a,began+1,end-1);
}
void exchange(char* a,int m){
    exchangeArray(a,0,m-1);
}

//4.FJ的字符串
string T(int n){
    if(n==1)    
        return "A";
    else    
        return T(n-1)+(char)('A'+n-1)+T(n-1);
}


int main()
{
    cout<<"1 ---------"<<endl;
    h(1234765);
    cout<<endl;
    cout<<"2 ---------"<<endl;
    cout<<T(5);
    cout<<endl;
    cout<<"3 ---------"<<endl;
    char a[]="asdfg";
    exchange(a,strlen(a));

    return 0;
}