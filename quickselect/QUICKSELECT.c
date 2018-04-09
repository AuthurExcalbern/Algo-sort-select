#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define swap(a, b, c) {c = a; a = b; b = c;}

//初始化随机种子,应该放在主函数中
/*
time_t t;
srand((unsigned)time(&t));
*/


//实现了对A[p..r]的原址重排
//选择一个主元A[r]，然后围绕它来划分数组
//返回的是划分后主元在数组里的位置
//即会返回第 i+1 小的数字
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
//主元在数组为第x小，则返回x
int RANDOMIZED_PARTITION(int* A, int p, int r)
{
    int temp;
    int i = rand() % (r-p+1) + p;
    
    swap(A[r], A[i], temp)
    
    return PARTITION(A, p, r);
}

//返回数组A[p..r]中第i小的元素
int RANDOMIZED_SELECT(int* A, int p, int r, int i)
{
    if(p == r)
        return A[p];
    
    //A[q] 为第 k 小的数字，其左边都比他小，右边都比他大
    //k = q - p + 1
    int q = RANDOMIZED_PARTITION(A, p, r);
    int k = q - p + 1;
    
    //如果 i == k ，则已经得到我们想要的数字，直接返回
    if(i == k)
        return A[q];
    //如果 i < k ，则我们要求的数字在 k 的左边
    //且在 k 的左边，我们所求的数字仍为第 i 小
    else if(i < k)
        return RANDOMIZED_SELECT(A, p, q-1, i);
    //如果数字在 k 的右边，则应该为第 i-k 小
    else
        return RANDOMIZED_SELECT(A, q+1, r, i-k);
}