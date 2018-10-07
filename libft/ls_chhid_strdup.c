/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_chhid_strdup.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbui <kbui@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/02 19:38:01 by kbui              #+#    #+#             */
/*   Updated: 2018/10/03 10:35:05 by kbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "filestat.h"

char		*ls_chhid_strdup(const char *str, t_opt_check opt_check)
{
	char *dup;

	if (opt_check.is_a != 1)
		if (*str == '.')
		{
			dup = "\0";
			return (dup);
		}
	dup = (char *)malloc(strlen(str) + 1);
	while (*str)
		*(dup++) = *(str++);
	*dup = '\0';
	return (dup);
}