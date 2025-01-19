/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdael-m <abdael-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 06:53:39 by abdael-m          #+#    #+#             */
/*   Updated: 2025/01/17 09:41:44 by abdael-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "global.h"

int	main(int ac, char *av[])
{
	t_game	*game;
	char	*status;

	game = NULL;
	if (ac == 2)
	{
		game = malloc(sizeof(t_game));
		status = game_init(game, av[1]);
		if (status[0] != 'D')
		{
			ft_printf("\033[1;31mError\n\033[0m%s\n", status);
			finish_init(game);
		}
		mlx_hook(game->window, 2, 1L << 0, control_init, game);
		mlx_hook(game->window, 17, 0, finish_init, game);
		mlx_loop_hook(game->mlx, loops_init, game);
		mlx_loop(game->mlx);
		finish_init(game);
	}
	ft_printf("\033[1;31mError\n\033[0mYou must contain exactly one map!\n");
	return (0);
}
