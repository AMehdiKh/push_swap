NAME = push_swap

CC = gcc

CFLAGS = -Wall -Wextra -Werror -MMD -fsanitize=address

M_DIR = Mandatory

SRCS = main.c linked_outils.c check_args.c

OBJS = ${SRCS:%.c=$(M_DIR)/%.o}

M_DEP = ${OBJS:.o=.d}

LIBFT = ./LibFT/libft.a

.PHONY: clean
all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	$(CC) $(OBJS) $(LIBFT) -fsanitize=address -static-libsan -o $@

$(LIBFT):
	$(MAKE) -C LibFT

sinclude $(M_DEP)
clean:
	$(MAKE) fclean -C LibFT
	$(RM) $(OBJS)
	@$(RM) $(M_DEP)

fclean: clean
	$(RM) $(NAME)

re: fclean all