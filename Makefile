NAME		=	fractol
PATH_M		=	./mandatory/
PATH_B		=	./bonus/
MAKEFLAGS	=	--no-print-directory
HEADER		=	-I./includes
LIBS		=	./libftprintf/libftprintf.a ./libftprintf/libft/libft.a

MANDATORY	=	main.c \
				draw.c \
				user_input.c \
				inits_exit.c \

BONUS		=	main_bonus.c set_fractal_bonus.c \
				errors_bonus.c events_bonus.c \
				render_fractal_bonus.c calc_fractal_bonus.c

OBJS		=	$(addprefix $(PATH_M), $(MANDATORY:.c=.o))
OBJS_B		=	$(addprefix $(PATH_B), $(BONUS:.c=.o))

# Compile flags
UNAME_S := $(shell uname -s)
ifeq ($(UNAME_S),Linux)
	CFLAG = -g -L./minilibx-linux -lmlx -lX11 -lXext -Imlx -lm -Wall -Wextra -Werror
else ifeq ($(UNAME_S),Darwin)
	CFLAG = -Wall -Wextra -Werror -lmlx -framework OpenGL -framework AppKit
else
	$(error "Unsupported operating system ($(UNAME_S)) == windows :-D")
endif

all: dependencies $(NAME)

bonus: libftprintf ${OBJS_B}
	@make $(NAME) OBJS="${OBJS_B}"

dependencies:
	@make -C ./libftprintf
	@make -C ./libftprintf/libft

$(NAME): ${LIBS} ${OBJS}
	cc ${OBJS} ${LIBS} ${CFLAG} -o ${NAME} ${HEADER}

%.o: %.c
	cc -Wall -Wextra -Werror -c $< -o $@ ${HEADER}

clean:
	rm -f ${OBJS} ${OBJS_B}
	$(MAKE) clean -C ./libftprintf

fclean: clean
	rm -f ${NAME}
	rm -f ${LIBS}

re: fclean all

.PHONY: all bonus libftprintf clean fclean re