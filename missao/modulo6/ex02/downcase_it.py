#!/usr/bin/env python3
import sys

num_para = len(sys.argv)

num_para_total = num_para -1

if num_para_total != 1:
    print("none")
else:
    print(sys.argv[1].lower())