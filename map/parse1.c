/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktombola <ktombola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 10:21:12 by ktombola          #+#    #+#             */
/*   Updated: 2025/06/30 16:44:52 by ktombola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	is_rectangular(t_game *game)
{
	int	expected_len;
	int	i;
	int	len;

	expected_len = ft_strlen(game->map[0]);
	if (game->map[0][expected_len - 1] == '\n')
		expected_len--;
	i = 1;
	while (i < game->height)
	{
		len = ft_strlen(game->map[i]);
		if (game->map[i][len - 1] == '\n')
			len--;
		if (len != expected_len)
			return (0);
		i++;
	}
	game->width = expected_len;
	if (game->width == game->height)
		return (0);
	return (1);
}

int	has_only_valid_chars(t_game *game)
{
	int		i;
	int		j;
	char	c;

	i = 0;
	while (i < game->height)
	{
		j = 0;
		while (game->map[i][j] && game->map[i][j] != '\n')
		{
			c = game->map[i][j];
			if (c != '0' && c != '1' && c != 'C' && c != 'E' && c != 'P')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

static void	process_map_line(t_game *game, char *line, int y)
{
	int	x;

	x = 0;
	while (line[x] && line[x] != '\n')
	{
		if (line[x] == 'P')
		{
			game->player_count++;
			game->player_x = x;
			game->player_y = y;
		}
		else if (line[x] == 'E')
			game->exit_count++;
		else if (line[x] == 'C')
			game->collectible_count++;
		x++;
	}
}

int	has_required_elements(t_game *game)
{
	int	y;

	y = 0;
	while (y < game->height)
	{
		process_map_line(game, game->map[y], y);
		y++;
	}
	if (game->player_count != 1
		|| game->exit_count != 1
		|| game->collectible_count < 1)
		return (0);
	return (1);
}

int	is_surrounded_by_walls(t_game *game)
{
	int	len;
	int	x;
	int	y;

	len = game->width;
	x = 0;
	y = 0;
	while (x < len)
	{
		if (game->map[0][x] != '1' || game->map[game->height - 1][x] != '1')
			return (0);
		x++;
	}
	while (y < game->height)
	{
		if (game->map[y][0] != '1' || game->map[y][len - 1] != '1')
			return (0);
		y++;
	}
	return (1);
}
