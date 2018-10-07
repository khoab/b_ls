/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_sort_ascii.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbui <kbui@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/29 12:58:48 by kbui              #+#    #+#             */
/*   Updated: 2018/09/29 13:38:07 by kbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "../libft/libft.h"

void	ls_sort_ascii(char **filename, int tab_size)
{
	int		i;
	int 	j;
	int 	len_i;
	int 	len_j;
	char	*temp;

	i = 0;
	while (i++ < tab_size - 1)
	{
		j = i + 1;
		while (j++ < tab_size)
		{
			if (ft_strcmp(filename[i], filename[j]) > 0)
			{
				if (ft_strlen(filename[i]) > ft_strlen(filename[j]))
					temp = (char *)malloc(sizeof(temp) * (ft_strlen(filename[i]) + 1));
				else
					temp = (char *)malloc(sizeof(temp) * (ft_strlen(filename[j]) + 1));
				ft_strcpy(temp, filename[i]);
				ft_strcpy(filename[i], filename[j]);
				ft_strcpy(filename[j], temp);
				free (temp);
			}
		}
	}
}

int main(void)
{
	char **filename = {"filea","afile", "zfile", ",file"};
	int size = 4;
	int n = 0;
	ls_sort_ascii(filename, size);
	while (n++ < size)
		printf("%s\n", filename[n]);
	return (0);
}