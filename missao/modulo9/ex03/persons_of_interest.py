#!/usr/bin/env python3

def famous_births(wemen):
    date_birth_ordenado = dict(sorted(wemen.items(), key=lambda items: items[1]['date_of_birth']))
    
    for valor in date_birth_ordenado.values():
        print(f'{valor["name"]} is a great scientist born in {valor["date_of_birth"]}')

women_scientists = {
"ada": { "name": "Ada Lovelace", "date_of_birth": "1815" },
"cecilia": { "name": "Cecila Payne", "date_of_birth": "1900" },
"lise": { "name": "Lise Meitner", "date_of_birth": "1878" },
"grace": { "name": "Grace Hopper", "date_of_birth": "1906" }
}
famous_births(women_scientists)