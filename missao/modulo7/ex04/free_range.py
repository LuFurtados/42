#!/usr/bin/env python3
import sys
import re

num_para = (len(sys.argv)-1)

if num_para == 2:
    n01 = int((sys.argv[1]))
    n02 = int((sys.argv[2]))

if num_para != 2:
    print("none")
elif n01 > n02:
    print("O primeiro número deve ser estritamente menor que o segundo")
elif n01 == n02:
    print("none")
else:
    print(list(range(n01,n02+1)))
