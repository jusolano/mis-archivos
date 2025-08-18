#Sources and file name
NAME	= ft_display_file 
SRCS	= ./ft_display_file.c
OBJECTS	= $(SRCS:.c=.o)

#Compile and flags
CC		= cc
CFLAGS	= -Wall -Wextra -Werror
RM		= rm -f

#RULES
all: $(NAME)

$(NAME): $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o $(NAME)

%.o:%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJECTS)

fclean: clean
	$(RM) $(NAME)

.PHONY: all clean fclean