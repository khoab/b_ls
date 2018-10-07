/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbui <kbui@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/04 23:46:20 by kbui              #+#    #+#             */
/*   Updated: 2018/10/06 14:31:14 by kbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <time.h>
#include "libft.h"

void	ls_print_reg(char **filenames, int num_files, t_opt_check opt_check)
{
	int i;
	
	if (opt_check.is_r == 1)
	{
		i = num_files;
		while (i-- >= 0)
			printf("%s\n",filenames[i]);
	}
	else
	{
		i = -1;
		while (++i < num_files)
			printf("%s\n", filenames[i]);
	}
}

void	ls_print_l(char **filesname, int num_files, t_opt_check opt_check)
{
	int i;

	i = 0;
	printf("total %d\n", block_size);
	while (i < ar)
	{
		struct stat		file;
		printf((file.perm & S_IRUSR) ? "r" : "-");
		printf((file[i].perm & S_IWUSR) ? "w" : "-");
		printf((file[i].perm & S_IXUSR) ? "x" : "-");
		printf((file[i].perm & S_IRGRP) ? "r" : "-");
		printf((file[i].perm & S_IWGRP) ? "w" : "-");
		printf((file[i].perm & S_IXGRP) ? "x" : "-");
		printf((file[i].perm & S_IROTH) ? "r" : "-");
		printf((file[i].perm & S_IWOTH) ? "w" : "-");
		printf((file[i].perm & S_IXOTH) ? "x  " : "-  ");
		printf("%u ", file[i].link);
		printf("%s  ", file[i].user);
		printf("%s  ", file[i].group);
		printf("%*lld ", prev ,file[i].size);
		date_counter = 4;
		while (date_counter <= 15)
			printf("%c", file[i].timestamp[date_counter++]);
		printf(" %s\n", file[i].name);
		i++;
}

void	ls_print(char **filenames, int num_files, t_opt_check opt_check)
{
	if (opt_check.is_l != 1)
		ls_print_reg(filenames, num_files, opt_check);
	else
		ls_print_l(filenames, num_files, opt_check);	
}