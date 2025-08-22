/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdael-m <abdael-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 14:01:41 by abdael-m          #+#    #+#             */
/*   Updated: 2025/01/08 08:30:11 by abdael-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../global.h"

static void	ft_putstr(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		write(1, &(str[i]), 1);
		i++;
	}
}

static void	ft_putnbr(int nbr)
{
	char	c;

	if (nbr > 9)
	{
		ft_putnbr(nbr / 10);
		ft_putnbr(nbr % 10);
	}
	else
	{
		c = nbr + '0';
		write(1, &c, 1);
	}
}

void	ft_printf(const char *str, ...)
{
	int		i;
	va_list	args;

	i = 0;
	va_start(args, str);
	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			i++;
			if (str[i] == 's')
				ft_putstr(va_arg(args, char *));
			else if (str[i] == 'd')
				ft_putnbr(va_arg(args, int));
		}
		else
			write(1, &(str[i]), 1);
		i++;
	}
	va_end(args);
}
