/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktombola <ktombola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 10:21:12 by ktombola          #+#    #+#             */
/*   Updated: 2025/06/30 16:37:38 by ktombola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# define TILE_SIZE 64
# define KEY_UP     65362
# define KEY_DOWN   65364
# define KEY_LEFT   65361
# define KEY_RIGHT  65363
# define KEY_ESC    65307

# include "libft.h"
# include <fcntl.h>   // open
# include <stdlib.h>  // malloc, free
# include <unistd.h>  // close
# include <stdio.h>   // perror
# include <mlx.h>
# include "structs.h"

int		parse_map(const char *filename, t_game *game);
int		is_rectangular(t_game *game);
int		has_only_valid_chars(t_game *game);
int		has_required_elements(t_game *game);
int		is_surrounded_by_walls(t_game *game);
int		is_solvable(t_game *game);
void	free_map(t_game *game);
void	free_copy_map(char **map, int height);
void	init_game(t_game *game);
void	init_exit_position(t_game *game);
void	init_graphics(t_graphics *gfx, int width, int height);
void	exit_with_error(char *message);
void	load_images(t_game *game);
void	render_map(t_game *game);
int		handle_keypress(int keycode, t_game *game);
int		exit_game(void *param);
void	render_info(t_game *game);
void	init_enemies(t_game *game);

#endif
