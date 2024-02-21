# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: ohendrix <ohendrix@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2024/01/12 16:42:13 by ohendrix      #+#    #+#                  #
#    Updated: 2024/02/13 13:18:11 by ohendrix      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
BONUS_NAME = checker

SRC_DIR = ./mandatory
BONUS_DIR = ./bonus
SOURCES = \
$(SRC_DIR)/main.c \
$(SRC_DIR)/operations.c \
$(SRC_DIR)/commands.c \
$(SRC_DIR)/commands2.c \
$(SRC_DIR)/commands3.c \
$(SRC_DIR)/initialize_stack.c \
$(SRC_DIR)/add_index.c \
$(SRC_DIR)/free.c \
$(SRC_DIR)/sort.c \

SOURCES_BONUS = \
$(BONUS_DIR)/bonus_main.c \
$(BONUS_DIR)/bonus_operations.c \
$(BONUS_DIR)/bonus_initialize_stack.c \
$(BONUS_DIR)/bonus_free.c \
$(BONUS_DIR)/bonus_commands.c \
$(BONUS_DIR)/bonus_commands2.c \
$(BONUS_DIR)/bonus_commands3.c \
$(BONUS_DIR)/get_next_line.c \
$(BONUS_DIR)/get_next_line_utils.c \

OBJS_MAND = $(SOURCES:.c=.o)
OBJS_BONUS = $(SOURCES_BONUS:.c=.o)

CFLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(OBJS_MAND)
	make -C Libft/ all
	cc $(CFLAGS) $(SOURCES) Libft/libft.a -o $(NAME) 

bonus: $(OBJS_BONUS)
	make -C Libft/ all
	cc $(CFLAGS) $(SOURCES_BONUS) Libft/libft.a -o $(BONUS_NAME) 

clean:
		rm -f $(OBJS_MAND) $(OBJS_BONUS)
		make -C Libft/ clean

fclean: clean
		rm -f $(NAME) $(BONUS_NAME)
		make -C Libft/ fclean

re: fclean all

.PHONY: all, bonus, clean, fclean, re,