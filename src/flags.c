/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parset.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dholiday <dholiday@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 17:03:41 by tguillem          #+#    #+#             */
/*   Updated: 2019/09/09 15:54:41 by dholiday         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		ft_usage_error(char c)
{
	ft_puterror("ls: illegal option -- ");
	write(2, &c, 1);
	ft_puterror("\nusage: ls [-ABCFGHLOPRSTUWab");
	ft_puterror("cdefghiklmnopqrstuwx1] [file ...]\n");
	return (1);
}

void	ft_flag_1(t_ancho *pansa)
{
	if (pansa->flags.m == 1)
		pansa->flags.m = 0;
	if (pansa->flags.l == 1)
		pansa->flags.l = 0;
	pansa->flags.one = 1;
}

void	ft_m_flag(t_ancho *pansa)
{
	if (pansa->flags.l == 1)
		pansa->flags.l = 0;
	pansa->flags.m = 1;
}

void	ft_search_flags(t_ancho *pansa, int i, char *str)
{
	if (str[i] == 'r')
		pansa->flags.rev = 1;
	else if (str[i] == 'R')
		pansa->flags.rec = 1;
	else if (str[i] == 'a')
		pansa->flags.a = 1;
	else if (str[i] == 't')
		pansa->flags.t = 1;
	else if (str[i] == 'p')
		pansa->flags.p = 1;
	else if (str[i] == 'G')
		pansa->flags.g = 1;
	else if (str[i] == '1')
		ft_flag_1(pansa);
	else if (str[i] == 'l')
	{
		if (pansa->flags.m == 1)
			pansa->flags.m = 0;
		pansa->flags.l = 1;
	}
	else if (str[i] == 'm')
		ft_m_flag(pansa);
	else if (ft_usage_error(str[i]) == 1)
		exit(1);
}

void	ft_flags(char *str, t_ancho *pansa)
{
	int		i;
	int		dash;
	char	c;

	dash = 0;
	i = 1;
	if (ft_strcmp(str, "--") == 0)
		pansa->two_dash = 1;
	else if (str[0] == '-' && str[1] != '\0')
	{
		while (str[i] != '\0')
		{
			ft_search_flags(pansa, i, str);
			i++;
		}
	}
	else
		pansa->no_flag = 1;
}
