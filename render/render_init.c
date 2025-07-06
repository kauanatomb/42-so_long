/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktombola <ktombola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 10:21:12 by ktombola          #+#    #+#             */
/*   Updated: 2025/07/02 18:09:10 by ktombola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_graphics(t_game *game, int width, int height)
{
	int	screen_width;
	int	screen_height;

	game->gfx.mlx = mlx_init();
	if (!game->gfx.mlx)
		exit_error("MLX init failed", game);
	mlx_get_screen_size(game->gfx.mlx, &screen_width, &screen_height);
	if (width > screen_width || height > screen_height)
		exit_error("Map too big for screen", game);
	game->gfx.win = mlx_new_window(game->gfx.mlx, width, height, "So Long");
	if (!game->gfx.win)
		exit_error("Window creation failed", game);
}

void	exit_error(char *msg, t_game *game)
{
	if (msg)
	{
		ft_putstr_fd("Error\n", 2);
		ft_putendl_fd(msg, 2);
	}
	if (game)
		exit_game(game);
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
	else if (tile == 'M')
		mlx_put_image_to_window(gfx->mlx, gfx->win, gfx->img_enemy.ptr, x, y);
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
	render_info(game);
}

int	exit_game(void *param)
{
	t_game	*game;

	game = (t_game *)param;
	free_game(game);
	if (game->gfx.img_wall.ptr)
		mlx_destroy_image(game->gfx.mlx, game->gfx.img_wall.ptr);
	if (game->gfx.img_floor.ptr)
		mlx_destroy_image(game->gfx.mlx, game->gfx.img_floor.ptr);
	if (game->gfx.img_player.ptr)
		mlx_destroy_image(game->gfx.mlx, game->gfx.img_player.ptr);
	if (game->gfx.img_exit.ptr)
		mlx_destroy_image(game->gfx.mlx, game->gfx.img_exit.ptr);
	if (game->gfx.img_collectible.ptr)
		mlx_destroy_image(game->gfx.mlx, game->gfx.img_collectible.ptr);
	if (game->gfx.win)
		mlx_destroy_window(game->gfx.mlx, game->gfx.win);
	if (game->gfx.img_enemy.ptr)
		mlx_destroy_image(game->gfx.mlx, game->gfx.img_enemy.ptr);
	if (game->gfx.mlx)
		mlx_destroy_display(game->gfx.mlx);
	free(game->gfx.mlx);
	exit(0);
	return (0);
}
