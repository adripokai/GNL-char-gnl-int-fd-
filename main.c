/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajuan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 12:43:58 by ajuan             #+#    #+#             */
/*   Updated: 2021/12/17 13:02:48 by ajuan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"
#include <fcntl.h>

int main()
{
	int fd1;
	int fd2;

	fd1 = open("test.txt", O_RDONLY);
	fd2 = open("test1.txt", O_RDONLY);

	printf("le premier fd a une valeur de %d\n", fd1);
	printf("le deuxieme fd a une valeur de %d\n", fd2);
	printf("\nle premier gnl %s\n", get_next_line(fd1));
	printf("\nle deuxieme gnl %s\n", get_next_line(fd2));
	return 0;
}
