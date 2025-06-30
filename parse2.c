/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktombola <ktombola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 10:21:12 by ktombola          #+#    #+#             */
/*   Updated: 2025/06/29 17:19:04 by ktombola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static char	**copy_map(t_game *game)
{
	char	**copy; 
	int		i;
    
    copy = malloc(sizeof(char *) * (game->height + 1));
	if (!copy)
		return (NULL);
    i = 0;
	while (i < game->height)
    {
		copy[i] = ft_strdup(game->map[i]);
        i++;
    }
	copy[i] = NULL;
	return (copy);
}

static void	flood_fill(char **map, int x, int y, int height, int width)
{
    if (x < 0 || y < 0 || y >= height || x >= width)
        return ;
	if (map[y][x] == '1' || map[y][x] == 'F' || map[y][x] == 'E')
		return ;
    map[y][x] = 'F';
	flood_fill(map, x + 1, y, height, width);
	flood_fill(map, x - 1, y, height, width);
	flood_fill(map, x, y + 1, height, width);
	flood_fill(map, x, y - 1, height, width);
}

static int  is_exit_reachable(char **map, int x, int y, int height, int width)
{
	if (map[y][x] != 'E')
		return (0);
	if (y > 0 && map[y - 1][x] == 'F') return (1);
	if (y < height - 1 && map[y + 1][x] == 'F') return (1);
	if (x > 0 && map[y][x - 1] == 'F') return (1);
	if (x < width - 1 && map[y][x + 1] == 'F') return (1);
	return (0);
}

static int	check_reachability(char **map, int height, int width)
{
	int	x;
	int y;
	int	found_exit = 0;

	y = 0;
	while (y < height)
	{
		x = 0;
		while (x < width)
		{
			if (map[y][x] == 'C')
				return (0);
			if (is_exit_reachable(map, x, y, height, width))
				found_exit = 1;
			x++;
		}
		y++;
	}
	return (found_exit);
}

static void	free_copy_map(char **map, int height)
{
    int i;

    i = 0;
	while (i < height)
		free(map[i++]);
	free(map);
}

int	is_solvable(t_game *game)
{
	char	**copy;
	int		result;
    
    copy = copy_map(game);
	if (!copy)
		return (0);
	flood_fill(copy, game->player_x, game->player_y, game->height,game->width);
	result = check_reachability(copy, game->height, game->width);
    for (int i = 0; i < game->height; i++)
	    ft_printf("%s", copy[i]);
    free_copy_map(copy, game->height);
	return (result);
}