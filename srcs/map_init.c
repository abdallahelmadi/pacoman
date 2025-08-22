/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdael-m <abdael-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 09:05:10 by abdael-m          #+#    #+#             */
/*   Updated: 2025/01/16 17:26:31 by abdael-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../global.h"

static char	*map_validate_next_next(t_game *game)
{
	char	*line;
	int		fd;
	int		len1;

	fd = open(game->pathfilename, O_RDONLY);
	line = get_next_line_init(fd);
	if (!line)
	{
		close(fd);
		return ("The file is empty!");
	}
	len1 = ft_strlen(line);
	while (line)
	{
		if (len1 != ft_strlen(line) || map_includes(line))
		{
			free(line);
			close(fd);
			return ("You added unknown elements to the map!");
		}
		free(line);
		line = get_next_line_init(fd);
	}
	close(fd);
	return (floodfill_init(game));
}

static	char	*map_validate_next(t_game *game)
{
	t_map	*curr;
	int		bt_y;
	int		rt_x;

	curr = ft_last_node(game->map);
	bt_y = curr->y;
	rt_x = curr->x;
	curr = game->map;
	while (curr)
	{
		if (curr->y == 0 || curr->y == bt_y || curr->x == 0 || curr->x == rt_x)
		{
			if (curr->type[0] != 'w')
				return ("The map must be fully enclosed by walls!");
		}
		curr = curr->next;
	}
	return (map_validate_next_next(game));
}

static	char	*map_validate(t_game *game)
{
	t_map	*temp;
	t_vars	vars;

	vars.x = 0;
	vars.y = 0;
	vars.z = 0;
	temp = game->map;
	while (temp)
	{
		if (temp->type[0] == 'e')
			vars.x++;
		else if (temp->type[0] == 'p')
			vars.y++;
		else if (temp->type[0] == 'c')
			vars.z++;
		temp = temp->next;
	}
	game->totalcoins = vars.z;
	if (vars.x != 1)
		return ("The map must contain exactly one exit!");
	else if (vars.y != 1)
		return ("The map must contain exactly one player!");
	else if (vars.z <= 0)
		return ("The map must have at least one collectible!");
	return (map_validate_next(game));
}

char	*map_init(t_game *game)
{
	int		fd;
	int		readed;
	char	buffer;
	t_vars	vars;

	fd = open(game->pathfilename, O_RDONLY);
	if (fd < 0)
		return ("Unable to open the file. check the file name or path!");
	game->map = ft_new_node(0, 0, "w");
	vars.x = 0;
	vars.y = 0;
	while (1)
	{
		readed = read(fd, &buffer, 1);
		if (readed < 0)
			return ("Unable to read the file. verify the accessibility!");
		else if (readed == 0)
		{
			close(fd);
			return (map_validate(game));
		}
		map_generate(&vars.x, &vars.y, buffer, game);
	}
	return ("An unexpected issue occurred while processing the map!");
}

void	map_display(t_game *game)
{
	t_map	*temp;
	int		random;

	temp = game->map;
	while (temp)
	{
		if (temp->type[0] == 'w')
		{
			random = ft_random(1);
			mlx_put_image_to_window(game->mlx,
				game->window, game->pgwalls[random], temp->x, temp->y);
		}
		if (temp->type[0] == 'c')
		{
			random = ft_random(7);
			mlx_put_image_to_window(game->mlx,
				game->window, game->pgcoins[random], temp->x, temp->y);
		}
		if (temp->type[0] == 'p')
			mlx_put_image_to_window(game->mlx,
				game->window, game->pgplayerb[0], temp->x, temp->y);
		temp = temp->next;
	}
}
