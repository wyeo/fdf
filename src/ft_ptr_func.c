/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptr_func.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyeo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/28 20:29:55 by wyeo              #+#    #+#             */
/*   Updated: 2015/06/09 19:55:38 by wyeo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		ft_key(int keycode, t_env *data)
{
	if (keycode == 53)
	{
		ft_putendl("BYE");
		exit(0);
	}
	(void)data;
	return (0);
}

int		ft_expose(int keycode, t_env *data)
{
	ft_putnbr(keycode);
	(void)data;
	return (0);
}

int		ft_mouse(int button, int x, int y, t_env *data)
{
	(void)button;
	setup_x1_y1_x2(210, 210, x, data->mlx_i);
	setup_y2_color(y, 0xFFFFFF, data->mlx_i);
	draw_line_to_img(&data->screen, data->mlx_i);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->screen.img
			, 0, 0);
	return (0);
}
