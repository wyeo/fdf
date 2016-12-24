/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyeo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/09 19:56:57 by wyeo              #+#    #+#             */
/*   Updated: 2015/06/09 19:59:37 by wyeo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void		ft_putlist_2(t_liste_nb_x *list_2)
{
	t_map_2		*courant;

	courant = list_2->first;
	while (courant)
	{
		ft_putnbr(courant->val);
		ft_putchar('\n');
		courant = courant->next;
	}
}

t_map_2		*get_end_elem_2(t_liste_nb_x *list)
{
	t_map_2	*courant;

	courant = list->first;
	while (courant->next)
		courant = courant->next;
	return (courant);
}

int			ft_add_elem_2(t_liste_nb_x *list, int str)
{
	t_map_2		*nouveau;

	if (!(nouveau = (t_map_2 *)malloc(sizeof(t_map_2))))
		return (-1);
	nouveau->val = str;
	nouveau->next = list->first;
	list->first = nouveau;
	list->len++;
	return (0);
}

int			ft_add_end_elem_2(t_liste_nb_x *list, int str)
{
	t_map_2	*nouveau;
	t_map_2	*courant;

	if (!(nouveau = (t_map_2 *)malloc(sizeof(t_map_2))))
		return (-1);
	nouveau->val = str;
	nouveau->next = NULL;
	courant = get_end_elem_2(list);
	courant->next = nouveau;
	list->len++;
	return (0);
}
