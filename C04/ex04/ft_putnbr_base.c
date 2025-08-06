/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juansolano <juansolano@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 14:53:35 by jusolano          #+#    #+#             */
/*   Updated: 2025/08/06 20:35:33 by juansolano       ###   ########.fr       */
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

int base_correta(char *base)
{
	int j;
	int k;

	j = 0;
	if (ft_strlen(base) < 2)
		return (0);
	while (base[j])
	{
		k = j + 1;
		if (base[j] == '+' || base[j] == '-')
			return (0);
		while (base[k])
		{
			if (base[k] == base[j])
				return (0);
			k++;
		}
		j++;
	}
	return (1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int	size_base;
	long n;
	int	i;
	char result[32];

	if (!base_correta(base))
		return;
	if (nbr == 0)
	{
		write(1, &base[0], 1);
		return;
	}
	size_base = ft_strlen(base);
	n = nbr;
	i = 0;
	if (n < 0)
	{
		write(1, "-", 1);
		n *= -1;
	}
	while (n > 0)
	{
		result[i] = base[n % size_base];
		n = n / size_base;
		i++;
	}
	while (--i >= 0)
	{
		write(1, &result[i], 1);
	}
}

/*int main(){
	ft_putnbr_base(-10,"0123456789ABCDEF");
}*/