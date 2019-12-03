# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marvin <marvin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/12/02 16:28:59 by marvin            #+#    #+#              #
#    Updated: 2019/12/02 16:28:59 by marvin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME1 = checker
NAME2 = push_swap

FLAGS = -Wall -Wextra -Werror
INCLUDES = -I includes/

COMMON_SRCS = \
		common \

CHK_SRCS = \
		main \

PUSH_SWAP_SRCS = \
		main \

COMMON_FILES = \
	$(addprefix srcs/, $(COMMON_SRCS))

CHK_FILES = \
	$(addprefix srcs/, $(addprefix checker/, $(CHK_SRCS)))

PUSH_SWAP_FILES = \
	$(addprefix srcs/, $(addprefix push_swap/, $(PUSH_SWAP_SRCS)))

COMMON_C_FILES = $(addsuffix .c, $(COMMON_FILES))
CHK_C_FILES = $(addsuffix .c, $(CHK_FILES))
PUSH_SWAP_C_FILES = $(addsuffix .c, $(PUSH_SWAP_FILES))

COMMON_OBJS = $(addsuffix .o, $(COMMON_FILES))
CHK_OBJS = $(addsuffix .o, $(CHK_FILES))
PUSH_SWAP_OBJS = $(addsuffix .o, $(PUSH_SWAP_FILES))


all: common $(NAME1) $(NAME2)

common:
	gcc -c $(FLAGS) $(INCLUDES) $(COMMON_C_FILES)

$(NAME1):
	gcc -c $(FLAGS) $(INCLUDES) $(CHK_C_FILES)
	gcc -o $(NAME1) $(FLAGS) $(INCLUDES) $(COMMON_OBJS) $(CHK_OBJS)

$(NAME2):
	gcc -c $(FLAGS) $(INCLUDES) $(PUSH_SWAP_C_FILES)
	gcc -o $(NAME2) $(FLAGS) $(INCLUDES) $(COMMON_OBJS) $(PUSH_SWAP_OBJS)
