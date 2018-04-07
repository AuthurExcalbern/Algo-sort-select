#include<stdio.h>

//注意A[0]不应该使用

#define LEFT(i) i*2
#define RIGHT(i) i*2+1
#define swap(a, b, c) {c = a; a = b; b = c;}

/* 假定A[i]左右子树都是最大堆
 * 让A[i]的值在最大堆中逐级下降
 * 从而让下标为i为根节点的子树重新遵循最大堆性质
 * 
 * T(n) <= T(2n/3) + 1
 * T(n) = O(lgn)
 * 所以对树高为h的节点，时间复杂度为O(h)
 */
void MAX_HEAPIFY(int* A, int heap_size, int i)
{
    int l = LEFT(i);
    int r = RIGHT(i);
    int largest;
    int temp;
    
    if(l <= heap_size && A[l] > A[i])
        largest = l;
    else largest = i;
    
    if(r <= heap_size && A[r] > A[largest])
        largest = r;
    
    if(largest != i)
    {
        swap(A[i], A[largest], temp);
        MAX_HEAPIFY(A, heap_size, largest);
    }
}

/* 因为A[n/2 + 1]的元素都是树叶节点
 * 所以从A[n/2]开始建立最大堆
 * 
 * 可以在线性时间内完成
 */
void BUILD_MAX_HEAP(int* A, int A_len)
{
    int i;
    
    for(i = A_len / 2; i > 0; i--)
        MAX_HEAPIFY(A, A_len, i);
}

/* 每次提取出队最大的元素
 * 然后堆大小减一，然后再让A[i]的值在最大堆中逐级下降
 * 
 * 因为调用了(n-1)次 MAX_HEAPIFY O(lgn)
 * 所以时间复杂度为 O(nlgn)
 */
void HEAPSORT(int* A, int A_len)
{
    int heap_size;
    int temp, i;
    
    heap_size = A_len;
    
    BUILD_MAX_HEAP(A, A_len);
    
    for(i = A_len; i > 1; i--)
    {
        swap(A[1], A[heap_size], temp);
        heap_size = heap_size - 1;
        MAX_HEAPIFY(A, heap_size, 1);
    }
}