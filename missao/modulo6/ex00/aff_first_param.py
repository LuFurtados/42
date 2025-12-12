#!/usr/bin/env python3
import sys

num_para = len(sys.argv)

num_para_total = num_para -1

if num_para_total >= 1:
    primeiro_arg = sys.argv[1]
    print(primeiro_arg)
else:
    print("none")