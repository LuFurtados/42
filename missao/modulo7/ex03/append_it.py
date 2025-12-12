#!/usr/bin/env python3
import sys

if (len(sys.argv)-1) < 1:
     print("none")
else:
    for i, arg in enumerate(sys.argv[1::]):
        if arg.find("ism") == -1:
            print(f'{arg}ism') 