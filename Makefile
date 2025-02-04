NAME = push_swap
BONUS_NAME = checker
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
		parsing.c\
		ft_strjoin.c\
		main.c\
		bubble_sort.c

BONUS_SRCS = bonus/checker.c\
             bonus/a_instructions_bonus.c\
             bonus/b_instructions_bonus.c\
             bonus/common_instructions_bonus.c\
             bonus/ft_split.c\
             bonus/get_next_line/get_next_line.c\
             bonus/get_next_line/get_next_line_utils.c\
             utils.c\
             parsing.c\
             linked_lists.c\
             ft_strjoin.c\
             bubble_sort.c\
			 push_swap.c\
			 ft_atoi.c

OBJECTS = $(SRCS:.c=.o)

BONUS_OBJECTS = $(BONUS_SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJECTS)
	$(CC) $(CFLAGS) $(SRCS) -o $(NAME)

bonus :$(BONUS_OBJECTS)
	$(CC) $(CFLAGS) $(BONUS_SRCS) -o $(BONUS_NAME)

clean :
	rm -rf  $(OBJECTS) $(BONUS_OBJECTS)

fclean : clean
	rm -rf $(NAME) $(BONUS_NAME)

re : clean fclean all

.PHONY : all clean fclean re
