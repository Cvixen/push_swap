NAME 	=	push_swap
NAME_BONUS  = checker 
CC		=	gcc
SRCS_F	=	function_list.c \
			function_list_2.c \
			push_swap.c \
			check_argv.c \
			rotate.c \
			swap.c \
			reverse.c \
			push.c \
			sort_array.c \
			sort_by_three.c \
			sort_by_five.c \
			sort_many_numbers.c

BONUS_F = 	checker.c \
			function_list.c \
			function_list_2.c \
			check_argv.c \
			rotate.c \
			swap.c \
			reverse.c \
			push.c \
			read_sort.c

SRCS_D = src/
BONUS_D = bonus/

SRC = $(addprefix $(SRCS_D),$(SRCS_F))
BONUS = $(addprefix $(BONUS_D),$(BONUS_F))

OBJS = ${SRC:.c=.o}
OBJS_BONUS = $(BONUS:.c=.o)

HEADER = includes/push_swap.h
HEADER_BONUS = bonus/includes/checker.h

LIB = libft/libft.a
RM = rm -f
CFLAGS = -Wall -Werror -Wextra

.PHONY: all clean fclean re bonus

.c.o: ${HEADER}
	${CC} ${CFLAGS} -c $< -o${<:.c=.o}

all		: ${NAME}

${NAME}	: ${OBJS} ${HEADER}
		  $(MAKE) -C libft
		  $(CC) -g $(CFLAGS) $(LIB) $(OBJS) -o $(NAME)

clean:
		$(MAKE) clean -C libft
		${RM} ${OBJS} ${OBJS_BONUS}

fclean: clean
		$(MAKE) fclean -C libft
		${RM} ${NAME} ${NAME_BONUS}

bonus: 	${OBJS_BONUS} ${HEADER_BONUS}
		$(MAKE) -C libft
		$(CC) -g $(CFLAGS) $(LIB) $(OBJS_BONUS) -o $(NAME_BONUS)

re: fclean all
