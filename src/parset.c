/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parset.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dholiday <dholiday@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 17:03:41 by tguillem          #+#    #+#             */
/*   Updated: 2019/09/09 15:54:41 by dholiday         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_ancho	*ft_sort(t_ancho *pansa, char **argv, int i)
{
	char	buf[100];

	if (errno == ENOTDIR)
		pansa->files = ft_sort_check(pansa, pansa->files,
			ft_create_elem(NULL, pansa, argv[i]));
	else if (readlink(argv[i], buf, 100) != -1 && errno == ENOENT)
		pansa->files = ft_sort_check(pansa,
			pansa->files, ft_create_elem(NULL, pansa, argv[i]));
	else
		pansa->error = ft_sort_check(pansa,
			pansa->error, ft_create_error_elem(argv[i]));
	return (pansa);
}

t_ancho	*ft_no_flags(t_ancho *pansa, char **argv, int i)
{
	DIR		*a;

	if ((a = opendir(argv[i])) == NULL)
		pansa = ft_sort(pansa, argv, i);
	else
	{
		closedir(a);
		pansa->dir = ft_sort_check(pansa,
			pansa->dir, ft_create_elem(NULL, pansa, argv[i]));
	}
	return (pansa);
}

t_ancho	*ft_no_flags2(t_ancho *pansa, char **argv, int i)
{
	DIR		*a;
	char	buf[100];

	if (pansa->no_flag == 1)
	{
		if (readlink(argv[i], buf, 100) != -1 && pansa->flags.l == 1)
			pansa->files = ft_sort_check(pansa,
				pansa->files, ft_create_elem(NULL, pansa, argv[i]));
		else if ((a = opendir(argv[i])) == NULL)
			pansa = ft_sort(pansa, argv, i);
		else
		{
			closedir(a);
			pansa->dir = ft_sort_check(pansa,
				pansa->dir, ft_create_elem(NULL, pansa, argv[i]));
		}
	}
	return (pansa);
}

void	ft_parset(int argc, char **argv, t_ancho *pansa)
{
	int		i;

	i = 1;
	while (i < argc)
	{
		if (pansa->no_flag == 1)
			pansa = ft_no_flags(pansa, argv, i);
		else
		{
			ft_flags(argv[i], pansa);
			if (pansa->two_dash == 1)
			{
				if (argc - i == 1)
					return ;
				pansa->no_flag = 1;
				i++;
				continue ;
			}
			pansa = ft_no_flags2(pansa, argv, i);
		}
		i++;
	}
	ft_print_list_error(pansa->error);
	ft_clean_list(pansa->error);
}
