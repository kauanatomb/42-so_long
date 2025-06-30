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

static void	flood_fill(char **map, int x, int y)
{
	if (map[y][x] == '1' || map[y][x] == 'F')
		return ;
	map[y][x] = 'F';
	flood_fill(map, x + 1, y);
	flood_fill(map, x - 1, y);
	flood_fill(map, x, y + 1);
	flood_fill(map, x, y - 1);
}

static int	check_reachability(char **map)
{
	int	x;
    int y;
	int	found_exit;
    
    found_exit = 0;
    y = 0;
	while (map[y])
	{
        x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'C')
				return (0);
			if (map[y][x] == 'E')
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
	flood_fill(copy, game->player_x, game->player_y);
	result = check_reachability(copy);
    free_copy_map(copy, game->height);
	return (result);
}