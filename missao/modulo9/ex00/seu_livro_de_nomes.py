#!/usr/bin/env python3

def array_de_nomes(dic_pessoas):
    full_name = []
    for nome,sobrenome in dic_pessoas.items():
        nome_format = nome
        sobre_format = sobrenome
        full_name.append(nome_format.capitalize() + ' ' + sobre_format.capitalize())   
    return(full_name)

pessoas = {
"jean": "valjean",
"grace": "hopper",
"xavier": "niel",
"fifi": "brindacier"
}
print(array_de_nomes(pessoas))