# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thloyan <thloyan@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/06 14:08:40 by thloyan           #+#    #+#              #
#    Updated: 2022/12/18 12:25:42 by thloyan          ###   ########.fr        #
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

SRCS = ft_printf.c ft_parser_utils.c ft_parser.c ft_print_char.c \
	ft_print_hex.c ft_print_nbr.c ft_print_str.c ft_printf_utils.c ft_print_ptr.c
OBJS = $(addprefix $(OBJDIR)/, $(SRCS:.c=.o))


################################################################################
#                                                                              #
#                                   RULES                                      #
#                                                                              #
################################################################################

all: $(NAME)

$(NAME): $(LIBFT_PATH) $(OBJDIR) $(OBJS)
	mv $(LIBFT_PATH)/libft.a $(NAME)
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)

$(OBJDIR):
	mkdir $(OBJDIR)

$(LIBFT_PATH):
	make -C $(LIBFT_PATH) all

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@ -I${INCLUDES} -I$(LIBFT_INCLUDES)

clean: libft_clean
	rm -f $(OBJS)
	rm -rf $(OBJDIR)

fclean: clean libft_fclean
	rm -f $(NAME)

re: fclean all

libft_clean:
	make -C $(LIBFT_PATH) clean

libft_fclean:
	make -C $(LIBFT_PATH) fclean

.PHONY: all clean fclean re $(LIBFT_PATH) libft_clean libft_fclean