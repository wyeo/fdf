/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyeo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/24 03:18:22 by wyeo              #+#    #+#             */
/*   Updated: 2015/06/09 21:57:13 by wyeo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void			ft_init_2(t_liste_nb_x *list_2)
{
	list_2->first = NULL;
	list_2->len = 0;
}

static int		ft_init_main(int argc)
{
	if (argc != 2)
	{
		if (argc == 1)
		{
			ft_putendl("usage : ./fdf file1");
			return (-1);
		}
		ft_putendl("Error: Wrong arguments");
		return (-1);
	}
	return (0);
}

int				main(int argc, char **argv)
{
	t_env			data;
	t_map			map;
	t_val			val;
	t_liste			list;
	t_liste_nb_x	list_2;

	if (ft_init_main(argc) == -1)
		return (-1);
	ft_init_data(&data, &map, &list, &val);
	ft_init_2(&list_2);
	ft_init_env(&data, &data.screen);
	if (ft_get_map(&list, argv[1]) == -1)
		return (-1);
	ft_check_map(&list, &val, &list_2);
	mlx_key_hook(data.win_ptr, ft_key, &data);
	ft_putpoint_image(&data, &val, &list_2);
	mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, data.screen.img
			, 0, 0);
	mlx_loop(data.mlx_ptr);
	return (0);
}
