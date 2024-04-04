#include <iostream>
using namespace std;
//字符串比较
void strncmp(const char* s,const char* t,int n){
    for(int i=0;i<n;i++){
        if(s[i]!=t[i]){
            cout<<(s[i]>t[i]?1:-1);
            return;
        }
    }
    cout<<0;
}

//字符串练习
void stringText(){

    string str="hello world";
    str.append(" haha",4);
    string copystr=str.substr(0,3); //截取子字符串
    str.compare(copystr);   //比较字符串

    cout<<copystr<<endl;    
}
int main(){

    stringText();
    return 0;
}