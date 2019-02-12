/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inspect_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adejbakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 16:24:47 by adejbakh          #+#    #+#             */
/*   Updated: 2019/02/13 00:10:17 by adejbakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static char				*ft_time_strsub(char const *s)
{
	size_t	a;
	size_t	start;
	char	*str;

	start = 4;
	a = 0;
	if (s == NULL)
		return (NULL);
	if (!(str = (char*)malloc(sizeof(*str) * 12 + 1)))
		return (NULL);
	while (a < 6)
	{
		str[a] = s[start];
		start++;
		a++;
	}
	start = 19;
	str[a] = ' ';
	while (a++ < 11)
	{
		str[a] = s[start];
		start++;
	}
	str[a] = '\0';
	return (str);
}

static struct s_info	*ft_sec_stat(t_info **p, struct stat buf)
{
	(*p)->time = ctime(&buf.st_mtime);
	(*p)->nano = buf.st_mtime;
	if (ft_puttime(ft_strdup(ctime(&buf.st_mtime)), time(0)) == 1)
		if (!((*p)->time = ft_time_strsub((*p)->time)))
			return (NULL);
	if (ft_puttime(ft_strdup(ctime(&buf.st_mtime)), time(0)) == 0)
		if (!((*p)->time = ft_strsub((*p)->time, 4, 12)))
			return (NULL);
	if (!((*p)->size = ft_itoa(buf.st_size)))
		return (NULL);
	if (!((*p)->minor = ft_itoa(buf.st_rdev & 0xFF)))
		return (NULL);
	if (!((*p)->major = ft_itoa(major(buf.st_rdev))))
		return (NULL);
	if (!((*p)->nbl = ft_itoa(buf.st_nlink)))
		return (NULL);
	(*p)->next = NULL;
	return (*p);
}

struct s_info			*ft_inspect_file(char *str)
{
	t_info			*p;
	struct stat		buf;
	struct passwd	*pwd;
	struct group	*grp;

	if (lstat(str, &buf) == -1 || !(p = (t_info*)malloc(sizeof(*p))))
		return (NULL);
	if (!(p->mode = ft_strnew(11)))
		return (NULL);
	p->mode = ft_strmode(buf.st_mode, p->mode);
	if (!(p = ft_sec_stat(&p, buf)))
		return (NULL);
	pwd = getpwuid(buf.st_uid);
	if (pwd)
		p->owner = pwd->pw_name;
	if ((grp = getgrgid(buf.st_gid)))
		p->group = grp->gr_name;
	else
		p->group = NULL;
	p->name = ft_cut_before_last_cara(str, '/');
	if (!(p->link = ft_strnew(400)))
		return (NULL);
	readlink(str, p->link, 400);
	p->block = buf.st_blocks;
	return (p);
}

int						ft_free_struc(t_info *p)
{
	if (p == NULL)
		return (0);
	ft_free_struc(p->next);
	free(p->nbl);
	free(p->mode);
	free(p->size);
	free(p->time);
	free(p->link);
	free(p->major);
	free(p->minor);
	free(p->name);
	free(p);
	return (0);
}
