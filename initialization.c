/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_structs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svkhacha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 21:22:28 by svkhacha          #+#    #+#             */
/*   Updated: 2023/03/03 21:22:40 by svkhacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_struct_game(t_data *data)
{
	data->game = malloc(sizeof(t_game));
	data->game->index = 0;
	data->game->mlx = 0;
	data->game->win = 0;
	data->game->no = 0;
	data->game->so = 0;
	data->game->ea = 0;
	data->game->we = 0;
	data->game->x = 0;
	data->game->y = 0;
}

void	init_struct_index(t_data *data)
{
	data->index = malloc(sizeof(t_index));
	data->index->index_no = 0;
	data->index->index_so = 0;
	data->index->index_ea = 0;
	data->index->index_we = 0;
	data->index->index_c = 0;
	data->index->index_f = 0;
}

void	init_struct_img(t_data *data)
{
	int	i;

	i = -1;
	while (++i < 5)
	{
		data->img[i].ptr = 0;
		data->img[i].img = 0;
		data->img[i].bpp = 0;
		data->img[i].width = 0;
		data->img[i].height = 0;
		data->img[i].size_line = 0;
		data->img[i].endian = 0;
	}
}

void	init_struct_raycasting(t_data *data)
{
	data->rcasting = malloc(sizeof(t_raycasting));
	data->rcasting->perpwalldist = 0;
	data->rcasting->deltadistx = 0;
	data->rcasting->lineheight = 0;
	data->rcasting->deltadisty = 0;
	data->rcasting->sidedistx = 0;
	data->rcasting->sidedisty = 0;
	data->rcasting->drawstart = 0;
	data->rcasting->drawend = 0;
	data->rcasting->camerax = 0;
	data->rcasting->raydirx = 0;
	data->rcasting->raydiry = 0;
	data->rcasting->planex = 0;
	data->rcasting->planey = 0;
	data->rcasting->stepx = 0;
	data->rcasting->stepy = 0;
	data->rcasting->dirx = 0;
	data->rcasting->diry = 0;
	data->rcasting->posx = 0;
	data->rcasting->posy = 0;
	data->rcasting->side = 0;
	data->rcasting->mapx = 0;
	data->rcasting->mapy = 0;
	data->rcasting->hit = 0;
}

void	init_structs(t_data *data)
{
	data->img = malloc(sizeof(t_img) * 5);
	init_struct_img(data);
	init_struct_raycasting(data);
	init_struct_index(data);
	init_struct_game(data);
}
