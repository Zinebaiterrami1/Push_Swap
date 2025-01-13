NAME = push_swap
CFLAGS = -Wall -Werror -Wextra -fsanitize=address -g3
CC = cc 
SRCS = common_instructions.c\
		ft_atoi.c\
		ft_split.c\
		instructions_a.c\
		instructions_b.c\
		linked_lists.c\
		push_swap.c\
		sort_algo.c\
		utils.c\
		main.c

OBJECTS = $(SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJECTS)
	$(CC) $(CFLAGS) $(SRCS) -o $(NAME)

clean :
	rm -rf  $(OBJECTS)

fclean :	
	rm -rf $(NAME) $(OBJECTS)

re : clean fclean all

.PHONY : all clean fclean re
