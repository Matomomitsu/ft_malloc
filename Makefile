# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mtomomit <mtomomit@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/10 19:56:18 by mtomomit          #+#    #+#              #
#    Updated: 2024/05/08 21:59:46 by mtomomit         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME				=	libft_malloc
HOSTTYPE			?=	$(shell uname -m)_$(shell uname -s)

LFT					=	./libft/libft.a
LFTDIR				=	./libft/
SRCDIR				=	src/
OBJDIR				=	obj/
INCDIR				=	inc/

BIN					=	bin/malloc
REQUIRED_DIRS		=	$(OBJDIR) bin/

CFLAGS				=	-Wall -Werror -Wextra -fPIC
CFLAGS				+=	-g -I $(LFTDIR) -I $(INCDIR)
CC 					= 	gcc -O3
FILES				=	main.c
SRC					=	$(addprefix $(SRCDIR), $(FILES))
OBJ					=	$(addprefix $(OBJDIR), $(FILES:.c=.o))

COLOR_WHITE			=	\e[00m
COLOR_GREEN			=	\e[32m
COLOR_RED			=	\e[91m
COLOR_YELLOW		=	\e[033m
COLOR_BLUE			=	\e[34m

NUMBER_SRC_FILES	=	$(words $(SRC))
PROGRESS			=	0

all: $(NAME)_$(HOSTTYPE).so

$(REQUIRED_DIRS):
	@mkdir -p $@

$(OBJDIR)%.o: $(SRCDIR)%.c
	@echo -e "$(COLOR_YELLOW)Compiling $(NAME) $(COLOR_WHITE)$$(( \
	$(PROGRESS) * 100 / $(NUMBER_SRC_FILES)))%\r"
	$(eval PROGRESS=$(shell echo $$(($(PROGRESS)+1))))
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME)_$(HOSTTYPE).so: $(LFT) $(REQUIRED_DIRS) $(OBJ)
	$(CC) $(OBJ) -shared -fPIC  -L./libft -lft -o $@
	ln -sf $(NAME)_$(HOSTTYPE).so $(NAME).so
	@echo -e "$(COLOR_GREEN)$(NAME) has compiled succesfully$(COLOR_WHITE)"

$(LFT):
	make -C $(LFTDIR)

clean:
	@echo -e "$(COLOR_BLUE)Removing all objects$(COLOR_WHITE)"
	rm -rf $(OBJDIR)
	make -C $(LFTDIR) clean

fclean: clean
	@echo -e "$(COLOR_BLUE)Removing $(NAME)$(COLOR_WHITE)"
	rm -rf $(BIN)
	rm -rf bin/
	rm -rf $(LFT)
	rm -rf $(NAME)_$(HOSTTYPE).so
	rm -rf $(NAME).so

re: fclean all

norm:
	@clear
	@norminette ${SRC} ${INCDIR}* | grep Error || true

.PHONY: all clean fclean re norm
#export LD_LIBRARY_PATH=.:$LD_LIBRARY_PATH
#LD_PRELOAD=./libft_malloc.so ./teste to test the malloc
