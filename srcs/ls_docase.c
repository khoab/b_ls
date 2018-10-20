/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_docase.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbui <kbui@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/18 14:41:13 by kbui              #+#    #+#             */
/*   Updated: 2018/10/19 21:19:01 by kbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "libft.h"

void	ls_fn_casenodir(t_opt_check opt_check)
{
	char		**filenames;
	int			num_files;
	
	num_files = ls_num_file(".", opt_check);
	filenames = ls_path_filenames(".", opt_check);
	ls_shellsort(filenames, num_files, opt_check.is_time);
	ls_print(filenames, ".", num_files, opt_check);
	ft_memdel((void **)filenames);
}

void	ls_fn_casedir(char **valid_dirname, int dir_size,
			t_mycheck mycheck, t_opt_check opt_check)
{
	char		**path_filenames;
	char		**filenames;
	int			num_files;
	int			i;

	i = -1;
	while(valid_dirname[++i])
	{
        num_files = ls_num_file(valid_dirname[i], opt_check);
        if (num_files == -1)
            break ;
		path_filenames = ls_path_filenames(valid_dirname[i], opt_check);
		ls_shellsort(path_filenames, num_files, opt_check.is_time);
		filenames = ls_filenames(path_filenames, num_files);
		if (i != 0 || mycheck.is_file == 1)
			printf("\n");
		if (dir_size != 1 || mycheck.is_error == 1 || mycheck.is_file == 1)
			printf("%s:\n",valid_dirname[i]);
		ls_print(filenames, valid_dirname[i], num_files, opt_check);
		free(filenames);
	}
}