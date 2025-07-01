/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktombola <ktombola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 10:21:12 by ktombola          #+#    #+#             */
/*   Updated: 2025/06/30 16:40:53 by ktombola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_map(t_game game)
{
	int	i;

	i = 0;
	while (i < game.height)
		ft_printf("%s", game.map[i++]);
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
		return (ft_putendl_fd("Usage: ./so_long map.ber", 2), 1);
	init_game(&game);
	if (!parse_map(argv[1], &game))
	{
		if (game.map)
			free_map(&game);
		return (1);
	}
	init_graphics(&game.gfx, game.width * TILE_SIZE, game.height * TILE_SIZE);
	print_map(game);
	free_map(&game);
	return (0);
}
