/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_filename.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbui <kbui@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/02 15:01:51 by kbui              #+#    #+#             */
/*   Updated: 2018/10/04 23:53:35 by kbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <dirent.h>
#include <stdlib.h>
#include <stdio.h>
#include "libft.h"

char		**ls_valid_dirname(char **av, int ar, int start)
{
	DIR		*d;
	char	**valid_dirname;
	int		size;
	int		valid_check;

	valid_check = start;
	size = 0;
	while (valid_check++ < ar)
	{
		d = opendir(av[valid_check]);
		if (d)
			size++;
		else
			printf("ls: %s: No such file or directory\n", av[valid_check]);
		closedir(d);
	}
	valid_dirname = (char **)malloc(sizeof(valid_dirname) * size);
	while (start++ < ar)
	{
		d = opendir(av[start]);
		if (d)
			*(valid_dirname++) = ft_strdup(av[valid_check]);
		closedir(d);
	}
	return (valid_dirname);
}

void		ls_dirname(int ar, int start, char **av, t_opt_check opt_check)
{
	char		**filenames;
	char		**valid_dirname;
	int			num_files;

	if (start == ar - 1)
	{
		filenames = ls_filenames(".", opt_check);
		num_files = ls_num_file(".", opt_check);
		ls_shellsort(filenames, num_files, opt_check);
		ls_print(filenames, opt_check);
		free(filenames);
	}
	else
	{
		valid_dirname = ls_valid_dirname(av, ar, start);
		while (*valid_dirname && valid_dirname++)
		{
			filenames = ls_filenames(*valid_dirname, opt_check);
			num_files = ls_num_file(*valid_dirname, opt_check);
			ls_shellsort(filenames, num_files, opt_check);
			ls_print(filenames, num_files, opt_check);
			free(filenames);
		}
	}
}

int			ls_num_file(char *dirname, t_opt_check opt_check)
{
	DIR				*d;
	struct dirent	*dir;
	int				num_of_file;

	num_of_file = 0;
	d = opendir(dirname);
	while ((dir = readdir(d)) != NULL)
	{
		if (opt_check.is_a == 1 && dir->d_name[0] == '.')
			continue ;
		num_of_file++;
	}
	closedir(d);
	return (num_of_file);
}

char		**ls_filenames(char *dirname, t_opt_check opt_check)
{
	struct dirent	*dir;
	char			**filenames;
	int				i;
	int				num_of_file;
	DIR				*d;

	num_of_file = ls_num_file(dirname, opt_check);
	if (num_of_file == 0)
		return (NULL);
	d = opendir(dirname);
	filenames = (char **)malloc(sizeof(filenames) * num_of_file);
	while ((dir = readdir(d)) != NULL)
		*(filenames++) = ls_chhid_strdup(dir->d_name, opt_check);
	return (filenames);
}
