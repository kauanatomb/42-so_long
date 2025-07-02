/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktombola <ktombola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 10:21:12 by ktombola          #+#    #+#             */
/*   Updated: 2025/07/02 09:39:29 by ktombola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_graphics(t_graphics *gfx, int width, int height)
{
	gfx->mlx = mlx_init();
	if (!gfx->mlx)
		exit_with_error("MLX init failed");
	gfx->win = mlx_new_window(
			gfx->mlx,
			width,
			height,
			"So Long"
			);
	if (!gfx->win)
		exit_with_error("Window creation failed");
}

void	exit_with_error(char *message)
{
	ft_putendl_fd(message, 2);
	exit(EXIT_FAILURE);
}

void	render_tile(t_game *game, char tile, int x, int y)
{
	t_graphics	*gfx;

	gfx = &game->gfx;
	if (tile == '1')
		mlx_put_image_to_window(gfx->mlx, gfx->win, gfx->img_wall.ptr, x, y);
	else if (tile == '0')
		mlx_put_image_to_window(gfx->mlx, gfx->win, gfx->img_floor.ptr, x, y);
	else if (tile == 'P')
		mlx_put_image_to_window(gfx->mlx, gfx->win, gfx->img_player.ptr, x, y);
	else if (tile == 'E')
		mlx_put_image_to_window(gfx->mlx, gfx->win, gfx->img_exit.ptr, x, y);
	else if (tile == 'C')
		mlx_put_image_to_window(gfx->mlx, gfx->win,
			gfx->img_collectible.ptr, x, y);
}

void	render_map(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->height)
	{
		x = 0;
		while (x < game->width)
		{
			render_tile(game, game->map[y][x], x * TILE_SIZE, y * TILE_SIZE);
			x++;
		}
		y++;
	}
}

int exit_game(void *param)
{
    t_game *game;
	
	game = (t_game *)param;
    free_map(game);
    mlx_destroy_window(game->gfx.mlx, game->gfx.win);
    exit(0);
    return (0);
}
