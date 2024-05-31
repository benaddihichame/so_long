/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbenaddi <hbenaddi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 14:05:11 by maxborde          #+#    #+#             */
/*   Updated: 2024/05/31 20:54:38 by hbenaddi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "MLX42.h"
# include "libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>

# define PIXEL 32
# define TRUE 1
# define FALSE 0

typedef struct s_mlx_img
{
	mlx_image_t	*img;
	mlx_texture_t	*texture;
	mlx_image_t	*steps_count;
}	t_mlx_img;

typedef struct s_game
{
	mlx_t	*mlx;
	t_mlx_img	*tab_png;
	char	**map;
	char	**map2;
	int	fd;
	char	player;
	char	exit;
	char	collectible;
	int	vide;
	int	x;
	int	y;
	int	step;
	int	poke;
	int	moove_count;
	char	*filename;
}	t_game;

int	is_valid(char *str);
void	get_map(char *file_name, t_game *game);
int	count_line(char *file_name);
int	verif_element(t_game *game);
int	is_rectang(char **map);
int	is_wall(char **map);
void	loading_png(t_game *game);
void	display(t_game *game);
void	resize(t_game *game);
int	error_msg(t_game game, char **av);
void	add_data(t_game *game);
void	grab_pokeball(t_game *game, int y, int x);
void	display_background(t_game *game);
int	basic_err(int ac, char **av);
int	all_checks(t_game *game);
void	display_moove_count(t_game *game, int start);
void    back_tracking(t_game *game, int x, int y);
int back_tracking2(t_game *game);
void    copy_map(t_game *game);


#endif
