/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jusolano <jusolano@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 10:11:21 by jusolano          #+#    #+#             */
/*   Updated: 2025/08/07 10:15:21 by jusolano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

int	ft_recursive_power(int nb, int power)
{
	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	nb *= ft_recursive_power(nb, power - 1);
	return (nb);
}

/*int main(){
	printf("%d\n", ft_recursive_power(2,2));
	printf("%d\n", ft_recursive_power(-2,3));
	printf("%d\n", ft_recursive_power(-3,2));
	printf("%d\n", ft_recursive_power(-10,5));
}*/