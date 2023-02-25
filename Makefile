NAME = push_swap

B_NAME = checker
##################################################################################
CC = gcc

CFLAGS = -Wall -Wextra -MMD -fsanitize=address
##################################################################################
M_DIR = Mandatory

SRCS = push_swap.c

OBJS = ${SRCS:%.c=$(M_DIR)/%.o}

M_DEP = ${OBJS:.o=.d}
#################################################################################
S_DIR = Shared

SHARE = check_args.c rules_1.c rules_2.c utils.c

SOBJS = ${SHARE:%.c=$(S_DIR)/%.o}

S_DEP = ${SOBJS:.o=.d}
#################################################################################
B_DIR = Bonus

BSRCS = checker.c

BOBJS = ${BSRCS:%.c=$(B_DIR)/%.o}

B_DEP = ${BOBJS:.o=.d}
#################################################################################
LIBFT = ./LibFT/libft.a
#################################################################################
.PHONY: clean
all: $(NAME)

$(NAME): $(LIBFT) $(OBJS) $(SOBJS)
	@$(CC) $(OBJS) $(SOBJS) $(LIBFT) -fsanitize=address -static-libsan -o $@

bonus: $(B_NAME)

$(B_NAME): $(LIBFT) $(BOBJS) $(SOBJS)
	@$(CC) $(BOBJS) $(SOBJS) $(LIBFT) -fsanitize=address -static-libsan -o $@

$(LIBFT):
	@$(MAKE) -C LibFT

sinclude $(M_DEP) $(B_DEP) $(S_DEP)
clean:
	@$(MAKE) fclean -C LibFT
	@$(RM) $(OBJS) $(BOBJS) $(SOBJS)
	@$(RM) $(M_DEP) $(B_DEP) $(S_DEP)

fclean: clean
	@$(RM) $(NAME) $(B_NAME)

re: fclean all