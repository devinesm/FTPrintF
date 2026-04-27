# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ipinto-m <ipinto-m@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/04/27 09:52:29 by ipinto-m          #+#    #+#              #
#    Updated: 2026/04/27 09:54:25 by ipinto-m         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
NAME        = libftprintf.a

CC          = cc
CFLAGS      = -Wall -Wextra -Werror

RM          = rm -f
AR          = ar rcs

LIBFT_DIR   = ./libft
LIBFT       = $(LIBFT_DIR)/libft.a

SRCS        = ft_printf.c \
              ft_print_chars.c \
              ft_print_numbers.c \
              ft_print_hex.c

OBJS        = $(SRCS:.c=.o)

all: $(NAME)

$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR)

$(NAME): $(LIBFT) $(OBJS)
	cp $(LIBFT) $(NAME)
	$(AR) $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@$(MAKE) clean -C $(LIBFT_DIR)
	$(RM) $(OBJS)

fclean: clean
	@$(MAKE) fclean -C $(LIBFT_DIR)
	$(RM) $(NAME)
	
re: fclean all

.PHONY: all clean fclean re
