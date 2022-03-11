# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jkong <jkong@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/07 18:17:01 by jkong             #+#    #+#              #
#    Updated: 2022/03/11 12:35:00 by jkong            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all clean fclean re

CC = gcc
CFLAGS = -I. -Wall -Wextra -Werror
RM = rm -f
AR = ar
ARFLAGS = crs

TARGET = libft.a
INCS = libft.h
SRCS = ft__io.c ft__string.c ft__string_split.c ft_ctype_testchar.c ft_string.c ft_string_compare.c ft_string_find.c ft__stdlib.c ft__string_function.c ft_ctype_letterconv.c ft_stdlib.c ft_string_bsd.c ft_string_duplicate.c
OBJS = $(SRCS:.c=.o)

all: $(TARGET)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(TARGET)

re: fclean all

%.o: %.c
	$(CC) -c $(CFLAGS) $< -o $@

$(TARGET): $(OBJS)
	$(AR) $(ARFLAGS) $@ $?

$(OBJS): $(INCS)
