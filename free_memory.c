/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_memory.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phijano- <phijano-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 10:58:53 by phijano-          #+#    #+#             */
/*   Updated: 2022/08/23 13:56:27 by phijano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libso_long.h"

static void	ft_free_array_s(t_sprite *anim, int number, t_game *game)
{
	int	count;

	count = -1;
	while (++count < number)
		mlx_destroy_image(game->mlx, anim[count].img);
}

static void	ft_free_sprites(t_game *game)
{
	mlx_destroy_image(game->mlx, game->map.wall.img);
	mlx_destroy_image(game->mlx, game->map.road.img);
	mlx_destroy_image(game->mlx, game->map.exit_c.img);
	mlx_destroy_image(game->mlx, game->map.exit_o.img);
	ft_free_array_s(game->map.coll, 4, game);
	ft_free_array_s(game->hero.d, 3, game);
	ft_free_array_s(game->hero.u, 3, game);
	ft_free_array_s(game->hero.l, 3, game);
	ft_free_array_s(game->hero.r, 3, game);
	ft_free_array_s(game->enemy.d, 3, game);
	ft_free_array_s(game->enemy.u, 3, game);
	ft_free_array_s(game->enemy.l, 3, game);
	ft_free_array_s(game->enemy.r, 3, game);
	ft_free_array_s(game->font.numb, 10, game);
	mlx_destroy_image(game->mlx, game->font.m.img);
	mlx_destroy_image(game->mlx, game->font.o.img);
	mlx_destroy_image(game->mlx, game->font.v.img);
	mlx_destroy_image(game->mlx, game->font.e.img);
	mlx_destroy_image(game->mlx, game->font.s.img);
}

void	ft_free_split(char **split)
{
	int	count;

	count = -1;
	while (split[++count])
		free(split[count]);
	free(split);
}

void	ft_free_enemies(t_moves *enemy)
{
	t_moves	*temp;

	if (enemy)
	{
		while (enemy)
		{
			temp = enemy->next;
			free(enemy);
			enemy = temp;
		}
	}
}

void	ft_free_game(t_game *game)
{
	ft_free_split(game->map.map);
	ft_free_enemies(game->enemy.moves);
	ft_free_sprites(game);
}
