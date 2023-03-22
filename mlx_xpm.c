/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx_xpm.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svkhacha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 21:25:30 by svkhacha          #+#    #+#             */
/*   Updated: 2023/03/03 21:25:37 by svkhacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "cub3d.h"

void	ft_mlx_xpm(t_data *data)
{
	data->game->no = mlx_xpm_file_to_image(data->game->mlx, \
	data->args->north, &data->img[1].width, &data->img[1].height);
	data->game->so = mlx_xpm_file_to_image(data->game->mlx, \
	data->args->south, &data->img[2].width, &data->img[2].height);
	data->game->ea = mlx_xpm_file_to_image(data->game->mlx, \
	data->args->east, &data->img[3].width, &data->img[3].height);
	data->game->we = mlx_xpm_file_to_image(data->game->mlx, \
	data->args->west, &data->img[4].width, &data->img[4].height);
	if (!data->game->no || !data->game->so || !data->game->ea || \
		!data->game->we)
	{
		write(2, "No such path\n", 13);
		exit(1);
	}
}
