/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   razriad.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dholiday <dholiday@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 17:03:41 by tguillem          #+#    #+#             */
/*   Updated: 2019/09/05 21:01:47 by dholiday         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include <sys/ioctl.h>

int		ft_razr(int n)
{
	int i;

	i = 1;
	while (n >= 10)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

void	ft_find_max(t_ancho *pansa, t_data *temp)
{
	char	*str;
	char	**date;

	str = ctime(&temp->stat.st_mtimespec.tv_sec);
	temp->date = ft_strsplit(str, ' ');
	temp->p = getpwuid(temp->stat.st_uid);
	temp->op.links = ft_razr(temp->stat.st_nlink);
	if (pansa->for_l.links < temp->op.links)
		pansa->for_l.links = temp->op.links;
	temp->op.half_year = 0;
	if (temp->stat.st_mtimespec.tv_sec >= 15778800 + pansa->now)
		temp->op.half_year = 1;
	else if (temp->stat.st_mtimespec.tv_sec <= pansa->now - 15778800)
		temp->op.half_year = 1;
	temp->op.user = ft_strlen(temp->p->pw_name);
	if (pansa->for_l.user < temp->op.user)
		pansa->for_l.user = temp->op.user;
	temp->op.size = ft_razr(temp->stat.st_size);
	if (pansa->for_l.size < temp->op.size)
		pansa->for_l.size = temp->op.size;
	temp->op.day = ft_strlen(temp->date[2]);
	if (pansa->for_l.day < temp->op.day)
		pansa->for_l.day = temp->op.day;
	temp->type_mod = ft_conv_octal(temp->stat.st_mode);
	temp->type = ft_atoi(temp->type_mod) / 10000;
}
