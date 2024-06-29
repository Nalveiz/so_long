/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps_control_1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: musozer <musozer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 00:36:31 by musozer           #+#    #+#             */
/*   Updated: 2024/02/24 16:49:58 by musozer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	char_control(t_map *game)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (i < game->row)
	{
		while (j < (game->col - 1))
		{
			if (game->mapin[i][j] != '1' && game->mapin[i][j] != '0'
			&& game->mapin[i][j] != 'P' && game->mapin[i][j] != 'E'
			&& game->mapin[i][j] != 'C')
			{
				ft_error_1("There are wrong Characters on the map", game);
			}
			j++;
		}
		j = 0;
		i++;
	}
}

void	char_count(t_map *game)
{
	int	i;
	int	j;

	i = -1;
	game->e = 0;
	game->p = 0;
	game->c = 0;
	while (++i < game->row)
	{
		j = -1;
		while (++j < (game->col - 1))
		{
			if (game->mapin[i][j] == 'P')
				game->p++;
			else if (game->mapin[i][j] == 'E')
				game->e++;
			else if (game->mapin[i][j] == 'C')
				game->c++;
		}
	}
	if (game->p != 1 || game->e != 1)
		ft_error_1("Exit or player is not the only one", game);
	else if (game->c < 1)
		ft_error_1("Must have at least 1 collection item", game);
}

void	player_and_exit_location(t_map *game)
{
	int	i;
	int	j;

	i = -1;
	while (++i < game->row)
	{
		j = -1;
		while (++j < (game->col - 1))
		{
			if (game->mapin[i][j] == 'P')
			{
				game->player[0] = i;
				game->player[1] = j;
			}
			if (game->mapin[i][j] == 'E')
			{
				game->exit[0] = i;
				game->exit[1] = j;
			}
		}
	}
}

void	ft_flood_fill_check(t_map *game)
{
	int	i;
	int	j;

	i = -1;
	while (++i < game->row)
	{
		j = -1;
		while (++j < game->col - 1)
		{
			if (game->cpymap[i][j] == 'E' || game->cpymap[i][j] == 'C')
				ft_error_2("Error : There are unreachable Items on the map...",
					game);
		}
	}
}
