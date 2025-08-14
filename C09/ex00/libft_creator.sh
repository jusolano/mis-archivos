# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    libft_creator.sh                                   :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jusolano <jusolano@student.42lisboa.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/08/13 15:45:28 by jusolano          #+#    #+#              #
#    Updated: 2025/08/14 09:07:20 by jusolano         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#!/bin/bash

#ar "archiver" to create static library, r to replace and c to create

cc -Wall -Wextra -Werror -c ft_putchar.c ft_swap.c ft_putstr.c ft_strlen.c ft_strcmp.c
ar rc libft.a ft_putchar.o ft_swap.o ft_putstr.o ft_strlen.o ft_strcmp.o
ranlib libft.a
rm -f *.o