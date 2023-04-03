/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_score.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phijano- <phijano-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 10:29:25 by phijano-          #+#    #+#             */
/*   Updated: 2022/08/23 13:55:05 by phijano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libso_long.h"

static void	ft_draw_number(t_game *game, int number, int x, int y)
{
	if (number > 0)
	{
		ft_draw_number(game, number / 10, x - 7, y);
		mlx_put_image_to_window(game->mlx, game->window,
			game->font.numb[number % 10].img, x, y);
	}
}

static int	ft_len(int n)
{
	int	len;

	len = 0;
	while (n != 0)
	{
		len++;
		n = n / 10;
	}
	return (len);
}

static void	ft_draw_amount(t_game *game, int x, int y)
{
	int	number;

	number = game->score;
	if (number == 0)
		mlx_put_image_to_window(game->mlx, game->window,
			game->font.numb[0].img, x + 7, y);
	else
	{
		x = x + (ft_len(number) * 7);
		ft_draw_number(game, number, x, y);
	}
}

void	ft_draw_score(t_game *game)
{
	int	x;
	int	y;

	y = game->map.rows * SIZE + 35;
	x = 32;
	mlx_put_image_to_window(game->mlx, game->window,
		game->font.m.img, x, y);
	mlx_put_image_to_window(game->mlx, game->window,
		game->font.o.img, x + 7, y);
	mlx_put_image_to_window(game->mlx, game->window,
		game->font.v.img, x + 14, y);
	mlx_put_image_to_window(game->mlx, game->window,
		game->font.e.img, x + 21, y);
	mlx_put_image_to_window(game->mlx, game->window,
		game->font.s.img, x + 28, y);
	ft_draw_amount(game, x + 42, y);
}
