CC = gcc
CFLAGS = -Wall -Wextra -Werror 	#-fsanitize=address -g
NAME = push_swap
NAME2 = checker

SRC = 	list_ops.c \
		helper.c \
		helper2.c \
		main.c	\
		p_ops.c \
		rot_ops.c \
		rrot_ops.c \
		s_ops.c \
		small_sort.c \
		big_sort.c \
		check_input.c \

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@$(MAKE) -C libft/ re
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) -L libft/ -lft

%.o: %.c push_swap.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@$(MAKE) -C libft/ clean
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)
	@$(MAKE) -C libft/ fclean

re: fclean all
