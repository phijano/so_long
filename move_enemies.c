/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_enemies.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phijano- <phijano-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 13:56:52 by phijano-          #+#    #+#             */
/*   Updated: 2022/08/23 14:07:56 by phijano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libso_long.h"

static void	ft_change_move(t_game *game, t_moves *enemy)
{
	enemy->change_c = 0;
	if (enemy->move_l == 'r' || enemy->move_l == 'l' )
	{
		if (game->map.map[enemy->y - 1][enemy->x] != '1')
			enemy->move = 'u';
		else if (game->map.map[enemy->y + 1][enemy->x] != '1')
			enemy->move = 'd';
	}
	else if (enemy->move_l == 'u' || enemy->move_l == 'd' )
	{
		if (game->map.map[enemy->y][enemy->x - 1] != '1')
			enemy->move = 'l';
		else if (game->map.map[enemy->y][enemy->x + 1] != '1')
			enemy->move = 'r';
	}
}

static void	ft_keep_enemy_move(t_game *game, t_moves *ogre)
{
	if (ogre->move_l == 'r' && game->map.map[ogre->y][ogre->x + 1] != '1')
		ogre->move = 'r';
	else if (ogre->move_l == 'l' && game->map.map[ogre->y][ogre->x - 1] != '1')
		ogre->move = 'l';
	else if (ogre->move_l == 'u' && game->map.map[ogre->y - 1][ogre->x] != '1')
		ogre->move = 'u';
	else if (ogre->move_l == 'd' && game->map.map[ogre->y + 1][ogre->x] != '1')
		ogre->move = 'd';
	else if (game->map.map[ogre->y][ogre->x + 1] != '1')
		ogre->move = 'r';
	else if (game->map.map[ogre->y][ogre->x - 1] != '1')
		ogre->move = 'l';
	else if (game->map.map[ogre->y - 1][ogre->x] != '1')
		ogre->move = 'u';
	else if (game->map.map[ogre->y + 1][ogre->x] != '1')
		ogre->move = 'd';
}

static void	ft_update_enemy(t_game *game, t_moves *enemy)
{
	enemy->move_l = enemy->move;
	if (enemy->move == 'r')
		enemy->x++;
	else if (enemy->move == 'l')
		enemy->x--;
	else if (enemy->move == 'u')
		enemy->y--;
	else if (enemy->move == 'd')
		enemy->y++;
	if (enemy->x == game->hero.x && enemy->y == game->hero.y)
		ft_finish("YOU LOSE\n", game);
	enemy->move = '0';
	enemy->change_c++;
	if (enemy->change_c == enemy->change)
		ft_change_move(game, enemy);
	if (enemy->move != '0')
		enemy->steps = 1;
}

void	ft_step_enemies(t_game *game)
{
	t_moves	*enemy;

	enemy = game->enemy.moves;
	while (enemy)
	{
		enemy->steps++;
		if (enemy->move != '0')
		{
			if (enemy->steps == 4)
				ft_update_enemy(game, enemy);
		}
		else
		{
			ft_keep_enemy_move(game, enemy);
			if (enemy->move != '0')
				enemy->steps = 1;
		}
		enemy = enemy->next;
	}
}
