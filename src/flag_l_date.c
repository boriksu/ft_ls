/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_l.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dholiday <dholiday@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 17:03:41 by tguillem          #+#    #+#             */
/*   Updated: 2019/09/09 15:52:10 by dholiday         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_print_year(t_data *k)
{
	ft_putstr("2019 ");
}

void	ft_print_date(t_data *k, t_ancho *pansa)
{
	int				i;
	char			*s;
	struct group	*p;

	p = getgrgid(k->stat.st_gid);
	ft_printf("%s ", p->gr_name);
	i = pansa->for_l.size - k->op.size + 1;
	while (i > 0)
	{
		ft_putchar(' ');
		i--;
	}
	ft_printf("%d ", k->stat.st_size);
	ft_printf("%s ", k->date[1]);
	ft_printf("%2s ", k->date[2]);
	if (k->op.half_year == 1)
	{
		s = ft_strchr(k->date[4], '\n');
		s[0] = '\0';
		ft_printf(" %s ", k->date[4]);
	}
	else
		ft_printf("%.5s ", k->date[3]);
}

int		ft_count_total(t_data *start)
{
	int i;

	i = 0;
	while (start != NULL)
	{
		i += start->stat.st_blocks;
		start = start->next;
	}
	return (i);
}

void	ft_color(t_data *temp, t_ancho *pansa)
{
	if (pansa->flags.g == 0)
		ft_putstr(temp->name);
	else if (temp->type == 4)
		ft_printf("\033[34;1;1m%s\033[0m", temp->name);
	else if (temp->type == 12)
		ft_printf("\033[35;1;1m%s\033[0m", temp->name);
	else if (temp->type == 1)
		ft_printf("\033[33;1;1m%s\033[0m", temp->name);
	else
		ft_putstr(temp->name);
	if (pansa->flags.p == 1 && temp->type == 4)
		ft_putchar('/');
}
