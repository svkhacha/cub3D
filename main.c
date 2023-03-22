/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabazyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 13:50:43 by sabazyan          #+#    #+#             */
/*   Updated: 2023/02/23 14:20:33 by sabazyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int ac, char **av)
{
	char		**map;
	t_data		data;

	map = check_arguments(ac, av);
	if (!map)
		return (0);
	data.args = create_struct(map);
	init_structs(&data);
	data.game->mlx = mlx_init();
	data.game->win = mlx_new_window(data.game->mlx, WIDTH, HEIGHT, \
	"Remont s tyoplim polom :)");
	ft_mlx_xpm(&data);
	init_win(&data);
	mlx_hook(data.game->win, 17, 1L << 0, ft_close, &data);
	mlx_hook(data.game->win, 2, 1L << 0, key_manager, &data);
	mlx_loop(data.game->mlx);
	destroy_struct(data.args);
}
