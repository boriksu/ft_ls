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

void	ft_print_bytes(t_data *k)
{
	ft_printf("%d ", k->stat.st_size);
}

void	ft_print_links(t_data *k, t_ancho *pansa)
{
	int i;

	i = pansa->for_l.links - k->op.links + 1;
	while (i > 0)
	{
		ft_putchar(' ');
		i--;
	}
	ft_printf("%d ", k->stat.st_nlink);
}

void	ft_print_name(t_data *k, t_ancho *pansa)
{
	int i;

	i = pansa->for_l.user - k->op.user;
	while (i > 0)
	{
		ft_putchar(' ');
		i--;
	}
	ft_printf("%s  ", k->p->pw_name);
}

void	ft_link(t_data *start, t_ancho *pansa)
{
	int		i;
	char	*buf;
	char	*test;

	ft_color(start, pansa);
	buf = ft_memalloc(100);
	if (start->path == NULL)
		test = start->name;
	else
		test = start->path;
	if ((i = readlink(test, buf, 100)) >= 0)
		ft_printf(" -> %s\n", buf);
	else
		ft_printf("\n");
	ft_strdel(&buf);
}

void	ft_print_list_details(t_data *start, t_ancho *pansa)
{
	if (start == NULL)
		return ;
	if (start != NULL && start->next != NULL)
		ft_printf("total %d\n", ft_count_total(start));
	else if (start->readdir != NULL)
		ft_printf("total %d\n", ft_count_total(start));
	if (pansa->flags.rev == 1)
		start = pansa->end;
	while (start != NULL)
	{
		ft_print_mod(start);
		ft_print_links(start, pansa);
		ft_print_name(start, pansa);
		ft_print_date(start, pansa);
		if (start->type == 12)
			ft_link(start, pansa);
		else
		{
			ft_color(start, pansa);
			ft_putchar('\n');
		}
		start = pansa->flags.rev == 1 ? start->prev : start->next;
	}
}
