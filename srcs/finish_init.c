/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finish_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdael-m <abdael-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 09:44:09 by abdael-m          #+#    #+#             */
/*   Updated: 2025/01/16 08:19:07 by abdael-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../global.h"

static void	finish_map(t_map *map)
{
	t_map	*temp;

	while (map)
	{
		temp = map;
		map = map->next;
		free(temp);
	}
	map = NULL;
}

static void	finish_declares_next(t_game *game)
{
	mlx_destroy_image(game->mlx, game->pgplayerb[0]);
	mlx_destroy_image(game->mlx, game->pgplayerb[1]);
	mlx_destroy_image(game->mlx, game->pgplayerb[2]);
	mlx_destroy_image(game->mlx, game->pgplayerb[3]);
	mlx_destroy_image(game->mlx, game->pgexit[7]);
	mlx_destroy_image(game->mlx, game->pgexit[8]);
	mlx_destroy_image(game->mlx, game->pgexit[9]);
	mlx_destroy_image(game->mlx, game->pgexit[10]);
	mlx_destroy_image(game->mlx, game->pgexit[11]);
	mlx_destroy_image(game->mlx, game->pgexit[12]);
	mlx_destroy_image(game->mlx, game->pgexit[13]);
	mlx_destroy_image(game->mlx, game->pgexit[14]);
	mlx_destroy_image(game->mlx, game->pgwalls[0]);
	mlx_destroy_image(game->mlx, game->pgwalls[1]);
	mlx_destroy_image(game->mlx, game->pgbg);
	mlx_destroy_image(game->mlx, game->pgplayerl[0]);
	mlx_destroy_image(game->mlx, game->pgplayerl[1]);
	mlx_destroy_image(game->mlx, game->pgplayerl[2]);
	mlx_destroy_image(game->mlx, game->pgplayerl[3]);
	mlx_destroy_image(game->mlx, game->pgplayerr[0]);
	mlx_destroy_image(game->mlx, game->pgplayerr[1]);
	mlx_destroy_image(game->mlx, game->pgplayerr[2]);
	mlx_destroy_image(game->mlx, game->pgplayerr[3]);
	mlx_destroy_image(game->mlx, game->pgplayert[0]);
	mlx_destroy_image(game->mlx, game->pgplayert[1]);
}

static void	finish_declares(t_game *game)
{
	mlx_destroy_image(game->mlx, game->pgcoins[3]);
	mlx_destroy_image(game->mlx, game->pgcoins[4]);
	mlx_destroy_image(game->mlx, game->pgcoins[5]);
	mlx_destroy_image(game->mlx, game->pgcoins[6]);
	mlx_destroy_image(game->mlx, game->pgcoins[7]);
	mlx_destroy_image(game->mlx, game->pgfirstenemi[0]);
	mlx_destroy_image(game->mlx, game->pgfirstenemi[1]);
	mlx_destroy_image(game->mlx, game->pgfirstenemi[2]);
	mlx_destroy_image(game->mlx, game->pgfirstenemi[3]);
	mlx_destroy_image(game->mlx, game->pglastenemi[0]);
	mlx_destroy_image(game->mlx, game->pglastenemi[1]);
	mlx_destroy_image(game->mlx, game->pglastenemi[2]);
	mlx_destroy_image(game->mlx, game->pglastenemi[3]);
	mlx_destroy_image(game->mlx, game->pgexit[0]);
	mlx_destroy_image(game->mlx, game->pgexit[1]);
	mlx_destroy_image(game->mlx, game->pgexit[2]);
	mlx_destroy_image(game->mlx, game->pgexit[3]);
	mlx_destroy_image(game->mlx, game->pgexit[4]);
	mlx_destroy_image(game->mlx, game->pgexit[5]);
	mlx_destroy_image(game->mlx, game->pgexit[6]);
	mlx_destroy_image(game->mlx, game->pgplayert[3]);
	mlx_destroy_image(game->mlx, game->pgplayert[2]);
	mlx_destroy_image(game->mlx, game->pgcoins[0]);
	mlx_destroy_image(game->mlx, game->pgcoins[1]);
	mlx_destroy_image(game->mlx, game->pgcoins[2]);
}

int	finish_init(t_game *game)
{
	if (game)
	{
		if (game->pgbg)
		{
			finish_declares(game);
			finish_declares_next(game);
		}
		if (game->mlx)
		{
			if (game->window)
				mlx_destroy_window(game->mlx, game->window);
			mlx_destroy_display(game->mlx);
			free(game->mlx);
		}
		if (game->map)
			finish_map(game->map);
		free(game);
		game = NULL;
	}
	exit(0);
}
