/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jusolano <jusolano@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 14:53:35 by jusolano          #+#    #+#             */
/*   Updated: 2025/08/06 15:31:22 by jusolano         ###   ########.fr       */
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

void	ft_putnbr_base(int nbr, char *base)
{
	int	size_base;
	int n;
	int	i;
	char result[100];

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
	while (i >= 0)
	{
		write(1, &result[i], 1);
		i--;
	}
}

/*int main(){
	ft_putnbr_base(-10,"0123456789ABCDEF");
}*/