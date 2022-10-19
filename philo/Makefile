# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aball <aball@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/05 21:53:44 by baller            #+#    #+#              #
#    Updated: 2022/10/08 18:06:43 by aball            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

FILES = ft_atoi.c parsing.c check.c init.c main.c routine.c create.c \
		sleep.c

SCRS = $(addprefix srcs/, ${FILES})

OBJS = ${SCRS:c=o}

CFLAGS = -g -Wall -Wextra -Werror

CC = gcc

RM = rm -fr

all: $(NAME)

$(NAME): ${OBJS}
	${CC} ${CFLAGS} -lpthread $^ -o $@

%.o: %.c
	${CC} ${CFLAGS} -c $< -o ${<:c=o}

clean:
	${RM} ${OBJS}

fclean: clean
	${RM} $(NAME)

re: fclean all

.PHONY: all clean fclean re
