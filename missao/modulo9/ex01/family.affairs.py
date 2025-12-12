#!/usr/bin/env python3

def find_the_redheads(dic_cabelo):
    cabelo = dic_cabelo
    termo_busca = "red"
    lista_red = []
    lista_nomes = []
    lista_red = dict(filter(lambda items:termo_busca in items[1],cabelo.items()))

    for nome in lista_red.keys():
          lista_nomes.append(nome)
    return lista_nomes

familia_dupont = {
"florian": "red",
"marie": "blond",
"virginie": "brunette",
"david": "red",
"franck": "red"
}
print(find_the_redheads(familia_dupont))