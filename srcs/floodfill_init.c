/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floodfill_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdael-m <abdael-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 10:37:59 by abdael-m          #+#    #+#             */
/*   Updated: 2025/01/19 13:16:42 by abdael-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "global.h"

static void	flood_fill_next_next(t_map *curr, int *coins_found,
	int *exit_found, int *res)
{
	if (curr->type[0] == 'c')
		*coins_found += 1;
	if (curr->type[0] == 'e')
		*exit_found += 1;
	curr->type = "Q";
	*res += 1;
}

static int	flood_fill_next(t_map *position, t_map *curr,
	int *coins_found, int *exit_found)
{
	int	res;

	res = 0;
	if (position->x + 16 == curr->x && position->y == curr->y
		&& (curr->type[0] == 'f' || curr->type[0] == 'c'
			|| curr->type[0] == 'e'))
		flood_fill_next_next(curr, coins_found, exit_found, &res);
	if (position->x - 16 == curr->x && position->y == curr->y
		&& (curr->type[0] == 'f' || curr->type[0] == 'c'
			|| curr->type[0] == 'e'))
		flood_fill_next_next(curr, coins_found, exit_found, &res);
	if (position->x == curr->x && position->y + 16 == curr->y
		&& (curr->type[0] == 'f' || curr->type[0] == 'c'
			|| curr->type[0] == 'e'))
		flood_fill_next_next(curr, coins_found, exit_found, &res);
	if (position->x == curr->x && position->y - 16 == curr->y
		&& (curr->type[0] == 'f' || curr->type[0] == 'c'
			|| curr->type[0] == 'e'))
		flood_fill_next_next(curr, coins_found, exit_found, &res);
	return (res);
}

static void	flood_fill(int *coins_found, int *exit_found, t_map *clone_map)
{
	t_map	*temp;
	t_map	*othertemp;
	int		tester;

	tester = 0;
	temp = clone_map;
	while (temp)
	{
		if (temp->type[0] == 'Q')
		{
			othertemp = clone_map;
			while (othertemp)
			{
				tester += flood_fill_next(temp, othertemp,
						coins_found, exit_found);
				othertemp = othertemp->next;
			}
		}
		temp = temp->next;
	}
	if (tester > 0)
		flood_fill(coins_found, exit_found, clone_map);
}

static char	*floodfill_init_next(t_game *game, t_map *clone_map,
	int *coins_found, int *exit_found)
{
	t_map	*temp;

	while (clone_map)
	{
		temp = clone_map;
		clone_map = clone_map->next;
		free(temp);
	}
	if (*coins_found == game->totalcoins && *exit_found == 1)
		return ("D");
	return ("Invalid map!");
}

char	*floodfill_init(t_game *game)
{
	int		coins_found;
	int		exit_found;
	t_map	*clone_map;
	t_map	*temp;

	coins_found = 0;
	exit_found = 0;
	clone_map = ft_new_node(0, 0, "w");
	temp = game->map;
	while (temp)
	{
		if (temp->type[0] == 'p')
		{
			ft_last_node(clone_map)->next = ft_new_node(temp->x,
				temp->y, "Q");
		}
		else
		{
			ft_last_node(clone_map)->next = ft_new_node(temp->x,
				temp->y, temp->type);
		}
		temp = temp->next;
	}
	flood_fill(&coins_found, &exit_found, clone_map);
	return (floodfill_init_next(game, clone_map, &coins_found, &exit_found));
}
