/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_img.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktombola <ktombola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 10:21:12 by ktombola          #+#    #+#             */
/*   Updated: 2025/07/02 12:50:45 by ktombola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	load_image(void *mlx, t_img *img, char *path)
{
	img->ptr = mlx_xpm_file_to_image(mlx, path, &img->width, &img->height);
	if (!img->ptr)
	{
		ft_putstr_fd("Error: failed to load image: ", 2);
		ft_putendl_fd(path, 2);
		exit(1);
	}
}

void	load_images(t_game *game)
{
	load_image(game->gfx.mlx, &game->gfx.img_wall, "assets/64x64-wall.xpm");
	load_image(game->gfx.mlx, &game->gfx.img_floor, "assets/64x64-floor.xpm");
	load_image(game->gfx.mlx, &game->gfx.img_player, "assets/64x64-player.xpm");
	load_image(game->gfx.mlx, &game->gfx.img_exit, "assets/64x64-exit.xpm");
	load_image(game->gfx.mlx, &game->gfx.img_collectible,
		"assets/64x64-coin.xpm");
	load_image(game->gfx.mlx, &game->gfx.img_enemy, "assets/64x64-fire(2).xpm");
}

static void	process_movement(t_game *game, int new_x, int new_y)
{
	if (game->map[new_y][new_x] == '1')
		return ;
	if (game->map[new_y][new_x] == 'C')
		game->collectible_count--;
	if (game->map[new_y][new_x] == 'E' && game->collectible_count == 0)
	{
		game->moves_count++;
		ft_printf("You won in %d moves!\n", game->moves_count);
		exit_game(game);
	}
	if (game->map[new_y][new_x] == 'M')
	{
		ft_putendl_fd("Game Over: You touched an enemy!", 1);
		exit_game(game);
	}
	if (game->player_x == game->exit_x && game->player_y == game->exit_y)
		game->map[game->player_y][game->player_x] = 'E';
	else
		game->map[game->player_y][game->player_x] = '0';
	game->player_x = new_x;
	game->player_y = new_y;
	game->map[new_y][new_x] = 'P';
	game->moves_count++;
	ft_printf("Moves: %d\n", game->moves_count);
	render_map(game);
}

int	handle_keypress(int keycode, t_game *game)
{
	int	new_x;
	int	new_y;

	new_y = game->player_y;
	new_x = game->player_x;
	if (keycode == KEY_UP)
		new_y--;
	else if (keycode == KEY_DOWN)
		new_y++;
	else if (keycode == KEY_LEFT)
		new_x--;
	else if (keycode == KEY_RIGHT)
		new_x++;
	else if (keycode == KEY_ESC)
		exit_game(game);
	process_movement(game, new_x, new_y);
	return (0);
}
