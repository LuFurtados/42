#!/usr/bin/env python3

n_01 = int(input("Enter a number less than 25: "))

if n_01 <= 25:
    while n_01 <= 25:
        print(f"Inside the loop, my variable is {n_01}")
        n_01 += 1
else:
    print("Error")
