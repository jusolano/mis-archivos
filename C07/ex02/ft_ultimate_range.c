/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jusolano <jusolano@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 10:08:09 by jusolano          #+#    #+#             */
/*   Updated: 2025/08/11 10:27:48 by jusolano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
//#include <stdio.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	i;
	int	*auxiliar;

	auxiliar = (int *)malloc(sizeof(int) * (max - min));
	if (min >= max)
	{
		*range = NULL;
		return (0);
	}
	if (auxiliar == NULL)
	{
		*range = NULL;
		return (-1);
	}
	i = 0;
	while (min < max)
	{
		auxiliar[i] = min;
		i++;
		min++;
	}
	*range = auxiliar;
	return (i);
}

/*int main()
{
	int *range;
	int i = ft_ultimate_range(&range,0,15);
	int j = 0;
	while (j < i)
	{
		printf("%d ", range[j]);
		j++;
	}
	free(range);
	return (0);
}*/