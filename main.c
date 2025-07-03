/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktombola <ktombola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 10:21:12 by ktombola          #+#    #+#             */
/*   Updated: 2025/07/02 12:54:33 by ktombola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
		return (ft_putendl_fd("Usage: ./so_long map.ber", 2), 1);
	init_game(&game);
	if (!parse_map(argv[1], &game))
	{
		if (game.map)
			free_game(&game);
		return (1);
	}
	init_exit_position(&game);
	init_graphics(&game.gfx, game.width * TILE_SIZE, game.height * TILE_SIZE);
	load_images(&game);
	render_map(&game);
	mlx_hook(game.gfx.win, 2, 1L << 0, handle_keypress, &game);
	mlx_hook(game.gfx.win, 17, 0, exit_game, &game);
	mlx_loop(game.gfx.mlx);
	return (0);
}
