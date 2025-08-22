/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_generate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdael-m <abdael-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 06:32:26 by abdael-m          #+#    #+#             */
/*   Updated: 2025/01/14 16:26:49 by abdael-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../global.h"

static	void	map_generate_next(int *x, int *y, char buffer, t_game *game)
{
	if (buffer == 'E')
	{
		ft_last_node(game->map)->next = ft_new_node(*x, *y, "e");
		game->exitx = *x;
		game->exity = *y;
	}
	else if (buffer == 'X')
	{
		if (ft_random(1) == 0)
			ft_last_node(game->map)->next = ft_new_node(*x, *y,
				"x0");
		else
			ft_last_node(game->map)->next = ft_new_node(*x, *y,
				"x1");
	}
	*x += 16;
}

void	map_generate(int *x, int *y, char buffer, t_game *game)
{
	if (buffer == '\n')
	{
		*y += 16;
		*x = -16;
	}
	else if (buffer == '1')
		ft_last_node(game->map)->next = ft_new_node(*x, *y, "w");
	else if (buffer == '0')
		ft_last_node(game->map)->next = ft_new_node(*x, *y, "f");
	else if (buffer == 'C')
		ft_last_node(game->map)->next = ft_new_node(*x, *y, "c");
	else if (buffer == 'P')
	{
		ft_last_node(game->map)->next = ft_new_node(*x, *y, "p");
		game->playerx = *x;
		game->playery = *y;
	}
	map_generate_next(x, y, buffer, game);
}
