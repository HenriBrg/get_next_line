/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hberger <hberger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 15:08:42 by hberger           #+#    #+#             */
/*   Updated: 2019/10/11 20:10:50 by hberger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s;

	if (s1 == 0 || s2 == 0 ||
		(!(s = (char*)malloc(sizeof(char) * ((ft_strlen(s1) + ft_strlen(s2)) + 1)))))
		return (0);
	s[0] = '\0';
	ft_strcat(s, s1);
	ft_strcat(s, s2);
	return (s);
}

char	*ft_strdup(const char *src)
{
	int		i;
	char	*output;

	i = 0;
	while (src[i] != '\0')
		i++;
	if ((output = (char*)malloc(sizeof(char) * (i + 1))) == NULL)
		return (NULL);
	i = 0;
	while (src[i] != '\0')
	{
		output[i] = src[i];
		i++;
	}
	output[i] = '\0';
	return (output);
}

char	*ft_strndup(const char *src, size_t n)
{
	size_t		i;
	char		*output;

	i = 0;
	while (src[i] != '\0' && i < n)
		i++;
	if ((output = (char*)malloc(sizeof(char) * (i + 1))) == NULL)
		return (NULL);
	i = 0;
	while (src[i] != '\0' && i < n)
	{
		output[i] = src[i];
		i++;
	}
	output[i] = '\0';
	return (output);
}

/*
**  1er while :
**  	Lecture du fichier tant qu'on ne trouve pas le RETOUR LIGNE
**  	+ tant que read ne retourne pas 0 ou < 0
**
** Ligne 87 (avant) : str = (str == 0) ? ft_strnew(1) : str;
*/

char	*ft_read(const int fd, char *str)
{
	int		x;
	char	buffer[BUFF_SIZE + 1];

	if (fd < 0 || BUFF_SIZE < 1 || read(fd, buffer, 0) < 0)
		return (0);
	str = (str == 0) ? (char*)ft_calloc(1, 1) : str;
	while (ft_strchr(str, '\n') == 0)
	{
		if ((x = read(fd, buffer, BUFF_SIZE)) < 0)
			return (0);
		buffer[x] = '\0';
		str = ft_strjoin(str, buffer);
		if (x == 0 || str[0] == '\0')
			break ;
	}
	return (str);
}

/*
**  str = 1er char de str et tmp = 1er Retour Ligne dans str
**  i = tmp - str -----> On fait une soustraction de "mémoire"
**  pour avoir l'index du /n
**
**  str = ft_strdup(tmp + 1) -----> Quand on rappellera get_next_line,
**  str contiendra le reste après '/n'
*/

int		get_next_line(int fd, char **line)
{
	int				i;
	char			*tmp;
	static char		*str;

	str = ft_read(fd, str);
	if ((tmp = ft_strchr(str, '\n')) > 0)
	{
		i = tmp - str;
		if ((*line = ft_strndup(str, i)) == 0)
			return (-1);
		str = ft_strdup(tmp + 1);
		return (1);
	}
	else
	{
		if ((*line = ft_strdup(str)) == 0)
			return (-1);
		free(str);
		str = NULL;
		return (line == 0) ? 1 : 0;
	}
}
