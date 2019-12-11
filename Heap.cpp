#include <bits/stdc++.h>
using namespace std;

class MinHeap
{
public:
    int *data;
    int count;

public:
    void Build(int a[], int n); // O(n)
    void Insert(int x);         //O(logn)
    void DeleteMin();           // O(logn)
    int GetMin();               // O(1)
    ~MinHeap() { delete data; }
private:
    void Heapify(int i);
};

void MinHeap::Build(int a[], int n)
{
    data = new int[n + 1];
    count = n;
    int i;
    for (i = 0; i < n; i++)
        data[i + 1] = a[i];
    for (i = n / 2; i >= 1; i--)
        Heapify(i);
}

void MinHeap::Heapify(int i)  //自上而下堆化
{
    while (true)
    {
        int minIndex = i;
        if (2 * i <= count && data[2 * i] < data[minIndex])
            minIndex = 2 * i;
        if (2 * i + 1 <= count && data[2 * i + 1] < data[minIndex])
            minIndex = 2 * i + 1;
        if (i == minIndex)
            break;
        swap(data[i], data[minIndex]);
        i = minIndex;
    }
}

int MinHeap::GetMin()
{
    if (count > 0)
        return data[1];
    else
        return -999;
}

void MinHeap::DeleteMin()
{
    swap(data[1], data[count]);
    count--;
    Heapify(1);
}

void MinHeap::Insert(int x)
{
    data[++count] = x;
    int i = count;
    while (i / 2 >= 1 && data[i] < data[i / 2])
    {
        swap(data[i], data[i / 2]);
        i /= 2;
    }
}

int main()
{
    int array[10] = {2, 1, 3, 4, 10, 9, 7, 5, 6, 8};
    MinHeap heap;
    heap.Build(array, sizeof(array) / sizeof(int));
    while (heap.count > 0)
    {
        cout << heap.GetMin() << " ";
        heap.DeleteMin();
    }
    return 0;
}