/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_filename.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbui <kbui@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/02 15:01:51 by kbui              #+#    #+#             */
/*   Updated: 2018/10/09 19:04:12 by kbui             ###   ########.fr       */
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
	int		i;

	valid_check = start - 1;
	size = 0;
	while (++valid_check < ar)
	{
		d = opendir(av[valid_check]);
		if (d)
		{
			size++;
			closedir(d);
		}
		else
			printf("ls: %s: No such file or directory\n", av[valid_check]);
	}
	valid_dirname = (char **)malloc(sizeof(valid_dirname) * size);
	i = 0;
	while (start < ar)
	{
		d = opendir(av[start]);
		if (d)
		{
			valid_dirname[i++] = ft_strdup(av[start]);
			closedir(d);
		}
		start++;
	}
	return (valid_dirname);
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
		if (opt_check.is_a != 1 && dir->d_name[0] == '.')
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
	i = 0;
	while ((dir = readdir(d)) != NULL)
	{
		if (dir->d_name[0] == '.' && opt_check.is_a != 1)
			continue ;
		filenames[i] = ft_strdup(dir->d_name);
		i++;
	}
	return (filenames);
}

void		ls_fn_case_nodir(t_opt_check opt_check)
{
	char		**filenames;
	int			num_files;

	filenames = ls_filenames(".", opt_check);
	num_files = ls_num_file(".", opt_check);
	ls_shellsort(filenames, num_files, opt_check);
	ls_print(filenames, num_files, opt_check);
	free(filenames);
}

void		ls_fn_case_dir(char **valid_dirname, t_opt_check opt_check)
{
	char		**filenames;
	int			num_files;
	int			i;

	i = -1;
	while(valid_dirname[++i])
	{
		filenames = ls_filenames(valid_dirname[i], opt_check);
		num_files = ls_num_file(valid_dirname[i], opt_check);
		ls_shellsort(filenames, num_files, opt_check);
		printf("%s\n",valid_dirname[i]);
		ls_print(filenames, num_files, opt_check);
		printf("\n");
		free(filenames);
	}
}

int			ls_dirname(int ar, int start, char **av, t_opt_check opt_check)
{
	char		**filenames;
	char		**valid_dirname;
	int			num_files;
	int			i;

	if (start == ar)
		ls_fn_case_nodir(opt_check);
	else
	{
		valid_dirname = ls_valid_dirname(av, ar, start);
		ls_fn_case_dir(valid_dirname, opt_check);
		free(valid_dirname);
	}
	return (0);
}
