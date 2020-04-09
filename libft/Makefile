# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: conrodri <conrodri@student.le-101.fr>      +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2018/10/09 15:24:03 by conrodri     #+#   ##    ##    #+#        #
#    Updated: 2018/10/23 18:21:32 by conrodri    ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

NAME = libft.a

FLAGS = -Wall -Wextra -Werror

SRC = ft_putchar.c\
	  ft_strlen.c\
	  ft_putstr.c\
	  ft_putnbr.c\
	  ft_strcpy.c\
	  ft_strncpy.c\
	  ft_strdup.c\
	  ft_memset.c\
	  ft_memcpy.c\
	  ft_bzero.c\
	  ft_memccpy.c\
	  ft_memcmp.c\
	  ft_strcat.c\
	  ft_strncat.c\
	  ft_strlcat.c\
	  ft_toupper.c\
	  ft_atoi.c\
	  ft_strstr.c\
	  ft_strnstr.c\
	  ft_memmove.c\
	  ft_strcmp.c\
	  ft_strncmp.c\
	  ft_memchr.c\
	  ft_memalloc.c\
	  ft_memdel.c\
	  ft_strnew.c\
	  ft_strdel.c\
	  ft_strclr.c\
	  ft_striter.c\
	  ft_striteri.c\
	  ft_strmap.c\
	  ft_strmapi.c\
	  ft_strequ.c\
	  ft_strnequ.c\
	  ft_strsub.c\
	  ft_strjoin.c\
	  ft_strtrim.c\
	  ft_itoa.c\
	  ft_strsplit.c\
	  ft_isalnum.c\
	  ft_isalpha.c\
	  ft_isascii.c\
	  ft_isdigit.c\
	  ft_isprint.c\
	  ft_tolower.c\
	  ft_strchr.c\
	  ft_strrchr.c\
	  ft_putendl.c\
	  ft_putchar_fd.c\
	  ft_putnbr_fd.c\
	  ft_putstr_fd.c\
	  ft_putendl_fd.c\
	  ft_countword.c\
	  ft_countletters.c\
	  ft_lstadd.c\
	  ft_lstdel.c\
	  ft_lstdelone.c\
	  ft_lstiter.c\
	  ft_lstmap.c\
	  ft_lstnew.c\
	  ft_strcapitalize.c\

OBJ = $(subst .c,.o,$(SRC))

LIGHT_RED = \033[0;38;5;9m

RED = \033[0;38;5;196m

BLUE = \033[0;38;5;123m

LIGHT_GREEN = \033[0;38;5;121m

GREEN = \033[33;32m

PURPLE = \033[33;35m

all: $(NAME)

$(NAME): $(OBJ)
	@ar rc $(NAME) $(OBJ)
	@echo "$(GREEN)Creation de la libft"
	@ranlib $(NAME)
	@echo "$(PURPLE)Indexation de la libft"

%.o: %.c
	@gcc $(FLAGS) -o $@ -c $<
	@echo "$(BLUE)Creation de $(LIGHT_GREEN)$@"

clean:
	@rm -rf $(OBJ)
	@echo "$(LIGHT_RED)Suppression des .o"

fclean: clean
	@rm -rf $(NAME)
	@echo "$(RED)Suppression de" $(NAME)

re: fclean all