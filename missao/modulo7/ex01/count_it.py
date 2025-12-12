#!/usr/bin/env python3
import sys

if (len(sys.argv)-1) == 0:
    print("none")
else:
    print ("parameters: ", len(sys.argv)-1) 
    for i, p01 in enumerate(sys.argv[1::]):
        print(f"{p01}: {len(p01)}")
