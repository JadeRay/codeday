#!/usr/bin/env python
# coding = utf-8
import random

def BubbleSort(num):
    n = len(num)
    for i in range(0, n):
        for j in range(i, n):
            if num[i] >= num[j]:
                num[i], num[j] = num[j], num[i] #swap the smallest element to head

    return num

def SelectSort(num):
    n = len(num)
    for i in range(0, n):
        mindex = i
        for j in range(i, n):
            if num[mindex] > num[j]:
                mindex = j
        num[mindex], num[i] = num[i], num[mindex]
    return num



def InsertSort(num):
    n = len(num)
    for i in range(1, n):
        j = i - 1
        tmp = num[i]
        while j >= 0 and tmp < num[j]:
            num[j+1] = num[j]
            j -= 1
        num[j + 1] = tmp
    return num

def MergeSort(num):
    if len(num) <= 1:
        return num
    n = len(num)
    left = MergeSort(num[:n/2])
    right = MergeSort(num[n/2:])
    result = []
    while len(left) > 0 and len(right) > 0:
        if left[0] > right[0]:
            result.append(right.pop(0))
        else:
            result.append(left.pop(0))
    if len(left) > 0:
        result.extend(left)
    else:
        result.extend(right)
    return result


def QuikSort(num):
    if len(num) <= 1:
        return num
    greater = []
    less = []
    p = num.pop(random.randint(0, len(num)-1))
    for item in num:
        if item < p:
            less.append(item)
        else:
            greater.append(item)
    return QuikSort(less)+[p]+QuikSort(greater)



def ShellSort(num):
    n = len(num)
    inc = 0
    while inc <= n/3:
        inc = inc*3 + 1
    inc = (inc - 1)//3
    #print(inc)
    #print num
    while inc>=1:
        for i in range(inc, n):
            tmp = num[i]
            for j in range(i, 0, -inc):          
                if tmp < num[j - inc]:
                    num[j] = num[j - inc]               
                else:
                    j += inc
                    break   
            num[j - inc] = tmp
            #print inc    
            #print num
        inc //= 3
    return num

if __name__ == '__main__':
    print 'hello'
    
    num = [random.randint(1, 100) for i in range(13)]
    print "unsorted list       :", num
    print "Bubble sor list     :", BubbleSort(num)
    num = [random.randint(1, 100) for i in range(13)]
    print "unsorted list       :", num
    print "SelectSort sort list:", SelectSort(num)
    num = [random.randint(1, 100) for i in range(13)]
    print "unsorted list       :", num
    print "InsertSort sort list:", InsertSort(num)
    num = [random.randint(1, 100) for i in range(13)]
    print "unsorted list       :", num
    print "MergeSort sort list :", MergeSort(num)
    num = [random.randint(1, 100) for i in range(13)]
    print "unsorted list       :", num
    print "QuikSort  srot list :", QuikSort(num)
    num = [random.randint(1, 100) for i in range(13)]
    print "unsorted list       :", num
    print "ShellSort  sort list:", ShellSort(num)
