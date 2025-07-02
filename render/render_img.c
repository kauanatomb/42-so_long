/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_img.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktombola <ktombola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 10:21:12 by ktombola          #+#    #+#             */
/*   Updated: 2025/07/02 09:42:28 by ktombola         ###   ########.fr       */
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
		"assets/64x64-collectible.xpm");
}

int	handle_keypress(int keycode, t_game *game)
{
	int new_x;
	int new_y;

    new_x = game->player_x;
    new_y = game->player_y;
	if (keycode == KEY_W)
		new_y--;
	else if (keycode == KEY_S)
		new_y++;
	else if (keycode == KEY_A)
		new_x--;
	else if (keycode == KEY_D)
		new_x++;
	if (game->map[new_y][new_x] != '1')
	{
		game->map[game->player_y][game->player_x] = '0';
		game->player_x = new_x;
		game->player_y = new_y;
		game->map[new_y][new_x] = 'P';
		render_map(game);
	}
	if (keycode == KEY_ESC)
		exit_game(game);
	return (0);
}
