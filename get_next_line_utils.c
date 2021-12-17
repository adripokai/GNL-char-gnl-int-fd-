/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajuan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 10:47:43 by ajuan             #+#    #+#             */
/*   Updated: 2021/12/17 12:44:21 by ajuan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

size_t	ft_len_before_n(char *stock)
{
	size_t	i;

	i = 0;
	while(stock[i] && stock[i] != '\n')
		i++;
	if (stock[i] == '\n')
		i++;
	return (i);
}

void	ft_strcpy(char *dest, char *src)
{
	size_t	i;

	i = 0;
	while(src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
}

char	*ft_extraction(char *stock)
{
	size_t i;
	size_t k;
	char *line;

	if (stock[0] == '\0')
		return (NULL);
	i = 0;
	k = ft_len_before_n(stock);
	line = malloc(sizeof(char *) * k + 1);
	while (i < k)
	{
		line[i] = stock[i];
		i++;
	}
	line[i] = '\0';
	ft_strcpy(stock, &stock[k]);
	return (line);
}
