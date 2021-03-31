/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsok <hyeonsok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 23:32:12 by hyeonsok          #+#    #+#             */
/*   Updated: 2021/03/30 23:33:09 by hyeonsok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	const char *tmp;

	tmp = s;
	while (*s)
		s++;
	return (s - tmp);
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

	len = ft_strlen(s1);
	s2 = (char *)malloc(sizeof(char) * len + 1);
	if (!s2)
		return (0);
	return (ft_memcpy(s2, s1, len + 1));
}

char	*ft_strchr(const char *s, int c)
{
	while (s != NULL && *s != '\0')
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if (*s == c)
		return ((char *)s);
	return (NULL);
}

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dst_len;
	size_t	src_len;

	src_len = ft_strlen(src);
	if (dst == NULL && dstsize == 0)
		return (src_len);
	dst_len = ft_strlen(dst);
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
