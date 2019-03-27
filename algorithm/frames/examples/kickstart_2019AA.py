from __future__ import absolute_import
from __future__ import division
from __future__ import print_function
from __future__ import unicode_literals

import sys
# import resource
# resource.setrlimit(resource.RLIMIT_STACK, [0x100000000, resource.RLIM_INFINITY])
# sys.setrecursionlimit(0x1000000)
# #when you need more memory for function recursion, uncomment above

if sys.version_info[0]==2:
    input=raw_input

def input_int_seq():
    s = input()
    return [int(i) for i in s.split()]

import math

MAXN = int(1e5+10)
MAXM = int(1e5+10)
INF = int(1e9+7)
llINF = 1e18+7
dir4 = [[0,1], [1,0], [0,-1], [-1,0]]
dir8 = [[0,1], [1,1], [1,0], [1,-1], [0,-1], [-1,-1], [-1,0], [-1,1]]
eps = 1e-10

N, M, T, Cases= 0, 0, INF, 0

sys.stdin = open('input.txt', 'r')
sys.stdout = open('output.txt', 'w')

T = int(input())
while(T>0):
    T-=1
    Cases+=1
    N, M = input_int_seq()

    # define your input procedure
    a = input_int_seq()
    a = sorted(a)+[0]
    pre_sum = 0
    ans = llINF
    for i in range(M):
        pre_sum += a[i]
    for i in range(M-1, N):
        if (M*a[i]-pre_sum<ans):
            ans = M*a[i]-pre_sum
        pre_sum += a[i+1]-a[i-M+1]
    
    # define your solution

    print('Case #%d:'%(Cases), ans)
