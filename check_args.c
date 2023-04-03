/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phijano- <phijano-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 11:33:21 by phijano-          #+#    #+#             */
/*   Updated: 2022/08/23 13:51:01 by phijano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libso_long.h"

static char	*ft_get_map(char *file)
{
	int		fd;
	char	*str;
	char	*map;
	char	*temp;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		ft_error_exit("Error\nMap file coudnt be opened");
	str = NULL;
	map = NULL;
	str = get_next_line(fd);
	if (str)
		map = ft_strjoin("", str);
	while (str)
	{
		free(str);
		str = get_next_line(fd);
		if (str)
		{
			temp = map;
			map = ft_strjoin(temp, str);
			free(temp);
		}
	}
	return (map);
}

static void	ft_check_file(char *file)
{
	int	length;

	length = ft_strlen(file);
	if (length > 4)
	{
		if (file[length - 1] != 'r' || file[length - 2] != 'e'
			|| file[length - 3] != 'b' || file[length - 4] != '.')
			ft_error_exit("Error\nMap file format is name.ber");
	}
	else
		ft_error_exit("Error\nMap file format is name.ber");
}

void	ft_check_arg(int argc, char **args, t_map *map)
{
	char	*map_str;

	if (argc != 2)
		ft_error_exit("Error\nExecute like this: ./so_long map_name.ber");
	ft_check_file(args[1]);
	map_str = ft_get_map(args[1]);
	ft_check_map(map_str, map);
}
