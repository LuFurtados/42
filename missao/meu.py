meu_dicionario = {'nome': 'Alice', 'idade': 30, 'cidade': 'São Paulo'}

# 1. Listar Chaves
print("--- Chaves ---")
for chave in meu_dicionario.keys(): # Ou apenas 'for chave in meu_dicionario:' [3, 5]
    print(chave)

# 2. Listar Valores
print("\n--- Valores ---")
for valor in meu_dicionario.values():
    print(valor)

# 3. Listar Chaves e Valores (Itens)
print("\n--- Chaves e Valores ---")
for chave, valor in meu_dicionario.items(): # Mais comum para exibir ambos [3, 12]
    print(f"Chave: {chave} - Valor: {valor}")

# 4. Acessar um valor específico pela chave
print("\n--- Acessando um valor ---")
print(meu_dicionario['nome']) # Saída: Alice

# 5. Converter para lista (apenas chaves)
print("\n--- Lista de Chaves ---")
print(list(meu_dicionario)) # Retorna ['nome', 'idade', 'cidade'] [13]


# dict_aninhado = {
#     'id1': {'nome': 'Alice', 'idade': 30},
#     'id2': {'nome': 'Bob', 'idade': 25},
#     'id3': {'nome': 'Charlie', 'idade': 35}
# }

# # Ordenar pelo valor da 'idade' dentro dos dicionários aninhados
# itens_ordenados = sorted(dict_aninhado.items(), key=lambda item: item[1]['idade'])
# print(itens_ordenados)
# # Saída: [('id2', {'nome': 'Bob', 'idade': 25}), ('id1', {'nome': 'Alice', 'idade': 30}), ('id3', {'nome': 'Charlie', 'idade': 35})]

# # Converter de volta para um dicionário (em Python 3.7+ a ordem é mantida)
# dict_ordenado = dict(itens_ordenados)
# print(dict_ordenado)
# # Saída: {'id2': {'nome': 'Bob', 'idade': 25}, 'id1': {'nome': 'Alice', 'idade': 30}, 'id3': {'nome': 'Charlie', 'idade': 35}}


# contatos = {
#     "guilherme@gmail.com": {"nome": "Guilherme", "telefone": "3333-2221"},
#     "giovanna@gmail.com": {"nome": "Giovanna", "telefone": "3443-2121"},
#     "chappie@gmail.com": {"nome": "Chappie", "telefone": "3344-9871"},
#     "melaine@gmail.com": {"nome": "Melaine", "telefone": "3333-7766"},
# }

# for chave in contatos:
#     print(chave, contatos[chave])

# print("=" * 100)

# for chave, valor in contatos.keys():
#     print(chave, valor)

# texto = "olá, mundo em python!"
# texto_formatado = texto.capitalize()
# print(texto_formatado)
# # Saída: "Olá, mundo em python!"

# texto2 = "PYTHON É PODEROSO!"
# texto_formatado2 = texto2.capitalize()
# print(texto_formatado2)
# # Saída: "Python é poderoso!"

# texto3 = "123 teste"
# texto_formatado3 = texto3.capitalize()
# print(texto_formatado3)
# # Saída: "123 teste" (números não são afetados, mas o restante fica minúsculo)


# numero = 10
# texto = "Olá"
# lista_numeros = [1, 2, 3]

# # Verifica se 'numero' é um inteiro (int)
# print(f"numero é int? {isinstance(numero, int)}") # Saída: True

# # Verifica se 'texto' é uma string (str)
# print(f"texto é str? {isinstance(texto, str)}") # Saída: True

# # Verifica se 'lista_numeros' é uma lista (list)
# print(f"lista_numeros é list? {isinstance(lista_numeros, list)}") # Saída: True

# # Verifica se 'numero' é uma string (str) ou float
# print(f"numero é str ou float? {isinstance(numero, (str, float))}") # Saída: False


# # # Exemplo de definição de método em Python

# # class Cachorro:
# #     # Método especial (construtor) para inicializar o objeto
#     def __init__(self, nome, raca):
#         self.nome = nome  # Atributo da instância
#         self.raca = raca  # Atributo da instância

#     # Método de instância para descrever o cachorro
#     def latir(self):
#         return f"{self.nome} está latindo: Au au!"

#     # Outro método de instância para mostrar informações
#     def descrever(self):
#         return f"Este é {self.nome}, um {self.raca}."

# # --- Como usar os métodos ---

# # 1. Criar objetos (instâncias) da classe Cachorro
# meu_cachorro = Cachorro("Rex", "Pastor Alemão")
# outro_cachorro = Cachorro("Luna", "Poodle")

# # 2. Chamar os métodos usando a notação de ponto
# print(meu_cachorro.descrever()) # Saída: Este é Rex, um Pastor Alemão.
# print(outro_cachorro.latir())   # Saída: Luna está latindo: Au au!


# # script_argumentos.py
# import sys

# print(f"Nome do script: {sys.argv[0]}")
# print(f"Total de argumentos: {len(sys.argv)}") # len() dá o número total

# # Verifica se há argumentos extras (além do nome do script)
# if len(sys.argv) > 1:
#     print("Argumentos fornecidos:")
#     # Loop para imprimir cada argumento (a partir do índice 1)
#     for i, arg in enumerate(sys.argv[1:]):
#         print(f"  Argumento {i+1}: {arg} (Tipo: {type(arg)})")
# else:
#     print("Nenhum argumento adicional fornecido.")

# # Exemplo de conversão para número (CUIDADO: pode dar erro se não for número)
# if len(sys.argv) > 2:
#     try:
#         num1 = int(sys.argv[1])
#         num2 = int(sys.argv[2])
#         print(f"Soma dos dois primeiros: {num1 + num2}")
#     except ValueError:
#         print("Erro: Os argumentos 1 e 2 devem ser números inteiros.")