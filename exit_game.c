/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phijano- <phijano-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 09:54:13 by phijano-          #+#    #+#             */
/*   Updated: 2022/08/23 13:38:01 by phijano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libso_long.h"

int	ft_close(t_game *game)
{
	ft_free_game(game);
	mlx_clear_window(game->mlx, game->window);
	mlx_destroy_window(game->mlx, game->window);
	free(game->mlx);
	exit(0);
}

void	ft_error_exit(char *s)
{
	ft_putstr_fd(s, 2);
	exit(1);
}

void	ft_finish(char *s, t_game *game)
{
	ft_putstr_fd(s, 1);
	ft_close(game);
}
