# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbico <mbico@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/01 15:23:49 by fparis            #+#    #+#              #
#    Updated: 2024/11/30 12:17:48 by mbico            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -g #-Wall -Wextra -Werror
NAME = cub_vst
HEADER = hdr

SRC_DIR = src
OBJ_DIR = obj

SRCS = main.c\
	   alloc_stream.c\
	   play_sound.c\
	   stream_lst/ft_streamnew.c\
	   

OBJS = $(SRCS:%.c=$(OBJ_DIR)/%.o)

RED = \033[0;31m
GREEN = \033[0;34m
YELLOW = \033[1;33m
PURPLE = \033[0;35m
NC = \033[0m

LIBFT = libft/libft.a
AUDIO_LIB = -I./hdr/include ./hdr/libmpg123.so ./hdr/libportaudio.a 

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	@$(CC) $(CFLAGS) $^ -o $(NAME) $(LIBFT) -I $(HEADER) $(AUDIO_LIB) -lpthread -lm -lasound 
	@echo "$(GREEN)$(NAME) compilation successful !$(NC)"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(@D)
	@echo "$(YELLOW)Compiling $(notdir $<)...$(NC)"
	@$(CC) $(CFLAGS) -c $< -o $@ -I $(HEADER) $(AUDIO_LIB)  -I ./libft

$(LIBFT):
	@echo "$(PURPLE)Compiling libft...$(NC)"
	@make -C libft -j -s

clean:
	@echo "$(RED)Removing object...$(NC)"
	@rm -rf $(OBJ_DIR)
	@echo "$(RED)Removing libft object...$(NC)"
	@make -C libft clean -s

fclean: clean
	@echo "$(RED)Removing $(NAME)...$(NC)"
	@rm -f $(NAME)
	@echo "$(RED)Removing libft.a...$(NC)"
	@make -C libft fclean -s
	
re: fclean all

.PHONY: all clean fclean re run
