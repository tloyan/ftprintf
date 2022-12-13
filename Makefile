# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tloyan <tloyan@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/06 14:08:40 by thloyan           #+#    #+#              #
#    Updated: 2022/12/12 22:51:09 by tloyan           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

################################################################################
#                                                                              #
#                                   VARIABLES                                  #
#                                                                              #
################################################################################

NAME = libftprintf.a

INCLUDES = includes

LIBFT_PATH = libft
LIBFT_INCLUDES = $(LIBFT_PATH)/includes

CC = cc
CFLAGS = -Wall -Wextra -Werror -g

OBJDIR = objs
SRCDIR = srcs

SRCS = ft_printf.c ft_printf_utils.c
OBJS = $(addprefix $(OBJDIR)/, $(SRCS:.c=.o))


################################################################################
#                                                                              #
#                                   RULES                                      #
#                                                                              #
################################################################################

all: $(NAME)

$(NAME): $(LIBFT_PATH)/libft.a $(OBJDIR) $(OBJS)
	mv $(LIBFT_PATH)/libft.a $(NAME)
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)

$(OBJDIR):
	mkdir $(OBJDIR)

$(LIBFT_PATH)/libft.a:
	make -C $(LIBFT_PATH) all

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@ -I${INCLUDES} -I$(LIBFT_INCLUDES)

clean:
	rm -f $(OBJS)
	rmdir $(OBJDIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

test:
	cc main.c -g -L. -lftprintf -Iincludes

.PHONY: all clean fclean re