CFLAGS = -Wall -Wextra -Werror
NAME = libftprintf.a
LIBFTDIR = ./libft
LIBFTNAME = libft.a
SRCS_FILES = ft_m_printf \
	   		 ft_m_put_uint \
	   		 ft_m_putchar \
	   		 ft_m_puthex \
	   		 ft_m_putnbr \
	   		 ft_m_putpointer \
	   		 ft_m_putstr \

SRCS_DIR = mandatory/
SRCS = $(addprefix $(SRCS_DIR), $(addsuffix .c, $(SRCS_FILES)))
OBJS = $(SRCS:.c=.o)

all: $(NAME)

makelibft:
	@make -C $(LIBFTDIR)
	@cp $(LIBFTDIR)/$(LIBFTNAME) .
	@mv $(LIBFTNAME) $(NAME)

$(NAME): makelibft $(OBJS)
	@ar rcs $@ $(OBJS)

clean:
	@rm -f $(OBJS) $(LIBFT_OBJS)
	@cd $(LIBFTDIR) && make clean

fclean: clean
	@rm -f $(NAME)
	@cd $(LIBFTDIR) && make fclean

re: fclean $(NAME)

.PHONY: all clean fclean re
