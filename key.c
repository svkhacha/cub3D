/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_manager.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svkhacha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 21:28:55 by svkhacha          #+#    #+#             */
/*   Updated: 2023/03/03 21:29:05 by svkhacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	key_manager(int key, t_data *data)
{
	if (key == ESC)
		ft_close(key, data);
	if (key == RIGHT)
		rotate_right(data, -ROTATE_SPEED);
	if (key == LEFT)
		rotate_right(data, ROTATE_SPEED);
	if (key == A)
		move_left(data);
	if (key == D)
		move_right(data);
	if (key == W)
		move_up(data);
	if (key == S)
		move_down(data);
	init_win(data);
	return (0);
}

int	ft_close(int keycode, t_data *data)
{
	(void)keycode;
	(void)data;
	exit (0);
	return (0);
}
