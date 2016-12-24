/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_octants_1_4.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyeo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/28 03:18:11 by wyeo              #+#    #+#             */
/*   Updated: 2015/05/31 01:17:40 by wyeo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void			horizontal_line(t_img *img, int mlx_i[10])
{
	int			tmp;

	if (DL_X > DL_X1)
	{
		tmp = DL_X;
		DL_X = DL_X1;
		DL_X1 = tmp;
	}
	while (DL_X < DL_X1)
	{
		ft_mlx_put_pixel_img(DL_X, DL_Y, LINE_COLOR, img);
		DL_X++;
	}
}

void			octant_1_2(t_img *img, int mlx_i[10])
{
	if (DL_DX >= DL_DY)
	{
		DL_E = DL_DX;
		DL_DX = DL_E * 2;
		DL_DY = DL_DY * 2;
		while (1)
		{
			ft_mlx_put_pixel_img(DL_X, DL_Y, LINE_COLOR, img);
			if (++DL_X == DL_X1)
				break ;
			if ((DL_E = DL_E - DL_DY) < 0)
			{
				DL_Y++;
				DL_E = DL_E + DL_DX;
			}
		}
	}
	else
		octant_2(img, mlx_i);
}

void			octant_2(t_img *img, int mlx_i[10])
{
	DL_E = DL_DY;
	DL_DY = DL_E * 2;
	DL_DX = DL_DX * 2;
	while (1)
	{
		ft_mlx_put_pixel_img(DL_X, DL_Y, LINE_COLOR, img);
		if (++DL_Y == DL_Y1)
			break ;
		if ((DL_E = DL_E - DL_DX) < 0)
		{
			DL_X++;
			DL_E = DL_E + DL_DY;
		}
	}
}

void			octant_3_4(t_img *img, int mlx_i[10])
{
	if (-DL_DX >= DL_DY)
	{
		DL_E = DL_DX;
		DL_DX = DL_E * 2;
		DL_DY = DL_DY * 2;
		while (1)
		{
			ft_mlx_put_pixel_img(DL_X, DL_Y, LINE_COLOR, img);
			if (--DL_X == DL_X1)
				break ;
			if ((DL_E = DL_E + DL_DY) >= 0)
			{
				DL_Y++;
				DL_E = DL_E + DL_DX;
			}
		}
	}
	else
		octant_3(img, mlx_i);
}

void			octant_3(t_img *img, int mlx_i[10])
{
	DL_E = DL_DY;
	DL_DY = DL_E * 2;
	DL_DX = DL_DX * 2;
	while (1)
	{
		ft_mlx_put_pixel_img(DL_X, DL_Y, LINE_COLOR, img);
		if (++DL_Y == DL_Y1)
			break ;
		if ((DL_E = DL_E + DL_DX) <= 0)
		{
			DL_X--;
			DL_E = DL_E + DL_DY;
		}
	}
}
