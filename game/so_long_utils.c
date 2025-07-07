/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktombola <ktombola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 10:21:12 by ktombola          #+#    #+#             */
/*   Updated: 2025/07/02 18:07:46 by ktombola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_game(t_game *game)
{
	game->map = NULL;
	game->width = 0;
	game->height = 0;
	game->player_x = 0;
	game->player_y = 0;
	game->player_count = 0;
	game->exit_count = 0;
	game->enemy_count = 0;
	game->collectible_count = 0;
	game->moves_count = 0;
	game->exit_x = 0;
	game->exit_y = 0;
	game->enemies = NULL;
	game->gfx.mlx = NULL;
	game->gfx.win = NULL;
	game->gfx.img_wall.ptr = NULL;
	game->gfx.img_floor.ptr = NULL;
	game->gfx.img_player.ptr = NULL;
	game->gfx.img_exit.ptr = NULL;
	game->gfx.img_collectible.ptr = NULL;
	game->gfx.img_enemy.ptr = NULL;
}

void	free_copy_map(char **map, int height)
{
	int	i;

	i = 0;
	while (i < height)
		free(map[i++]);
	free(map);
}

void	free_game(t_game *game)
{
	int	i;

	if (!game)
		return ;
	i = 0;
	if (game->map)
	{
		while (i < game->height)
		{
			if (game->map[i])
				free(game->map[i]);
			i++;
		}
		free(game->map);
		game->map = NULL;
	}
	if (game->enemies)
	{
		free(game->enemies);
		game->enemies = NULL;
	}
}

void	init_exit_position(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	while (y < game->height)
	{
		x = 0;
		while (game->map[y][x])
		{
			if (game->map[y][x] == 'E')
			{
				game->exit_x = x;
				game->exit_y = y;
				return ;
			}
			x++;
		}
		y++;
	}
}

void	init_enemies(t_game *game)
{
	int	y;
	int	x;
	int	i;

	game->enemies = malloc(sizeof(t_enemy) * game->enemy_count);
	if (!game->enemies)
		exit_error("Memory allocation failed for enemies", game);
	i = 0;
	y = 0;
	while (y < game->height)
	{
		x = 0;
		while (x < game->width)
		{
			if (game->map[y][x] == 'M')
			{
				game->enemies[i].x = x;
				game->enemies[i].y = y;
				i++;
			}
			x++;
		}
		y++;
	}
}
