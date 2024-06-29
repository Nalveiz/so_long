/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_control.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: musozer <musozer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 16:12:13 by musozer           #+#    #+#             */
/*   Updated: 2024/02/25 16:32:53 by musozer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	maps_control(char *maps, t_map *game)
{
	int	fd;
	int	len ;

	fd = open(maps, O_RDWR);
	if (fd <= 0)
	{
		close(fd);
		ft_error("Error : ! Wrong file...", game);
	}
	close(fd);
	len = ft_strlen(maps);
	if (maps[len - 1] == 'r' && maps[len - 2] == 'e'
		&& maps[len - 3] == 'b' && maps[len - 4] == '.')
		return ;
	else
	{
		ft_error("Error : Maps should have the extension '.ber'...", game);
	}
}

void	map_memory(t_map *game, char *map)
{
	char	*line;
	int		fd;

	fd = open(map, O_RDONLY);
	game->row = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		game->row++;
		free(line);
	}
	close(fd);
	free(line);
	if (game->row == 0)
		ft_error("the map is empty", game);
	game->mapin = (char **)malloc(game->row * sizeof(char *));
	game->cpymap = (char **)malloc(game->row * sizeof(char *));
	if (game->mapin == NULL || game->mapin == NULL)
		ft_error_1("Error: Memory problem !", game);
}

void	map(t_map *game, char *map)
{
	int	i;
	int	fd;

	i = -1;
	fd = open(map, O_RDONLY);
	while (++i < game->row)
		game->mapin[i] = get_next_line(fd);
	game->col = ft_strlen(game->mapin[0]);
	close(fd);
	fd = open(map, O_RDONLY);
	i = -1;
	while (++i < game->row)
		game->cpymap[i] = get_next_line(fd);
	close(fd);
}

void	rectangle(t_map *game)
{
	int	i;

	i = 1;
	while (i < game->row)
	{
		if (game->col != ft_strlen(game->mapin[i]))
			ft_error_1("Error: Map isn't rectangular", game);
		i++;
	}
}

void	wall_control(t_map *game)
{
	int	i;

	i = -1;
	while (++i < (game->col - 1))
		if (game->mapin[0][i] != '1' || game->mapin[game->row - 1][i] != '1')
			ft_error_1("Error : The map must be enclosed...", game);
	i = 1;
	while (i < game->row - 1)
	{
		if (game->mapin[i][0] != '1' || game->mapin[i][game->col - 2] != '1')
			ft_error_1("Error : The map must be enclosed...", game);
		i++;
	}
	if (game->row >= 23 || game->col >= 42)
		ft_error_1("Error: Map is so long !", game);
}
