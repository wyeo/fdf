/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyeo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/24 03:45:07 by wyeo              #+#    #+#             */
/*   Updated: 2015/06/09 23:48:14 by wyeo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# define W_MAP				1200
# define H_MAP				1800
# define SPACE				550
# define CELL_SIZE			13
# define KEY_ESCAPE			53
# define KEY_LEFT			123
# define KEY_RIGHT			124
# define KEY_DOWN			125
# define KEY_UP				126
# define COLOR				0x00FF00

# define PI					3.1415
# define CTE				1.0
# define DL_X0				mlx_i[0]
# define DL_Y0				mlx_i[1]
# define DL_X1				mlx_i[2]
# define DL_Y1				mlx_i[3]
# define DL_DX				mlx_i[4]
# define DL_DY				mlx_i[5]
# define DL_E				mlx_i[6]
# define DL_X				mlx_i[7]
# define DL_Y				mlx_i[8]
# define LINE_COLOR			mlx_i[9]

# define D_HACK1			if (DL_DX>0){if((DL_DY=DL_Y1-DL_Y0)!=0){
# define D_HACK2			if(DL_DY>0){octant_1_2(m);}else{octant_7_8(m);}
# define D_HACK3			}else{horizontal_line(m);}}

# include <mlx.h>
# include <math.h>
# include <fcntl.h>
# include <stdlib.h>
# include "../libft/libft.h"
# include "get_next_line.h"

typedef struct				s_point2
{
	int						x;
	int						y;
	int						z;
}							t_point2;

typedef struct				s_pos
{
	int						x;
	int						y;
}							t_pos;

typedef struct				s_img
{
	void					*img;
	char					*img_data;
	int						bpp;
	int						w_window;
	int						h_window;
	int						size_line;
	int						endian;
}							t_img;

typedef struct				s_env
{
	void					*mlx_ptr;
	void					*win_ptr;
	int						keycode;
	char					*name_window;
	t_img					screen;
	t_pos					pos;
	t_point2				p1;
	t_point2				p2;
	int						color;
	int						mlx_i[10];
}							t_env;

typedef struct				s_val
{
	double					nb_y;
	double					**val_to_val;
}							t_val;

typedef struct				s_map
{
	char					*val;
	struct s_map			*next;
}							t_map;

typedef struct				s_liste
{
	t_map					*first;
	int						len;
}							t_liste;

typedef struct				s_map_2
{
	int						val;
	struct s_map_2			*next;
}							t_map_2;

typedef struct				s_liste_nb_x
{
	t_map_2					*first;
	int						len;
}							t_liste_nb_x;

int							ft_key(int keycode, t_env *data);
int							ft_expose(int keycode, t_env *data);
int							ft_mouse(int button, int x, int y, t_env *data);

void						ft_init_data(t_env *data, t_map *map, t_liste *list
		, t_val *val);
int							ft_init_env(t_env *data, t_img *img);
void						ft_init_table(int *tab, int len);

void						ft_putpoint_image(t_env *data, t_val *val
		, t_liste_nb_x *list_2);
void						ft_init_point_2(t_env *data, t_point2 *p2
		, t_val *val);
void						ft_init_point_2_2(t_env *data, t_point2 *p2
		, t_val *val);
void						ft_project(t_point2 *p);
void						ft_draw_p(t_point2 *p1, t_point2 *p2, int color
		, t_env *data);
void						ft_init_pos(t_env *data);
void						ft_init_point_1(t_env *data, t_point2 *p1
		, t_val *val);

void						ft_putlist(t_liste *list);
int							ft_count_elem(t_liste *list);
t_map						*get_end_elem(t_liste *list);
int							ft_add_elem(t_liste *list, char *str);
int							ft_add_end_elem(t_liste *list, char *str);

void						ft_putlist_2(t_liste_nb_x *list_2);
t_map_2						*get_end_elem_2(t_liste_nb_x *list_2);
int							ft_add_elem_2(t_liste_nb_x *list, int str);
int							ft_add_end_elem_2(t_liste_nb_x *list, int str);
int							ft_get_map(t_liste *list, char *argv);
double						*ft_catch_double(char **final
		, t_liste_nb_x *list_2);
int							ft_check_map(t_liste *list, t_val *val
		, t_liste_nb_x *list_2);
int							ft_len_double_table(char **final);

int							ft_mlx_put_pixel_img(int x, int y, int color
		, t_img *img);

void						setup_x1_y1_x2(int x1, int y1, int x2
		, int mlx_i[10]);
void						setup_y2_color(int y2, int color, int mlx_i[10]);
void						draw_line_to_img(t_img *img, int mlx_i[10]);
void						draw_line_to_img_vol1(t_img *img, int mlx_i[10]);

void						vertical_line(t_img *img, int mlx_i[10]);
void						horizontal_line(t_img *img, int mlx_i[10]);
void						octant_1_2(t_img *img, int mlx_i[10]);
void						octant_2(t_img *img, int mlx_i[10]);
void						octant_3_4(t_img *img, int mlx_i[10]);
void						octant_3(t_img *img, int mlx_i[10]);
void						octant_5_6(t_img *img, int mlx_i[10]);
void						octant_6(t_img *img, int mlx_i[10]);
void						octant_7_8(t_img *img, int mlx_i[10]);
void						octant_7(t_img *img, int mlx_i[10]);

#endif
