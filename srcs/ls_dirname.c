/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_dirname.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbui <kbui@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/17 13:10:38 by kbui              #+#    #+#             */
/*   Updated: 2018/10/19 21:16:07 by kbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <dirent.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <stdlib.h>
#include "libft.h"

int		ls_dir_size(char **av, int ar, int start, int *is_print)
{
	int				size;
	struct stat		file;
	
	size = 0;
	start -= 1;
	while (++start < ar)
	{
		if (start == 0)
			start = 1;
		lstat(av[start], &file);
		if (S_ISDIR(file.st_mode))
			size++;
		else if (ft_isfile(av[start]))
			continue ;
		else
		{
			printf("ls: %s: No such file or directory\n", av[start]);
			*is_print = 1;
		}
	}
	return (size);
}

void	ls_dup_dirname(char **av, char **valid_dirname, int ar,
			int start, t_opt_check opt_check)
{
	int				i;
	struct stat		file;
	
	i = -1;
	if (opt_check.is_r != 1)
		while (start < ar)
		{
			lstat(av[start], &file);
			if (S_ISDIR(file.st_mode))
				valid_dirname[++i] = ft_strdup(av[start]);
			start++;
		}
	else
		while (--ar >= start)
		{
			lstat(av[ar], &file);
			if (S_ISDIR(file.st_mode))
				valid_dirname[++i] = ft_strdup(av[ar]);
		}
}

int		ls_dirname(int ar, int start, char **av, t_opt_check opt_check)
{
	char		**valid_dirname;
	int			dir_size;
	t_mycheck	my_check;
	
	ft_memset(&my_check, '0', sizeof(my_check));
	if (start == ar)
		ls_fn_casenodir(opt_check);
	else
	{
		dir_size = ls_dir_size(av, ar, start, &my_check.is_error);
		ls_filename_input(av, ar, start, &my_check.is_file, opt_check);
		if (dir_size == 0)
			return (0);
		valid_dirname = (char **)malloc(sizeof(valid_dirname) * dir_size);
		ls_dup_dirname(av, valid_dirname, ar, start, opt_check);
		ls_fn_casedir(valid_dirname, dir_size, my_check, opt_check);
		ft_memdel((void **)valid_dirname);
	}
	return (0);
}
