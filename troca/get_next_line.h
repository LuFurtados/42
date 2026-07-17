
#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# volatile
# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

/* Funções Principais e Coordenadoras */
char	*get_next_line(int fd);
char	*ft_create_line(const char *s, const char *delimiter);
char	*ft_update_leftover(char *s, const char *delimiter);
char	*ft_append_leftover(char *leftover, char *buffer);

/* Funções Utilitárias Obrigatórias (Utils) */
char	*ft_strchr(const char *s, int c);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlen(const char *s);
char	*ft_substr(char const *s, unsigned int start, size_t len);

#endif