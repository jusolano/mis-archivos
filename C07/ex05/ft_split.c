/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jusolano <jusolano@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 07:32:41 by jusolano          #+#    #+#             */
/*   Updated: 2025/08/13 10:47:47 by jusolano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
//#include <stdio.h>

int	is_sep(char c, char *charset)
{
	int	i;

	i = 0;
	while (charset[i] != '\0')
	{
		if (charset[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	check_word(int start, int end, char *str, char *charset)
{
	while (start < end && str[start] != '\0')
	{
		if (!(str[start] == ' ' || (str[start] >= 9 && str[start] <= 13))
			&& !is_sep(str[start], charset))
			return (1);
		start++;
	}
	return (0);
}

int	quantidade_palavras(char *str, char *charset)
{
	int	i;
	int	sep_inicial;
	int	sep_final;
	int	quantidade;

	i = 0;
	sep_inicial = 0;
	sep_final = 0;
	quantidade = 0;
	while (str[i] != '\0')
	{
		if (is_sep(str[i], charset))
		{
			sep_final = i;
			if (check_word(sep_inicial, sep_final, str, charset))
				quantidade++;
			sep_inicial = sep_final;
		}
		i++;
	}
	if (check_word(sep_inicial, i, str, charset))
		quantidade++;
	return (quantidade);
}

char	*save_word(char *str, char *charset)
{
	int		j;
	char	*palavra;

	j = 0;
	while (str[j] != '\0' && !is_sep(str[j], charset))
		j++;
	if (!check_word(0, j, str, charset))
		return (0);
	palavra = (char *)malloc(sizeof(char) * (j + 1));
	if (palavra == NULL)
		return (0);
	j = 0;
	while (str[j] != '\0' && !is_sep(str[j], charset))
	{
		palavra[j] = str[j];
		j++;
	}
	palavra[j] = '\0';
	return (palavra);
}

char	**ft_split(char *str, char *charset)
{
	int		i;
	int		j;
	char	**array_final;

	array_final = (char **)malloc(sizeof(char *)
			* (quantidade_palavras(str, charset) + 1));
	if (array_final == NULL || str == NULL || charset == NULL)
		return (0);
	i = 0;
	j = 0;
	while (str[i] != '\0')
	{
		if (!is_sep(str[i], charset))
		{
			array_final[j] = save_word(&str[i], charset);
			if (array_final[j] != NULL)
				j++;
			while (str[i] != '\0' && !is_sep(str[i], charset))
				i++;
		}
		else
			i++;
	}
	array_final[j] = 0;
	return (array_final);
}

/*int main()
{
	char *str = "Hola, dj   ?  abgv    , , , hadhbv   ??";
	char *charset = ",!?"; 
	int cantidad = quantidade_palavras(str, charset);
	printf("Numero de palabras: %d\n", cantidad);
	char **array;
	int	i;

	array = ft_split(str, charset);
	i = 0;
	while (array[i] != NULL)
	{
		printf("%s\n", array[i]);
		i++;
	}
	return (0);
}*/