/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyeo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/27 23:39:50 by wyeo              #+#    #+#             */
/*   Updated: 2015/06/09 22:42:09 by wyeo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	setup_x1_y1_x2(int x1, int y1, int x2, int mlx_i[10])
{
	DL_X = x1;
	DL_X0 = x1;
	DL_Y = y1;
	DL_Y0 = y1;
	DL_X1 = x2;
}

void	setup_y2_color(int y2, int color, int mlx_i[10])
{
	DL_Y1 = y2;
	LINE_COLOR = color;
}

int		ft_mlx_put_pixel_img(int x, int y, int color, t_img *img)
{
	int		index;
	char	*ccolor;

	if (x >= W_MAP || x < 0 || y >= H_MAP || y < 0)
		return (1);
	index = img->size_line * y + (x * img->bpp / 8);
	ccolor = (char *)&color;
	img->img_data[index] = ccolor[2];
	img->img_data[index + 1] = ccolor[1];
	img->img_data[index + 2] = ccolor[0];
	return (0);
}

void	draw_line_to_img(t_img *img, int mlx_i[10])
{
	if ((DL_DX = DL_X1 - DL_X0) != 0)
	{
		if (DL_DX > 0)
		{
			if ((DL_DY = DL_Y1 - DL_Y0) != 0)
				if (DL_DY > 0)
					octant_1_2(img, mlx_i);
				else
					octant_7_8(img, mlx_i);
			else
				horizontal_line(img, mlx_i);
		}
		else
		{
			if ((DL_DY = DL_Y1 - DL_Y0) != 0)
				if (DL_DY > 0)
					octant_3_4(img, mlx_i);
				else
					octant_5_6(img, mlx_i);
			else
				horizontal_line(img, mlx_i);
		}
	}
	draw_line_to_img_vol1(img, mlx_i);
}

void	draw_line_to_img_vol1(t_img *img, int mlx_i[10])
{
	if (!((DL_DX = DL_X1 - DL_X0) != 0))
	{
		if ((DL_DY = DL_Y1 - DL_Y0) > 0)
			vertical_line(img, mlx_i);
		else
			vertical_line(img, mlx_i);
	}
}
