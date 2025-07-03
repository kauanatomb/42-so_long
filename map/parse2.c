/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktombola <ktombola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 10:21:12 by ktombola          #+#    #+#             */
/*   Updated: 2025/06/30 16:50:28 by ktombola         ###   ########.fr       */
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
		if (!copy[i])
		{
			while (i--)
				free(copy[i]);
			free(copy);
			return (NULL);
		}
		i++;
	}
	copy[i] = NULL;
	return (copy);
}

static void	flood_fill(char **map, int x, int y, t_game *game)
{
	if (x < 0 || y < 0 || y >= game->height || x >= game->width)
		return ;
	if (map[y][x] == '1' || map[y][x] == 'F' || map[y][x] == 'E'
		|| map[y][x] == 'M')
		return ;
	map[y][x] = 'F';
	flood_fill(map, x + 1, y, game);
	flood_fill(map, x - 1, y, game);
	flood_fill(map, x, y + 1, game);
	flood_fill(map, x, y - 1, game);
}

static int	is_exit_reachable(char **map, int x, int y, t_game *game)
{
	if (map[y][x] != 'E')
		return (0);
	if (y > 0 && map[y - 1][x] == 'F')
		return (1);
	if (y < game->height - 1 && map[y + 1][x] == 'F')
		return (1);
	if (x > 0 && map[y][x - 1] == 'F')
		return (1);
	if (x < game->width - 1 && map[y][x + 1] == 'F')
		return (1);
	return (0);
}

static int	check_reachability(char **map, t_game *game)
{
	int	x;
	int	y;
	int	found_exit;

	found_exit = 0;
	y = 0;
	while (y < game->height)
	{
		x = 0;
		while (x < game->width)
		{
			if (map[y][x] == 'C')
				return (0);
			if (is_exit_reachable(map, x, y, game))
				found_exit = 1;
			x++;
		}
		y++;
	}
	return (found_exit);
}

int	is_solvable(t_game *game)
{
	char	**copy;
	int		result;
	int		i;

	i = 0;
	copy = copy_map(game);
	if (!copy)
		return (0);
	flood_fill(copy, game->player_x, game->player_y, game);
	result = check_reachability(copy, game);
	free_copy_map(copy, game->height);
	return (result);
}
