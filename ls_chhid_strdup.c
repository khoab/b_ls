/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_chhid_strdup.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbui <kbui@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/02 19:38:01 by kbui              #+#    #+#             */
/*   Updated: 2018/10/09 18:36:03 by kbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char		*ls_chhid_strdup(char *str, t_opt_check opt_check)
{
	char 	*dup;
	int		i;

	i = 0;
	if (opt_check.is_a != 1)
	{
		if (str[i] == '.')
		{
			dup = "\0";
			return (dup);
		}
	}
	dup = (char *)malloc(ft_strlen(str) + 1);
	while (str[++i])
		dup[i] = str[i];
	dup[i] = '\0';
	return (dup);
}