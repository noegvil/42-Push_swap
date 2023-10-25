NAME = push_swap
BNAME= checker
LIBFT = libft/libft.a

CC = gcc 
CFLAGS = -Wall -Werror -Wextra
CLEAN = rm -f

SRC := \
	src/main.c \
	src/utils.c \
	src/check.c \
	src/stack_ops.c \
	src/move_push.c \
	src/move_rev_rotate.c \
	src/move_rotate.c \
	src/move_swap.c \
	src/stack_utils.c \
	src/simple_sort.c \
	src/radix_sort.c \

BONUS_SRC = \
	bonus/bonus_main.c \
	bonus/utils.c \
	bonus/check.c \
	bonus/stack_ops.c \
	bonus/move_push.c \
	bonus/move_rev_rotate.c \
	bonus/move_rotate.c \
	bonus/move_swap.c \
	bonus/stack_utils.c \
	bonus/get_next_line.c \
	bonus/get_next_line_utils.c \

OBJS = $(SRC:.c=.o)

BONUS_OBJS = $(BONUS_SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

bonus: $(BONUS_OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(BONUS_OBJS) $(LIBFT) -o $(BNAME)

$(LIBFT):
	make -C ./libft
# cd libft && make all
	
clean:
	$(CLEAN) $(OBJS) $(BONUS_OBJS)
	make clean -C ./libft

fclean: clean
	$(CLEAN) $(NAME) $(BNAME)
	make fclean -C ./libft

re: fclean all bonus
.PHONY: all clean fclean re bonus