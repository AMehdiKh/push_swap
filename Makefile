##################################################################################
NAME = push_swap

CHECKER = checker
##################################################################################
CC = gcc

CFLAGS = -Wall -Wextra -Werror -MMD
##################################################################################
M_DIR = Mandatory

SRCS = push_swap.c

OBJS = ${SRCS:%.c=$(M_DIR)/%.o}

M_DEP = ${OBJS:.o=.d}
#################################################################################
B_DIR = Bonus

BSRCS = checker.c

BOBJS = ${BSRCS:%.c=$(B_DIR)/%.o}

B_DEP = ${BOBJS:.o=.d}
#################################################################################
S_DIR = Shared

SHARE = check_args.c rules_1.c rules_2.c utils.c

SOBJS = ${SHARE:%.c=$(S_DIR)/%.o}

S_DEP = ${SOBJS:.o=.d}
#################################################################################
LIBFT = ./include/LibFT/libft.a
#################################################################################
.PHONY: clean
all: $(NAME)

$(NAME): $(LIBFT) $(OBJS) $(SOBJS)
	$(CC) $(OBJS) $(SOBJS) $(LIBFT) -o $@

bonus: $(CHECKER)

$(CHECKER): $(LIBFT) $(BOBJS) $(SOBJS)
	$(CC) $(BOBJS) $(SOBJS) $(LIBFT) -o $@

$(LIBFT):
	$(MAKE) -C include/LibFT

sinclude $(M_DEP) $(B_DEP) $(S_DEP)
clean:
	$(MAKE) fclean -C include/LibFT
	$(RM) $(OBJS) $(BOBJS) $(SOBJS)
	@$(RM) $(M_DEP) $(B_DEP) $(S_DEP)

fclean: clean
	$(RM) $(NAME) $(CHECKER)

re: fclean all