/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_game.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phijano- <phijano-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 13:35:37 by phijano-          #+#    #+#             */
/*   Updated: 2022/08/22 15:04:25 by phijano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libso_long.h"

int	ft_update(void *param)
{
	t_game		*game;
	static int	frame;

	game = (t_game *)param;
	frame++;
	ft_move_hero(game);
	if (frame % 250 == 0)
	{
		if (frame % 500 == 0)
			game->map.steps++;
		if (game->map.steps == 5)
			game->map.steps = 1;
		ft_step_hero(game);
		ft_step_enemies(game);
		mlx_clear_window(game->mlx, game->window);
		ft_draw(game);
	}
	if (frame == 1000)
		frame = 0;
	return (0);
}
