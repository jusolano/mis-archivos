/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juansolano <juansolano@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 10:24:37 by jusolano          #+#    #+#             */
/*   Updated: 2025/08/05 17:08:01 by juansolano       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char *str, char *to_find)
{
	int	i;
	int	j;

	i = 0;
	if (*to_find == '\0')
	{
		return (str);
	}
	while (str[i] != '\0')
	{
		j = 0;
		while (to_find[j] == str[i + j] && str[i + j] != '\0')
		{
			j++;
			if (to_find[j] == '\0')
			{
				return (str + i);
			}
		}
		i++;
	}
	return (0);
}
