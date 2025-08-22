/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loops_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdael-m <abdael-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 12:42:03 by abdael-m          #+#    #+#             */
/*   Updated: 2025/02/25 10:28:37 by abdael-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../global.h"

static void	door(t_game *game)
{
	mlx_put_image_to_window(game->mlx, game->window,
		game->pgexit[game->exitframe], game->exitx, game->exity);
}

static void	enemies(t_game *game)
{
	t_map	*temp;

	temp = game->map;
	while (temp)
	{
		if (temp->type[0] == 'x' && temp->type[1] == '0')
			mlx_put_image_to_window(game->mlx, game->window,
				game->pgfirstenemi[game->enemiesframe], temp->x, temp->y);
		else if (temp->type[0] == 'x' && temp->type[1] == '1')
			mlx_put_image_to_window(game->mlx, game->window,
				game->pglastenemi[game->enemiesframe], temp->x, temp->y);
		temp = temp->next;
	}
}

int	loops_init(t_game *game)
{
	game->exitloop += 1;
	if (game->exitloop >= 17500)
	{
		game->exitframe += 1;
		if (game->exitframe == 15)
			game->exitframe = 0;
		game->exitloop = 0;
		if (game->eatedcoins == game->totalcoins)
			door(game);
	}
	game->enemiesloop += 1;
	if (game->enemiesloop >= 20500)
	{
		game->enemiesframe += 1;
		if (game->enemiesframe == 4)
			game->enemiesframe = 0;
		game->enemiesloop = 0;
		enemies(game);
	}
	return (0);
}
