/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_maps.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyeo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/29 00:57:13 by wyeo              #+#    #+#             */
/*   Updated: 2015/06/09 22:42:18 by wyeo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		ft_get_map(t_liste *list, char *argv)
{
	int		i;
	int		f;
	int		fd;
	char	*line;

	i = 0;
	f = 0;
	if ((fd = open(argv, O_RDONLY)) == -1)
	{
		ft_putendl("Error: Not Open Map");
		return (-1);
	}
	while (get_next_line(fd, &line) > 0)
	{
		if (list->len >= 1)
			ft_add_end_elem(list, line);
		else
			ft_add_elem(list, line);
		f += 1;
	}
	return (0);
}

int		ft_check_map(t_liste *list, t_val *val, t_liste_nb_x *list_2)
{
	int		i;
	char	**final;
	t_map	*courant;

	i = 0;
	courant = list->first;
	if (!(val->val_to_val = (double **)malloc(sizeof(double *)
					* list->len)))
		return (-1);
	while (courant)
	{
		final = ft_strsplit(courant->val, ' ');
		val->val_to_val[i] = ft_catch_double(final, list_2);
		i += 1;
		free(final);
		courant = courant->next;
	}
	val->nb_y = (double)i;
	return (0);
}

int		ft_len_double_table(char **final)
{
	int		i;

	i = 0;
	while (final[i])
		i += 1;
	return (i);
}

double	*ft_catch_double(char **final, t_liste_nb_x *list_2)
{
	int		i;
	double	*tab;

	i = 0;
	if (!(tab = (double *)malloc(sizeof(double) * ft_len_double_table(final))))
		return (NULL);
	while (final[i])
	{
		tab[i] = (double)ft_atoi(final[i]);
		i += 1;
	}
	if (list_2->len >= 1)
		ft_add_end_elem_2(list_2, i);
	else
		ft_add_elem_2(list_2, i);
	return (tab);
}
