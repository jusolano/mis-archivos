/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jusolano <jusolano@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 12:44:12 by jusolano          #+#    #+#             */
/*   Updated: 2025/08/13 14:25:26 by jusolano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_stock_str.h"
//#include <unistd.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (*str)
	{
		i++;
		str++;
	}
	return (i);
}

char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = src[i];
	return (dest);
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	int			i;
	t_stock_str	*array;

	array = (t_stock_str *)malloc(sizeof(t_stock_str) * (ac + 1));
	if (array == NULL)
		return (NULL);
	i = 0;
	while (i < ac)
	{
		array[i].str = (char *)malloc(sizeof(char) * (ft_strlen(av[i]) + 1));
		array[i].copy = (char *)malloc(sizeof(char) * (ft_strlen(av[i]) + 1));
		if (array[i].str == NULL || array[i].copy == NULL)
			return (NULL);
		array[i].size = ft_strlen(av[i]);
		array[i].str = ft_strcpy(array[i].str, av[i]);
		array[i].copy = ft_strcpy(array[i].copy, av[i]);
		i++;
	}
	array[i].size = 0;
	array[i].str = NULL;
	array[i].copy = NULL;
	return (array);
}
/*void	ft_putstr(char *str)
{
	while (*str != '\0')
	{
		write(1, str, 1);
		str++;
	}
	write(1, "\n", 1);
}

void	ft_putnbr(int nb)
{
	char	c;

	if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
		return ;
	}
	if (nb < 0)
	{
		write(1, "-", 1);
		nb = -nb;
	}
	if (nb > 9)
	{
		ft_putnbr(nb / 10);
	}
	c = '0' + (nb % 10);
	write(1, &c, 1);
	write(1, "\n", 1);
}

void	ft_show_tab(struct s_stock_str *par)
{
	int	i;

	i = 0;
	while (par[i].str != NULL)
	{
		ft_putstr(par[i].str);
		ft_putnbr(par[i].size);
		ft_putstr(par[i].copy);
		i++;
	}
}
int	main(int argc, char **argv)
{
	t_stock_str *str;

	str = ft_strs_to_tab(argc, argv);
	ft_show_tab(str);
	free(str);
}*/