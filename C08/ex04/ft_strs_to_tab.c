/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jusolano <jusolano@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 12:44:12 by jusolano          #+#    #+#             */
/*   Updated: 2025/08/13 13:18:02 by jusolano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_stock_str.h"

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
