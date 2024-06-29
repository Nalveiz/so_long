/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: musozer <musozer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 17:06:08 by musozer           #+#    #+#             */
/*   Updated: 2024/02/25 16:04:07 by musozer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include "gnl/get_next_line.h"
# include "mlx/mlx.h"

typedef struct s_mlx
{
	void	*mlx;
	void	*win;
	void	*block;
	void	*bg;
	void	*coin;
	void	*exit;
	void	*player;

}	t_mlx;

typedef struct s_map
{
	t_mlx	*data;
	char	**mapin;
	char	**cpymap;
	int		c;
	int		p;
	int		e;
	int		x;
	int		y;
	int		player[2];
	int		exit[2];
	int		movement;
	int		row;
	int		col;

}	t_map;

void	map(t_map *game, char *map);
void	maps_control(char *maps, t_map *game);
void	map_memory(t_map *game, char *map);
void	rectangle(t_map *game);
void	ft_error(char *error, t_map *game);
void	wall_control(t_map *game);
void	char_control(t_map *game);
void	char_count(t_map *game);
void	open_window(t_map *game);
void	put_image(t_map *game, int i, int j);
void	put_image_1(t_map *game);
void	data_memory(t_map *game);
void	player_and_exit_location(t_map *game);
void	ft_full_free(t_map *game);
void	ft_error_1(char *error, t_map *game);
void	ft_error_2(char *error, t_map *game);
void	ft_flood_fill(int x, int y, t_map *game);
void	ft_flood_fill_check(t_map *game);
void	ft_putnbr_fd(int n, int fd);
void	ft_putchar_fd(char c, int fd);
void	move_up(t_map *game);
void	ft_finish(t_map *game);
void	ft_free_mlx(t_map *game);
int		ft_close_window(t_map *game);
int		key_press(int key_code, t_map *game);

#endif
