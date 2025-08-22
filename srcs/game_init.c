/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdael-m <abdael-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 13:51:07 by abdael-m          #+#    #+#             */
/*   Updated: 2025/01/16 15:28:26 by abdael-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../global.h"

static void	*d(void *mlx, char *str, int *x, int *y)
{
	return (mlx_xpm_file_to_image(mlx, str, x, y));
}

static	void	game_declates_next_next(t_game *game)
{
	int	z;

	game->pgcoins[0] = d(game->mlx, "public/coins/0.xpm", &z, &z);
	game->pgcoins[1] = d(game->mlx, "public/coins/1.xpm", &z, &z);
	game->pgcoins[2] = d(game->mlx, "public/coins/2.xpm", &z, &z);
	game->pgcoins[3] = d(game->mlx, "public/coins/3.xpm", &z, &z);
	game->pgcoins[4] = d(game->mlx, "public/coins/4.xpm", &z, &z);
	game->pgcoins[5] = d(game->mlx, "public/coins/5.xpm", &z, &z);
	game->pgcoins[6] = d(game->mlx, "public/coins/6.xpm", &z, &z);
	game->pgcoins[7] = d(game->mlx, "public/coins/7.xpm", &z, &z);
	game->pgfirstenemi[0] = d(game->mlx, "public/enemies/1/0.xpm", &z, &z);
	game->pgfirstenemi[1] = d(game->mlx, "public/enemies/1/1.xpm", &z, &z);
	game->pgfirstenemi[2] = d(game->mlx, "public/enemies/1/2.xpm", &z, &z);
	game->pgfirstenemi[3] = d(game->mlx, "public/enemies/1/3.xpm", &z, &z);
	game->pglastenemi[0] = d(game->mlx, "public/enemies/2/0.xpm", &z, &z);
	game->pglastenemi[1] = d(game->mlx, "public/enemies/2/1.xpm", &z, &z);
	game->pglastenemi[2] = d(game->mlx, "public/enemies/2/2.xpm", &z, &z);
	game->pglastenemi[3] = d(game->mlx, "public/enemies/2/3.xpm", &z, &z);
	game->pgexit[0] = d(game->mlx, "public/exit/0.xpm", &z, &z);
	game->pgexit[1] = d(game->mlx, "public/exit/1.xpm", &z, &z);
	game->pgexit[2] = d(game->mlx, "public/exit/2.xpm", &z, &z);
	game->pgexit[3] = d(game->mlx, "public/exit/3.xpm", &z, &z);
	game->pgexit[4] = d(game->mlx, "public/exit/4.xpm", &z, &z);
	game->pgexit[5] = d(game->mlx, "public/exit/5.xpm", &z, &z);
	game->pgexit[6] = d(game->mlx, "public/exit/6.xpm", &z, &z);
}

static	void	game_declates_next(t_game *game)
{
	int	z;

	game->pgexit[7] = d(game->mlx, "public/exit/7.xpm", &z, &z);
	game->pgexit[8] = d(game->mlx, "public/exit/8.xpm", &z, &z);
	game->pgexit[9] = d(game->mlx, "public/exit/9.xpm", &z, &z);
	game->pgexit[10] = d(game->mlx, "public/exit/10.xpm", &z, &z);
	game->pgexit[11] = d(game->mlx, "public/exit/11.xpm", &z, &z);
	game->pgexit[12] = d(game->mlx, "public/exit/12.xpm", &z, &z);
	game->pgexit[13] = d(game->mlx, "public/exit/13.xpm", &z, &z);
	game->pgexit[14] = d(game->mlx, "public/exit/14.xpm", &z, &z);
	game->pgwalls[0] = d(game->mlx, "public/walls/0.xpm", &z, &z);
	game->pgwalls[1] = d(game->mlx, "public/walls/1.xpm", &z, &z);
	game->pgbg = d(game->mlx, "public/0.xpm", &z, &z);
	game->pgplayerl[0] = d(game->mlx, "public/player/left/0.xpm", &z, &z);
	game->pgplayerl[1] = d(game->mlx, "public/player/left/1.xpm", &z, &z);
	game->pgplayerl[2] = d(game->mlx, "public/player/left/2.xpm", &z, &z);
	game->pgplayerl[3] = d(game->mlx, "public/player/left/3.xpm", &z, &z);
	game->pgplayerr[0] = d(game->mlx, "public/player/right/0.xpm", &z, &z);
	game->pgplayerr[1] = d(game->mlx, "public/player/right/1.xpm", &z, &z);
	game->pgplayerr[2] = d(game->mlx, "public/player/right/2.xpm", &z, &z);
	game->pgplayerr[3] = d(game->mlx, "public/player/right/3.xpm", &z, &z);
	game->pgplayert[0] = d(game->mlx, "public/player/top/0.xpm", &z, &z);
	game->pgplayert[1] = d(game->mlx, "public/player/top/1.xpm", &z, &z);
	game->pgplayert[2] = d(game->mlx, "public/player/top/2.xpm", &z, &z);
	game_declates_next_next(game);
}

static	void	game_declates(t_game *game)
{
	int	z;

	game->pgplayert[3] = d(game->mlx, "public/player/top/3.xpm", &z, &z);
	game->pgplayerb[0] = d(game->mlx, "public/player/bottom/0.xpm", &z, &z);
	game->pgplayerb[1] = d(game->mlx, "public/player/bottom/1.xpm", &z, &z);
	game->pgplayerb[2] = d(game->mlx, "public/player/bottom/2.xpm", &z, &z);
	game->pgplayerb[3] = d(game->mlx, "public/player/bottom/3.xpm", &z, &z);
	game->eatedcoins = 0;
	game->playerframe = 0;
	game->playerscore = 0;
	game->enemiesframe = 0;
	game->enemiesloop = 0;
	game->exitframe = 0;
	game->exitloop = 0;
	game_declates_next(game);
}

char	*game_init(t_game *game, char *pathfilename)
{
	char	*mapstatus;
	t_map	*node;

	game->pathfilename = pathfilename;
	mapstatus = map_init(game);
	if (mapstatus[0] != 'D')
		return (mapstatus);
	node = ft_last_node(game->map);
	game->mlx = mlx_init();
	game->window = mlx_new_window(game->mlx,
			(node->x) + 16, (node->y) + 32, "so_long - abdael-m");
	game->screenwidth = (node->x) + 16;
	game->screenhight = (node->y) + 16;
	game_declates(game);
	map_display(game);
	ft_string_put(game);
	return ("D");
}
