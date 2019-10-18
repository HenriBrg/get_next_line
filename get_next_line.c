/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hberger <hberger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 15:08:42 by hberger           #+#    #+#             */
/*   Updated: 2019/10/18 17:51:47 by hberger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	while (*s != c)
	{
		if (*s == '\0')
			return (NULL);
		s++;
	}
	return ((char*)s);
}

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	*str;

	i = 0;
	str = (unsigned char *)b;
	while (i < len)
	{
		str[i] = (unsigned char)c;
		i++;
	}
	return (str);
}

char	*ft_strnew(size_t size)
{
	char *output;

	if ((output = (char*)malloc((size + 1) * sizeof(char))) == NULL)
		return (NULL);
	ft_memset(output, '\0', size + 1);
	return (output);
}

char	*ft_strcat(char *dest, const char *src)
{
	int i;
	int j;

	i = 0;
	while (dest[i] != '\0')
		i++;
	j = 0;
	while (src[j] != '\0')
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s;

	if (s1 == 0 || s2 == 0 || (!(s = (char*)malloc(sizeof(char) *
	((ft_strlen(s1) + ft_strlen(s2)) + 1)))))
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
*/

char	*ft_read(const int fd, char *str)
{
	int		x;
	char	*tmp;
	char	buffer[BUFF_SIZE + 1];

	if (fd < 0 || BUFF_SIZE < 1 || read(fd, buffer, 0) < 0)
		return (0);
	str = (str == 0) ? ft_strnew(1) : str;
	while (ft_strchr(str, '\n') == 0)
	{
		tmp = str;
		if ((x = read(fd, buffer, BUFF_SIZE)) < 0)
			return (0);
		buffer[x] = '\0';
		str = ft_strjoin(str, buffer);
		free(tmp);
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

	if (line == 0 || (str = ft_read(fd, str)) == 0)
		return (-1);
	if (ft_strlen(str) == 0)
		return (0);
	if (((tmp = ft_strchr(str, '\n')) > 0))
	{
		i = tmp - str;
		if ((*line = ft_strndup(str, i)) == 0)
			return (-1);
		free(str);
		str = ft_strdup(tmp + 1);
		return (1);
	}
	else
	{
		if ((*line = ft_strdup(str)) == 0)
			return (-1);
		free(str);
		str = NULL;
		return (1);
	}
}
