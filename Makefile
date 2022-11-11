# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jkong <jkong@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/07 18:17:01 by jkong             #+#    #+#              #
#    Updated: 2022/07/04 13:41:43 by jkong            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all clean fclean re bonus

CC = gcc
CFLAGS = -I. -Wall -Wextra -Werror
RM = rm -f
AR = ar
ARFLAGS = crs

NAME = libft.a
INCS = libft.h
SRCS = ft__io.c ft__string.c ft__string_split.c ft_ctype_testchar.c ft_string.c ft_string_compare.c ft_string_find.c ft__stdlib.c ft__string_function.c ft_ctype_letterconv.c ft_stdlib.c ft_string_bsd.c ft_string_duplicate.c
SRCS_BONUS = ft__list.c ft__list_function.c ft__list_insert.c ft__list_remove.c
OBJS = $(SRCS:.c=.o)
OBJS_BONUS = $(SRCS_BONUS:.c=.o)

all: $(NAME)

clean:
	$(RM) $(OBJS)
	$(RM) $(OBJS_BONUS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

%.o: %.c
	$(CC) -c $(CFLAGS) $< -o $@

$(NAME): $(OBJS)
	$(AR) $(ARFLAGS) $@ $?

bonus: $(OBJS_BONUS)
	$(AR) $(ARFLAGS) $(NAME) $?

$(OBJS): $(INCS)

$(OBJS_BONUS): $(INCS)
