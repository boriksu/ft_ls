/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dholiday <dholiday@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 17:03:41 by tguillem          #+#    #+#             */
/*   Updated: 2019/09/09 15:53:35 by dholiday         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_init(t_ancho *pansa)
{
	pansa->no_flag = 0;
	pansa->files = NULL;
	pansa->start = NULL;
	pansa->end = NULL;
	pansa->dir = NULL;
	pansa->error = NULL;
	pansa->max_name = 0;
	pansa->flags.a = 0;
	pansa->flags.one = 0;
	pansa->flags.l = 0;
	pansa->flags.t = 0;
	pansa->flags.p = 0;
	pansa->flags.g = 0;
	pansa->flags.rev = 0;
	pansa->flags.rec = 0;
	pansa->flags.m = 0;
	pansa->sum = 0;
	pansa->two_dash = 0;
	pansa->window_size = 0;
	ft_init_l(&pansa->for_l);
	pansa->now = time(NULL);
	pansa->errno_o = 0;
}

void	ft_init_l(t_for_l *new)
{
	new->day = 0;
	new->links = 0;
	new->mounth = 3;
	new->size = 0;
	new->time = 5;
	new->user = 0;
	new->year = 4;
}

int		main(int argc, char **argv)
{
	DIR				*a;
	struct dirent	*k;
	t_data			*head;
	t_ancho			pansa;

	ft_init(&pansa);
	ft_parset(argc, argv, &pansa);
	if (pansa.no_flag == 0)
		ft_apply(&pansa, ".");
	else
		ft_enum_files(&pansa, argc, argv);
	return (0);
}
