/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauberna <pauberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 09:57:57 by pauberna          #+#    #+#             */
/*   Updated: 2023/11/14 14:52:30 by pauberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	char		*result;
	int			bytes;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	result = NULL;
	while (1)
	{
		if (buffer[0] == '\0')
		{
			bytes = ft_read_file(fd, buffer, result);
			if (bytes == -1)
				return (NULL);
			else if (bytes == 0)
				return (result);
		}
		result = use_remains(result, buffer);
		if (adjust_buffer(buffer) == 1)
			break ;
	}
	return (result);
}

/* int	main(void)
{
	int		fd;
	int		i;
	char	*result;

	i = 1;
	fd = open("teste.txt", O_RDONLY);
	while (i < 20)
	{
		result = get_next_line(fd);
		printf("%s",result);
		free(result);
		i++;
	}
	close (fd);
	return (0);
} */
