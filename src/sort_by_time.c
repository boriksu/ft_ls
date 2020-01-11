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

t_data	*ft_time_sort_less(t_data *head, t_data *new, t_data *temp)
{
	if (head->prev == NULL)
	{
		ft_prev_null_sort(head, new);
		return (new);
	}
	else if (ft_prev_sort(head, new) == 1)
		return (temp);
	return (temp);
}

t_data	*ft_head_time_less(t_data *head, t_data *new, t_data *temp)
{
	head->next = new;
	new->prev = head;
	return (temp);
}

int		ft_if_same_time(t_data *head, t_data *new)
{
	if (new->stat.st_mtimespec.tv_sec == head->stat.st_mtimespec.tv_sec)
		return (1);
	return (-1);
}

t_data	*ft_time_sort_cycle(t_data *head, t_data *new, t_data *temp)
{
	while (head != NULL)
	{
		if (new->stat.st_mtimespec.tv_sec < head->stat.st_mtimespec.tv_sec)
		{
			if (ft_time_put_new(head, new) == 1)
				return (temp);
			else
				head = head->next;
		}
		else if (ft_if_same_time(head, new) == 1)
		{
			if (ft_strcmp(new->name, head->name) > 0)
			{
				if (head->next == NULL)
					return (ft_head_time_less(head, new, temp));
				else
					head = head->next;
			}
			else
				return (ft_same_time(head, new, temp));
		}
		else
			return (ft_time_sort_less(head, new, temp));
	}
	return (temp);
}

t_data	*ft_sort_time(t_data *head, t_data *new)
{
	t_data *temp;

	temp = head;
	if (new == NULL)
		return (head);
	if (head == NULL)
	{
		head = new;
		return (head);
	}
	else if (head->next == NULL)
		return (ft_time_next_null(head, new));
	else
		return (ft_time_sort_cycle(head, new, temp));
	return (temp);
}
