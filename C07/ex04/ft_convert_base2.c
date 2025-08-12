/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juansolano <juansolano@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 10:01:17 by jusolano          #+#    #+#             */
/*   Updated: 2025/08/12 19:03:34 by juansolano       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
//#include <stdio.h>

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

int	required_size(int nbr, char *base)
{
	int		i;
	long	n;
	int		size;

	i = 1;
	n = nbr;
	size = ft_strlen(base);
	if (n < 0)
	{
		n *= -1;
		i++;
	}
	while (n >= size)
	{
		n /= size;
		i++;
	}
	return (i);	
}


void	ft_putnbr_base(int nbr, char *base, char *resultado)
{
	int		size_base;
	int		last_digit;
	long	n;

	last_digit = required_size(nbr, base);
	if (nbr == 0)
	{
		resultado[0] = base[0];
		return ;
	}
	size_base = ft_strlen(base);
	n = nbr;
	if (n < 0)
	{
		resultado[0] = '-';
		n *= -1;
	}
	while (n > 0)
	{
		resultado[--last_digit] = base[n % size_base];
		n = n / size_base;
	}
}