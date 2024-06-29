/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: musozer <musozer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 18:32:43 by musozer           #+#    #+#             */
/*   Updated: 2024/02/25 16:34:23 by musozer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_full_free(t_map *game)
{
	int	i;

	i = -1;
	while (++i < game->row)
		free(game->mapin[i]);
	free(game->mapin);
	i = -1;
	while (++i < game->row)
		free(game->cpymap[i]);
	free(game->cpymap);
	free(game->data);
	free(game);
	exit(1);
}

void	ft_error(char *error, t_map *game)
{
	write(2, error, ft_strlen(error));
	write(1, "\n", 1);
	free(game);
	exit(1);
}

void	ft_error_1(char *error, t_map *game)
{
	int	i;

	i = -1;
	while (++i < game->row)
		free(game->mapin[i]);
	free(game->mapin);
	i = -1;
	while (++i < game->row)
		free(game->cpymap[i]);
	free(game->cpymap);
	free(game);
	write(2, error, ft_strlen(error));
	write(1, "\n", 1);
	exit(1);
}

void	ft_error_2(char *error, t_map *game)
{
	int	i;

	i = -1;
	while (++i < game->row)
		free(game->mapin[i]);
	free(game->mapin);
	i = -1;
	while (++i < game->row)
		free(game->cpymap[i]);
	free(game->cpymap);
	free(game->data);
	free(game);
	write(2, error, ft_strlen(error));
	write(1, "\n", 1);
	exit(1);
}

void	ft_finish(t_map *game)
{
	write(1, "Congratulations you finished the game :)\n", 41);
	ft_full_free(game);
	ft_free_mlx(game);
	exit(1);
}
