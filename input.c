/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phijano- <phijano-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 13:43:32 by phijano-          #+#    #+#             */
/*   Updated: 2022/08/23 13:59:04 by phijano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libso_long.h"

char	ft_get_next_move(t_game *game)
{
	int		count;
	char	move;

	count = -1;
	move = '0';
	while (++count < 3 && move == '0')
	{
		if (game->hero.moves_priority[count] == 'r')
			if (game->map.map[game->hero.y][game->hero.x + 1] != '1'
				&& !ft_strchr(game->hero.moves_priority, 'l'))
				move = 'r';
		if (game->hero.moves_priority[count] == 'l')
			if (game->map.map[game->hero.y][game->hero.x - 1] != '1'
				&& !ft_strchr(game->hero.moves_priority, 'r'))
				move = 'l';
		if (game->hero.moves_priority[count] == 'u')
			if (game->map.map[game->hero.y - 1][game->hero.x] != '1'
				&& !ft_strchr(game->hero.moves_priority, 'd'))
				move = 'u';
		if (game->hero.moves_priority[count] == 'd')
			if (game->map.map[game->hero.y + 1][game->hero.x] != '1'
				&& !ft_strchr(game->hero.moves_priority, 'u'))
				move = 'd';
	}
	return (move);
}

static void	ft_set_priority(char *str, char move)
{
	int	count;

	if (!ft_strchr(str, move))
	{
		count = 3;
		while (--count > -1)
			str[count + 1] = str[count];
		str[0] = move;
	}
}

static void	ft_remove_priority(char *str, char move)
{
	int	count;

	count = -1;
	while (str[++count])
		if (str[count] == move)
			break ;
	while (count < 3)
	{
		str[count] = str[count + 1];
		count++;
	}
	str[3] = '0';
}

int	ft_input_press(int key, void *param)
{
	t_game	*game;

	game = (t_game *)param;
	if (key == 53)
		ft_close(game);
	if (key == 2 || key == 124)
		ft_set_priority(game->hero.moves_priority, 'r');
	if (key == 0 || key == 123)
		ft_set_priority(game->hero.moves_priority, 'l');
	if (key == 1 || key == 125)
		ft_set_priority(game->hero.moves_priority, 'd');
	if (key == 13 || key == 126)
		ft_set_priority(game->hero.moves_priority, 'u');
	if (key == 2 || key == 124 || key == 0 || key == 123
		|| key == 1 || key == 125 || key == 13 || key == 126)
		game->hero.next_move = ft_get_next_move(game);
	return (0);
}

int	ft_input_release(int key, void *param)
{
	t_game	*game;

	game = (t_game *)param;
	if (key == 2 || key == 124)
		ft_remove_priority(game->hero.moves_priority, 'r');
	if (key == 0 || key == 123)
		ft_remove_priority(game->hero.moves_priority, 'l');
	if (key == 1 || key == 125)
		ft_remove_priority(game->hero.moves_priority, 'd');
	if (key == 13 || key == 126)
		ft_remove_priority(game->hero.moves_priority, 'u');
	return (0);
}
