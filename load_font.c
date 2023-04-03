/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_font.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phijano- <phijano-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 13:06:34 by phijano-          #+#    #+#             */
/*   Updated: 2022/08/23 13:12:57 by phijano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libso_long.h"

void	ft_load_font(t_game *game)
{
	game->font.numb[0] = ft_new_sprite(game->mlx, "./sprites/font/zero.xpm");
	game->font.numb[1] = ft_new_sprite(game->mlx, "./sprites/font/one.xpm");
	game->font.numb[2] = ft_new_sprite(game->mlx, "./sprites/font/two.xpm");
	game->font.numb[3] = ft_new_sprite(game->mlx, "./sprites/font/three.xpm");
	game->font.numb[4] = ft_new_sprite(game->mlx, "./sprites/font/four.xpm");
	game->font.numb[5] = ft_new_sprite(game->mlx, "./sprites/font/five.xpm");
	game->font.numb[6] = ft_new_sprite(game->mlx, "./sprites/font/six.xpm");
	game->font.numb[7] = ft_new_sprite(game->mlx, "./sprites/font/seven.xpm");
	game->font.numb[8] = ft_new_sprite(game->mlx, "./sprites/font/eight.xpm");
	game->font.numb[9] = ft_new_sprite(game->mlx, "./sprites/font/nine.xpm");
	game->font.m = ft_new_sprite(game->mlx, "./sprites/font/m.xpm");
	game->font.o = ft_new_sprite(game->mlx, "./sprites/font/o.xpm");
	game->font.v = ft_new_sprite(game->mlx, "./sprites/font/v.xpm");
	game->font.e = ft_new_sprite(game->mlx, "./sprites/font/e.xpm");
	game->font.s = ft_new_sprite(game->mlx, "./sprites/font/s.xpm");
}
