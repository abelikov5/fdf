# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rmarni <rmarni@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/29 09:12:50 by rmarni            #+#    #+#              #
#    Updated: 2019/12/26 16:43:23 by rmarni           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	fdf

#						*****	OBJECT FILES	******
SRC 	= 	abs_swap.o \
			brzn_alg_line.o \
			color.o \
			draw_figure.o \
			fdf_initial.o \
			ft_exit.o \
			iso.o \
			key_press.o \
			main.o \
			menu.o \
			mouse_cntr.o \
			press_control.o \
			validate.o \
			arr_operation.o \
			validate_map.o \
			ft_move.o

		
SRCDIR		= 	$(addprefix ./sources/, $(SRC))
LIBDIR		=	./libft/
MLXDIR		=	./common_filles/minilibx_macos/
INCLUDES 	=	./includes/
INC_FLAG 	= 	$(addprefix -I, $(INCLUDES))

#						*****	COLLORS			*****
GREEN 		=	\033[0;32m
RED 		=	\033[0;31m 
YELLOW		=	\033[0;33m 
RESET 		= 	\033[0m


CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror -lmlx -framework OpenGL -framework AppKit

all: $(NAME)

%.o: %.c
				@echo "$(GREEN)$(NAME): $(RESET) [Compilation:$(YELLOW) $@$(RESET)]"
				@$(CC) -o $@ -c $< $(INC_FLAG) #$(CFLAGS)

lib:
				@echo "$(NAME): creating LIBFT...$(GREEN)OK!$(RESET)"
				@make -C $(LIBDIR) 

mlx:	
				@echo "$(NAME): creating MLX...$(GREEN)OK!$(RESET)"
				@make -C $(MLXDIR)


$(NAME): mlx lib $(SRCDIR)
				$(CC) $(CFLAGS) $(SRCDIR) -o $(NAME) -L $(LIBDIR) -lft -L $(MLXDIR)
				@echo "$(NAME): creating $(NAME)...$(GREEN) OK!$(RESET)"



clean:
				@make -C $(LIBDIR) clean
				@make -C $(MLXDIR) clean
				@rm -rf $(SRCDIR)

fclean:
				@make -C $(LIBDIR) fclean
#				@make -C $(MLXDIR) fclean
				@rm -rf $(SRCDIR)
				@rm -rf $(NAME)
				@echo "$(NAME): delete all files...$(GREEN) OK!$(RESET)"

re: fclean all

.PHONY: re clean fclean all lib
