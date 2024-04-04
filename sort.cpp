#include <iostream>
#include <algorithm>
using namespace std;

//冒泡排序
void BubbleSort(int* arr,int n){
    int end=n-1;    //最后一个元素的索引
    while(end){
        bool flag=false;
        for(int i=1;i<=end;i++){
            if(arr[i-1]>arr[i]){
                swap(arr[i-1],arr[i]);
                flag=true;
            }
        }
        if(flag==false){
            break;
        }
        end--;
    }
}

//选择排序
void selectSort(int* arr,int n){
    int began=0,end=n-1;
    while(began<end){
        int maxi=began;
        int mini=began;
        for(int i=began;i<=end;i++){
            if(arr[i]>arr[maxi])    maxi=i;
            if(arr[i]<arr[mini])    mini=i;
        }
        //交换
        swap(arr[began],arr[mini]);
        if(maxi==began){
            maxi=mini;
        }
        swap(arr[end],arr[maxi]);
        //缩小区间
        began++;
        end--;
    }
}

//插入排序
void InsertSort(int* arr,int n){
    for(int i=0;i<n;i++){
        //记录有序数组的末尾索引
        int end=i;
        //记录待插入元素
        int temp=arr[end+1];
        while(end){
            if(temp<arr[end]){
                arr[end+1]=arr[end];
                arr--;
            }else{
                break;
            }
        }
        arr[end+1]=temp;
    }
}

//快速排序 分治的思想
int part(int* arr,int left,int right){
    int begin=left,end=right,key=left;
    while(begin<end){
        //右面找小
        while(begin<end&&arr[end]>=arr[key]){
            end--;
        }
        //左面找大
        while(begin<end&&arr[begin]<=arr[key]){
            begin++;
        }
        swap(arr[end],arr[begin]);
    }

    swap(arr[end],arr[key]);

    return end;
}
void QuickSort(int* arr,int left,int right){
    if(left>=right){
        return;
    }
    int mid=part(arr,left,right);

    QuickSort(arr,left,mid-1);
    QuickSort(arr,mid+1,right);
}


//排序
int main(){

    int arr[]={1,34,56,3,2,45};
    //selectSort(arr,sizeof(arr)/sizeof(int));
    QuickSort(arr,0,sizeof(arr)/sizeof(int)-1);
    for(int num:arr){
        cout<<num<<" ";
    }
    cout<<endl;
    return 0;
}