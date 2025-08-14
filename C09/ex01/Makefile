#Diretorios
SRC_DIR	= ./srcs/
INC_DIR	= ./includes

#Fontes e objetos
SRC	= ft_putchar.c ft_swap.c ft_putstr.c ft_strlen.c ft_strcmp.c

SRCS	= $(addprefix $(SRC_DIR), $(SRC))

OBJECTS	= $(SRCS:.c=.o)

#Nome biblioteca
NAME	= libft.a

#Compilar e flags
CC	= cc

AR	= ar rc

RM	= rm -f

CFLAGS	= -Wall -Wextra -Werror

#Reglas
all: $(NAME)

$(NAME): $(OBJECTS)
	$(AR) $(NAME) $(OBJECTS)
	ranlib $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -I $(INC_DIR) -c $< -o $@

clean:
	$(RM) $(OBJECTS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
