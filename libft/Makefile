# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: atoof <atoof@student.hive.fi>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/31 13:20:08 by atoof             #+#    #+#              #
#    Updated: 2023/03/06 12:10:20 by atoof            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
HEADER = libft.h
FLAG = -Wall -Wextra -Werror
SRC = ft_strlcat.c ft_strlen.c ft_bzero.c ft_isalnum.c ft_isalpha.c ft_strclr.c get_next_line_2.c \
		ft_isascii.c ft_printf.c ft_isdigit.c ft_tolower.c ft_isprint.c ft_memcpy.c ft_strnew.c\
		ft_memmove.c ft_memset.c ft_toupper.c ft_strlcpy.c ft_memchr.c ft_convert_number.c get_line.c\
		ft_memcmp.c ft_strchr.c ft_strrchr.c ft_atoi.c ft_strncmp.c ft_putchar.c ft_putstr.c \
		ft_strnstr.c ft_calloc.c ft_strdup.c ft_substr.c ft_putchar_fd.c get_next_line.c ft_strdel.c\
		ft_putstr_fd.c ft_putnbr_fd.c ft_strjoin.c ft_putendl_fd.c ft_strcat.c \
		ft_striteri.c ft_strmapi.c ft_itoa.c ft_strtrim.c ft_split.c
SRC_B = ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c \
		ft_lstlast_bonus.c ft_lstadd_back_bonus.c ft_lstdelone_bonus.c \
		ft_lstclear_bonus.c ft_lstiter_bonus.c ft_lstmap_bonus.c get_next_line_bonus.c

all: $(NAME)
	@echo "\033[1;32m[✔] Successfully compiled libft.a!\033[0m"

$(NAME):
	@cc $(FLAG) -c $(SRC)
	@ar rcs $(NAME) $(SRC:.c=.o)
	@echo "\033[1;34m[✨] Creating libft.a...\033[0m"

bonus: $(SRC_B:.c=.o)
	@echo "\033[1;33m[⭐] Compiling bonus functions...\033[0m"

$(SRC_B:.c=.o): $(SRC_B)	
	@cc $(FLAGS) -c $(SRC_B) -I $(HEADER)
	@ar rcs $(NAME) $(SRC_B:.c=.o)

clean:
	@/bin/rm -f $(SRC:.c=.o) $(SRC_B:.c=.o)
	@echo "\033[1;35m[🧹] Cleaning object files...\033[0m"

fclean: clean
	@/bin/rm -f $(NAME)
	@echo "\033[1;35m[🧹] Cleaning libft.a...\033[0m"

re: fclean all
