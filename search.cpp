#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

//二分查找
int binarySearch(const vector<int>& nums,int target){
    int n=nums.size();
    int left=0,right=n-1;
    while(left<=right){
        int mid=(left+right)/2;
        if(target<=nums[mid]){
            right=mid-1;
        }else{
            left=mid+1;

        }
    }
    return left;
}

int main(){
    vector<int> nums={1,2,3,4,5,6,7,8,9};
    int flag=binarySearch(nums,8);
    cout<<flag;
    return 0;
}