/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbui <kbui@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/04 23:46:20 by kbui              #+#    #+#             */
/*   Updated: 2018/10/19 20:51:08 by kbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <time.h>
#include <stdlib.h>
#include <pwd.h>
#include <grp.h>
#include "libft.h"

void	ls_print_l(char **filename, char *dirname, int num_files)
{
	struct stat		file;
	int				i;
	int				date_counter;
	struct group	*grp;
	struct passwd 	*pwd;

	i = 0;
	lstat(dirname, &file);
	if (S_ISDIR(file.st_mode) == 1)
		printf("total %d\n", file.st_blksize);
	while (i < num_files)
	{
		lstat(filename[i], &file);
		pwd = getpwuid(file.st_uid);
		grp = getgrgid(file.st_gid);
		if (S_ISDIR(file.st_mode))
			printf("d");
		else
			printf((S_ISLNK(file.st_mode)) ? "l" : "-");
		printf((file.st_mode & S_IRUSR) ? "r" : "-");
		printf((file.st_mode & S_IWUSR) ? "w" : "-");
		printf((file.st_mode & S_IXUSR) ? "x" : "-");
		printf((file.st_mode & S_IRGRP) ? "r" : "-");
		printf((file.st_mode & S_IWGRP) ? "w" : "-");
		printf((file.st_mode & S_IXGRP) ? "x" : "-");
		printf((file.st_mode & S_IROTH) ? "r" : "-");
		printf((file.st_mode & S_IWOTH) ? "w" : "-");
		printf((file.st_mode & S_IXOTH) ? "x  " : "-  ");
		printf("%u ", file.st_nlink);
		printf("%s  ", pwd->pw_name);
		printf("%s  ", grp->gr_name);
		printf("%6lld ",file.st_size);
		date_counter = 4;
		while (date_counter <= 15)
			printf("%c", ctime(&file.st_mtime)[date_counter++]);
		printf(" %s\n", filename[i]);
		i++;
	}
}

void	ls_print(char **filenames, char *dirname, int num_files, t_opt_check opt_check)
{
	int i;
	
	if (opt_check.is_l != 1)
	{
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
	else
		ls_print_l(filenames, dirname, num_files);
}