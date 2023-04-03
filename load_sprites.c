/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_sprites.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phijano- <phijano-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 11:23:26 by phijano-          #+#    #+#             */
/*   Updated: 2022/08/23 13:12:35 by phijano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libso_long.h"

t_sprite	ft_new_sprite(void *mlx, char *path)
{
	t_sprite	sprite;

	sprite.img = mlx_xpm_file_to_image(mlx, path,
			&sprite.size.x, &sprite.size.y);
	sprite.pixels = mlx_get_data_addr(sprite.img,
			&sprite.bits_per_pixel, &sprite.line_size, &sprite.endian);
	return (sprite);
}

static void	ft_load_others(t_game *game)
{
	game->map.wall = ft_new_sprite(game->mlx, "./sprites/others/wall.xpm");
	game->map.road = ft_new_sprite(game->mlx, "./sprites/others/road.xpm");
	game->map.exit_c = ft_new_sprite(game->mlx, "./sprites/others/door_0.xpm");
	game->map.exit_o = ft_new_sprite(game->mlx, "./sprites/others/door_1.xpm");
	game->map.coll[0] = ft_new_sprite(game->mlx, "./sprites/others/coll_0.xpm");
	game->map.coll[1] = ft_new_sprite(game->mlx, "./sprites/others/coll_1.xpm");
	game->map.coll[2] = ft_new_sprite(game->mlx, "./sprites/others/coll_2.xpm");
	game->map.coll[3] = ft_new_sprite(game->mlx, "./sprites/others/coll_3.xpm");
}

static void	ft_load_enemy(t_game *game)
{
	game->enemy.d[0] = ft_new_sprite(game->mlx, "./sprites/enemy/enemy_f0.xpm");
	game->enemy.d[1] = ft_new_sprite(game->mlx, "./sprites/enemy/enemy_f1.xpm");
	game->enemy.d[2] = ft_new_sprite(game->mlx, "./sprites/enemy/enemy_f2.xpm");
	game->enemy.l[0] = ft_new_sprite(game->mlx, "./sprites/enemy/enemy_l0.xpm");
	game->enemy.l[1] = ft_new_sprite(game->mlx, "./sprites/enemy/enemy_l1.xpm");
	game->enemy.l[2] = ft_new_sprite(game->mlx, "./sprites/enemy/enemy_l2.xpm");
	game->enemy.u[0] = ft_new_sprite(game->mlx, "./sprites/enemy/enemy_b0.xpm");
	game->enemy.u[1] = ft_new_sprite(game->mlx, "./sprites/enemy/enemy_b1.xpm");
	game->enemy.u[2] = ft_new_sprite(game->mlx, "./sprites/enemy/enemy_b2.xpm");
	game->enemy.r[0] = ft_new_sprite(game->mlx, "./sprites/enemy/enemy_r0.xpm");
	game->enemy.r[1] = ft_new_sprite(game->mlx, "./sprites/enemy/enemy_r1.xpm");
	game->enemy.r[2] = ft_new_sprite(game->mlx, "./sprites/enemy/enemy_r2.xpm");
}

static void	ft_load_hero(t_game *game)
{
	game->hero.d[0] = ft_new_sprite(game->mlx, "./sprites/hero/hero_f0.xpm");
	game->hero.d[1] = ft_new_sprite(game->mlx, "./sprites/hero/hero_f1.xpm");
	game->hero.d[2] = ft_new_sprite(game->mlx, "./sprites/hero/hero_f2.xpm");
	game->hero.l[0] = ft_new_sprite(game->mlx, "./sprites/hero/hero_l0.xpm");
	game->hero.l[1] = ft_new_sprite(game->mlx, "./sprites/hero/hero_l1.xpm");
	game->hero.l[2] = ft_new_sprite(game->mlx, "./sprites/hero/hero_l2.xpm");
	game->hero.u[0] = ft_new_sprite(game->mlx, "./sprites/hero/hero_b0.xpm");
	game->hero.u[1] = ft_new_sprite(game->mlx, "./sprites/hero/hero_b1.xpm");
	game->hero.u[2] = ft_new_sprite(game->mlx, "./sprites/hero/hero_b2.xpm");
	game->hero.r[0] = ft_new_sprite(game->mlx, "./sprites/hero/hero_r0.xpm");
	game->hero.r[1] = ft_new_sprite(game->mlx, "./sprites/hero/hero_r1.xpm");
	game->hero.r[2] = ft_new_sprite(game->mlx, "./sprites/hero/hero_r2.xpm");
}

void	ft_load_sprites(t_game *game)
{
	ft_load_hero(game);
	ft_load_enemy(game);
	ft_load_others(game);
	ft_load_font(game);
}
