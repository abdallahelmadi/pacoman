/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdael-m <abdael-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 08:36:33 by abdael-m          #+#    #+#             */
/*   Updated: 2025/08/24 10:40:12 by abdael-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../global.h"

static char	control_check(int newx, int newy, t_game *game)
{
	t_map	*temp;

	temp = game->map;
	while (temp)
	{
		if (temp->x == newx && temp->y == newy)
		{
			if (temp->type[0] == 'c')
			{
				game->eatedcoins += 1;
				temp->type = "f";
			}
			return (temp->type[0]);
		}
		temp = temp->next;
	}
	return ('0');
}

static void	control_move_next_next(char to, t_game *game)
{
	if (to == 't')
	{
		game->playery -= 16;
		mlx_put_image_to_window(game->mlx, game->window,
			game->pgplayert[game->playerframe], game->playerx, game->playery);
	}
	game->playerscore += 1;
	ft_string_put(game);
}

static void	control_move_next(char res, char to, t_game *game)
{
	if (res == 'e' && game->eatedcoins == game->totalcoins)
		finish_init(game);
	mlx_put_image_to_window(game->mlx, game->window,
		game->pgbg, game->playerx, game->playery);
	if (to == 'r')
	{
		game->playerx += 16;
		mlx_put_image_to_window(game->mlx, game->window,
			game->pgplayerr[game->playerframe], game->playerx, game->playery);
	}
	else if (to == 'l')
	{
		game->playerx -= 16;
		mlx_put_image_to_window(game->mlx, game->window,
			game->pgplayerl[game->playerframe], game->playerx, game->playery);
	}
	else if (to == 'b')
	{
		game->playery += 16;
		mlx_put_image_to_window(game->mlx, game->window,
			game->pgplayerb[game->playerframe], game->playerx, game->playery);
	}
	control_move_next_next(to, game);
}

static void	control_move(int x, int y, char to, t_game *game)
{
	char	res;

	game->playerframe += 1;
	if (game->playerframe == 4)
		game->playerframe = 0;
	res = control_check(x, y, game);
	if (res == 'w' && to == 'r')
		mlx_put_image_to_window(game->mlx, game->window,
			game->pgplayerr[game->playerframe], game->playerx, game->playery);
	else if (res == 'w' && to == 'l')
		mlx_put_image_to_window(game->mlx, game->window,
			game->pgplayerl[game->playerframe], game->playerx, game->playery);
	else if (res == 'w' && to == 't')
		mlx_put_image_to_window(game->mlx, game->window,
			game->pgplayert[game->playerframe], game->playerx, game->playery);
	else if (res == 'w' && to == 'b')
		mlx_put_image_to_window(game->mlx, game->window,
			game->pgplayerb[game->playerframe], game->playerx, game->playery);
	if (res == 'w')
		return ;
	if (res == 'x')
		finish_init(game);
	control_move_next(res, to, game);
}

int	control_init(int keycode, t_game *game)
{
	if (keycode == 65307)
		finish_init(game);
	if (keycode == 65363 || keycode == 100)
		control_move(game->playerx + 16, game->playery, 'r', game);
	if (keycode == 65361 || keycode == 97)
		control_move(game->playerx - 16, game->playery, 'l', game);
	if (keycode == 65364 || keycode == 115)
		control_move(game->playerx, game->playery + 16, 'b', game);
	if (keycode == 65362 || keycode == 119)
		control_move(game->playerx, game->playery - 16, 't', game);
	return (0);
}
