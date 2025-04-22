/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mqueiros <mqueiros@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 09:51:02 by mqueiros          #+#    #+#             */
/*   Updated: 2025/04/22 12:26:48 by mqueiros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_read_line(char *buffer, size_t *save)
{
	size_t	i;
	char	*dst;
	
	i = 0;
	while (buffer[i] != '\n' || buffer[i] != '\0')
		i++;
	
	dst = malloc((*save + i + 1) * sizeof(char));
	if (dst)
	{
		
	}
	free(save);
	return (dst);
}

char	*get_next_line(int fd)
{
	size_t			i;
	static char		*fd_save[1024];
	char			buffer[BUFFER_SIZE + 1];
	char			*dst;
	
	i = 0;
	if (fd == -1 || fd >= FD_MAX || BUFFER_SIZE <= 0)
		return (NULL);
	while (fd != -1 && read(fd, buffer, BUFFER_SIZE))
	{
		ft_read_line(buffer, *fd_save[fd]);
		
	}
	
}
