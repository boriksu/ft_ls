/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dholiday <dholiday@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 17:03:41 by tguillem          #+#    #+#             */
/*   Updated: 2019/09/09 15:52:50 by dholiday         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		ft_window(t_ancho *pansa)
{
	int				colons;
	struct winsize	window_size;
	int				p;

	if (pansa->window_size == 0)
	{
		ioctl(0, TIOCGWINSZ, &window_size);
		pansa->window_size = (int)window_size.ws_col;
		pansa->window_size = pansa->window_size <
				pansa->max_name ? pansa->max_name : pansa->window_size;
	}
	if (pansa->max_name == 0)
	{
		colons = 0;
		pansa->max_name = pansa->max_name == 0 ? 1 : pansa->max_name;
	}
	else
	{
		p = (pansa->window_size / (pansa->max_name + 1));
		if ((pansa->sum) % p != 0)
			colons = (pansa->sum / p) + 1;
		else
			colons = (pansa->sum / p);
	}
	return (colons);
}

void	ft_print_list_rev(t_data *start, t_ancho *pansa)
{
	t_data	*temp;
	int		i;
	int		j;
	int		colons;

	j = 1;
	colons = ft_window(pansa);
	while (j <= colons)
	{
		temp = ft_go(start, j, '<');
		i = 1;
		while (temp != NULL && i <= pansa->window_size / pansa->max_name)
		{
			ft_put_and_go(pansa, temp, colons, i);
			if ((temp = ft_go2(temp, colons, '<')) == NULL)
				break ;
			i++;
		}
		ft_putchar('\n');
		j++;
	}
	pansa->sum = 0;
	pansa->max_name = 0;
}

void	ft_print_comma(t_ancho *pansa, t_data *temp)
{
	if (temp == NULL)
		return ;
	if (pansa->flags.rev == 1)
	{
		ft_end(pansa, temp);
		temp = pansa->end;
		while (temp != NULL)
		{
			ft_putstr(temp->name);
			if (temp->prev != NULL)
				ft_printf(", ");
			temp = temp->prev;
		}
		pansa->end = NULL;
	}
	else
		while (temp != NULL)
		{
			ft_putstr(temp->name);
			if (temp->next != NULL)
				ft_printf(", ");
			temp = temp->next;
		}
	ft_putchar('\n');
}

void	ft_go_one(t_data *temp, t_ancho *pansa)
{
	while (temp != NULL)
	{
		ft_putstr(temp->name);
		if (pansa->flags.p == 1 && temp->type == 4)
			ft_putchar('/');
		if (temp->next != NULL)
			ft_printf("\n");
		temp = temp->next;
	}
}

void	ft_print_one(t_ancho *pansa, t_data *temp)
{
	if (temp == NULL)
		return ;
	if (pansa->flags.rev == 1)
	{
		ft_end(pansa, temp);
		temp = pansa->end;
		while (temp != NULL)
		{
			ft_putstr(temp->name);
			if (pansa->flags.p == 1 && temp->type == 4)
				ft_putchar('/');
			if (temp->prev != NULL)
				ft_printf("\n");
			temp = temp->prev;
		}
		pansa->end = NULL;
	}
	else
		ft_go_one(temp, pansa);
	ft_putchar('\n');
}
