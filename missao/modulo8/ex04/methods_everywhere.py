#!/usr/bin/env python3
import sys

def shrink(p01):
    print(p01[0:8])

def enlarge (p01):
    p02 = p01
    x = 8
    npos = len(p02)
    while npos < x:
        p02 += "Z"
        npos += 1
    print(p02)

if (len(sys.argv)-1) < 1:
     print("none")
else:
    for i, arg in enumerate(sys.argv[1::]):
        if len(arg) >= 8:
            shrink(arg)
        else:
            enlarge (arg)