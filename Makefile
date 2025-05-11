# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jyoo <jyoo@student.42gyeongsan.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/11 22:58:46 by jyoo              #+#    #+#              #
#    Updated: 2025/05/12 01:03:04 by jyoo             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror -g

LIBFT_DIR	:= libft
LIBFT		:= $(LIBFT_DIR)/libft.a

INCLUDES	:= -Iincludes -I$(LIBFT_DIR)

SRC_DIRS	:= src

SRCS		:= algo.c algo3.c algo5.c make_order.c ps_func.c push_swap.c \
			sort_func_r.c sort_func_rr.c sort_func_s.c sort_func_pa.c \
			sort_func_pb.c

OBJ_DIR	:= obj
OBJS := $(addprefix $(OBJ_DIR)/,$(SRCS:%.c=%.o))

vpath %.c $(SRC_DIRS)

NAME = push_swap

all: $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(SYSLIB_FLG) -o $@

$(OBJ_DIR)/%.o: %.c | check_dir
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

check_dir:
	@mkdir -p $(OBJ_DIR)

clean:
	rm -rf $(OBJ_DIR)
	$(MAKE) clean -C $(LIBFT_DIR)

fclean: clean
	$(MAKE) fclean -C $(LIBFT_DIR)
	rm -f $(NAME)
re:
	make fclean
	make all

.PHONY: all clean fclean re bonus check_dir
