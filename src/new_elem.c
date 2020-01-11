/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dholiday <dholiday@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 17:03:41 by tguillem          #+#    #+#             */
/*   Updated: 2019/09/09 15:52:50 by dholiday         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_end(t_ancho *pansa, t_data *head)
{
	t_data *temp;

	temp = head;
	if (head == NULL)
	{
		pansa->end = NULL;
		return ;
	}
	while (temp->next != NULL)
		temp = temp->next;
	pansa->end = temp;
}

t_data	*ft_k_not_null(struct dirent *k, t_ancho *pansa, char *str, t_data *new)
{
	char *temp;

	temp = ft_strjoin(str, "/");
	new->path = ft_strjoin(temp, k->d_name);
	if (k->d_type == 10)
		lstat(new->path, &new->stat);
	else
		stat(new->path, &new->stat);
	new->readdir = k;
	ft_strdel(&temp);
	new->name = ft_strsub(new->readdir->d_name, 0, new->readdir->d_namlen);
	if (pansa->max_name < new->readdir->d_namlen)
		pansa->max_name = new->readdir->d_namlen;
	return (new);
}

t_data	*ft_k_null(t_ancho *pansa, char *str, t_data *new)
{
	char *temp;

	if (lstat(str, &new->stat) == -1 && stat(str, &new->stat) == -1)
	{
		free(new);
		temp = ft_strjoin("ls: ", str);
		perror(temp);
		ft_strdel(&temp);
		return (NULL);
	}
	new->name = ft_strsub(str, 0, ft_strlen(str));
	if (pansa->max_name < ft_strlen(str))
		pansa->max_name = ft_strlen(str);
	return (new);
}

t_data	*ft_create_elem(struct dirent *k, t_ancho *pansa, char *str)
{
	t_data	*new;
	char	*path;
	char	*temp;

	if (k != NULL)
		if (pansa->flags.a == 0 && k->d_name[0] == '.')
			return (NULL);
	new = (t_data *)malloc(sizeof(t_data));
	new->path = NULL;
	pansa->sum++;
	if (k != NULL)
		new = ft_k_not_null(k, pansa, str, new);
	else
	{
		if ((new = ft_k_null(pansa, str, new)) == NULL)
			return (NULL);
	}
	ft_find_max(pansa, new);
	new->dir = NULL;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

t_data	*ft_put_elem_to_list(t_data *new, t_data *head)
{
	if (new == NULL)
		return (head);
	head->next = new;
	new->prev = head;
	return (new);
}
