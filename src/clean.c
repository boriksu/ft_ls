/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dholiday <dholiday@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 17:03:41 by tguillem          #+#    #+#             */
/*   Updated: 2019/09/09 15:22:02 by dholiday         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_clean_list(t_data *hello)
{
	t_data	*temp;
	int		i;

	while (hello != NULL)
	{
		i = 0;
		temp = hello->next;
		if (hello->date != NULL)
		{
			while (hello->date[i] != NULL)
			{
				ft_strdel(&hello->date[i]);
				i++;
			}
			free(hello->date);
			hello->date = NULL;
		}
		ft_strdel(&hello->type_mod);
		ft_strdel(&hello->name);
		ft_strdel(&hello->path);
		free(hello);
		hello = temp;
	}
}

void	ft_clean_param(t_param *hello)
{
	t_param *temp;

	temp = hello->next;
	while (temp != NULL)
	{
		free(hello);
		hello = temp;
		temp = temp->next;
	}
	free(hello);
}
