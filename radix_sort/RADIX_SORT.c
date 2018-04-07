#include<stdio.h>
#include<math.h>
#include<string.h>

#define swap(a, b, c) {c = a; a = b; b = c;}
#define GET_POS(i, pos) ((i % (int)pow(10, pos)) / (int)pow(10, pos-1))

//A为输入数组，B数组为排序后的输出数组，C为临时储存数组
//len 为需要排序数组的长度
//数组里所有元素的值x : 0 <= x <= k
void COUNTING_SORT(int* A, int* B, const int len, const int k, const int pos)
{
    int i;
    int C[k+1];
    
    memset(C, 0, sizeof(C));
    
    //对需排序数组的值进行计数
    for(i = 0; i < len; i++)
        C[GET_POS(A[i], pos)] = C[GET_POS(A[i], pos)] + 1;
    
    //计算小于等于i的元素个数
    for(i = 1; i <= k; i++)
        C[i] = C[i] + C[i-1];
    
    //因为C记录了小于等于GET_POS(A[i], pos)的元素个数x
    //所以可以将值为GET_POS(A[i], pos)的元素放到第x位上，即为B[x-1](因为要计入0
    //然后C的小于等于GET_POS(A[i], pos)的元素个数要减一： x = x - 1
    for(i = len-1; i >= 0; i--)
    {
        B[C[GET_POS(A[i], pos)]-1] = A[i];
        C[GET_POS(A[i], pos)] = C[GET_POS(A[i], pos)] - 1;
    }
}

void RADIX_SORT(int* A, int* B, const int len, int d)
{
    int i,j;
    int* C;
    
    for(i = 1; i <= d; i++)
    {
        COUNTING_SORT(A, B, len, 9, i);
        swap(A, B, C);
    }
}