/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabazyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 13:52:10 by sabazyan          #+#    #+#             */
/*   Updated: 2023/02/23 14:21:31 by sabazyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	**check_arguments(int ac, char **av)
{
	int		fd;
	int		malloc_count;
	char	**map;

	if (ac != 2)
	{
		printf("Invalid number of arguments\n");
		return (NULL);
	}
	if (check_extension(av[1]) == 0)
	{
		printf("Invalid file\n");
		return (NULL);
	}
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
	{
		printf("No such file\n");
		return (NULL);
	}
	malloc_count = reading_lines(fd) + 1;
	close(fd);
	map = check_arguments_2(av, malloc_count);
	return (map);
}

char	**check_arguments_2(char **av, int count)
{
	int		fd;
	char	**map;

	fd = open(av[1], O_RDONLY);
	if (fd == -1)
	{
		printf("No such file\n");
		return (NULL);
	}
	map = reading_file(fd, count);
	if (map == NULL)
	{
		printf("Invalid map\n");
		return (NULL);
	}
	if (check_new_lines(map) == 0 || check_full_map(map) == 0)
	{
		free_map(map);
		printf("Invalid map\n");
		return (NULL);
	}
	return (map);
}

int	check_new_lines(char **map)
{
	int	i;
	int	id_count;

	i = 0;
	id_count = 0;
	while (map[++i])
	{
		if (is_id(map[i], 0))
			id_count++;
		if (map[i] && id_count == 6)
		{
			i++;
			while (map[i] && is_empty_str(map[i]) == 1)
				i++;
			while (map[i])
			{
				if (is_empty_str(map[i]) == 1)
					return (0);
				i++;
			}
			i--;
		}
	}
	return (1);
}

int	check_extension(char *str)
{
	int	index;

	index = ft_strlen(str) - 1;
	if (ft_strlen(str) < 5)
		return (0);
	if (str[index] != 'b' || str[index - 1] != 'u'
		|| str[index - 2] != 'c' || str[index - 3] != '.')
		return (0);
	return (1);
}

int	check_other_chars(char **map, int first_i)
{
	int	i;
	int	j;

	i = first_i - 1;
	while (map[++i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] != '0' && map[i][j] != '1'
				&& map[i][j] != 'N' && map[i][j] != 'S'
				&& map[i][j] != 'E' && map[i][j] != 'W'
				&& map[i][j] != ' ' && map[i][j] != '\t' && map[i][j] != '\n')
				return (0);
			j++;
		}
	}
	return (1);
}
