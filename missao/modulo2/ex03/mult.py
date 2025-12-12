#!/usr/bin/env python3

n_01 = int(input("Enter the first number:"))
n_02 = int(input("Enter the second number:"))

multi = n_01 * n_02

if multi > 0:
    print("The result is positive.")
elif multi < 0:
    print("The result in negative.")
else:
    print("The result is positive and negative.")