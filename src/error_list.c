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

t_data	*ft_create_error_elem(char *str)
{
	t_data	*new;
	char	*path;
	char	*temp;

	new = (t_data *)malloc(sizeof(t_data));
	new->name = ft_strsub(str, 0, ft_strlen(str));
	new->dir = NULL;
	new->date = NULL;
	new->next = NULL;
	new->prev = NULL;
	new->type_mod = NULL;
	new->path = NULL;
	return (new);
}

void	ft_print_list_error(t_data *start)
{
	while (start != NULL)
	{
		ft_puterror("ls: ");
		ft_puterror(start->name);
		ft_puterror(": ");
		ft_puterror("No such file or directory");
		ft_puterror("\n");
		start = start->next;
	}
}

void	ft_puterror(char *str)
{
	int		i;
	char	c;

	i = 0;
	while (str[i] != '\0')
	{
		c = str[i];
		ft_cherror(str[i]);
		i++;
	}
}

void	ft_cherror(char c)
{
	write(2, &c, 1);
}
