/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_win_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svkhacha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 21:24:29 by svkhacha          #+#    #+#             */
/*   Updated: 2023/03/03 21:24:42 by svkhacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	create_rgb(int r, int g, int b)
{
	int	t;

	t = 0;
	return (t << 24 | r << 16 | g << 8 | b);
}

void	draw_floor_and_celling(t_data *data, char *dest)
{
	int		i;

	i = -1;
	data->args->f_color = create_rgb(data->args->f1, data->args->f2, \
	data->args->f3);
	data->args->c_color = create_rgb(data->args->c1, data->args->c2, \
	data->args->c3);
	while (++i < HEIGHT / 2)
	{
		dest = data->img[0].img + (i * data->img[0].size_line + \
		data->game->index * data->img[0].bpp / 8);
		*(int *)dest = data->args->c_color;
	}
	while (++i < HEIGHT)
	{
		dest = data->img[0].img + (i * data->img[0].size_line + \
		data->game->index * data->img[0].bpp / 8);
		*(int *)dest = data->args->f_color;
	}
}

int	ft_texx(t_data *data, int n)
{
	int		texx;
	double	wallx;

	wallx = 0.0;
	if (data->rcasting->side == 0)
		wallx = data->rcasting->posy + data->rcasting->perpwalldist \
		* data->rcasting->raydiry;
	else
		wallx = data->rcasting->posx + data->rcasting->perpwalldist \
		* data->rcasting->raydirx;
	wallx -= floor(wallx);
	texx = (int)(wallx * (double)data->img[n].width);
	if (data->rcasting->side == 0 && data->rcasting->raydirx > 0)
	texx = data->img[n].width - texx - 1;
	if (data->rcasting->side == 1 && data->rcasting->raydiry < 0)
		texx = data->img[n].width - texx - 1;
	return (texx);
}

int	draw_walls(t_data *data, char *dest, char *dest_2, int texx)
{
	double	step;
	double	texpos;
	int		texy;
	int		i;
	int		n;

	n = check_nwse(data);
	i = data->rcasting->drawstart;
	texx = (int)ft_texx(data, n);
	step = 1.0 * data->img[n].width / data->rcasting->lineheight;
	texpos = (data->rcasting->drawstart - HEIGHT / 2 + \
	data->rcasting->lineheight / 2) * step;
	while (i < data->rcasting->drawend)
	{
		texy = (int)texpos & data->img[n].width;
		texpos += step;
		dest = data->img[0].img + (i * data->img[0].size_line + \
		data->game->index * (data->img[0].bpp / 8));
		dest_2 = data->img[n].img + ((int)texpos * data->img[n].size_line + \
		texx * (data->img[n].bpp / 8));
		*(int *)dest = *(int *)dest_2;
		i++;
	}
	return (0);
}

void	norm_init_win_3(t_data *data)
{
	if (data->rcasting->side == 0)
		data->rcasting->perpwalldist = (data->rcasting->sidedistx - \
		data->rcasting->deltadistx);
	else
		data->rcasting->perpwalldist = (data->rcasting->sidedisty - \
		data->rcasting->deltadisty);
	data->rcasting->lineheight = (int)(HEIGHT / data->rcasting->perpwalldist);
	data->rcasting->drawstart = -data->rcasting->lineheight / 2 + HEIGHT / 2;
	if (data->rcasting->drawstart < 0)
		data->rcasting->drawstart = 0;
	data->rcasting->drawend = data->rcasting->lineheight / 2 + HEIGHT / 2;
	if (data->rcasting->drawend >= HEIGHT)
		data->rcasting->drawend = HEIGHT - 1;
	draw_floor_and_celling(data, 0);
	draw_walls(data, 0, 0, 0);
}
