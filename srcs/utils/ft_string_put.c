/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string_put.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdael-m <abdael-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 16:07:30 by abdael-m          #+#    #+#             */
/*   Updated: 2025/01/14 09:37:31 by abdael-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../global.h"

static char	*string_itao_next(int nbr, int len, char *out)
{
	out[len] = '\0';
	while (nbr > 0)
	{
		out[--len] = (nbr % 10) + '0';
		nbr /= 10;
	}
	return (out);
}

static char	*string_itao(int nbr)
{
	char	*out;
	int		len;
	int		temp;

	if (nbr == 0)
		len = 1;
	else
		len = 0;
	temp = nbr;
	while (temp > 0)
	{
		len++;
		temp /= 10;
	}
	out = malloc(sizeof(char) * (len + 1));
	if (out == NULL)
		return (NULL);
	if (nbr == 0)
	{
		out[0] = '0';
		out[1] = '\0';
		return (out);
	}
	return (string_itao_next(nbr, len, out));
}

static char	*string_result(t_game *game)
{
	char	*res;
	char	*temp;
	char	*othertemp;

	temp = string_itao(game->playerscore);
	res = ft_strjoin("Score: ", temp);
	free(temp);
	temp = string_itao(game->eatedcoins);
	othertemp = ft_strjoin(res, " (collectibles: ");
	free(res);
	res = ft_strjoin(othertemp, temp);
	free(othertemp);
	free(temp);
	temp = string_itao(game->totalcoins);
	othertemp = ft_strjoin(res, "/");
	free(res);
	res = ft_strjoin(othertemp, temp);
	free(othertemp);
	free(temp);
	othertemp = ft_strjoin(res, ")");
	free(res);
	return (othertemp);
}

void	ft_string_put(t_game *game)
{
	char	*res;
	int		i;

	i = 0;
	while (game->screenwidth > i)
	{
		mlx_put_image_to_window(game->mlx, game->window, game->pgbg,
			i, game->screenhight);
		i += 16;
	}
	res = string_result(game);
	mlx_string_put(game->mlx, game->window,
		(game->screenwidth / 2) - ft_strlen(res) * 3,
		game->screenhight + 13,
		0xffffff,
		res);
	free(res);
}
