/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbui <kbui@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/29 13:39:39 by kbui              #+#    #+#             */
/*   Updated: 2018/10/04 23:12:58 by kbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

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

void			*ft_memcpy(void *dst, const void *src, size_t n);
int				ft_strcmp(const char *s1, const char *s2);
char			*ft_strcpy(char *dst, const char *src);
size_t			ft_strlen(const char *str);
char			*ls_chhid_strdup(const char *str, t_opt_check opt_check);
char			*ft_strdup(const char *s1);
void			ls_strswap(char **t1, char **t2);
void			ls_shellsort(char **filenames, int numf, t_opt_check opt_check);

char			**ls_valid_dirname(char **av, int ar, int start);
void			ls_dirname(int ar, int start, char **av, t_opt_check opt_check);
int				ls_num_file(char *dirname, t_opt_check opt_check);
char			**ls_filenames(char *dirname, t_opt_check opt_check);

int				ls_num_opt(int size, char **opt);
t_opt_check		ls_opt_check(char **av, size_t num_of_opt);
int				b_ls(int ar, char **av);

#endif
