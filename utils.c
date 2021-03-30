/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsok <hyeonsok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 21:20:13 by hyeonsok          #+#    #+#             */
/*   Updated: 2021/03/30 20:16:30 by hyeonsok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <string.h>

int	ft_strlen_mod(const char *s, size_t *count)
{
	const char	*tmp;

	if (!s)
		s = ft_strdup("");
	if (!s)
		return (0);
	tmp = s;
	while (*s)
		s++;
	*count = s - tmp;
	return (1);
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	void	*first_dst;

	first_dst = dst;
	if (dst == src)
		return (first_dst);
	while (n--)
		*(char *)dst++ = *(char *)src++;
	return (first_dst);
}

char	*ft_strdup(const char *s1)
{
	size_t	len;
	char	*s2;

	len = strlen(s1);
	s2 = (char *)malloc(sizeof(char) * len + 1);
	if (!s2)
		return (0);
	return (ft_memcpy(s2, s1, len + 1));
}

int     ft_strchr_mod(char **addr, const char *s, int c)
{
	while (s != NULL && *s != '\0')
	{
		if (*s == (char)c)
		{
			*addr = (char *)s;
			return (1);
		}
		s++;
	}
	if (*s == c)
	{
		*addr = (char *)s;
		return (1);
	}
	else
	{   
		*addr = NULL;
		return (0);
	}
}

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dst_len;
	size_t	src_len;

	src_len = strlen(src);
	if (dst == NULL && dstsize == 0)
		return (src_len);
	dst_len = strlen(dst);
	if (dst_len >= dstsize)
		return (dstsize + src_len);
	while (*dst && dst++)
		dstsize--;
	while (*src && dstsize > 1)
	{
		*dst++ = *src++;
		dstsize--;
	}
	*dst = '\0';
	return (dst_len + src_len);
}
