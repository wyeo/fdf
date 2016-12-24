/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_project.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyeo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/29 05:42:47 by wyeo              #+#    #+#             */
/*   Updated: 2015/06/09 23:46:17 by wyeo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void			ft_project(t_point2 *p)
{
	int		x;

	x = p->x;
	p->x = CTE * (p->x * CELL_SIZE) - CTE * (p->y * CELL_SIZE) + SPACE;
	p->y = CTE / 2 * x * CELL_SIZE + CTE / 2 * p->y * CELL_SIZE - p->z + SPACE;
}

void			ft_draw_p(t_point2 *p1, t_point2 *p2, int color, t_env *data)
{
	setup_x1_y1_x2(p1->x, p1->y, p2->x, data->mlx_i);
	setup_y2_color(p2->y, color, data->mlx_i);
	draw_line_to_img(&data->screen, data->mlx_i);
}

static void		ft_init(t_env *data)
{
	data->pos.x = 0;
	data->pos.y = 0;
}

static void		ft_norme(t_env *data, t_val *val)
{
	if (data->pos.x > 0)
	{
		data->p2.x = data->pos.x - 1;
		data->p2.y = data->pos.y;
		data->p2.z = val->val_to_val[data->pos.y][data->pos.x - 1];
		ft_project(&data->p2);
		ft_draw_p(&data->p1, &data->p2, COLOR, data);
	}
	if (data->pos.y > 0)
	{
		data->p2.x = data->pos.x;
		data->p2.y = data->pos.y - 1;
		data->p2.z = val->val_to_val[data->pos.y - 1][data->pos.x];
		ft_project(&data->p2);
		ft_draw_p(&data->p1, &data->p2, COLOR, data);
	}
}

void			ft_putpoint_image(t_env *data, t_val *val, t_liste_nb_x *list_2)
{
	t_map_2			*courant;

	ft_init(data);
	courant = list_2->first;
	while (courant)
	{
		data->pos.x = 0;
		while (data->pos.x < courant->val)
		{
			data->p1.x = data->pos.x;
			data->p1.y = data->pos.y;
			data->p1.z = val->val_to_val[data->pos.y][data->pos.x];
			ft_project(&data->p1);
			ft_norme(data, val);
			ft_mlx_put_pixel_img(data->p1.x, data->p1.y, 0x0000FF
					, &data->screen);
			data->pos.x += 1;
		}
		courant = courant->next;
		data->pos.y += 1;
	}
}
