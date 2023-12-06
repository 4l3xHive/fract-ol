NAME		=	fractol
PATH_M		=	./mandatory/
PATH_B		=	./bonus/
MAKEFLAGS	=	--no-print-directory
HEADER		=	-I./includes
LIBS		=	./libftprintf/libftprintf.a ./libftprintf/libft/libft.a

MANDATORY	=	main.c \
				calculate.c \
				user_input.c \
				refresh.c \
				inits.c \
				utils.c \
				

BONUS		=	main_bonus.c set_fractal_bonus.c \
				errors_bonus.c events_bonus.c \
				render_fractal_bonus.c calc_fractal_bonus.c

OBJS		=	$(addprefix $(PATH_M), $(MANDATORY:.c=.o))
OBJS_B		=	$(addprefix $(PATH_B), $(BONUS:.c=.o))

# Check for OS
UNAME_S := $(shell uname -s)
ifeq ($(UNAME_S),Linux)
    CFLAG = -g -L./minilibx-linux -lmlx -lX11 -lXext -Imlx -lm -Wall -Wextra -Werror
    LIBRARY_PATH = ./minilibx-linux
else ifeq ($(UNAME_S),Darwin)
    CFLAG = -Wall -Wextra -Werror -lmlx -Imlx -L./minilibx-macos -framework OpenGL -framework AppKit -lm
    LIBRARY_PATH = ./minilibx-macos
else
    $(error "Unsupported operating system ($(UNAME_S)) == windows :-D")
endif

all: dependencies $(NAME)

bonus: libftprintf ${OBJS_B}
	@make $(NAME) OBJS="${OBJS_B}"

dependencies:
	@make -C ./libftprintf
	@make -C ./libftprintf/libft
	@make -C $(LIBRARY_PATH)

$(NAME): ${LIBS} ${OBJS}
	cc ${OBJS} ${LIBS} ${CFLAG} -o ${NAME} ${HEADER}

%.o: %.c
	cc -Wall -Wextra -Werror -c $< -o $@ ${HEADER}

clean:
	@make clean -C $(LIBRARY_PATH)
	rm -f ${OBJS} ${OBJS_B}
	$(MAKE) clean -C ./libftprintf

fclean: clean
	rm -f ${NAME}
	rm -f ${LIBS}

re: fclean all

.PHONY: all bonus libftprintf clean fclean re dependencies
