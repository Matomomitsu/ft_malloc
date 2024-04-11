# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mtomomit <mtomomit@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/10 19:56:18 by mtomomit          #+#    #+#              #
#    Updated: 2024/04/10 22:14:30 by mtomomit         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME				=	libft_malloc

LFT					=	./libft/libft.a
LFTDIR				=	./libft/
SRCDIR				=	src/
OBJDIR				=	obj/
INCDIR				=	inc/

BIN					=	bin/malloc
REQUIRED_DIRS		=	$(OBJDIR) bin/

CFLAGS				=	-Wall -Werror -Wextra -fPIC
CFLAGS				+=	-g -I $(LFTDIR) -I $(INCDIR)
CC 					= 	cc -O3
CC                  +=  -mno-vzeroupper -funroll-loops -flto -finline-functions
FILES				=	main.c \
						teste.c
SRC					=	$(addprefix $(SRCDIR), $(FILES))
OBJ					=	$(addprefix $(OBJDIR), $(FILES:.c=.o))

COLOR_WHITE			=	\e[00m
COLOR_GREEN			=	\e[32m
COLOR_RED			=	\e[91m
COLOR_YELLOW		=	\e[033m
COLOR_BLUE			=	\e[34m

NUMBER_SRC_FILES	=	$(words $(SRC))
PROGRESS			=	0

ifeq ($(HOSTTYPE),"")
	HOSTTYPE := $(shell uname -m)_$(shell uname -s)
endif

all: $(NAME)_$(HOSTTYPE).so

$(REQUIRED_DIRS):
	@mkdir -p $@

$(OBJDIR)%.o: $(SRCDIR)%.c
	@echo -n "$(COLOR_YELLOW)Compiling $(NAME) $(COLOR_WHITE)$$(( \
	$(PROGRESS) * 100 / $(NUMBER_SRC_FILES)))%\r"
	$(eval PROGRESS=$(shell echo $$(($(PROGRESS)+1))))
	@$(CC) $(CFLAGS) -c -fPIC $< -o $@

$(NAME)_$(HOSTTYPE).so: $(LFT) $(REQUIRED_DIRS) $(OBJ)
	$(CC) $(OBJ) -shared -o $(NAME)_$(HOSTTYPE).so -L./libft -lft
	ln -sf $(NAME)_$(HOSTTYPE).so $(NAME).so
	@echo "$(COLOR_GREEN)$(NAME) has compiled succesfully$(COLOR_WHITE)"

$(OBJ_DIR):
	mkdir -p $@

$(LFT):
	make -C $(LFTDIR)

clean:
	@echo "$(COLOR_BLUE)Removing all objects$(COLOR_WHITE)"
	rm -rf $(OBJDIR)
	cd $(LFTDIR) && make clean

fclean: clean
	@echo "$(COLOR_BLUE)Removing $(NAME)$(COLOR_WHITE)"
	rm -rf $(NAME)
	rm -rf $(BIN)
	rm -rf bin/
	rm -rf $(LFT)
	rm -rf $(NAME)_$(HOSTTYPE).so

re: fclean all

norm:
	@clear
	@norminette ${SRC} ${INCDIR}* | grep Error || true

.PHONY: all clean fclean re norm
