/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map_3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabazyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 13:57:16 by sabazyan          #+#    #+#             */
/*   Updated: 2023/02/23 13:58:00 by sabazyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_player_count(char **map, int first_i)
{
	int	i;
	int	j;
	int	n_count;
	int	s_count;

	i = first_i - 1;
	n_count = 0;
	s_count = 0;
	while (map[++i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'N')
				n_count++;
			else if (map[i][j] == 'S')
				s_count++;
			j++;
		}
	}
	if (check_player_count_2(map, first_i, n_count, s_count) == 0)
		return (0);
	return (1);
}

int	check_player_count_2(char **map, int first_i, int n_count, int s_count)
{
	int	i;
	int	j;
	int	e_count;
	int	w_count;

	i = first_i - 1;
	j = 0;
	e_count = 0;
	w_count = 0;
	while (map[++i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'E')
				e_count++;
			else if (map[i][j] == 'W')
				w_count++;
			j++;
		}
	}
	if (n_count + s_count + e_count + w_count != 1)
		return (0);
	return (1);
}

int	check_textures(char *line)
{
	int	i;

	i = 0;
	while (line[i] && (line[i] == ' ' || line[i] == '\t'))
		i++;
	i += 2;
	while (line[i] && (line[i] == ' ' || line[i] == '\t'))
		i++;
	if (line[i] && line[i] == '.')
	{
		i++;
		if (line[i] && line[i] != '/')
			return (0);
		i++;
	}
	while (line[i] && (ft_isalpha(line[i]) || ft_isdigit(line[i])
			|| line[i] == '/' || line[i] == '_'))
		i++;
	if (check_textures_2(line, i) == 0)
		return (0);
	return (1);
}

int	check_textures_2(char *line, int i)
{
	if (!line[i] || !line[i + 1] || !line[i + 2] || !line[i + 3])
		return (0);
	if (line[i] != '.' || line[i + 1] != 'x' || line[i + 2] != 'p'
		|| line[i + 3] != 'm')
		return (0);
	i += 4;
	while (line[i])
	{
		if (line[i] != ' ' && line[i] != '\t' && line[i] != '\n')
			return (0);
		i++;
	}
	return (1);
}

void	free_map(char **map)
{
	int	i;

	i = -1;
	while (map[++i])
		free(map[i]);
	free(map);
}
