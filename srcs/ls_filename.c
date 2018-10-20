/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_filename.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbui <kbui@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/02 15:01:51 by kbui              #+#    #+#             */
/*   Updated: 2018/10/19 21:19:06 by kbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <dirent.h>
#include <stdlib.h>
#include <stdio.h>
#include "libft.h"

int			ls_num_file(char *dirname, t_opt_check opt_check)
{
	DIR				*d;
	struct dirent	*dir;
	int				num_of_file;

	num_of_file = 0;
	d = opendir(dirname);
	if (d)
	{
		while ((dir = readdir(d)) != NULL)
		{
			if (opt_check.is_a != 1 && dir->d_name[0] == '.')
				continue ;
			num_of_file++;
		}
		closedir(d);
		return (num_of_file);
	}
	return (-1);
}

char		**ls_filenames(char **path_filenames, int num_files)
{
	char	**filenames;
	int		i;

	i = -1;
	filenames = (char **)malloc(sizeof(filenames) * num_files);
	while (++i < num_files)
		filenames[i] = ls_mod_strrchr(path_filenames[i], '/');
	return (filenames);
}

char		**ls_path_filenames(char *dirname, t_opt_check opt_check)
{
	struct dirent	*dir;
	char			**filenames;
	int				i;
	int				num_of_file;
	DIR				*d;

	num_of_file = ls_num_file(dirname, opt_check);
	if (num_of_file == 0)
		return (NULL);
	filenames = (char **)malloc(sizeof(filenames) * num_of_file);
	i = 0;
	d = opendir(dirname);
	while ((dir = readdir(d)) != NULL)
	{
		if (dir->d_name[0] == '.' && opt_check.is_a != 1)
			continue ;
		if (ft_strcmp(dirname, ".") != 0)
			filenames[i] = ls_mod_strjoin(dirname, dir->d_name);
		else
			filenames[i] = ft_strdup(dir->d_name);
		i++;
	}
	closedir(d);
	return (filenames);
}
