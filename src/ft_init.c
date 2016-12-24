/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyeo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/28 00:22:47 by wyeo              #+#    #+#             */
/*   Updated: 2015/06/09 23:47:25 by wyeo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	ft_init_table(int *tab, int len)
{
	int		i;

	i = 0;
	while (i < len)
	{
		tab[i] = 5;
		i += 1;
	}
}

void	ft_init_data(t_env *data, t_map *map, t_liste *list, t_val *val)
{
	data->mlx_ptr = mlx_init();
	data->win_ptr = NULL;
	data->keycode = 0;
	data->screen.w_window = W_MAP;
	data->screen.h_window = H_MAP;
	data->color = COLOR;
	data->name_window = "42";
	ft_init_table(data->mlx_i, 10);
	data->screen.img = NULL;
	data->screen.img_data = NULL;
	data->screen.bpp = 0;
	data->screen.size_line = 0;
	data->screen.endian = 0;
	map->val = NULL;
	list->first = NULL;
	list->len = 0;
	val->val_to_val = 0;
	val->nb_y = 0;
}

int		ft_init_env(t_env *data, t_img *img)
{
	if (!(data->mlx_ptr = mlx_init()))
	{
		ft_putendl("Error : mlx_init()");
		return (-1);
	}
	if (!(data->win_ptr = mlx_new_window(data->mlx_ptr,
					img->w_window, img->h_window, data->name_window)))
	{
		ft_putendl("Error : mlx_new_window()");
		return (-1);
	}
	if (!(img->img = mlx_new_image(data->mlx_ptr,
					data->screen.w_window, data->screen.h_window)))
	{
		ft_putendl("Error : mlx_new_image()");
		return (-1);
	}
	if (!(img->img_data = mlx_get_data_addr(img->img,
					&img->bpp, &img->size_line, &img->endian)))
	{
		ft_putendl("Error: mlx_get_image_data");
		return (-1);
	}
	return (0);
}
