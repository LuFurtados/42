#!/usr/bin/env python3
import sys

def downcase_it(p01):
    return p01.lower()

if (len(sys.argv)-1) < 1:
     print("none")
else:
    for i, arg in enumerate(sys.argv[1::]):
        print (downcase_it(arg))
