/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajuan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 10:47:13 by ajuan             #+#    #+#             */
/*   Updated: 2021/12/17 13:07:01 by ajuan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

static int	occurence_is_n(char *stock, char c)
{
	unsigned int i;

	i = 0;
	if(!stock)
		return (0);
	while (stock[i])
	{
		if (stock[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static void	*ft_calloc(size_t count, size_t size)
{
	unsigned char	*stock;

	stock = malloc(count * size);
	if(!stock)
		return (NULL);
	stock[0] = 0;
	return(stock);
}

static size_t	ft_strlen(char	*str)
{
	size_t i;

	i = 0;
	while (str[i])
		i++;
	return i;
}

static char	*ft_strjoin(char *stock, char *buf)
{
	size_t	i;
	size_t	j;
	char	*resultat;

	i = 0;
	j = 0;
	if (!stock)
		stock = ft_calloc(1,1);
	resultat = malloc(ft_strlen(stock) + ft_strlen(buf) + 1);
	while (stock[i])
	{
		resultat[i] = stock[i];
		i++;
	}
	while (buf[j])
	{
		resultat[i+j] = buf[j];
		j++;
	}
	resultat[i+j] = '\0';
	free(stock);
	return(resultat);
}

char	*get_next_line(int fd)
{
	char		buf[BUFFER_SIZE + 1];//memoire tampon buffersize
	char		*line;//ligne a renvoyer pour gnl
	int			r;// indicateur du read
	static char	*stock;//variable static qui sauvegarde

	r = 1;// pret pour read
	while(r > 0 && !(occurence_is_n(stock, '\n')))
	{
		r = read(fd, buf, BUFFER_SIZE);
		if (r == -1)//fichier probleme
			return (NULL);
		if (r == 0 && stock && !stock[0])
		{
			free(stock);
			return (NULL);
		}
		buf[r] = '\0';//eof du buff
		stock = ft_strjoin(stock, buf);//concatener le buff dans larmoire
	}
	line = ft_extraction(stock);//extrait la premiere ligne
	return (line);//retourne la premiere ligne
}
