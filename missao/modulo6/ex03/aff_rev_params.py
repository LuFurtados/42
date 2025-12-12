#!/usr/bin/env python3
import sys

num_para = (len(sys.argv)-1)

if num_para <= 2:
    print("none")
else:
    for i, arg in enumerate(sys.argv[:0:-1]):
        print(arg)  