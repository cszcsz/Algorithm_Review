#include <iostream>
#include <algorithm>
#include <ctime>
using namespace std;

// 1.冒泡排序
// 时间复杂度:最好-O(n),最坏-O(n^2)，平均-O(n^2)  
// 空间复杂度:O(1)
// 稳定排序
void BubbleSort(int nums[],int n)
{
    bool flag;
    for(int i=0;i<n;i++)
    {
        flag=true;
        for(int j=0;j<n-i-1;j++)
        {
            if(nums[j]>nums[j+1])
            {
                flag=false;
                int temp = nums[j];
                nums[j]=nums[j+1];
                nums[j+1]=temp;
            }
        }
        if(flag)
            break;
    }
}


// 2.插入排序
// 时间复杂度:最好-O(n),最坏-O(n^2)，平均-O(n^2)  
// 空间复杂度:O(1)
// 稳定排序
void InsertSort(int nums[],int n) 
{
    // 初始化：假定一个元素是已排序区间，之后的元素为未排序区间
    for(int i=1;i<n;i++)
    {
        int tmp = nums[i],j;
        for(j=i-1;j>=0;j--)
        {
            if(tmp>=nums[j])
                break;
            else
                nums[j+1]=nums[j];
        }
        nums[j+1]=tmp;
    }
    
}

// 3.选择排序
// 时间复杂度:最好-O(n^2),最坏-O(n^2)，平均-O(n^2)  
// 空间复杂度:O(1)
// 不稳定排序
void SelectSort(int nums[],int n)
{
    for(int i=0;i<n;i++)
    {
        int tempMin=nums[i],index=i;
        for(int j=i+1;j<n;j++)
        {
            if(nums[j]<tempMin)
            {
                tempMin=nums[j];
                index=j;
            }
        }
        nums[index]=nums[i];
        nums[i]=tempMin;
    }
}

// 4.归并排序
// 时间复杂度：
// 空间复杂度：
// 稳定性：
// 递推式：sort(p,q) = merge(sort(p,r),sort(r+1,q))  边界条件:p>=q
void Merge(int nums[],int p,int q,int r);
void MergeSortR(int nums[],int p,int q)
{
    if(p>=q)
        return;
    int r = (p+q)/2;
    MergeSortR(nums,p,r);
    MergeSortR(nums,r+1,q);
    Merge(nums,p,q,r);

}

//把nums[p...r]和nums[r+1,q]合并到nums[p...q]
void Merge(int nums[],int p,int q,int r)
{
    int n=q-p+1,i=p,j=r+1,k=0;
    int *tmp = new int[n];
    //二路归并
    while (i<=r&&j<=q)
    {
        if(nums[i]<=nums[j])
            tmp[k++]=nums[i++];
        else
            tmp[k++]=nums[j++];
    }
    //把其中一个剩余的数组中的数搬到临时数组中
    int start=i,end=r;
    if(j<=q)
    {
       start=j;
       end=q;  
    }
    while (start<=end)
        tmp[k++]=nums[start++];
    //将tmp临时数组拷贝回nums数组
    for(int t=0;t<=q-p;t++)
        nums[p+t]=tmp[t];
    delete tmp;
}

void MergeSort(int nums[],int n)
{
    MergeSortR(nums,0,n-1);
}

void output(int nums[],int n)
{
    for(int i=0;i<n;i++)
        cout<<nums[i]<<" ";
    cout<<endl;
}

int data1[5][40000];
int data2[5][40000];

int main()
{
    int data0[10] = {8,2,1,3,4,9,6,5,7,10};
    clock_t start,finish;
    // MergeSort(data0,10);
    // output(data0,10);

    
    //随机产生待排序数组
    for(int i=0;i<5;i++)
    {
        for(int j=0;j<40000;j++)
        {
            data1[i][j]=data2[i][j]=rand()%100;
        }
    }

    start=clock();
    for(int i=0;i<5;i++)
        MergeSort(data1[i],40000);
    finish=clock();
    cout<<"归并排序用时："<<(double)(finish-start)/(CLOCKS_PER_SEC)<<"秒"<<endl;

    start=clock();
    for(int i=0;i<5;i++)
        InsertSort(data2[i],40000);
    finish=clock();
    cout<<"插入排序用时："<<(double)(finish-start)/(CLOCKS_PER_SEC)<<"秒"<<endl;


    return 0;
}