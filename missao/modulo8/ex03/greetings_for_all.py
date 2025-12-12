#!/usr/bin/env python3

def greetings(p01 = "noble stranger"):
    if isinstance(p01,str) == True:
        print(f"Hello, {p01}.")
    else:
        print('Error! It was not a name.')

greetings('Alexandra')
greetings('Wil')
greetings()
greetings(42)