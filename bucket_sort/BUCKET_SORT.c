#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int val;
    struct Node* next;
}

/* 把每一个桶的大小划分为10
 * 有n个桶，所以排序数组中不能有元素的值超过 A_len * 10
 */
void BUCKET_SORT(int* A, const int A_len)
{
    int i;
    int n = A_len;
    struct Node B[A_len];
    
    for(i = 0; i < n; i++)
    {
        B[i].val = 10 * i;
        B[i].next = NULL;
    }
    
    for(i = 0; i < n; i++)
        INSERT_INTO(A[i], B[A[i] / 10]);
    
    for(i = 0; i < n; i++)
        A[i] = GET_NUM(B);
}