/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fibonacci.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jusolano <jusolano@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 10:16:27 by jusolano          #+#    #+#             */
/*   Updated: 2025/08/07 10:26:01 by jusolano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

int	ft_fibonacci(int index)
{
	int	sum;

	sum = 0;
	if (index < 0)
		return (-1);
	if (index == 0)
		return (0);
	if (index == 1)
		return (1);
	sum = ft_fibonacci(index - 1) + ft_fibonacci(index - 2);
	return (sum);
}

/*int main(){
	printf("Index %d: %d\n", 3, ft_fibonacci(3));
	printf("Index %d: %d\n", 5, ft_fibonacci(5));
	printf("Index %d: %d\n", 10, ft_fibonacci(10));
}*/