#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define swap(a, b, c) {c = a; a = b; b = c;}

//初始化随机种子
time_t t;
srand((unsigned)time(&t));

//实现了对A[p..r]的原址重排
//选择一个主元A[r]，然后围绕它来划分数组
//返回的是划分后主元在数组里的位置
int PARTITION(int* A, int p, int r)
{
    int j, temp;
    
    int x = A[r];
    int i = p - 1;
    
    //j代表最新一个未检查的元素位置
    //i代表最后一个比主元小的元素位置
    for(j = p; j < r; j++)
    {
        if(A[j] <= x)
        {
            i = i + 1;
            swap(A[i], A[j], temp);
        }
    }
    swap(A[i+1], A[r], temp);
    
    return i + 1;
}

//随机选择一个元素，并作为主元
int RANDOMIZED_PARTITION(int* A, int p, int r)
{
    int temp;
    int i = rand() % (r-p+1) + p;
    
    swap(A[r], A[i], temp)
    
    return PARTITION(A, p, r);
}

//以分治的方法，依靠主元来进行快速排序
void RANDOMIZED_QUICKSORT(int* A, int p, int r)
{
    int q;
    
    if(p < r)
    {
        q = RANDOMIZED_PARTITION(A, p, r);
        RANDOMIZED_QUICKSORT(A, p, q-1);
        RANDOMIZED_QUICKSORT(A, q+1, r);
    }
}

