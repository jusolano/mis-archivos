/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jusolano <jusolano@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 08:54:11 by jusolano          #+#    #+#             */
/*   Updated: 2025/08/07 09:29:05 by jusolano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

int	base_correta(char *base)
{
	int	j;
	int	k;

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

int	pos_1st_num(char *str, int *sign)
{
	int	i;
	int	sign_aux;

	i = 0;
	sign_aux = 1;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign_aux *= -1;
		i++;
	}
	(*sign) = sign_aux;
	return (i);
}

int	position(char c, char *base)
{
	int	i;

	i = 0;
	while (base[i] != '\0')
	{
		if (base[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

int	ft_atoi_base(char *str, char *base)
{
	int	i;
	int	sign;
	int	num_final;
	int	pos_base;

	sign = 1;
	i = pos_1st_num(str, &sign);
	num_final = 0;
	if (!base_correta(base))
		return (0);
	pos_base = position(str[i], base);
	while (pos_base != -1)
	{
		num_final = num_final * ft_strlen(base) + pos_base;
		i++;
		pos_base = position(str[i], base);
	}
	num_final *= sign;
	return (num_final);
}

/*int main()
{
	printf("%d\n", ft_atoi_base("A","0123456789ABCDEF"));
	printf("%d\n", ft_atoi_base("FF","0123456789ABCDEF"));
	printf("%d\n", ft_atoi_base("11110100011","01"));
	printf("%d\n", ft_atoi_base("B2DD","0123456789ABCDEF"));
	printf("%d\n", ft_atoi_base("100100110100","01"));
	printf("%d\n", ft_atoi_base("0","0123456789ABCDEF"));
}*/