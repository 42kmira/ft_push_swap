# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kmira <kmira@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/12/02 16:28:59 by marvin            #+#    #+#              #
#    Updated: 2020/01/18 13:47:14 by kmira            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME1 = checker
NAME2 = push_swap

FLAGS = -Wall -Wextra -Werror
INCLUDES = -I includes/
LIBRARY = srcs/libft/libft.a

COMMON_SRCS = \
		common \
		debug \
		move_interface \
		operations \
		stack_ops \

CHK_SRCS = \
		input_checker_stack \
		input_checker_operations \
		main \

PUSH_SWAP_SRCS = \
		main \

COMMON_FILES = \
	$(addprefix srcs/, $(COMMON_SRCS))

CHK_FILES = \
	$(addprefix srcs/, $(addprefix src_checker/, $(CHK_SRCS)))

PUSH_SWAP_FILES = \
	$(addprefix srcs/, $(addprefix src_push_swap/, $(PUSH_SWAP_SRCS)))

COMMON_C_FILES = $(addsuffix .c, $(COMMON_FILES))
CHK_C_FILES = $(addsuffix .c, $(CHK_FILES))
PUSH_SWAP_C_FILES = $(addsuffix .c, $(PUSH_SWAP_FILES))

COMMON_OBJS = $(addsuffix .o, $(COMMON_SRCS))
CHK_OBJS = $(addsuffix .o, $(CHK_SRCS))
PUSH_SWAP_OBJS = $(addsuffix .o, $(PUSH_SWAP_SRCS))


all: $(LIBRARY) common $(NAME1) $(NAME2)

$(LIBRARY):
	make -C srcs/libft/

common:
	@gcc -c $(FLAGS) $(INCLUDES) $(COMMON_C_FILES)

$(NAME1):
	@gcc -c $(FLAGS) $(INCLUDES) $(CHK_C_FILES)
	@gcc -o $(NAME1) $(FLAGS) $(INCLUDES) $(LIBRARY) $(COMMON_OBJS) $(CHK_OBJS)

$(NAME2):
	@gcc -c $(FLAGS) $(INCLUDES) $(PUSH_SWAP_C_FILES)
	@gcc -o $(NAME2) $(FLAGS) $(INCLUDES) $(LIBRARY) $(COMMON_OBJS) $(PUSH_SWAP_OBJS)

.PHONY: clean fclean re common all

clean:
	@rm -f $(COMMON_OBJS)
	@rm -f $(CHK_OBJS)
	@rm -f $(PUSH_SWAP_OBJS)
	make clean -C srcs/libft/


fclean: clean
	@rm -rf $(NAME1)
	@rm -rf $(NAME2)
# make fclean -C srcs/libft/

re: fclean all

quick: re
	@make clean

test:
	@rm -f $(NAME1)
	@rm -f $(NAME2)
	@make all
	@make clean
	@clear
