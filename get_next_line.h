#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <limits.h>

int		get_next_line(int fd, void **lineptr);
int	    ft_strlen_mod(const char *s, size_t *count);
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);
void	*ft_memcpy(void *dst, const void *src, size_t n);
int     ft_strchr_mod(char **addr, const char *s, int c);
char	*ft_strdup(const char *s1);

#endif