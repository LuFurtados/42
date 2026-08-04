*This project has been created as part of the 42 curriculum by jobezerr.*

# ft_printf

## Description

Este projeto consiste em recriar a função `printf` da libc em C, gerando a biblioteca estática `libftprintf.a`. O objetivo principal é praticar funções variádicas, parsing de strings de formato e escrita estruturada de saída.

A implementação cobre as conversões obrigatórias do projeto:

- `%c`
- `%s`
- `%p`
- `%d`
- `%i`
- `%u`
- `%x`
- `%X`
- `%%`

## Instructions

Para compilar a biblioteca:

```bash
make
```

Regras disponíveis no Makefile:

- `make` ou `make all`
- `make clean`
- `make fclean`
- `make re`

Para usar no seu projeto:

```c
#include "ft_printf.h"
```

Exemplo:

```c
ft_printf("Valor: %d\n", 42);
```

## Technical choices

A função `ft_printf` percorre a string de formato caractere por caractere. Quando encontra `%`, ela encaminha o próximo caractere para uma função responsável por decidir qual conversão deve ser executada.

Para caracteres e strings, a escrita é feita com funções simples baseadas em `write`. Para números, a implementação usa recursão e divisão por base, o que permite reaproveitar a mesma ideia para decimal, hexadecimal minúsculo e hexadecimal maiúsculo.

No caso de `%p`, o ponteiro é tratado separadamente: a função imprime o prefixo `0x`, converte o endereço para um tipo inteiro sem sinal adequado e imprime o valor em hexadecimal. Ponteiros nulos também recebem tratamento específico.

Cada função retorna a quantidade de caracteres impressos. Em caso de erro de escrita, o retorno `-1` é propagado até `ft_printf`.

## Files

- `ft_printf.c`
- `ft_printf_char.c`
- `ft_printf_numbers.c`
- `ft_printf.h`
- `Makefile`


## Resources

Recursos utilizados durante o projeto:

- Subject oficial do `ft_printf` da 42.
- Documentação e man pages sobre `write` e funções variádicas.
- Testes comparando a saída e o retorno com o `printf` original.

## AI usage

A IA foi usada como ferramenta de apoio para tirar dúvidas conceituais sobre funções e correções.:
O código foi implementado, ajustado e testado manualmente ao longo do desenvolvimento.