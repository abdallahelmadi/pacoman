/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_last_node.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdael-m <abdael-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 13:59:04 by abdael-m          #+#    #+#             */
/*   Updated: 2025/01/13 08:35:39 by abdael-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../global.h"

t_map	*ft_last_node(t_map *header)
{
	t_map	*temp;

	temp = header;
	while (temp)
	{
		if (temp->next == NULL)
			return (temp);
		temp = temp->next;
	}
	return (NULL);
}
