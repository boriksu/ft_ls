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

void	ft_print_mod(t_data *k)
{
	char	*list;
	ssize_t	listlen;

	if (k->type == 4)
		ft_putchar('d');
	else if (k->type == 12)
		ft_putchar('l');
	else if (k->type == 1)
		ft_putchar('p');
	else
		ft_putchar('-');
	ft_under_mod(k);
	list = ft_memalloc(XATTR_SIZE + 1);
	if (k->path == NULL)
		listlen = listxattr(k->name, list, XATTR_SIZE, XATTR_NOFOLLOW);
	else
		listlen = listxattr(k->path, list, XATTR_SIZE, XATTR_NOFOLLOW);
	if (listlen > 0)
		ft_putchar('@');
	else
		ft_putchar(' ');
	ft_strdel(&list);
}

void	ft_change_letter(char *str, char i)
{
	if (i == '1' || i == '3' || i == '5' || i == '7')
		str[8] = str[8] == '-' ? 'T' : 't';
	if (i == '2' || i == '3' || i == '6' || i == '7')
		str[5] = str[5] == '-' ? 'S' : 's';
	if (i == '4' || i == '5' || i == '6' || i == '7')
		str[2] = str[2] == '-' ? 'S' : 's';
}

void	ft_under_mod(t_data *k)
{
	char	*i;
	int		kk;
	char	*mode;
	int		len;

	mode = ft_memalloc(10);
	kk = 0;
	i = k->type_mod;
	len = ft_strlen(i);
	kk = len - 3;
	while (kk < len)
	{
		ft_mod_letter(i[kk], mode);
		kk++;
	}
	ft_change_letter(mode, i[len - 4]);
	ft_printf("%s", mode);
	ft_strdel(&mode);
}

void	ft_mod_letter(char i, char *mode)
{
	if (i == '0')
		ft_strcat(mode, "---");
	else if (i == '1')
		ft_strcat(mode, "--x");
	else if (i == '2')
		ft_strcat(mode, "-w-");
	else if (i == '3')
		ft_strcat(mode, "-wx");
	else if (i == '4')
		ft_strcat(mode, "r--");
	else if (i == '5')
		ft_strcat(mode, "r-x");
	else if (i == '6')
		ft_strcat(mode, "rw-");
	else if (i == '7')
		ft_strcat(mode, "rwx");
}
