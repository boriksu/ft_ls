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

int		ft_prev_sort(t_data *head, t_data *new)
{
	new->prev = head->prev;
	new->next = head;
	head->prev->next = new;
	head->prev = new;
	return (1);
}

void	ft_prev_null_sort(t_data *head, t_data *new)
{
	head->prev = new;
	new->next = head;
}

t_data	*ft_sort_next_not_null(t_data *head, t_data *new, t_data *temp)
{
	while (head != NULL)
	{
		if (ft_strcmp(new->name, head->name) > 0)
		{
			if (head->next == NULL)
			{
				head->next = new;
				new->prev = head;
				break ;
			}
			else
				head = head->next;
		}
		else
		{
			if (head->prev == NULL)
			{
				ft_prev_null_sort(head, new);
				return (new);
			}
			else if (ft_prev_sort(head, new) == 1)
				break ;
		}
	}
	return (temp);
}

t_data	*ft_alpha_1(t_data *head, t_data *new)
{
	if (ft_strcmp(new->name, head->name) > 0)
	{
		head->next = new;
		new->prev = head;
		return (head);
	}
	else
	{
		new->next = head;
		head->prev = new;
		return (new);
	}
}

t_data	*ft_sort_alpha(t_data *head, t_data *new)
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
		return (ft_alpha_1(head, new));
	else
		temp = ft_sort_next_not_null(head, new, temp);
	return (temp);
}
