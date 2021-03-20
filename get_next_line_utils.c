/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feschall <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 16:26:03 by feschall          #+#    #+#             */
/*   Updated: 2021/02/27 21:30:23 by feschall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	char	*str;
	char	sym;
	int		i;

	str = (char *)s;
	sym = (char)c;
	i = 0;
	while (str[i])
	{
		if (str[i] == sym)
			return (str + i);
		i++;
	}
	if (str[i] == '\0' && sym == '\0')
		return (str + i);
	return (0);
}

char	*ft_strcpy(char *dest, char *src)
{
	int i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strdup(const char *s1)
{
	char	*s2;
	int		i;
	int		len;

	i = 0;
	len = ft_strlen(s1);
	if (!(s2 = ((char *)malloc(sizeof(char) * (len + 1)))))
		return (0);
	while (i <= len)
	{
		s2[i] = s1[i];
		i++;
	}
	return (s2);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	len;
	size_t	i;
	size_t	n;

	i = 0;
	if (s1 && s2)
	{
		len = ft_strlen(s1) + ft_strlen(s2);
		if (!(str = (char *)malloc(sizeof(char) * (len + 1))))
			return (0);
		i = 0;
		n = 0;
		while (s1[n])
			str[i++] = s1[n++];
		n = 0;
		while (s2[n])
			str[i++] = s2[n++];
		str[i] = '\0';
		return (str);
	}
	return (0);
}
