/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jusolano <jusolano@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 10:01:08 by jusolano          #+#    #+#             */
/*   Updated: 2025/08/07 10:10:55 by jusolano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

int	ft_iterative_power(int nb, int power)
{
	int	i;
	int	result;

	i = 1;
	result = nb;
	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	while (i < power)
	{
		result *= nb;
		i++;
	}
	return (result);
}

/*int main(){
	printf("%d\n", ft_iterative_power(2,2));
	printf("%d\n", ft_iterative_power(-2,3));
	printf("%d\n", ft_iterative_power(-3,2));
	printf("%d\n", ft_iterative_power(-10,5));
}*/