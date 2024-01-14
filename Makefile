NAME		=	fractol
NAME_BONUS =	fractol_bonus
PATH_M		=	./mandatory/
PATH_B		=	./bonus/
HEADER		=	-I./mandatory -I./bonus -I./libft
LIBS		=	./libft/libft.a

MANDATORY	=	main.c \
				calculate.c \
				user_input.c \
				refresh.c \
				inits.c \
				utils.c \

BONUS=			main_bonus.c \
				calculate_bonus.c \
				user_input_bonus.c \
				refresh_bonus.c \
				inits_bonus.c \
				utils_bonus.c \

OBJS_MANDATORY = $(addprefix $(PATH_M), $(MANDATORY:.c=.o))
OBJS_BONUS = $(addprefix $(PATH_B), $(BONUS:.c=.o))

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

all: $(NAME)

bonus: $(NAME_BONUS)

$(NAME): ${OBJS_MANDATORY}
ifeq ($(UNAME_S),Linux)
	@make -C $(LIBRARY_PATH)
	@make -C ./libft
else
	@make -C ./libft
endif
	@cc ${OBJS_MANDATORY} ${LIBS} ${CFLAG} -o ${NAME} ${HEADER}
	@printf "\033[0;32m$(NAME) succesfully created🌀🌌🌀.\033[0m\n"

$(NAME_BONUS): ${OBJS_BONUS}
ifeq ($(UNAME_S),Linux)
	@make -C $(LIBRARY_PATH)
	@make -C ./libft
else
	@make -C ./libft
endif
	@cc ${OBJS_BONUS} ${LIBS} ${CFLAG} -o ${NAME_BONUS} ${HEADER}
	@printf "\033[0;32m$(NAME_BONUS) succesfully created🌀🌌🌀.\033[0m\n"

%.o: %.c
	@cc -Wall -Wextra -Werror -c $< -o $@ ${HEADER}

clean:
ifeq ($(UNAME_S),Linux)
	@make clean -C $(LIBRARY_PATH)
	@rm -f ${OBJS_MANDATORY} ${OBJS_BONUS}
	@make clean -C ./libft
else
	@rm -f ${OBJS_MANDATORY} ${OBJS_BONUS}
	@make clean -C ./libft
endif


fclean: clean
	@rm -f ${NAME}
	@rm -f ${NAME_BONUS}
	@rm -f ${LIBS}
	@printf "\033[0;31m Succesfully Cleaned.\033[0m\n"

re: fclean all

.PHONY: all bonus clean fclean re dependencies
