/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_hero.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phijano- <phijano-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 15:02:59 by phijano-          #+#    #+#             */
/*   Updated: 2022/08/23 14:06:10 by phijano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libso_long.h"

static void	ft_update_exit(t_game *game)
{
	int	count_x;
	int	count_y;
	int	exit;

	exit = 1;
	count_y = -1;
	while (++count_y < game->map.rows)
	{
		count_x = -1;
		while (++count_x < game->map.cols)
			if (game->map.map[count_y][count_x] == 'C')
				exit = 0;
	}
	game->exit = exit;
}

static void	ft_check_killed(t_game *game)
{
	t_moves	*enemy;

	enemy = game->enemy.moves;
	while (enemy)
	{
		if (enemy->x == game->hero.x && enemy->y == game->hero.y)
			ft_finish("YOU LOSE\n", game);
		enemy = enemy->next;
	}
}

static void	ft_check_win(t_game *game)
{
	if (game->exit == 1)
		ft_finish("YOU WIN\n", game);
}

static void	ft_update_pos(t_game *game)
{
	if (game->hero.move == 'r')
		game->hero.x++;
	else if (game->hero.move == 'l')
		game->hero.x--;
	else if (game->hero.move == 'u')
		game->hero.y--;
	else if (game->hero.move == 'd')
		game->hero.y++;
	if (game->score < 999999)
		game->score++;
	if (game->enemy.moves)
		ft_check_killed(game);
	if (game->map.map[game->hero.y][game->hero.x] == 'C')
	{
		game->map.map[game->hero.y][game->hero.x] = '0';
		ft_update_exit(game);
	}
	if (game->map.map[game->hero.y][game->hero.x] == 'E')
		ft_check_win(game);
	if (game->hero.move != '0')
		game->hero.last_move = game->hero.move;
	game->hero.next_move = ft_get_next_move(game);
}

void	ft_step_hero(t_game *game)
{
	if (game->hero.move != '0')
	{
		game->hero.steps++;
		if (game->hero.steps == 4)
		{
			ft_update_pos(game);
			game->hero.move = '0';
		}
	}
}
