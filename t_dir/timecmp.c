/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   timecmp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbui <kbui@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/04 22:57:33 by kbui              #+#    #+#             */
/*   Updated: 2018/10/04 23:08:17 by kbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/stat.h>
#include <sys/types.h>
#include <stdio.h>
#include <time.h>
#include <stdint.h>

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