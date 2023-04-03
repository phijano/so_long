/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phijano- <phijano-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 10:31:40 by phijano-          #+#    #+#             */
/*   Updated: 2023/03/06 14:27:48 by phijano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libso_long.h"

static void	ft_new_window(t_game *game, int widht, int height, char *name)
{
	game->window = mlx_new_window(game->mlx, widht, height, name);
	mlx_hook(game->window, 17, 0, ft_close, (void *)game);
}

static void	ft_start_game(t_map *map)
{
	t_game	game;

	game.map = *map;
	game.mlx = mlx_init();
	ft_init_game(&game);
	ft_new_window(&game, game.map.cols * SIZE,
		(game.map.rows * SIZE) + 80, "so_long");
	ft_load_sprites(&game);
	ft_draw(&game);
	mlx_hook(game.window, 2, 0, *ft_input_press, &game);
	mlx_hook(game.window, 3, 0, *ft_input_release, &game);
	mlx_loop_hook(game.mlx, *ft_update, &game);
	mlx_loop(game.mlx);
}

int	main(int argc, char **args)
{
	t_map	map;

	ft_check_arg(argc, args, &map);
	ft_start_game(&map);
	return (1);
}
