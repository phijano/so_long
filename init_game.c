/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phijano- <phijano-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 13:19:03 by phijano-          #+#    #+#             */
/*   Updated: 2022/08/23 13:57:27 by phijano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libso_long.h"

static void	ft_new_enemy(t_game *game, int x, int y)
{
	t_moves	*moves;

	moves = (t_moves *)malloc(sizeof(t_moves));
	if (!moves)
	{
		ft_free_enemies(game->enemy.moves);
		ft_error_exit("memory problem\n");
	}
	moves->x = x;
	moves->y = y;
	moves->move = '0';
	moves->move_l = '0';
	moves->steps = 4;
	moves->change_c = 0;
	if (game->enemy.moves == NULL)
		moves->next = NULL;
	else
		moves->next = game->enemy.moves;
	game->enemy.moves = moves;
}

static void	ft_init_enemies(t_game *game)
{
	int		count;
	t_moves	*enemy;

	if (game->enemy.moves)
	{
		count = 2;
		enemy = game->enemy.moves;
		while (enemy)
		{
			enemy->change = ++count;
			enemy = enemy->next;
			if (count == 10)
				count = 2;
		}
	}
}

static void	ft_init_hero(t_game *game, int x, int y)
{
	game->hero.x = x;
	game->hero.y = y;
	game->hero.next_move = '0';
	game->hero.moves_priority = ft_strdup("0000");
	game->hero.last_move = '0';
	game->hero.steps = 4;
	game->hero.move = '0';
}

void	ft_init_game(t_game *game)
{
	int	count_x;
	int	count_y;

	game->enemy.moves = NULL;
	count_y = -1;
	while (++count_y < game->map.rows)
	{
		count_x = -1;
		while (++count_x < game->map.cols)
		{
			if (game->map.map[count_y][count_x] == 'P')
				ft_init_hero(game, count_x, count_y);
			else if (game->map.map[count_y][count_x] == 'B')
				ft_new_enemy(game, count_x, count_y);
		}
	}
	ft_init_enemies(game);
	game->map.steps = 4;
	game->exit = 0;
	game->score = 0;
}
