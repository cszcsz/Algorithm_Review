#include <iostream>
#include <ctime>
using namespace std;
//TODO:用c++和python实现各种排序算法

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

void output(int nums[],int n)
{
    for(int i=0;i<n;i++)
        cout<<nums[i]<<" ";
    cout<<endl;
}

int data1[5][40000];
int data2[5][40000];
int data3[5][40000];

int main()
{

    clock_t start,finish;
    
    //随机产生待排序数组
    for(int i=0;i<5;i++)
    {
        for(int j=0;j<40000;j++)
        {
            data1[i][j]=data2[i][j]=data3[i][j]=rand()%100;
        }
    }

    // start=clock();
    // for(int i=0;i<5;i++)
    //     BubbleSort(data1[i],40000);
    // finish=clock();
    // cout<<"冒泡排序用时："<<(double)(finish-start)/(CLOCKS_PER_SEC)<<endl;

    start=clock();
    for(int i=0;i<5;i++)
        InsertSort(data2[i],40000);
    finish=clock();
    cout<<"插入排序用时："<<(double)(finish-start)/(CLOCKS_PER_SEC)<<endl;

    // start=clock();
    // for(int i=0;i<5;i++)
    //     SelectSort(data3[i],40000);
    // finish=clock();
    // cout<<"选择排序用时："<<(double)(finish-start)/(CLOCKS_PER_SEC)<<endl;
    // cout<<data2[0]<<" ";
    return 0;
}