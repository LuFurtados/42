#!/usr/bin/env python3
import sys
import re

num_para = (len(sys.argv)-1)

if num_para == 1:
    p_chave = ('z')
    p_pesquisa = (sys.argv[1])

if num_para != 1:
    print("none")
elif len(re.findall(p_chave,p_pesquisa)) == 0:
    print("none")
else:
    resultado = re.findall(p_chave,p_pesquisa)
    print("" .join(resultado))