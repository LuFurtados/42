#!/usr/bin/env python3

n_01 = [2,8,9,48,8,22,-12,2]
print(f"Original array: {n_01}")

n_01_new = [] 
            
for i in n_01:
    if i > 5:
        n_01_new.append(i+2)

n_02_new = set(n_01_new)
print(f"New array: {n_02_new}")