/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsok <hyeonsok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 04:01:19 by hyeonsok          #+#    #+#             */
/*   Updated: 2021/03/30 20:18:44 by hyeonsok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		encounter_err(void *save);
int		read_mod(int fd, char buf[], size_t *mem_count, ssize_t *read_count);
int		alloc_cat(char **save, char buf[], size_t size);
int		encounter_end(void **lineptr, char **save, char *newline_addr);

#define BUFFER_SIZE 5

int	get_next_line(int fd, void **lineptr)
{
	static char	*savebuf[OPEN_MAX];
	char		strbuf[BUFFER_SIZE];
	char		*newline_addr;
	size_t		mem_count;
	ssize_t		read_count;

	if ((BUFFER_SIZE < 1) || (fd > OPEN_MAX) || (fd < 0) || !lineptr)
		return (-1);
	if (!ft_strlen_mod(savebuf[fd], &mem_count))    //savebuf[fd] 비어있는 경우 "" 할당, 할당 실패시 0을 반환
		return (encounter_err(savebuf[fd]));
	while (1)
	{
		if (!read_mod(fd, strbuf, &mem_count, &read_count))   //read함수가 올바르게 작동하지 못할시 할당해제 0을 반환
			return (encounter_err(&savebuf[fd]));
		if (!alloc_cat(&savebuf[fd], strbuf, mem_count + 1))  //savebuf[fd]는 할당이 보장된 상태임, realloc실패시 0을 반환 성공적으로 마친 경우 1을 반환
			return (encounter_err(&savebuf[fd]));
		if (ft_strchr_mod(&newline_addr, savebuf[fd], '\n') \
		|| read_count < BUFFER_SIZE) // 찾지 못한 경우 0을 반환 찾은 경우 1을 반환(mod)
			return (encounter_end(lineptr, &savebuf[fd], newline_addr));
	}
}

int encounter_err(void  *save)
{
	if (!save)
		return (-1);
	free(save);
	save = NULL;
	return (-1);
}

int read_mod(int fd, char buf[], size_t *mem_count, ssize_t *read_count)
{
	*read_count = read(fd, buf, BUFFER_SIZE);
	if (*read_count < 0)
		return (*read_count);
	*mem_count += *(size_t *)read_count;
	return (*read_count);
}

int alloc_cat(char **save, char buf[], size_t size)     //size는 mem_count + read_count된 값이다. *save는 null아닌 값이 이미 확인되어있음.
{   
	char	*tmp;
	size_t  count;
	
	tmp = NULL;
	tmp = ft_strdup(*save);
	free(*save);
	*save = NULL;
	*save = (char *)malloc(size);
	if (!tmp || !*save)
	{
		free(*save);
		free(tmp);
		return (0);
	}
	ft_strlen_mod(tmp, &count);
	ft_memcpy(*save, tmp, count + 1);
	free(tmp);
	tmp = NULL;
	ft_strlcat(*save, buf, size);
	return (1);
}

int	encounter_end(void **lineptr, char **save, char *newline_addr)
{
	char	*tmp;
	
	tmp = NULL;
	if (newline_addr != NULL)
	{	
		*newline_addr = '\0';
		*lineptr = ft_strdup(*save);
		tmp = ft_strdup(++newline_addr);
		if (!*lineptr || !tmp)
		{
			free(lineptr);
			free(tmp);
			return (encounter_err(save));
		}
		free(*save);
		*save = tmp;
		return (1);
	}
	*lineptr = ft_strdup(*save);
	if (!*lineptr)
		return (encounter_err(save));
	free(*save);
	*save = NULL;
	return (0);
}
