/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dholiday <dholiday@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 17:03:41 by tguillem          #+#    #+#             */
/*   Updated: 2019/09/07 11:42:35 by dholiday         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_data	*ft_sort_check(t_ancho *pansa, t_data *head, t_data *new)
{
	if (new == NULL)
		return (head);
	if (pansa->flags.t == 1)
		return (ft_sort_time(head, new));
	else
		return (ft_sort_alpha(head, new));
}

t_data	*ft_time_next_null(t_data *head, t_data *new)
{
	if (new->stat.st_mtimespec.tv_sec < head->stat.st_mtimespec.tv_sec)
	{
		head->next = new;
		new->prev = head;
		return (head);
	}
	else if (new->stat.st_mtimespec.tv_sec ==
			head->stat.st_mtimespec.tv_sec)
		return (ft_sort_alpha(head, new));
	else
	{
		new->next = head;
		head->prev = new;
		return (new);
	}
}

int		ft_time_put_new(t_data *head, t_data *new)
{
	if (head->next == NULL)
	{
		head->next = new;
		new->prev = head;
		return (1);
	}
	return (0);
}

t_data	*ft_same_time(t_data *head, t_data *new, t_data *temp)
{
	if (head->prev == NULL)
	{
		head->prev = new;
		new->next = head;
		return (new);
	}
	else if (ft_prev_sort(head, new) == 1)
		return (temp);
	return (temp);
}
