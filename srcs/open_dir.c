/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_dir.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adejbakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 15:37:09 by adejbakh          #+#    #+#             */
/*   Updated: 2019/01/26 16:53:15 by adejbakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char			*ft_naming(char *s1, char *s2)
{
	size_t	a;
	size_t	b;
	char	*str;

	b = 0;
	a = 0;
	if (s2 == NULL)
		return (NULL);
	if (s1 != NULL)
		a = ft_strlen(s1);
	a += ft_strlen(s2);
	if (!(str = (char*)malloc(sizeof(*str) * a + 2)))
		return (NULL);
	a = 0;
	if (s1 != NULL)
		while (s1[a])
			str[a++] = s1[b++];
	b = 0;
	if (str[a - 1] != '/')
		str[a++] = '/';
	while (s2[b])
		str[a++] = s2[b++];
	str[a] = '\0';
	return (str);
}

t_info	*ft_auto_open_dir(DIR *dirp, struct dirent *direntp, char *str)
{
	char	*t;
	t_info	*p;
	t_info	*start;

	t = ft_naming(str, direntp->d_name);
	p = ft_inspect_file(t);
	start = p;
	ft_strdel(&t);
	while ((direntp = readdir(dirp)) != NULL)
	{
		t = ft_naming(str, direntp->d_name);
		p->next = ft_inspect_file(t);
		ft_strdel(&t);
		p = p->next;
	}
	p->next = NULL;
	closedir(dirp);
	return (start);
}

struct s_info	*ft_opendir(char *str)
{
	char			*t;
	struct dirent	*direntp;
	DIR				*dirp;

	t = NULL;
	dirp = opendir(str);
	if (dirp == NULL)
		return (NULL);
	direntp = readdir(dirp);
	return (ft_auto_open_dir(dirp, direntp, str));
}

void	ft_print_notl(t_info *p, int a)
{
	if (p == NULL)
		return ;
	if (a == 0 && p->name[0] == '.')
	{
		ft_print_notl(p->next, a);
		return ;
	}
/*	ft_putin(1, p->mode);
	ft_putin(2, "\t", p->nbl);
	ft_putin(2, "\t", p->time);
	ft_putin(2, "\t", p->size);
	ft_putin(2, "\t", p->owner);
*/	ft_putin(3, "\t", p->name, "\t");
	ft_putstr("\n");
	ft_print_notl(p->next, a);
}
