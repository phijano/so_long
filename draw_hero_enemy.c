/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_hero_enemy.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phijano- <phijano-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 10:48:57 by phijano-          #+#    #+#             */
/*   Updated: 2022/08/23 13:54:25 by phijano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libso_long.h"

static void	ft_draw_enemy(t_game *game, t_moves *enemy)
{
	if (enemy->move == 'r')
		mlx_put_image_to_window(game->mlx, game->window,
			game->enemy.r[enemy->steps % 2].img,
			(enemy->x * SIZE + (SIZE * enemy->steps / 4)), (enemy->y * SIZE));
	else if (enemy->move == 'l')
		mlx_put_image_to_window(game->mlx, game->window,
			game->enemy.l[enemy->steps % 2].img,
			(enemy->x * SIZE - (SIZE * enemy->steps / 4)), (enemy->y * SIZE));
	else if (enemy->move == 'u')
		mlx_put_image_to_window(game->mlx, game->window,
			game->enemy.u[enemy->steps % 2].img,
			(enemy->x * SIZE), (enemy->y * SIZE - (SIZE * enemy->steps / 4)));
	else if (enemy->move == 'd')
		mlx_put_image_to_window(game->mlx, game->window,
			game->enemy.d[enemy->steps % 2].img,
			(enemy->x * SIZE), (enemy->y * SIZE + (SIZE * enemy->steps / 4)));
	else
		mlx_put_image_to_window(game->mlx, game->window,
			game->enemy.d[2].img, (enemy->x * SIZE), (enemy->y * SIZE));
}

void	ft_draw_enemies(t_game *game)
{
	t_moves	*enemy;

	enemy = game->enemy.moves;
	while (enemy)
	{
		ft_draw_enemy(game, enemy);
		enemy = enemy->next;
	}
}

static void	ft_draw_hero_stopped(t_game *game)
{
	if (game->hero.last_move == 'r')
		mlx_put_image_to_window(game->mlx, game->window,
			game->hero.r[2].img, (game->hero.x * SIZE), (game->hero.y * SIZE));
	else if (game->hero.last_move == 'l')
		mlx_put_image_to_window(game->mlx, game->window,
			game->hero.l[2].img, (game->hero.x * SIZE), (game->hero.y * SIZE));
	else if (game->hero.last_move == 'u')
		mlx_put_image_to_window(game->mlx, game->window,
			game->hero.u[2].img, (game->hero.x * SIZE), (game->hero.y * SIZE));
	else
		mlx_put_image_to_window(game->mlx, game->window,
			game->hero.d[2].img, (game->hero.x * SIZE), (game->hero.y * SIZE));
}

void	ft_draw_hero(t_game *game)
{
	if (game->hero.move == 'r')
		mlx_put_image_to_window(game->mlx, game->window,
			game->hero.r[game->hero.steps % 2].img,
			(game->hero.x * SIZE + (SIZE * game->hero.steps / 4)),
			(game->hero.y * SIZE));
	else if (game->hero.move == 'l')
		mlx_put_image_to_window(game->mlx, game->window,
			game->hero.l[game->hero.steps % 2].img,
			(game->hero.x * SIZE - (SIZE * game->hero.steps / 4)),
			(game->hero.y * SIZE));
	else if (game->hero.move == 'u')
		mlx_put_image_to_window(game->mlx, game->window,
			game->hero.u[game->hero.steps % 2].img,
			(game->hero.x * SIZE),
			(game->hero.y * SIZE - (SIZE * game->hero.steps / 4)));
	else if (game->hero.move == 'd')
		mlx_put_image_to_window(game->mlx, game->window,
			game->hero.d[game->hero.steps % 2].img,
			(game->hero.x * SIZE),
			(game->hero.y * SIZE + (SIZE * game->hero.steps / 4)));
	else
		ft_draw_hero_stopped(game);
}
