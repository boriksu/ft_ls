/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dholiday <dholiday@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 17:03:41 by tguillem          #+#    #+#             */
/*   Updated: 2019/09/09 12:32:54 by dholiday         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_enum_pansa_null(t_ancho *pansa)
{
	if (pansa->flags.m == 1)
		ft_print_comma(pansa, pansa->files);
	else if (pansa->flags.l == 1)
		ft_print_list_details(pansa->files, pansa);
	else if (pansa->flags.one == 1)
		ft_print_one(pansa, pansa->files);
	else if (pansa->flags.rev == 1)
	{
		ft_end(pansa, pansa->files);
		ft_print_list_rev(pansa->end, pansa);
		pansa->end = NULL;
	}
	else
		ft_print_list2(pansa->files, pansa);
}

t_data	*ft_enum_pansa_not_null(t_ancho *pansa, t_data *temp)
{
	if (pansa->dir->next != NULL || pansa->files != NULL)
	{
		if (pansa->flags.rev == 1 && temp->next == NULL && pansa->files == NULL)
			ft_printf("%s:\n", temp->name);
		else if (pansa->flags.rev == 0 &&
			temp->prev == NULL && pansa->files == NULL)
			ft_printf("%s:\n", temp->name);
		else
			ft_printf("\n%s:\n", temp->name);
	}
	else if (pansa->errno_o == 1)
		ft_printf("%s:\n", temp->name);
	pansa->max_name = 0;
	ft_apply(pansa, temp->name);
	if (pansa->flags.rev == 1)
		temp = temp->prev;
	else
		temp = temp->next;
	return (temp);
}

void	ft_enum_files(t_ancho *pansa, int argc, char **argv)
{
	t_data	*temp;
	DIR		*a;

	temp = pansa->files;
	if (temp != NULL)
		ft_enum_pansa_null(pansa);
	ft_init_l(&pansa->for_l);
	ft_end(pansa, pansa->dir);
	if (pansa->flags.rev == 1)
		temp = pansa->end;
	else
		temp = pansa->dir;
	while (temp != NULL)
		temp = ft_enum_pansa_not_null(pansa, temp);
	ft_clean_list(pansa->files);
	pansa->files = NULL;
	ft_clean_list(pansa->dir);
	pansa->dir = NULL;
}

void	ft_apply(t_ancho *pansa, char *str)
{
	if (pansa->flags.rec == 1)
	{
		pansa->start = ft_flag_rec(str, pansa->start, pansa);
		ft_clean_list(pansa->start);
		pansa->start = NULL;
		ft_init_l(&pansa->for_l);
	}
	else
		ft_read_all(pansa, str);
}

void	ft_read_all(t_ancho *pansa, char *str)
{
	DIR				*a;
	struct dirent	*k;
	t_data			*head;

	head = NULL;
	a = opendir(str);
	if (a != NULL)
		while ((k = readdir(a)) != NULL)
			pansa->start = ft_sort_check(pansa,
				pansa->start, ft_create_elem(k, pansa, str));
	closedir(a);
	ft_end(pansa, pansa->start);
	if (pansa->flags.m == 1)
		ft_print_comma(pansa, pansa->start);
	else if (pansa->flags.l == 1)
		ft_print_list_details(pansa->start, pansa);
	else if (pansa->flags.one == 1)
		ft_print_one(pansa, pansa->start);
	else if (pansa->flags.rev == 1)
		ft_print_list_rev(pansa->end, pansa);
	else
		ft_print_list2(pansa->start, pansa);
	ft_clean_list(pansa->start);
	pansa->start = NULL;
}
