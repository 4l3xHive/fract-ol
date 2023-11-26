NAME 		=	fractol

MANDATORY	=	main.c \
				draw_funcs.c

BONUS		=	main_bonus.c set_fractal_bonus.c \
				errors_bonus.c events_bonus.c \
				render_fractal_bonus.c calc_fractal_bonus.c

PATH_M		=	./mandatory/
PATH_B		=	./bonus/

OBJS		=	$(addprefix $(PATH_M), $(MANDATORY:.c=.o))
OBJS_B		=	$(addprefix $(PATH_B), $(BONUS:.c=.o))

#Linux
#CFLAG		=	-lmlx -lX11 -lXext -Imlx -lm -Wall -Wextra -Werror
#Macos
CFLAG = -Wall -Wextra -Werror -lmlx -framework OpenGL -framework AppKit
MAKEFLAGS	=	--no-print-directory

HEADER		=	-I./includes

LIB 		=	./libftprintf/libftprintf.a

%.o:%.c ${HEADER}
	cc -Wall -Wextra -Werror -c $< -o $@ -I./includes

ifeq ($(wildcard $(OBJS_B)),)
all: libftprintf $(NAME)
else
all: 
endif

ifeq ($(wildcard $(OBJS)),)
bonus : libftprintf  ${OBJS_B}
	@make ${NAME} OBJS="${OBJS_B}"
else
bonus: fclean libftprintf ${OBJS_B}
	@make ${NAME} OBJS="${OBJS_B}"
endif

libftprintf:
	@make -C ./libftprintf

$(NAME) : ${LIB} ${OBJS}
	cc ${OBJS} ${LIB} ${CFLAG} -o ${NAME}

clean :
	rm -f ${OBJS} ${OBJS_B}
	$(MAKE) clean -C ./libftprintf

fclean : clean
	rm -f ${NAME}
	rm -f ${LIB}

re : fclean
	make

.PHONY:	all libftprintf clean fclean re
