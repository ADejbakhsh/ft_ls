/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adejbakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 15:36:53 by adejbakh          #+#    #+#             */
/*   Updated: 2019/02/17 11:11:06 by adejbakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include <sys/stat.h>
# include <sys/types.h>
# include <pwd.h>
# include <dirent.h>
# include "../libft/includes/libft.h"
# include <time.h>
# include <grp.h>
# define DAY 86400
# define HOUR 3600
# define MIN 60
# define YEAR 31556926
# define MONTH 2629743

typedef	struct		s_info
{
	char			*name;
	char			*mode;
	char			*time;
	char			*size;
	char			*owner;
	char			*group;
	char			*usr_id;
	char			*nbl;
	char			*link;
	char			*major;
	char			*minor;
	int				block;
	long			nano;

	struct s_info	*next;
}					t_info;

struct s_info		*ft_sort_struc_rev(t_info *p);
struct s_info		*ft_opendir(char *str);
struct s_info		*ft_sort_struc_ascii(t_info *p);
struct s_info		*ft_inspect_file(char *str);
struct s_info		*ft_sort_hub(t_info *p, int *tab);

int					ft_free_struc(t_info *p);
int					ft_argv_time_reverse(char **argv);
int					ft_argv_time(char **argv);
int					ft_print_error(char *str);
int					ft_menu(int argc, char **argv);
int					ft_puttime(char *str, size_t b);
int					ft_option(t_info *p, char *str, int tab[]);
int					ft_recursive(t_info *p, char *str, int tab[]);
int					ft_start_option(char **argv, int tab[]);
int					ft_nb_argv_is_two(char **argv);
int					ft_prints(t_info *p, int a);
int					ft_print_l(t_info *p, int a, int r);
char				**ft_open_not_dir(char **argv, int tab[]);
int					ft_is_not_a_dir(char *str);
int					ft_security_input(int argc, char **argv);
int					ft_print_hub(t_info *p, int a, int l, int r);
char				*ft_naming(char *s1, char *s2);
char				*ft_strmode(int mode, char *str);
void				ft_swap(t_info *a, t_info *b);
void				ft_default(int argc, char **argv);
void				ft_free_tab(char **argv);
void				ft_paddind_total_print(int a, int block);
void				ft_space(int a, int b);

#endif
