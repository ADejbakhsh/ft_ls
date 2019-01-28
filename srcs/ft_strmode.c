/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmode.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adejbakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 20:52:14 by adejbakh          #+#    #+#             */
/*   Updated: 2019/01/13 19:50:04 by adejbakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static	char	ft_strmode_sat(int mode)
{
	if (S_ISDIR(mode))
		return ('d');
	if (S_ISCHR(mode))
		return ('c');
	if (S_ISBLK(mode))
		return ('b');
	if (S_ISREG(mode))
		return ('-');
	if (S_ISLNK(mode))
		return ('l');
	if (S_ISSOCK(mode))
		return ('s');
	if (S_IFIFO == (S_IFMT & mode))
		return ('p');
	if (S_ISWHT(mode))
		return ('w');
	return ('?');
}

static	char	ft_exented_attribute(char *init)
{
	ssize_t		xattr;
	acl_entry_t	dummy;
	acl_t		acl;

	acl = acl_get_link_np(init, ACL_TYPE_EXTENDED);
	if (acl && acl_get_entry(acl, ACL_FIRST_ENTRY, &dummy) == -1)
	{
		acl_free(acl);
		acl = NULL;
	}
	xattr = listxattr(init, NULL, 0, XATTR_NOFOLLOW);
	if (xattr > 0)
	{
		free(acl);
		return ('@');
	}
	if (acl != NULL)
	{
		free(acl);
		return ('+');
	}
	return (' ');
}

static	char	ft_if(int cond, char s1, char s2)
{
	if (cond)
		return (s1);
	return (s2);
}

static	char	ft_s_if(int mode, int a, int b)
{
	if ((mode & (a | b)) == 0)
		return ('-');
	if ((mode & (a | b)) == a)
		return ('x');
	if ((mode & (a | b)) == b)
		return ('S');
	return ('s');
}

char			*ft_strmode(int mode, char *str, char *init)
{
	int	a;

	a = 0;
	if (!(mode))
		return ("error");
	str[a++] = ft_strmode_sat(mode);
	str[a++] = ft_if(S_IRUSR & mode, 'r', '-');
	str[a++] = ft_if(S_IWUSR & mode, 'w', '-');
	str[a++] = ft_s_if(mode, S_IXUSR, S_ISUID);
	str[a++] = ft_if(S_IRGRP & mode, 'r', '-');
	str[a++] = ft_if(S_IWGRP & mode, 'w', '-');
	str[a++] = ft_s_if(mode, S_IXGRP, S_ISGID);
	str[a++] = ft_if(S_IROTH & mode, 'r', '-');
	str[a++] = ft_if(S_IWOTH & mode, 'w', '-');
	str[a++] = ft_s_if(mode, S_IXOTH, S_ISVTX);
	str[a++] = ft_exented_attribute(init);
	str[a++] = '\0';
	return (str);
}
