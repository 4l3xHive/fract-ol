CFLAGS = -Wall -Wextra -Werror
NAME = libft.a
SRCS_FILES = ft_memset \
		ft_bzero \
		ft_memcpy \
		ft_memmove \
		ft_memchr \
		ft_memcmp \
		ft_strlen \
		ft_strlcpy \
		ft_strlcat \
		ft_strchr \
		ft_strrchr \
		ft_strnstr \
		ft_strncmp \
		ft_atoi \
		ft_isalpha \
		ft_isdigit \
		ft_isalnum \
		ft_isascii \
		ft_isprint \
		ft_toupper \
		ft_tolower \
		ft_calloc \
		ft_strdup \
		ft_substr \
		ft_strjoin \
		ft_strtrim \
		ft_split \
		ft_itoa \
		ft_strmapi \
		ft_striteri \
		ft_putchar_fd \
		ft_putstr_fd \
		ft_putendl_fd \
		ft_putnbr_fd \

BONUS_FILES = 	ft_lstnew \
	  		ft_lstadd_front \
	  		ft_lstsize \
	  		ft_lstlast \
	  		ft_lstadd_back \
	  		ft_lstdelone \
	  		ft_lstclear \
	  		ft_lstiter \
	  		ft_lstmap

SRCS_DIR = ./
SRCS = $(addprefix $(SRCS_DIR), $(addsuffix .c, $(SRCS_FILES)))
BONUS_SRCS = $(addprefix $(SRCS_DIR), $(addsuffix .c, $(BONUS_FILES)))

OBJS_DIR = ./
OBJS = $(addprefix $(OBJS_DIR), $(addsuffix .o, $(SRCS_FILES)))
BONUS_OBJ = $(addprefix $(OBJS_DIR), $(addsuffix .o, $(BONUS_FILES)))

all: $(NAME)

$(NAME): $(OBJS)
	@ar rcs $@ $^ 

%.o: %.c
	@gcc $(CFLAGS) -c $< -o $@

bonus: $(BONUS_OBJ)
	@ar rus $(NAME) $^

clean:
	@rm -f $(OBJS) $(BONUS_OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean $(NAME)

.PHONY: bonus all clean fclean re
