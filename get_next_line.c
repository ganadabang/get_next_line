/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsok <hyeonsok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 20:19:50 by hyeonsok          #+#    #+#             */
/*   Updated: 2021/03/30 21:03:37 by hyeonsok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#define BUFFER_SIZE 5
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

void    check_save(char *save)
{

}
int get_next_line(int fd, void **lineptr)
{
    static char *save[OPEN_MAX];
    char        buff[BUFFER_SIZE];
    char        *newline;
    size_t      aloc_size;
    ssize_t     read_size;

    if ((BUFFER_SIZE < 1) || (fd > OPEN_MAX) || (fd < 0) || !lineptr)
		return (-1);
    check_save(save[fd]);

    return (-1);
}
