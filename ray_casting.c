/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_win.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svkhacha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 21:23:42 by svkhacha          #+#    #+#             */
/*   Updated: 2023/03/03 21:23:50 by svkhacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "cub3d.h"

void	find_pos_player(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->args->map[i])
	{
		j = 0;
		while (data->args->map[i][j])
		{
			if (data->args->map[i][j] == 'N' || \
				data->args->map[i][j] == 'S' || \
				data->args->map[i][j] == 'E' || \
				data->args->map[i][j] == 'W')
			{
				init_player_pos(data, i, j);
				data->rcasting->posx = i + 0.5;
				data->rcasting->posy = j + 0.5;
				data->args->map[i][j] = '0';
				return ;
			}
			j++;
		}
		i++;
	}
}

void	norm_init_win_2(t_data *data)
{
	data->rcasting->hit = 0;
	while (data->rcasting->hit == 0)
	{
		if (data->rcasting->sidedistx < data->rcasting->sidedisty)
		{
			data->rcasting->sidedistx += data->rcasting->deltadistx;
			data->rcasting->mapx += data->rcasting->stepx;
			data->rcasting->side = 0;
		}
		else
		{
			data->rcasting->sidedisty += data->rcasting->deltadisty;
			data->rcasting->mapy += data->rcasting->stepy;
			data->rcasting->side = 1;
		}
		if (data->args->map[data->rcasting->mapx] \
		[data->rcasting->mapy] != '0')
			data->rcasting->hit = 1;
	}
	norm_init_win_3(data);
}

void	norm_init_win(t_data *data)
{
	if (data->rcasting->raydiry < 0)
	{
		data->rcasting->stepy = -1;
		data->rcasting->sidedisty = (data->rcasting->posy - \
		data->rcasting->mapy) * data->rcasting->deltadisty;
	}
	else
	{
		data->rcasting->stepy = 1;
		data->rcasting->sidedisty = (data->rcasting->mapy + 1.0 - \
		data->rcasting->posy) * data->rcasting->deltadisty;
	}
	norm_init_win_2(data);
}

void	continue_init_win(t_data *data)
{
	if (data->rcasting->raydirx == 0)
		data->rcasting->deltadistx = 1e30;
	else
		data->rcasting->deltadistx = ft_abs(1 / data->rcasting->raydirx);
	if (data->rcasting->raydiry == 0)
		data->rcasting->deltadisty = 1e30;
	else
		data->rcasting->deltadisty = ft_abs(1 / data->rcasting->raydiry);
	if (data->rcasting->raydirx < 0)
	{
		data->rcasting->stepx = -1;
		data->rcasting->sidedistx = (data->rcasting->posx - \
		data->rcasting->mapx) * data->rcasting->deltadistx;
	}
	else
	{
		data->rcasting->stepx = 1;
		data->rcasting->sidedistx = (data->rcasting->mapx + 1.0 - \
		data->rcasting->posx) * data->rcasting->deltadistx;
	}
	norm_init_win(data);
}
