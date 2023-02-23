NAME = push_swap

CC = gcc

CFLAGS = -Wall -Wextra -MMD -fsanitize=address

M_DIR = Man

SRCS = main.c check_args.c rules_1.c rules_2.c

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