def swap(a,b):
    temp = a
    a = b 
    b = temp 
    return a,b
def partition (a, l, r):
    x = a[r]
    i = (l - 1)
    for j in range(l,r):
        if a[j] <= x:
            i = i + 1
            a[i],a[j] = swap(a[i], a[j])
    a[i + 1],a[r] = swap(a[i + 1],a[r])
    return i + 1
def Quicksort(a, l, r):
    if l < r:
        p = partition(a, l, r)
        print(p)
        for i in range(l,r+1):
            print(a[i],end=' ')
        print()
        Quicksort(a, l, p - 1)
        Quicksort(a, p + 1, r)
n = int(input())
a = list(map(int,input().split()))
Quicksort(a,0,n-1)
