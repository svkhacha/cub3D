/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabazyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 13:54:40 by sabazyan          #+#    #+#             */
/*   Updated: 2023/02/23 14:17:46 by sabazyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_walls(char **map, int first_i, int last_i)
{
	int	i;
	int	j;

	i = first_i;
	while (i <= last_i && map[i])
	{
		j = 0;
		if (i == first_i || i == last_i)
		{
			while (map[i][j])
			{
				if (map[i][j] != '1' && map[i][j] != ' '
					&& map[i][j] != '\t' && map[i][j] != '\n')
					return (0);
				j++;
			}
		}
		else if (i > first_i && i < last_i)
		{
			if (check_walls_2(map, i, j) == 0)
				return (0);
		}
		i++;
	}
	return (1);
}

int	check_walls_2(char **map, int i, int j)
{
	int	length;

	length = ft_strlen(map[i]) - 1;
	while (map[i][j])
	{
		if ((map[i][0] != '1' && map[i][0] != ' ' && map[i][0] != '\t')
			|| (map[i][length - 1] != '1' && map[i][length - 1] != ' '
			&& map[i][length - 1] != '\t'))
			return (0);
		if (j > 0 && j < length)
		{
			if ((map[i][j - 1] == ' ' || map[i][j + 1] == ' '
			|| (j <= ft_strlen(map[i - 1]) && map[i - 1][j] == ' ')
			|| (j <= ft_strlen(map[i + 1]) && map[i + 1][j] == ' '))
			&& (map[i][j] != '1' && map[i][j] != ' ' && map[i][j] != '\t'))
				return (0);
			if ((j >= ft_strlen(map[i - 1]) || j >= ft_strlen(map[i + 1]))
				&& (map[i][j] != '1' && map[i][j] != ' ' && map[i][j] != '\t'))
				return (0);
		}
		j++;
	}
	return (1);
}

int	malloc_counting(char *line)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (line[i])
	{
		while (line[i] == ' ' || line[i] == '\t')
			i++;
		while (line[i])
		{
			i++;
			count++;
		}
	}
	return (count + 1);
}

char	*no_tab(char *line)
{
	int		i;
	int		j;
	int		new_count;
	char	*new;

	i = -1;
	j = 0;
	new_count = 0;
	while (line[++i])
	{
		if (line[i] == '\t')
			new_count++;
	}
	i = 0;
	new_count = new_count * 3 + ft_strlen(line) + 1;
	new = malloc(sizeof(char) * new_count);
	if (!new)
		return (NULL);
	no_tab_2(i, j, new, line);
	return (new);
}

void	no_tab_2(int i, int j, char *new_line, char *line)
{
	int		count;

	j = 0;
	while (line[i] != '\n')
	{
		count = 4;
		if (line[i] == '\t')
		{
			while (count)
			{
				new_line[j] = ' ';
				j++;
				count--;
			}
			j--;
		}
		else
			new_line[j] = line[i];
		i++;
		j++;
	}
	new_line[j] = '\n';
	new_line[++j] = '\0';
}
