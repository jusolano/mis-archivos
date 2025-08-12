/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jusolano <jusolano@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 10:01:08 by jusolano          #+#    #+#             */
/*   Updated: 2025/08/12 10:39:43 by jusolano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

void	ft_putnbr_base(int nbr, char *base, char *resultado);
int	required_size(int nbr, char *base);
int	ft_strlen(char *str);

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

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int		number;
	int		espacos;
	char	*n_basenova;

	if (!(base_correta(base_from) && base_correta(base_to)))
		return (NULL);
	number = ft_atoi_base(nbr, base_from);
	espacos = required_size(number, base_to);
	n_basenova = (char *)malloc(sizeof(char) * (espacos + 1));
	if (n_basenova == NULL)
		return (NULL);
	ft_putnbr_base(number, base_to, n_basenova);
	n_basenova[espacos] = '\0';
	return (n_basenova);
}

int main()
{
	char *bin = "01";
	char *hexa = "0123456789ABCDEF";
	char *num = "1010";
	printf("El resultado es: %s", ft_convert_base(num, bin, hexa));
}