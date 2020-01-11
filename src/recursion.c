/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recursion.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dholiday <dholiday@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 17:03:41 by tguillem          #+#    #+#             */
/*   Updated: 2019/09/09 14:07:12 by dholiday         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_rec_print(t_data *temp, t_ancho *pansa)
{
	pansa->end = NULL;
	ft_end(pansa, temp);
	if (pansa->flags.m == 1)
		ft_print_comma(pansa, temp);
	else if (pansa->flags.l == 1)
		ft_print_list_details(temp, pansa);
	else if (pansa->flags.one == 1)
		ft_print_one(pansa, temp);
	else if (pansa->flags.rev == 1)
		ft_print_list_rev(pansa->end, pansa);
	else
		ft_print_list2(temp, pansa);
	ft_init_l(&pansa->for_l);
	ft_end(pansa, temp);
}

t_data	*ft_temp_r(t_data *temp, t_ancho *pansa)
{
	if (pansa->flags.rev == 1)
		temp = temp->prev;
	else
		temp = temp->next;
	return (temp);
}

void	ft_rec(char *str, t_data *temp, t_ancho *pansa)
{
	char	*new;
	char	*t;

	while (temp != NULL)
	{
		if (temp->type == 4)
		{
			if (ft_strcmp(temp->name, ".") == 0
				|| ft_strcmp(temp->name, "..") == 0)
			{
				temp = ft_temp_r(temp, pansa);
				continue ;
			}
			new = ft_strjoin(str, "/");
			t = ft_strjoin(new, temp->name);
			ft_printf("\n%s:\n", t);
			temp->dir = ft_flag_rec(t, temp->dir, pansa);
			ft_strdel(&new);
			ft_strdel(&t);
			ft_clean_list(temp->dir);
			temp->dir = NULL;
		}
		temp = ft_temp_r(temp, pansa);
	}
}

t_data	*ft_flag_rec(char *str, t_data *temp, t_ancho *pansa)
{
	DIR				*a;
	struct dirent	*k;
	t_data			*head;

	pansa->max_name = 0;
	a = opendir(str);
	if (a != NULL)
		while ((k = readdir(a)) != NULL)
			temp = ft_sort_check(pansa, temp, ft_create_elem(k, pansa, str));
	else
	{
		ft_puterror("ls: ");
		perror(str);
		return (temp);
	}
	closedir(a);
	ft_rec_print(temp, pansa);
	head = temp;
	if (pansa->flags.rev == 1)
		temp = pansa->end;
	ft_rec(str, temp, pansa);
	return (head);
}
