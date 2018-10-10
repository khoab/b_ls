/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbui <kbui@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/04 23:46:20 by kbui              #+#    #+#             */
/*   Updated: 2018/10/09 18:21:49 by kbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <time.h>
#include <stdlib.h>
#include "libft.h"

void	ls_print_reg(char **filenames, int num_files, t_opt_check opt_check)
{
	int i;
	
	if (opt_check.is_r == 1)
	{
		i = num_files;
		while (--i >= 0)
			printf("%s\n",filenames[i]);
	}
	else
	{
		i = -1;
		while (++i < num_files)
			printf("%s\n", filenames[i]);
	}
}

void	ls_print_l(char **filename, int num_files, t_opt_check opt_check)
{
	struct stat		file;
	int				i;
	int				date_counter;
	
	i = 0;

	while (i < num_files)
	{
		lstat(filename[i], &file);
		printf("total %d\n", file.st_blksize);
		printf((file.st_mode & S_IRUSR) ? "r" : "-");
		printf((file.st_mode & S_IWUSR) ? "w" : "-");
		printf((file.st_mode & S_IXUSR) ? "x" : "-");
		printf((file.st_mode & S_IRGRP) ? "r" : "-");
		printf((file.st_mode & S_IWGRP) ? "w" : "-");
		printf((file.st_mode & S_IXGRP) ? "x" : "-");
		printf((file.st_mode & S_IROTH) ? "r" : "-");
		printf((file.st_mode & S_IWOTH) ? "w" : "-");
		printf((file.st_mode & S_IXOTH) ? "x  " : "-  ");
		// printf("%u ", file.link);
		// printf("%s  ", file.user);
		// printf("%s  ", file.group);
		// printf("%*lld ", prev ,file.st_size);
		date_counter = 4;
		while (date_counter <= 15)
			printf("%c", ctime(&file.st_mtime)[date_counter++]);
		printf(" %s\n", filename[i]);
		i++;
	}
}

void	ls_print(char **filenames, int num_files, t_opt_check opt_check)
{
	if (opt_check.is_l != 1)
		ls_print_reg(filenames, num_files, opt_check);
	else
		ls_print_l(filenames, num_files, opt_check);
}