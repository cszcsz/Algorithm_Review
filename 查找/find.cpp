#include <bits/stdc++.h>

using namespace std;

// 二分查找：在互不相同的一组有序数中查找给定值元素(最基本的形态)
int BinarySearch(int nums[],int val,int lo,int hi)
{
    if(lo>hi)
        return -1;
    int mid = lo + ((hi-lo)>>1);
    if(val==nums[mid])
        return mid;
    else if(val<nums[mid])
        hi = mid-1;
    else if(val>nums[mid])
        lo = mid+1;
    return BinarySearch(nums,val,lo,hi);
}

// 二分查找变体1：在一组有序数中,查找第一个等于给定值的元素
int FindFirstEquVal(int nums[],int val,int lo,int hi)
{
    if(lo>hi)
        return -1;
    int mid = lo + ((hi-lo)>>1);
    if(val<nums[mid])
        hi = mid-1;
    else if(val>nums[mid])
        lo = mid+1;
    else
    {
        if(mid==lo||nums[mid-1]!=val)
            return mid;
        else
            hi = mid-1;
    }
    return FindFirstEquVal(nums,val,lo,hi);
}

// 二分查找变体2：在一组有序数中,查找最后一个等于给定值的元素
int FindLastEquVal(int nums[],int val,int lo,int hi)
{
    if(lo>hi)
        return -1;
    int mid = lo + ((hi-lo)>>1);
    if(val<nums[mid])
        hi = mid-1;
    else if(val>nums[mid])
        lo = mid+1;
    else
    {
        if(mid==hi||nums[mid+1]!=val)
            return mid;
        else
            lo = mid+1;
    }
    return FindFirstEquVal(nums,val,lo,hi); 
}

// 二分查找变体3：在一组有序数中,查找第一个大于等于给定值的元素
int FindFirstGreatThanVal(int nums[],int val,int lo,int hi)
{
    if(lo>hi)
        return -1;
    int mid = lo + ((hi-lo)>>1);
    if(val>nums[mid])
        lo = mid+1;
    else
    {
        if(mid==lo||nums[mid-1]<val)
            return mid;
        else
            hi = mid-1; 
    }
    return FindFirstGreatThanVal(nums,val,lo,hi);
}

// 二分查找变体4：在一组有序数中,查找最后一个小于等于给定值的元素
int FindLastSmallThanVal(int nums[],int val,int lo,int hi)
{
    if(lo>hi)
        return -1;
    int mid = lo + ((hi-lo)>>1);
    if(val<nums[mid])
        hi = mid-1;
    else
    {
        if(mid==hi||nums[mid+1]>val)
            return mid;
        else
            lo = mid+1;
    }
    return FindLastSmallThanVal(nums,val,lo,hi);
}

int main()
{
    int nums[10]={1,2,2,3,3,3,7,7,9,10};
    int first_index = FindFirstEquVal(nums,3,0,sizeof(nums)/sizeof(int)-1);
    cout<<first_index<<endl;
    int last_index = FindLastEquVal(nums,3,0,sizeof(nums)/sizeof(int)-1);
    cout<<last_index<<endl;
    int i1,i2;
    i1 = FindFirstGreatThanVal(nums,6,0,sizeof(nums)/sizeof(int)-1);
    cout<<i1<<endl;
    i2 = FindLastSmallThanVal(nums,6,0,sizeof(nums)/sizeof(int)-1);
    cout<<i2<<endl;
    return 0;
}

