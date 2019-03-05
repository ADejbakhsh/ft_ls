/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inspect_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adejbakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 16:24:47 by adejbakh          #+#    #+#             */
/*   Updated: 2019/03/05 12:08:09 by adejbakh         ###   ########.fr       */
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
	if ((buf.st_mtime) > time(0) || (time(0) - buf.st_mtime) >= 15778458)
		if (!((*p)->time = ft_time_strsub((*p)->time)))
			return (ft_free_struc(*p));
	if (buf.st_mtime <= time(0) && (time(0) - buf.st_mtime) < 15778458)
		if (!((*p)->time = ft_strsub((*p)->time, 4, 12)))
			return (ft_free_struc(*p));
	if (!((*p)->size = ft_itoa(buf.st_size)))
		return (ft_free_struc(*p));
	if (!((*p)->minor = ft_itoa(buf.st_rdev & 0xFF)))
		return (ft_free_struc(*p));
	if (!((*p)->major = ft_itoa(major(buf.st_rdev))))
		return (ft_free_struc(*p));
	if (!((*p)->nbl = ft_itoa(buf.st_nlink)))
		return (ft_free_struc(*p));
	(*p)->next = NULL;
	(*p)->block = buf.st_blocks;
	(*p)->usr_id = ft_itoa(buf.st_uid);
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
		return (ft_free_struc(p));
	p->mode = ft_strmode(buf.st_mode, p->mode);
	if (!(p = ft_sec_stat(&p, buf)))
		return (ft_free_struc(p));
	pwd = getpwuid(buf.st_uid);
	p->owner = NULL;
	if (pwd)
		p->owner = ft_strdup(pwd->pw_name);
	if ((grp = getgrgid(buf.st_gid)))
		p->group = grp->gr_name;
	else
		p->group = NULL;
	p->name = ft_cut_before_last_cara(str, '/');
	if (!(p->link = ft_strnew(400)))
		return (ft_free_struc(p));
	readlink(str, p->link, 400);
	return (p);
}

t_info					*ft_free_struc(t_info *p)
{
	if (p->next != NULL)
		ft_free_struc(p->next);
	if (p->nbl)
		free(p->nbl);
	if (p->mode)
		free(p->mode);
	if (p->size)
		free(p->size);
	if (p->time)
		free(p->time);
	if (p->link)
		free(p->link);
	if (p->major)
		free(p->major);
	if (p->minor)
		free(p->minor);
	if (p->name)
		free(p->name);
	if (p->usr_id)
		free(p->usr_id);
	if (p->owner)
		free(p->owner);
	free(p);
	return (NULL);
}
