/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyeo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/28 23:50:46 by wyeo              #+#    #+#             */
/*   Updated: 2015/06/09 19:57:15 by wyeo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	ft_putlist(t_liste *list)
{
	t_map		*courant;

	courant = list->first;
	while (courant)
	{
		ft_putendl(courant->val);
		courant = courant->next;
	}
}

t_map	*get_end_elem(t_liste *list)
{
	t_map	*courant;

	courant = list->first;
	while (courant->next)
		courant = courant->next;
	return (courant);
}

int		ft_add_elem(t_liste *list, char *str)
{
	t_map		*nouveau;

	if (!(nouveau = (t_map *)malloc(sizeof(t_map))))
		return (-1);
	if (!(nouveau->val = (char *)malloc(sizeof(char) * (ft_strlen(str) + 1))))
		return (-1);
	nouveau->val = ft_strdup(str);
	nouveau->next = list->first;
	list->first = nouveau;
	list->len++;
	return (0);
}

int		ft_add_end_elem(t_liste *list, char *str)
{
	t_map	*nouveau;
	t_map	*courant;

	if (!(nouveau = (t_map *)malloc(sizeof(t_map))))
		return (-1);
	if (!(nouveau->val = (char *)malloc(sizeof(char) * (ft_strlen(str) + 1))))
		return (-1);
	nouveau->val = ft_strdup(str);
	nouveau->next = NULL;
	courant = get_end_elem(list);
	courant->next = nouveau;
	list->len++;
	return (0);
}
