/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_new_node.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdael-m <abdael-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 13:59:49 by abdael-m          #+#    #+#             */
/*   Updated: 2025/01/13 08:34:48 by abdael-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../global.h"

t_map	*ft_new_node(int x, int y, char *type)
{
	t_map	*newlocation;

	newlocation = (t_map *)malloc(sizeof(t_map));
	if (!newlocation)
		return (NULL);
	newlocation->x = x;
	newlocation->y = y;
	newlocation->type = type;
	newlocation->next = NULL;
	return (newlocation);
}
