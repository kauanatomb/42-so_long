/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktombola <ktombola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 10:21:12 by ktombola          #+#    #+#             */
/*   Updated: 2025/06/30 16:23:11 by ktombola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	is_valid_extension(const char *filename)
{
	int	len;

	len = ft_strlen(filename);
	if (len < 5)
		return (0);
	return (ft_strncmp(filename + len - 4, ".ber", 4) == 0);
}

static int	count_lines(const char *filename)
{
	int		fd;
	int		count;
	char	*line;

	count = 0;
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (-1);
	line = get_next_line(fd);
	while (line)
	{
		count++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (count);
}

static int	read_lines_into_map(int fd, t_game *game)
{
	char	*line;
	int		i;

	i = 0;
	line = get_next_line(fd);
	while (line)
	{
		game->map[i] = line;
		if (i == 0)
			game->width = ft_strlen(line) - (line[ft_strlen(line) - 1] == '\n');
		line = get_next_line(fd);
		i++;
	}
	game->map[i] = NULL;
	return (1);
}

static int	read_map_file(const char *filename, t_game *game)
{
	int	fd;

	game->height = count_lines(filename);
	if (game->height <= 0)
		return (0);
	game->map = malloc(sizeof(char *) * (game->height + 1));
	if (!game->map)
		return (0);
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (free(game->map), 0);
	if (!read_lines_into_map(fd, game))
		return (close(fd), 0);
	close(fd);
	return (1);
}

int	parse_map(const char *filename, t_game *game)
{
	if (!is_valid_extension(filename))
		return (ft_putendl_fd("Invalid file extension", 2), 0);
	if (!read_map_file(filename, game))
		return (ft_putendl_fd("Failed to read map", 2), 0);
	if (!is_rectangular(game))
		return (ft_putendl_fd("Map is not rectangular", 2), 0);
	if (!has_only_valid_chars(game))
		return (ft_putendl_fd("Map contains invalid characters", 2), 0);
	if (!has_required_elements(game))
		return (ft_putendl_fd("Map must have 1P, ≥1E and ≥1C", 2), 0);
	if (!is_surrounded_by_walls(game))
		return (ft_putendl_fd("Map is not closed by walls", 2), 0);
	if (!is_solvable(game))
		return (ft_putendl_fd("Map is not solvable", 2), 0);
	return (1);
}
