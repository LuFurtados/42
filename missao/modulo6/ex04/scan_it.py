#!/usr/bin/env python3
import sys
import re

num_para = (len(sys.argv)-1)

if num_para == 2:
    p_chave = (sys.argv[1])
    p_pesquisa = (sys.argv[2])

if num_para != 2:
    print("none")
elif len(re.findall(p_chave,p_pesquisa)) == 0:
    print("none")
else:
    print(len(re.findall(p_chave,p_pesquisa)))