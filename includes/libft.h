/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbui <kbui@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/29 13:39:39 by kbui              #+#    #+#             */
/*   Updated: 2018/10/03 10:50:57 by kbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

#include <string.h>

typedef	struct	s_filestat
{
	char		*filename;
	size_t		is_hidden;
	char		*file_permision[10];
	int			number_of_links;
	char		*owner_name;
	char		*gr_name;
	int			file_size;
	char		*last_modify;
}				t_filestat;

typedef	struct	s_opt_check
{
	size_t		is_l;
	size_t		is_a;
	size_t		is_r;
	size_t		is_time;
	size_t		illegal_opt;
}				t_opt_check;

void		*ft_memcpy(void *dst, const void *src, size_t n);

int			ft_strcmp(const char *s1, const char *s2);
char		*ft_strcpy(char *dst, const char *src);
size_t		ft_strlen(const char *str);
char		*ls_chhid_strdup(const char *str, t_opt_check opt_check);
char		*ft_strdup(const char *s1);

#endif