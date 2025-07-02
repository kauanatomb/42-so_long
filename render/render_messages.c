/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_messages.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktombola <ktombola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 10:21:12 by ktombola          #+#    #+#             */
/*   Updated: 2025/07/02 09:39:29 by ktombola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	render_info(t_game *game)
{
	char	*move_str;
	char	*msg;

	move_str = ft_itoa(game->moves_count);
	if (!move_str)
		return ;
	mlx_string_put(game->gfx.mlx, game->gfx.win, 20, 10, 0x0000FF, "Moves:");
	mlx_string_put(game->gfx.mlx, game->gfx.win, 60, 10, 0x0000FF, move_str);
	free(move_str);
	if (game->player_x == game->exit_x && game->player_y == game->exit_y
		&& game->collectible_count > 0)
	{
		msg = "Mission incomplete!";
		mlx_string_put(game->gfx.mlx, game->gfx.win, 10, 30, 0xFF0000, msg);
	}
}
