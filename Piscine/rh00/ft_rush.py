x=10 #colunas - largura
y=10 #linhas - altura

h = 'o' #horizontal
v = '' #vertical
e = '' #espaço

#Horizontal - coluna
i=2
while i < x:
    h = h + '-'
    i += 1

if x > 1:
    h = h + 'o'

if x > 0:
    print(f'{h}')

#Espaços em branco
i=2
while i < x:
    e = e + ' '
    i += 1

if e != '':
  e = e + '|'

#Vertical linha
i=2
if y > 2:
  while i < y:
      v ='|' + e
      print(f'{v}')
      i += 1

if y > 2:
    print(f'{h}')