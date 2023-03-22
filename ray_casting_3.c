/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_win_3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svkhacha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 21:26:37 by svkhacha          #+#    #+#             */
/*   Updated: 2023/03/03 21:26:46 by svkhacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "cub3d.h"

float	ft_abs(float num)
{
	if (num < 0)
		return (-num);
	return (num);
}

char	*get_correct_arg(char *ptr)
{
	int		i;
	int		j;
	char	*new_arg;

	new_arg = malloc(sizeof(char) * (ft_strlen(ptr) + 1));
	i = 0;
	j = 0;
	while (ptr[i])
	{
		if (ptr[i] != ' ' && ptr[i] != '\t')
		{
			new_arg[j] = ptr[i];
			j++;
		}
		i++;
	}
	new_arg[j] = '\0';
	return (new_arg);
}

void	init_plane(t_data *data, double i, double j)
{
	data->rcasting->planex = i;
	data->rcasting->planey = j;
}

void	init_dir(t_data *data, double i, double j)
{
	data->rcasting->dirx = i;
	data->rcasting->diry = j;
}

void	init_player_pos(t_data *data, int i, int j)
{
	if (data->args->map[i][j] == 'S')
	{
		init_dir(data, 1, 0);
		init_plane(data, 0, -0.66);
	}
	else if (data->args->map[i][j] == 'N')
	{
		init_dir(data, -1, 0);
		init_plane(data, 0, 0.66);
	}
	else if (data->args->map[i][j] == 'E')
	{
		init_dir(data, 0, 1);
		init_plane(data, 0.66, 0);
	}
	else if (data->args->map[i][j] == 'W')
	{
		init_dir(data, 0, -1);
		init_plane(data, -0.66, 0);
	}
}
