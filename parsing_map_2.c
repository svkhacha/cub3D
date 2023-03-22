/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabazyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 13:55:43 by sabazyan          #+#    #+#             */
/*   Updated: 2023/02/23 13:56:16 by sabazyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_full_map(char **map)
{
	int	i;
	int	count;
	int	count_2;

	i = -1;
	count = 0;
	count_2 = 0;
	if (check_full_map_2(map, i, count, count_2) == 0)
		return (0);
	return (1);
}

int	check_full_map_2(char **map, int i, int count, int count_2)
{
	int	j;

	while (map[++i] && count < 6)
	{
		j = 0;
		if (is_id(map[i], j))
		{
			count++;
			count_2 += is_id(map[i], j);
		}
		else
		{
			while (map[i][j])
			{
				if (map[i][j] != '1' && map[i][j] != '0' && map[i][j] != ' '
				&& map[i][j] != '\t' && map[i][j] != '\n' && map[i][j] != 'N'
				&& map[i][j] != 'S' && map[i][j] != 'E' && map[i][j] != 'W')
					return (0);
				j++;
			}
		}
	}
	if (count_2 != 21 || check_full_map_3(map, i) == 0)
		return (0);
	return (1);
}

int	check_full_map_3(char **map, int i)
{
	int	first_i;
	int	last_i;

	first_i = i;
	while (map[++i])
		last_i = i;
	if (check_walls(map, first_i, last_i) == 0
		|| check_other_chars(map, first_i) == 0
		|| check_player_count(map, first_i) == 0)
		return (0);
	return (1);
}

int	is_id(char *map_line, int j)
{
	char	*new_line;

	while (map_line[j] && (map_line[j] == ' ' || map_line[j] == '\t'))
		j++;
	if (map_line[j] && (map_line[j] == 'F' || map_line[j] == 'C'))
		return (is_id_3(map_line, j));
	else if ((map_line[j] == 'N' && map_line[j + 1] && map_line[j + 1] == 'O')
		|| (map_line[j] == 'S' && map_line[j + 1] && map_line[j + 1] == 'O')
		|| (map_line[j] == 'W' && map_line[j + 1] && map_line[j + 1] == 'E')
		|| (map_line[j] == 'E' && map_line[j + 1] && map_line[j + 1] == 'A'))
	{
		new_line = create_line(map_line, j);
		if (!new_line || check_textures(new_line) == 0)
		{
			free(new_line);
			return (0);
		}
		else
			return (is_id_2(map_line, j, new_line));
	}
	return (0);
}

int	is_id_2(char *map_line, int j, char *new_line)
{
	if (map_line[j] == 'N')
	{
		free(new_line);
		return (3);
	}
	else if (map_line[j] == 'S')
	{
		free(new_line);
		return (4);
	}
	else if (map_line[j] == 'W')
	{
		free(new_line);
		return (5);
	}
	else
	{
		free(new_line);
		return (6);
	}
	free(new_line);
	return (0);
}
