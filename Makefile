NAME		=	fractol
PATH_M		=	./mandatory/
PATH_B		=	./bonus/
HEADER		=	-I./includes -I./libft
LIBS		=	./libft/libft.a

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
    CFLAG = -Wall -Wextra -Werror -lmlx -framework OpenGL -framework AppKit -lm
else
    $(error "Unsupported operating system ($(UNAME_S)) == windows :-D")
endif

all: dependencies $(NAME)

bonus: libft ${OBJS_B}
	@make $(NAME) OBJS="${OBJS_B}"

dependencies:
	@make -C ./libft

$(NAME): ${LIBS} ${OBJS}
	@cc ${OBJS} ${LIBS} ${CFLAG} -o ${NAME} ${HEADER}
	@printf "\033[0;32m$(NAME) succesfully created.\033[0m\n"

%.o: %.c
	@cc -Wall -Wextra -Werror -c $< -o $@ ${HEADER}

clean:
ifeq ($(UNAME_S),Linux)
	@make clean -C $(LIBRARY_PATH)
	@rm -f ${OBJS} ${OBJS_B}
	$(MAKE) clean -C ./libft
else
	@rm -f ${OBJS} ${OBJS_B}
	@make clean -C ./libft
endif


fclean: clean
	@rm -f ${NAME}
	@rm -f ${LIBS}

re: fclean all

.PHONY: all bonus clean fclean re dependencies
