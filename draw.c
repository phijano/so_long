/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phijano- <phijano-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 13:12:23 by phijano-          #+#    #+#             */
/*   Updated: 2022/08/23 13:53:19 by phijano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libso_long.h"

static void	ft_draw_others(t_game *game)
{
	int	count_x;
	int	count_y;

	count_y = -1;
	while (++count_y < game->map.rows)
	{
		count_x = -1;
		while (++count_x < game->map.cols)
			if (game->map.map[count_y][count_x] == 'C')
				mlx_put_image_to_window(game->mlx, game->window,
					game->map.coll[game->map.steps % 4].img,
					(count_x * SIZE), (count_y * SIZE));
	}
	ft_draw_hero(game);
	ft_draw_score(game);
	if (game->enemy.moves)
		ft_draw_enemies(game);
}

static void	ft_draw_exit(t_game *game, int x, int y)
{
	if (game->exit == 0)
		mlx_put_image_to_window(game->mlx, game->window,
			game->map.exit_c.img, (x * SIZE),
			(y * SIZE));
	else
		mlx_put_image_to_window(game->mlx, game->window,
			game->map.exit_o.img, (x * SIZE),
			(y * SIZE));
}

void	ft_draw(t_game *game)
{
	int	count_x;
	int	count_y;

	count_y = -1;
	while (++count_y < game->map.rows)
	{
		count_x = -1;
		while (++count_x < game->map.cols)
		{
			if (game->map.map[count_y][count_x] == '1')
				mlx_put_image_to_window(game->mlx, game->window,
					game->map.wall.img, (count_x * SIZE), (count_y * SIZE));
			else if (game->map.map[count_y][count_x] == 'E')
				ft_draw_exit(game, count_x, count_y);
			else
				mlx_put_image_to_window(game->mlx, game->window,
					game->map.road.img, (count_x * SIZE), (count_y * SIZE));
		}
	}
	ft_draw_others(game);
}
