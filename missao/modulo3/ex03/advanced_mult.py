#!/usr/bin/env python3

x = 0
while x <= 10:
    tab = [i*x for i in range(11)]
    print(f'Table of {x}: {tab}')
    tab = []
    x += 1 
