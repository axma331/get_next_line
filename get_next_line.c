/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feschall <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 16:26:03 by feschall          #+#    #+#             */
/*   Updated: 2021/02/27 21:30:14 by feschall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_bzero(void *s, size_t n)
{
	char	*str;
	size_t	i;

	str = (char *)s;
	i = 0;
	while (i < n)
	{
		str[i] = '\0';
		i++;
	}
}

char	check_end(char **line, char *end, char *buff)
{
	char *temp;
	char *unend;

	if ((unend = ft_strchr(end, '\n')))
	{
		*unend = '\0';
		temp = ft_strdup(*line);
		free(*line);
		*line = ft_strjoin(temp, end);
		free(temp);
		ft_strcpy(end, ++unend);
		free(buff);
		return (1);
	}
	else
	{
		temp = ft_strdup(*line);
		free(*line);
		*line = ft_strjoin(temp, end);
		free(temp);
	}
	return (0);
}

char	check_n(char **line, char *buff, char *end)
{
	char *temp;
	char *un;

	if ((un = ft_strchr(buff, '\n')))
	{
		*un = '\0';
		ft_strcpy(end, ++un);
		temp = ft_strdup(*line);
		free(*line);
		*line = ft_strjoin(temp, buff);
		free(temp);
		free(buff);
		return (1);
	}
	else
	{
		temp = ft_strdup(*line);
		free(*line);
		*line = ft_strjoin(temp, buff);
		free(temp);
	}
	return (0);
}

int		get_next_line(int fd, char **line)
{
	static char end[BUFFER_SIZE + 1];
	int			sb;
	char		*buff;

	if (!(buff = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1))))
		return (-1);
	if (!line || fd < 0 || BUFFER_SIZE < 1 || read(fd, NULL, 0) < 0)
	{
		free(buff);
		return (-1);
	}
	*line = ft_strdup("");
	if (check_end(line, end, buff) == 1)
		return (1);
	while (((sb = read(fd, buff, BUFFER_SIZE))) > 0)
	{
		buff[sb] = '\0';
		if (check_n(line, buff, end) == 1)
			return (1);
	}
	if (sb == 0 && *end)
		ft_bzero(end, ft_strlen(end));
	free(buff);
	return (0);
}
