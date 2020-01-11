/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dholiday <dholiday@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/13 13:53:13 by dholiday          #+#    #+#             */
/*   Updated: 2019/09/09 15:53:55 by dholiday         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include "mlx.h"
# include <unistd.h>
# include <stdlib.h>
# include "Libft/libft.h"
# include <fcntl.h>
# include <math.h>
# include <sys/types.h>
# include <pwd.h>
# include <sys/stat.h>
# include <dirent.h>
# include <stdio.h>
# include <stdlib.h>
# include <time.h>
# include <stddef.h>
# include <errno.h>
# include <sys/ioctl.h>
# include <sys/types.h>
# include <sys/xattr.h>
# include <grp.h>
# define XATTR_SIZE 10000

typedef struct		s_param
{
	char			*str;
	struct s_param	*next;
}					t_param;

typedef struct		s_razriad
{
	int				links;
	int				user;
	int				size;
	int				day;
	int				half_year;
}					t_razriad;

typedef struct		s_data
{
	int				x;
	int				y;
	int				z;
	int				type;
	char			*name;
	char			*path;
	char			*type_mod;
	char			**date;
	struct dirent	*readdir;
	struct passwd	*p;
	DIR				*a;
	struct s_data	*next;
	struct s_data	*prev;
	struct s_data	*dir;
	t_razriad		op;
	struct stat		stat;
}					t_data;

typedef struct		s_flags
{
	int				a;
	int				rev;
	int				rec;
	int				t;
	int				l;
	int				m;
	int				one;
	int				p;
	int				g;
}					t_flags;

typedef struct		s_for_l
{
	int				links;
	int				user;
	int				year;
	int				size;
	int				mounth;
	int				day;
	int				time;
}					t_for_l;

typedef struct		s_ancho
{
	int				max_name;
	int				no_flag;
	int				sum;
	int				window_size;
	int				two_dash;
	long int		now;
	int				errno_o;
	t_data			*files;
	t_data			*dir;
	t_data			*end;
	t_data			*error;
	t_flags			flags;
	t_for_l			for_l;
	t_data			*start;
}					t_ancho;

void				ft_parset(int argc, char **argv, t_ancho *pansa);
void				ft_flags(char *str, t_ancho *pansa);

t_data				*ft_create_elem(struct dirent *k,
		t_ancho *pansa, char *str);
t_data				*ft_put_elem_to_list(t_data *new, t_data *head);
void				ft_print_list1(t_ancho *pansa);
void				ft_print_list2(t_data *temp, t_ancho *pansa);
int					ft_window(t_ancho *pansa);
t_data				*ft_go(t_data *temp, int k, char c);
t_data				*ft_go2(t_data *temp, int k, char c);
void				ft_put_and_go(t_ancho *pansa,
	t_data *temp, int colons, int i);
void				ft_print_comma(t_ancho *pansa, t_data *temp);

t_data				*ft_flag_rec(char *str, t_data *temp, t_ancho *pansa);
void				ft_print_list_rec1(t_ancho *pansa,
		t_data *start, char *str);

t_param				*ft_put_param_to_list(t_param *new, t_param *head);
t_param				*ft_create_param(t_param *temp, char *str);

void				ft_read_all(t_ancho *pansa, char *str);
void				ft_apply(t_ancho *pansa, char *str);
void				ft_enum_files(t_ancho *pansa, int argc, char **argv);

void				ft_print_list_rec(t_data *head);
void				ft_clean_list(t_data *hello);
void				ft_clean_param(t_param *hello);

t_data				*ft_sort_check(t_ancho *pansa, t_data *head, t_data *new);
t_data				*ft_sort_alpha(t_data *head, t_data *new);
void				ft_prev_null_sort(t_data *head, t_data *new);
t_data				*ft_sort_time(t_data *head, t_data *new);
t_data				*ft_same_time(t_data *head, t_data *new, t_data *temp);
t_data				*ft_time_next_null(t_data *head, t_data *new);
int					ft_prev_sort(t_data *head, t_data *new);
int					ft_time_put_new(t_data *head, t_data *new);
void				ft_print_list_details(t_data *start, t_ancho *pansa);
void				ft_under_mod(t_data *k);
void				ft_print_mod(t_data *k);
void				ft_mod_letter(char i, char *mode);
void				ft_print_date(t_data *k, t_ancho *pansa);
int					ft_count_total(t_data *start);
void				ft_init_l(t_for_l *new);
void				ft_find_max(t_ancho *pansa, t_data *temp);
void				ft_print_list_rev(t_data *start, t_ancho *pansa);
void				ft_end(t_ancho *pansa, t_data *head);

void				ft_print_one(t_ancho *pansa, t_data *temp);
void				ft_puterror(char *str);
void				ft_cherror(char c);
void				ft_print_list_error(t_data *start);
t_data				*ft_create_error_elem(char *str);
void				ft_color(t_data *temp, t_ancho *pansa);

#endif
