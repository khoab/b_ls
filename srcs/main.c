/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbui <kbui@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/26 19:50:43 by kbui              #+#    #+#             */
/*   Updated: 2018/10/07 12:46:46 by kbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

int				ls_num_opt(int size, char **opt)
{
	int		len;

	if (size == 2 && strcmp(opt[1], "-") == 0)
		return (0);
	len = 1;
	while (opt[len][0] == '-')
	{
		if (opt[len][1] == '-')
			break ;
		if (len == size - 1)
			break ;
		if (opt[len + 1][0] != '-')
			break ;
		len++;
	}
	return (len);
}

t_opt_check		ls_opt_check(char **av, size_t num_of_opt)
{
	size_t			i;
	size_t			j;
	t_opt_check		check;

	i = 0;
	while (++i <= num_of_opt && (strcmp(av[i], "--") != 0))
	{
		j = 0;
		while (av[i][++j] != '\0')
			if (av[i][j] == 'l')
				check.is_l = 1;
			else if (av[i][j] == 'a')
				check.is_a = 1;
			else if (av[i][j] == 'r')
				check.is_r = 1;
			else if (av[i][j] == 't')
				check.is_time = 1;
			else
			{
				printf("ls: illegal option -- %c\n", av[i][j]);
				check.illegal_opt = 1;
				return (check);
			}
	}
	return (check);
}


int				b_ls(int ar, char **av)
{
	t_opt_check		opt_check;
	int				start;
	char			**filenames;
	int				num_of_file;

	start = ls_num_opt(ar, av) + 1;
	opt_check = ls_opt_check(av, start - 1);
	if (opt_check.illegal_opt == 1)
	{
		printf("usage: ls [-lart] [file ...]\n");
		return (0);
	}
	ls_dirname(ar, start, av, opt_check);
}

int				main(int ar, char **av)
{
	if (ar == 1)
		return (0);
	else
		b_ls(ar, av);
	return (0);
}
