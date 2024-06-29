/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: musozer <musozer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 19:12:52 by musozer           #+#    #+#             */
/*   Updated: 2024/02/25 16:12:09 by musozer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_close_window(t_map *game)
{
	ft_full_free(game);
	ft_free_mlx(game);
	write(1, "You closed the window :(", 24);
	exit(0);
}

void	ft_free_mlx(t_map *game)
{
	mlx_destroy_image(game->data->mlx, game->data->bg);
	mlx_destroy_image(game->data->mlx, game->data->block);
	mlx_destroy_image(game->data->mlx, game->data->player);
	mlx_destroy_image(game->data->mlx, game->data->exit);
	mlx_destroy_image(game->data->mlx, game->data->coin);
	mlx_destroy_window(game->data->mlx, game->data->win);
	free(game->data->mlx);
	ft_full_free(game);
}

int	main(int ac, char **av)
{
	t_map	*game;

	game = (t_map *)malloc(sizeof(t_map));
	if (game == NULL)
		ft_error("Memory allocation failed.", game);
	if (ac != 2)
		ft_error("Error : PLEASE! Enter two arguments", game);
	game->movement = 0;
	maps_control(av[1], game);
	map_memory(game, av[1]);
	map(game, av[1]);
	rectangle(game);
	wall_control(game);
	char_control(game);
	char_count(game);
	data_memory(game);
	player_and_exit_location(game);
	ft_flood_fill(game->player[0], game->player[1], game);
	ft_flood_fill_check(game);
	open_window(game);
	mlx_hook(game->data->win, 2, (1L << 0), key_press, game);
	mlx_hook(game->data->win, 17, 0L, ft_close_window, game);
	mlx_loop(game->data->mlx);
	ft_full_free(game);
	return (0);
}
