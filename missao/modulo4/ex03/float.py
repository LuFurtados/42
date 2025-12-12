#!/usr/bin/env python3

# n_01 = float(input("Me de um numero: "))

# if n_01 % 2 == 0:
#     print("Esse numero e um inteiro.")
# else:
#     print("Esse numero e um decimal.")

n = float(input("Me de um numero: "))
if n.is_integer():
    print('Esse numero e um inteiro.')
else:
    print('Esse numero e um decimal')