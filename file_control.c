/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_control.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: musozer <musozer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 03:59:46 by musozer           #+#    #+#             */
/*   Updated: 2024/02/24 17:21:53 by musozer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	data_memory(t_map *game)
{
	game->data = malloc(sizeof(t_mlx));
	if (!game->data)
	{
		free(game->data);
		ft_error_2("Memory allocation failed", game);
	}
}

void	ft_flood_fill(int x, int y, t_map *game)
{
	if (game->cpymap[x][y] == '1')
		return ;
	game->cpymap[x][y] = '1';
	ft_flood_fill(x + 1, y, game);
	ft_flood_fill(x - 1, y, game);
	ft_flood_fill(x, y + 1, game);
	ft_flood_fill(x, y - 1, game);
}

void	open_window(t_map *game)
{
	int	h;
	int	w;

	game->data->mlx = mlx_init();
	game->data->win = mlx_new_window(game->data->mlx,
			(game->col - 1) * 64, (game->row) * 64, "so_long");
	game->data->bg = mlx_xpm_file_to_image(game->data->mlx,
			"./textures/bg.xpm", &h, &w);
	game->data->block = mlx_xpm_file_to_image(game->data->mlx,
			"./textures/block.xpm", &h, &w);
	game->data->coin = mlx_xpm_file_to_image(game->data->mlx,
			"./textures/coin.xpm", &h, &w);
	game->data->exit = mlx_xpm_file_to_image(game->data->mlx,
			"./textures/endgate.xpm", &h, &w);
	game->data->player = mlx_xpm_file_to_image(game->data->mlx,
			"./textures/player.xpm", &h, &w);
	put_image_1(game);
}

void	put_image_1(t_map *game)
{
	int	i;
	int	j;

	i = -1;
	while (++i < game->row)
	{
		j = -1;
		while (++j < game->col)
		{
			put_image(game, i, j);
		}
	}
}

void	put_image(t_map *game, int i, int j)
{
	if (game->mapin[i][j] == '0')
		mlx_put_image_to_window(game->data->mlx, game->data->win,
			game->data->bg, j * 64, i * 64);
	if (game->mapin[i][j] == 'P')
		mlx_put_image_to_window(game->data->mlx, game->data->win,
			game->data->player, j * 64, i * 64);
	if (game->mapin[i][j] == '1')
		mlx_put_image_to_window(game->data->mlx, game->data->win,
			game->data->block, j * 64, i * 64);
	if (game->mapin[i][j] == 'E')
		mlx_put_image_to_window(game->data->mlx, game->data->win,
			game->data->exit, j * 64, i * 64);
	if (game->mapin[i][j] == 'C')
		mlx_put_image_to_window(game->data->mlx, game->data->win,
			game->data->coin, j * 64, i * 64);
	return ;
}
