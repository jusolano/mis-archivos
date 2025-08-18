/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cat.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jusolano <jusolano@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 10:39:00 by jusolano          #+#    #+#             */
/*   Updated: 2025/08/18 10:50:12 by jusolano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>

void	ft_display_file(char *file_name)
{
	int		file;
	int		line;
	char	letter;

	file = open(file_name, O_RDONLY);
	if (file == -1)
		return (0);
	while ((line = read(file, &letter, 1)))
	{
		if (line == -1)
		{
			close(file);
			return (0);
		}
		write(1, &letter, 1);
	}
	close(file);
	return (1);
}

int	main(int argc, char **argv)
{
	int	i;

	i = 0;
	if (argc < 2)
	{
		write(1, "File(s) name missing.\n", 22);
		return (0);
	}
	
}