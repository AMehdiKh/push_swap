NAME = libft.a

CC = gcc

CFLAGS = -Wall -Wextra -Werror

SRCS = \
	ft_isdigit.c ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c ft_strlcpy.c ft_strncmp.c ft_calloc.c \
	ft_split.c ft_putendl_fd.c ./get_next_line/get_next_line.c ./get_next_line/get_next_line_utils.c

OBJS = ${SRCS:.c=.o}

.PHONY: clean
all: $(NAME)

$(NAME): $(OBJS)
	$(AR) rcs $@ $?

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all