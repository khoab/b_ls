/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbui <kbui@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/29 13:39:39 by kbui              #+#    #+#             */
/*   Updated: 2018/10/19 19:39:03 by kbui             ###   ########.fr       */
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
	int			is_l;
	int			is_a;
	int			is_r;
	int			is_time;
	int			illegal_opt;
}				t_opt_check;

typedef struct	s_mycheck
{
	int			is_error;
	int			is_file;
}				t_mycheck;

/*
** Libft
*/

void			ft_memdel(void **ap);	
int				ft_strcmp(const char *s1, const char *s2);
size_t			ft_strlen(const char *str);
char			*ft_strdup(const char *s1);
void			ft_strswap(char **s1, char **s2);
int				ft_isfile(char *filename);
void			*ft_memset(void *b, int c, size_t len);
char			*ft_strjoin(char const *s1, char const *s2);
void			*ft_memalloc(size_t size);
void			ft_bzero(void *str, size_t n);
char			*ft_strcat(char *dst, const char *src);
char			*ft_strrchr(const char *s, int c);

/*
** Print function
*/

void			ls_print_reg(char **filenames, int num_files, t_opt_check opt_check);
void			ls_print_l(char **filename, char *dirname, int num_files, t_opt_check opt_check);
void			ls_print(char **filenames, char *dirname, int num_files, t_opt_check opt_check);

/*
** Sorting function
*/

int				ls_timecmp(char *filename1, char *filename2);
void			ls_shellsort(char **filenames, int num, int is_time);

/*
** Check if have dir or not then do it
*/

void			ls_fn_casenodir(t_opt_check opt_check);
void			ls_fn_casedir(char **valid_dirname, int dir_size,
					t_mycheck mycheck, t_opt_check opt_check);

/*
** Those function will define and printout all filename that have been input
*/

int				ls_filesize(char **av, int ar, int start);
char			**ls_valid_filename(char **av, int ar, int start, int file_size);
void			ls_filename_input(char **av, int ar, int start,
					int *is_file, t_opt_check opt_check);

/*
** Finding dirname and filename handler
*/

char			**ls_valid_dirname(char **av, int ar, int start, t_opt_check opt_check);
int				ls_num_file(char *dirname, t_opt_check opt_check);
int				ls_dirname(int ar, int start, char **av, t_opt_check opt_check);
char			**ls_path_filenames(char *dirname, t_opt_check opt_check);
char			**ls_filenames(char **path_filenames, int num_files);

/*
** Optiong handler and main checker
*/

int				ls_num_opt(int size, char **opt);
t_opt_check		ls_opt_check(char **av, int num_of_opt);
int				b_ls(int ar, char **av);

#endif