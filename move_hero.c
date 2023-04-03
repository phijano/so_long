/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_hero.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phijano- <phijano-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 14:39:03 by phijano-          #+#    #+#             */
/*   Updated: 2022/08/23 14:02:28 by phijano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libso_long.h"

static void	ft_new_hero_move(t_game *game, char direction)
{
	game->hero.move = direction;
	game->hero.steps = 1;
}

void	ft_move_hero(t_game *game)
{
	if (game->hero.move == '0')
	{
		if (game->hero.next_move == 'r'
			&& game->map.map[game->hero.y][game->hero.x + 1] != '1')
			ft_new_hero_move(game, 'r');
		else if (game->hero.next_move == 'l'
			&& game->map.map[game->hero.y][game->hero.x - 1] != '1')
			ft_new_hero_move(game, 'l');
		else if (game->hero.next_move == 'u'
			&& game->map.map[game->hero.y - 1][game->hero.x] != '1')
			ft_new_hero_move(game, 'u');
		else if (game->hero.next_move == 'd'
			&& game->map.map[game->hero.y + 1][game->hero.x] != '1')
			ft_new_hero_move(game, 'd');
	}
	game->hero.next_move = ft_get_next_move(game);
}
