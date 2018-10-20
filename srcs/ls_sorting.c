/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_sorting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbui <kbui@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/04 10:40:53 by kbui              #+#    #+#             */
/*   Updated: 2018/10/19 19:46:59 by kbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <time.h>
#include "libft.h"

int		ls_timecmp_nanosec(struct stat attr, struct stat attr2)
{
	long long	t1;
	long long	t2;

	t1 = attr.st_mtimespec.tv_nsec;
	t2 = attr2.st_mtimespec.tv_nsec;
	return (t1 - t2);
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
	if (t1 != t2)
		return (t1 - t2);
	else
		return (ls_timecmp_nanosec(attr, attr2));
}

void	ls_shellsort(char **filenames, int num, int is_time)
{
	int		i;
	int		j;
	int		k;

	i = num / 2;
	while (i > 0)
	{
		j = i;
		while (j < num)
		{
			k = j - i;
			while (k >= 0)
			{
				if (is_time == 1)
				{
					if (ls_timecmp(filenames[k], filenames[k + 1]) > 0)
						break ;
				}
				else
					if (ft_strcmp(filenames[k + i], filenames[k]) > 0)
						break ;
				ft_strswap(&filenames[k], &filenames[k + i]);
				k -= i;
			}
			j++;
		}
		i /= 2;
	}
}
