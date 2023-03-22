/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabazyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 18:32:07 by sabazyan          #+#    #+#             */
/*   Updated: 2023/02/24 18:32:09 by sabazyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_matrix	*create_struct(char **map)
{
	t_matrix	*args;
	char		**temp_floor;
	char		**temp_ceiling;

	args = malloc(sizeof(t_matrix));
	args->north = get_arguments(map, 'N', 2);
	args->south = get_arguments(map, 'S', 2);
	args->west = get_arguments(map, 'W', 2);
	args->east = get_arguments(map, 'E', 2);
	args->floor = get_arguments(map, 'F', 1);
	temp_floor = ft_split(args->floor, ',');
	args->f1 = ft_atoi(temp_floor[0]);
	args->f2 = ft_atoi(temp_floor[1]);
	args->f3 = ft_atoi(temp_floor[2]);
	free_map(temp_floor);
	args->ceiling = get_arguments(map, 'C', 1);
	temp_ceiling = ft_split(args->ceiling, ',');
	args->c1 = ft_atoi(temp_ceiling[0]);
	args->c2 = ft_atoi(temp_ceiling[1]);
	args->c3 = ft_atoi(temp_ceiling[2]);
	free_map(temp_ceiling);
	args->map = get_map(map);
	return (args);
}

void	destroy_struct(t_matrix *args)
{
	free(args->north);
	free(args->south);
	free(args->west);
	free(args->east);
	free(args->floor);
	free(args->ceiling);
	free_map(args->map);
}
