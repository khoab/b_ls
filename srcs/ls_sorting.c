/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_sorting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbui <kbui@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/04 10:40:53 by kbui              #+#    #+#             */
/*   Updated: 2018/10/05 00:18:30 by kbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <time.h>
#include "libft.h"

void	ls_strswap(char **t1, char **t2)
{
	char	*t;

	t = *t1;
	*t1 = *t2;
	*t2 = t;
}

int		ls_timecmp(char *filename1, char *filename2)
{
	struct stat attr;
	struct stat attr2;
	time_t		t1;
	time_t		t2;

	lstat(filename1, &attr);
	lstat(filename2, &attr2);
	t1 = attr.st_mtime;
	t2 = attr2.st_mtime;
	if (t1 > t2)
		return (1);
	else if (t1 < t2)
		return (-1);
	else
	{
		t1 = attr.st_mtimespec.tv_nsec;
		t2 = attr2.st_atimespec.tv_nsec;
		if (t1 > t2)
			return (1);
		else
			return (-1);
	}
}

void	ls_shellsort(char **filenames, int numf, t_opt_check opt_check)
{
	int		i;
	int		j;
	int		k;

	i = numf / 2;
	while (i > 0)
	{
		j = i;
		while (j < numf)
		{
			k = j - i;
			while (k >= 0)
			{
				if (opt_check.is_time == 1)
				{
					if (ls_timecmp(filenames[k + 1], filenames[k]) == 1)
						break ;
				}
				else
					if (strcmp(filenames[k + i], filenames[k]) > 0)
						break ;
				ls_strswap(&filenames[k], &filenames[k + i]);
				k -= i;
			}
			j++;
		}
		i /= 2;
	}
}

/*
** #include <stdio.h>
** int main (int ar, char **av)
** {
** 	int i;
**
** 	i = -1;
** 	ls_shellsort(av, ar);
** 	while (++i < ar)
** 		printf("%s\n", av[i]);
** 	return (0);
** }
*/