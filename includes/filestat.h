/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filestat.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbui <kbui@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/29 15:10:05 by kbui              #+#    #+#             */
/*   Updated: 2018/10/02 19:55:11 by kbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILESTAT_H
# define FILESTAT_H

# include <string.h>

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

#endif
