/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting_4.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svkhacha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 17:50:36 by svkhacha          #+#    #+#             */
/*   Updated: 2023/03/08 17:50:47 by svkhacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_get_data_addr(t_data *data)
{
	data->img[1].img = mlx_get_data_addr(data->game->no, &data->img[1].bpp, \
	&data->img[1].size_line, &data->img[1].endian);
	data->img[2].img = mlx_get_data_addr(data->game->so, &data->img[2].bpp, \
	&data->img[2].size_line, &data->img[2].endian);
	data->img[3].img = mlx_get_data_addr(data->game->ea, &data->img[3].bpp, \
	&data->img[3].size_line, &data->img[3].endian);
	data->img[4].img = mlx_get_data_addr(data->game->we, &data->img[4].bpp, \
	&data->img[4].size_line, &data->img[4].endian);
}

int	check_nwse(t_data *data)
{
	int	n;

	n = 1;
	if (data->rcasting->side == 1 && data->rcasting->raydiry < 0)
		n = 3;
	else if (data->rcasting->side == 1 && data->rcasting->raydiry > 0)
		n = 4;
	else if (data->rcasting->side == 0 && data->rcasting->raydirx > 0)
		n = 2;
	else if (data->rcasting->side == 0 && data->rcasting->raydirx < 0)
		n = 1;
	return (n);
}

void	init_win(t_data *data)
{
	int		i;
	void	*temp;

	i = 0;
	temp = NULL;
	init_win_continue(data, i, temp);
}

void	init_win_continue(t_data *data, int i, void *temp)
{
	find_pos_player(data);
	data->img[0].ptr = mlx_new_image(data->game->mlx, WIDTH, HEIGHT);
	temp = data->img[0].ptr;
	data->img[0].img = mlx_get_data_addr(data->img[0].ptr, &data->img[0].bpp, \
	&data->img[0].size_line, &data->img[0].endian);
	ft_get_data_addr(data);
	while (i < WIDTH)
	{
		data->game->index = i;
		data->rcasting->camerax = 2 * i / (double)WIDTH - 1;
		data->rcasting->raydirx = data->rcasting->dirx + \
		data->rcasting->planex * data->rcasting->camerax;
		data->rcasting->raydiry = data->rcasting->diry + \
		data->rcasting->planey * data->rcasting->camerax;
		data->rcasting->mapx = (int)data->rcasting->posx;
		data->rcasting->mapy = (int)data->rcasting->posy;
		continue_init_win(data);
		i++;
	}
	mlx_put_image_to_window(data->game->mlx, data->game->win, \
	data->img[0].ptr, 0, 0);
	mlx_destroy_image(data->game->mlx, temp);
}
