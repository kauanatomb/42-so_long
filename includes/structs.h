/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktombola <ktombola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 10:21:12 by ktombola          #+#    #+#             */
/*   Updated: 2025/07/02 18:08:27 by ktombola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

typedef struct s_img		t_img;
typedef struct s_graphics	t_graphics;
typedef struct s_game		t_game;
typedef struct s_enemy		t_enemy;

struct s_enemy {
	int	x;
	int	y;
};

struct s_img
{
	void	*ptr;
	int		width;
	int		height;
};

struct s_graphics
{
	void		*mlx;
	void		*win;
	t_img		img_wall;
	t_img		img_floor;
	t_img		img_player;
	t_img		img_exit;
	t_img		img_collectible;
	t_img		img_enemy;
};

struct s_game
{
	char		**map;
	int			width;
	int			height;
	int			player_count;
	int			exit_count;
	int			collectible_count;
	int			player_x;
	int			player_y;
	int			exit_x;
	int			exit_y;
	int			moves_count;
	t_enemy		*enemies;
	int			enemy_count;
	t_graphics	gfx;
};

#endif
