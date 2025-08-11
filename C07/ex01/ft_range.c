/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jusolano <jusolano@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 09:52:32 by jusolano          #+#    #+#             */
/*   Updated: 2025/08/11 10:03:14 by jusolano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
//#include <stdio.h>

int	*ft_range(int min, int max)
{
	int	*range;
	int	i;

	if (min >= max)
		return (NULL);
	range = (int *)malloc(sizeof(int) * (max - min + 1));
	if (range == NULL)
		return (NULL);
	i = 0;
	while (min <= max)
	{
		range[i] = min;
		i++;
		min++;
	}
	return (range);
}

/*int main()
{
	int *range;
	range = ft_range(0,10);
	int i = 0;
	while (i < 11 && range)
	{
		printf("%d ", range[i]);
		i++;
	}
	return (0);
}*/
