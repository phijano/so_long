/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libso_long.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phijano- <phijano-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 10:38:49 by phijano-          #+#    #+#             */
/*   Updated: 2022/08/23 13:49:33 by phijano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBSO_LONG_H
# define LIBSO_LONG_H

# include "minilibx_opengl_20191021/mlx.h"
# include "libft/libft.h"
# include <stdlib.h>
# include <fcntl.h>

# define SIZE 32

typedef struct s_size
{
	int	x;
	int	y;
}	t_size;

typedef struct s_sprite
{
	void	*img;
	int		x;
	int		y;
	t_size	size;
	char	*pixels;
	int		bits_per_pixel;
	int		line_size;
	int		endian;
}	t_sprite;

typedef struct s_font
{
	t_sprite	numb[10];
	t_sprite	m;
	t_sprite	o;
	t_sprite	v;
	t_sprite	e;
	t_sprite	s;
}	t_font;

typedef struct s_moves
{
	int				x;
	int				y;
	char			move;
	char			move_l;
	int				steps;
	int				change;
	int				change_c;
	struct s_moves	*next;
}	t_moves;

typedef struct s_enemy
{
	t_moves		*moves;
	t_sprite	d[3];
	t_sprite	u[3];
	t_sprite	l[3];
	t_sprite	r[3];
}	t_enemy;

typedef struct s_hero
{
	t_sprite	d[3];
	t_sprite	u[3];
	t_sprite	l[3];
	t_sprite	r[3];
	int			x;
	int			y;
	char		move;
	char		next_move;
	char		last_move;
	char		*moves_priority;
	int			steps;
}	t_hero;

typedef struct s_map
{
	char		**map;
	int			rows;
	int			cols;
	t_sprite	wall;
	t_sprite	road;
	t_sprite	exit_c;
	t_sprite	exit_o;
	t_sprite	coll[4];
	int			steps;
}	t_map;

typedef struct s_game
{
	void		*mlx;
	void		*window;
	t_map		map;
	t_hero		hero;
	t_enemy		enemy;
	t_font		font;
	int			exit;
	int			score;
}	t_game;

void		ft_check_arg(int argc, char **args, t_map *map);
void		ft_check_map(char *map_str, t_map *map);
void		ft_init_game(t_game *game);
t_sprite	ft_new_sprite(void *mlx, char *path);
void		ft_load_sprites(t_game *game);
void		ft_load_font(t_game *game);
int			ft_input_press(int key, void *param);
int			ft_input_release(int key, void *param);
char		ft_get_next_move(t_game *game);
int			ft_update(void *param);
void		ft_step_hero(t_game *game);
void		ft_move_hero(t_game *game);
void		ft_step_enemies(t_game *game);
void		ft_draw(t_game *game);
void		ft_draw_hero(t_game *game);
void		ft_draw_enemies(t_game *game);
void		ft_draw_score(t_game *game);
void		ft_error_exit(char *message);
void		ft_finish(char *message, t_game *game);
int			ft_close(t_game *game);
void		ft_free_split(char **split);
void		ft_free_enemies(t_moves *enemies);
void		ft_free_game(t_game *game);

#endif
