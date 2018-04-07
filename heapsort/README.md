# Heapsort

- 堆排序：
    + O(nlgn)
    + 空间原址性

- 构造：
    + `MAX-HEAPIFY` O(lgn)，维护最大堆性质的关键
    + `BUILD-MAX-HEAP` O(n)，对一个数组构造最大堆
    + `HEAPSORT` O(nlgn)，对一个数组进行原址排序
    + `MAX-HEAP-INSERT/HEAP-EXTRACT-MAX/HEAP-INCREASE-KEY/HEAP-MAXIMUN` O(lgn)，用堆实现优先队列

- 优先队列
    + INSERT(S, x) 把x插入集合S中
    + MAXIMUN(S) 返回S中具有最大关键字的元素
    + EXTRACT-MAX(s) 去掉并返回S中具有最大关键字的元素
    + INCREASE-KEY(S, x, k) 将x的关键值增加到k