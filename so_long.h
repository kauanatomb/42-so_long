/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktombola <ktombola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 10:21:12 by ktombola          #+#    #+#             */
/*   Updated: 2025/06/21 17:19:04 by ktombola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft.h"
# include <fcntl.h>   // open
# include <stdlib.h>  // malloc, free
# include <unistd.h>  // close
# include <stdio.h>   // perror

typedef struct s_game {
    char    **map;
    int     width;
    int     height;
    int     player_count;
    int     exit_count;
    int     collectible_count;
    int     player_x;
    int     player_y;
} t_game;

void	init_game(t_game *game);
int	parse_map(const char *filename, t_game *game);
int	is_solvable(t_game *game);
void	free_map(t_game *game);

#endif