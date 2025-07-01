/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktombola <ktombola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 10:21:12 by ktombola          #+#    #+#             */
/*   Updated: 2025/06/30 16:23:11 by ktombola         ###   ########.fr       */
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
