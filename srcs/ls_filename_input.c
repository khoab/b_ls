/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_filename_input.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbui <kbui@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/18 15:13:52 by kbui              #+#    #+#             */
/*   Updated: 2018/10/19 19:41:30 by kbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

/*
** Those function will define and printout all filename that have been input
*/

int		ls_filesize(char **av, int ar, int start)
{
	int file_size;

	start -= 1;
	file_size = 0;
	while (++start < ar)
	{
		if (start == 0)
			start = 1;
		if (ft_isfile(av[start]) == 1)
			file_size++;
	}
	return (file_size);
}

char	**ls_valid_filename(char **av, int ar, int start, int file_size)
{
	char	**valid_filename;
	int		i;
	
	valid_filename = (char **)malloc(sizeof(valid_filename) * file_size);
	i = -1;
	start -= 1;
	while (++start < ar)
	{
		if (start == 0)
			start = 1;
		if (ft_isfile(av[start]))
			valid_filename[++i] = ft_strdup(av[start]);
	}
	return (valid_filename);
}

void	ls_filename_input(char **av, int ar, int start,
			int *is_file, t_opt_check opt_check)
{
	char	**valid_filename;
	int		file_size;

	file_size = ls_filesize(av, ar, start);
	if (file_size != 0)
	{
		valid_filename = ls_valid_filename(av, ar, start, file_size);
		ls_shellsort(valid_filename, file_size, opt_check.is_time);
		ls_print(valid_filename, NULL, file_size, opt_check);
		*is_file = 1;
		ft_memdel((void **)valid_filename);
	}
}