/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juansolano <juansolano@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 08:40:18 by jusolano          #+#    #+#             */
/*   Updated: 2025/08/14 12:48:22 by juansolano       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
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

int	ft_total_len(int size, char **strs, char *sep)
{
	int	i;
	int	total_lenght;

	i = 0;
	total_lenght = 0;
	while (i < size)
	{
		total_lenght += ft_strlen(strs[i]);
		i++;
	}
	total_lenght += ft_strlen(sep) * (size - 1);
	return (total_lenght);
}

void	ft_cat(char *str_final, int size, char **strs, char *sep)
{
	int	k;
	int	j;
	int	i;
	int	lenght;

	lenght = ft_total_len(size, strs, sep);
	i = 0;
	k = 0;
	while (i < size)
	{
		j = 0;
		while (strs[i][j] != '\0')
			str_final[k++] = strs[i][j++];
		if (k < lenght)
		{
			j = 0;
			while (sep[j] != '\0')
				str_final[k++] = sep[j++];
		}
		i++;
	}
	str_final[k] = '\0';
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		lenght;
	char	*str_final;

	if (size == 0)
	{
		str_final = (char *)malloc(sizeof(char));
		if (str_final == NULL)
			return (NULL);
		str_final[0] = '\0';
		return (str_final);
	}
	lenght = ft_total_len(size, strs, sep);
	str_final = (char *)malloc(sizeof(char) * (lenght + 1));
	if (str_final == NULL)
		return (NULL);
	ft_cat(str_final, size, strs, sep);
	return (str_final);
}

/*int main()
{
	char *fruits[] = {"apple", "banana", "pineapple"};
	char *joined = ft_strjoin(3, fruits, "::;::");
	printf("Resultado: %s\n", joined);
	free(joined); 
	return (0);
}*/