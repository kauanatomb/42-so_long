/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktombola <ktombola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 10:21:12 by ktombola          #+#    #+#             */
/*   Updated: 2025/06/29 17:19:04 by ktombola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	is_valid_extension(char *filename)
{
	int	len = ft_strlen(filename);
	if (len < 5)
		return (0);
	return (ft_strncmp(filename + len - 4, ".ber", 4) == 0);
}

static int	count_lines(const char *filename)
{
	int		fd;
	int		count = 0;
	char	*line;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (-1);
	while ((line = get_next_line(fd)))
	{
		count++;
		free(line);
	}
	close(fd);
	return (count);
}

int	parse_map(const char *filename, t_game *game)
{
	int		fd;
	int		i = 0;
	char	*line;

	game->height = count_lines(filename);
	if (game->height <= 0)
		return (0);
	game->map = malloc(sizeof(char *) * (game->height + 1));
	if (!game->map)
		return (0);
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (free(game->map), 0);
	while ((line = get_next_line(fd)))
	{
		game->map[i] = line;
		if (i == 0)
			game->width = ft_strlen(line) - (line[ft_strlen(line)-1] == '\n');
		i++;
	}
	game->map[i] = NULL;
	close(fd);
	return (1);
}

int main(int argc, char **argv)
{
    t_game game;

    if (argc != 2)
        return (ft_printf("Usage: ./so_long map.ber\n"), 1);
    if (!is_valid_extension(argv[1]))
	return (ft_printf("Error: map must have .ber extension\n"), 1);
    if (!parse_map(argv[1], &game))
        return (ft_printf("Invalid map\n"), 1);

    // Debug
    for (int i = 0; i < game.height; i++)
        ft_printf("%s", game.map[i]);
}
