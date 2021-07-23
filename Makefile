CC			= gcc
CFLAGS		= -Wall -Werror -Wextra

LIBFT_DIR	= ./libft/
LIBGNL_DIR	= ./gnl/
LIBFT		= libft.a
LIBGNL		= libgnl.a

PUSH_SWAP	= push_swap
CHECKER		= checker
NAME		= $(PUSH_SWAP) $(CHECKER)

OBJS_DIR	= ./objs/
PUSH_DIR	= ./push/
CHECK_DIR	= ./check/
PUB_DIR		= ./pub/

PUSH_FILE 	= push_swap.c \
			operations_a.c \
			operations_b.c \
			sort_basic_a_only.c \
			sort_basic_a.c \
			sort_basic_b.c \
			sort_basic_main_a.c \
			sort_basic_main_b.c \
			sort_main.c \

CHECK_FILE	= main_check.c \
			ch_operations_a.c \
			ch_operations_b.c \
			ch_operations_c.c

PUB_FILE 	= make_stack_a.c \
			operations_basic.c \
			utils_etc.c \
			utils_get.c \
			utils_search.c \
			print_funcs.c \
			quick_sort.c \
			error_check.c \
			print_error.c \
			utils_tmp.c

PUSH_SRCS	= $(addprefix $(PUSH_DIR), $(PUSH_FILE))
CHECK_SRCS	= $(addprefix $(CHECK_DIR), $(CHECK_FILE))
PUB_SRCS	= $(addprefix $(PUB_DIR), $(PUB_FILE))

all: $(NAME) 

$(NAME): make_lib
	$(CC) $(CFLAGS) $(PUSH_SRCS) $(PUB_SRCS) $(LIBFT) -o $(PUSH_SWAP)
	$(CC) $(CFLAGS) $(CHECK_SRCS) $(PUB_SRCS) $(LIBFT) $(LIBGNL) -o $(CHECKER)

$(LIBFT):
	make -C $(LIBFT_DIR)
	make clean -C $(LIBFT_DIR)
	mv $(LIBFT_DIR)$(LIBFT) .

$(LIBGNL):
	make -C $(LIBGNL_DIR)
	make clean -C $(LIBGNL_DIR)
	mv $(LIBGNL_DIR)$(LIBGNL) .

make_lib: $(LIBFT) $(LIBGNL)

clean:
	rm -rf ./objs *.a

fclean: clean
	rm -rf push_swap checker *.dSYM

re: fclean all

.PHONY: all clean fclean re
