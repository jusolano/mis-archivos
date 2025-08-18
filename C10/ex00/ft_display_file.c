/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jusolano <jusolano@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 08:59:26 by jusolano          #+#    #+#             */
/*   Updated: 2025/08/18 10:22:06 by jusolano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>

int	ft_display_file(char *file_name)
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

int main(int argc, char **argv)
{
	if (argc < 2)
	{
		write(1, "File name missing.\n", 19);
		return (0);
	}
	if (argc > 2)
	{
		write(1, "Too many arguments.\n", 20);
		return (0);
	}
	if (!ft_display_file(argv[1]))
		write(1, "Cannot read file.\n", 18);
	return (0);
}