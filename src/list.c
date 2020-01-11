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

int		ft_is_end_of_line(t_data *data, int colons, t_ancho *pansa)
{
	t_data *temp;

	temp = data;
	while (colons >= 1 && temp != NULL)
	{
		if (pansa->flags.rev == 1)
			temp = temp->prev;
		else
			temp = temp->next;
		colons--;
	}
	if (temp == NULL)
		return (0);
	return (1);
}

t_data	*ft_go(t_data *temp, int k, char c)
{
	while (k > 1 && temp->next != NULL)
	{
		if (c == '>')
			temp = temp->next;
		else
			temp = temp->prev;
		k--;
	}
	return (temp);
}

void	ft_put_and_go(t_ancho *pansa, t_data *temp, int colons, int i)
{
	int a;

	ft_color(temp, pansa);
	a = pansa->max_name + 1 - ft_strlen(temp->name);
	if (i % (pansa->window_size / pansa->max_name) != 0 &&
		ft_is_end_of_line(temp, colons, pansa) == 1)
	{
		if (pansa->flags.rev == 1)
			while (a >= 1 && temp->prev != NULL)
			{
				a--;
				ft_putchar(' ');
			}
		else
		{
			while (a >= 1 && temp->next != NULL)
			{
				a--;
				ft_putchar(' ');
			}
		}
	}
}

t_data	*ft_go2(t_data *temp, int k, char c)
{
	while (k >= 1 && temp != NULL)
	{
		if (c == '>')
			temp = temp->next;
		else
			temp = temp->prev;
		k--;
	}
	return (temp);
}

void	ft_print_list2(t_data *start, t_ancho *pansa)
{
	t_data	*temp;
	int		i;
	int		j;
	int		colons;

	j = 1;
	colons = ft_window(pansa);
	while (j <= colons)
	{
		temp = ft_go(start, j, '>');
		i = 1;
		while (temp != NULL && i <= pansa->window_size / pansa->max_name)
		{
			ft_put_and_go(pansa, temp, colons, i);
			if ((temp = ft_go2(temp, colons, '>')) == NULL)
				break ;
			i++;
		}
		ft_putchar('\n');
		j++;
	}
	pansa->sum = 0;
	pansa->max_name = 0;
}
