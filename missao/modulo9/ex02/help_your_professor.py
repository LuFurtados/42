#!/usr/bin/env python3

def average(dic_notas):
    return sum(dic_notas.values())/ len(dic_notas)

# def average(dic_notas):
#     notas = dic_notas
#     lista_notas = []
    
#     for n in notas.values():
#           lista_notas.append(n)
#     soma = sum(lista_notas)
#     quantidade = len(lista_notas)
#     media = soma / quantidade
#     return media

class_3B = {
"marine": 18,
"jean": 15,
"coline": 8,
"luc": 9
}
class_3C = {
"quentin": 17,
"julie": 15,
"marc": 8,
"stephanie": 13
}
print(f"Average for class 3B: {average(class_3B)}.")
print(f"Average for class 3C: {average(class_3C)}.")