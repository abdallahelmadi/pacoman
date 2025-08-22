/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_init.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdael-m <abdael-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 07:53:36 by abdael-m          #+#    #+#             */
/*   Updated: 2025/01/13 09:04:29 by abdael-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../global.h"

char	*get_next_line_init(int fd)
{
	char	buffer[2];
	char	*line;
	char	*temp;

	buffer[1] = '\0';
	temp = NULL;
	line = NULL;
	while (read(fd, &buffer[0], 1) > 0)
	{
		if (buffer[0] == '\n')
			break ;
		temp = line;
		if (!temp)
			line = ft_strjoin("", buffer);
		else
			line = ft_strjoin(temp, buffer);
		free(temp);
	}
	return (line);
}
