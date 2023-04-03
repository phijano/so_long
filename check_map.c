/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phijano- <phijano-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 12:19:21 by phijano-          #+#    #+#             */
/*   Updated: 2022/08/23 13:52:26 by phijano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libso_long.h"

static int	ft_get_rows(char *map)
{
	int	count;
	int	rows;

	count = -1;
	rows = 0;
	while (map[++count])
		if (map[count] == '\n')
			rows++;
	if (rows < 3)
		ft_error_exit("Error\nNot enough rows in map\n");
	return (rows);
}

static int	ft_get_cols(char *map)
{
	int	count;
	int	col;
	int	total_col;

	count = -1;
	total_col = -1;
	col = 0;
	while (map[++count])
	{
		col++;
		if (map[count] == '\n')
		{
			col--;
			if (total_col == -1)
				total_col = col;
			if (total_col != col)
				ft_error_exit("Error\nDiferent size of columns in map\n");
			col = 0;
		}
	}
	if (total_col < 3)
		ft_error_exit("Error\nNot enough columns in map\n");
	return (total_col);
}

static void	ft_check_obj(char *map)
{
	int	food;
	int	hero;
	int	portal;
	int	count;

	food = 0;
	hero = 0;
	portal = 0;
	count = -1;
	while (map[++count])
	{
		if (map[count] == 'C')
			food = 1;
		else if (map[count] == 'P')
			hero++;
		else if (map[count] == 'E')
			portal++;
		else if (map[count] != '0' && map[count] != '1'
			&& map[count] != 'B' && map[count] != '\n')
			ft_error_exit("Error\nMap has not allowed characters\n");
	}
	if (food == 0 || portal == 0 || portal > 1
		|| hero == 0 || hero > 1)
		ft_error_exit("Error\nPut 1 hero, at least 1 collectible and 1 exit\n");
}

static void	ft_check_walls(char **map, int rows, int cols)
{
	int	count;

	count = -1;
	while (map[0][++count])
	{
		if (map[0][count] != '1' || map[rows - 1][count] != '1')
		{
			ft_free_split(map);
			ft_error_exit("Error\nMap is not closed\n");
		}
	}
	count = -1;
	while (map[++count])
	{
		if (map[count][0] != '1' || map[count][cols - 1] != '1')
		{
			ft_free_split(map);
			ft_error_exit("Error\nMap is not closed\n");
		}
	}
}

void	ft_check_map(char *map_str, t_map *map)
{
	map->rows = ft_get_rows(map_str);
	map->cols = ft_get_cols(map_str);
	if (map->cols <= map->rows)
		ft_error_exit("Error\nMap has to be rectangular\n");
	ft_check_obj(map_str);
	map->map = ft_split(map_str, '\n');
	free(map_str);
	ft_check_walls(map->map, map->rows, map->cols);
}
