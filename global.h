/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   global.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdael-m <abdael-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 13:53:50 by abdael-m          #+#    #+#             */
/*   Updated: 2025/01/18 10:47:39 by abdael-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GLOBAL_H
# define GLOBAL_H

# include "./srcs/mlx/mlx.h"
# include <math.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

typedef struct s_vars
{
	int	x;
	int	y;
	int	z;
}	t_vars;

typedef struct s_map
{
	int				x;
	int				y;
	char			*type;
	struct s_map	*next;
}	t_map;

typedef struct s_game
{
	char	*pathfilename;
	void	*mlx;
	void	*window;
	void	*pgbg;
	void	*pgcoins[8];
	void	*pgfirstenemi[4];
	void	*pglastenemi[4];
	void	*pgexit[15];
	void	*pgwalls[2];
	void	*pgplayerl[4];
	void	*pgplayerr[4];
	void	*pgplayert[4];
	void	*pgplayerb[4];
	t_map	*map;
	int		playerx;
	int		playery;
	int		playerframe;
	int		playerscore;
	int		eatedcoins;
	int		totalcoins;
	int		enemiesframe;
	int		enemiesloop;
	int		exitx;
	int		exity;
	int		exitframe;
	int		exitloop;
	int		screenwidth;
	int		screenhight;
}	t_game;

char	*ft_strjoin(char const *s1, char const *s2);
char	*get_next_line_init(int fd);
char	*floodfill_init(t_game *game);
char	*map_init(t_game *game);
char	*game_init(t_game *game, char *pathfilename);
t_map	*ft_new_node(int x, int y, char *type);
t_map	*ft_last_node(t_map *header);
void	ft_printf(const char *str, ...);
void	ft_string_put(t_game *game);
void	map_generate(int *x, int *y, char buffer, t_game *game);
void	map_display(t_game *game);
int		ft_random(int nbr);
int		ft_strlen(const char *str);
int		loops_init(t_game *game);
int		control_init(int keycode, t_game *game);
int		finish_init(t_game *game);
int		map_includes(char *str);

#endif