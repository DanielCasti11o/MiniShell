# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dacastil <dacastil@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/18 10:53:25 by dacastil          #+#    #+#              #
#    Updated: 2025/03/28 03:38:03 by dacastil         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

EXEC = libpipex.a
AR = ar rcs
CC = cc
RM = rm -f
FLAGS = -Wall -Wextra -Werror -g3 -I./pipex/libft_bonus -L./pipex/libft_bonus -I ./include
SRC_DIR = ./src
INCLUDE_DIR = ./pipex.h
LIBFT_DIR = ./libft_bonus
LIBFT = $(LIBFT_DIR)/libft.a
SRC =$(SRC_DIR)/pipex.c $(SRC_DIR)/process.c $(SRC_DIR)/utils.c
OBJS = $(SRC:.c=.o)
RED             = \033[1;31m
YELLOW          = \033[1;33m
BLUE            = \033[1;34m
WHITE			= \033[0;97m

all: $(LIBFT) $(EXEC)

	@echo "$(YELLOW)                                             Co.                "
	@echo "$(YELLOW)                                            lomb                "
	@echo "$(YELLOW)                                        _iaC/                    "
	@echo "$(YELLOW)                                   olombiaC'                    "
	@echo "$(YELLOW)                               olombiaColo                    "
	@echo "$(YELLOW)                             mbiaColombi                    "
	@echo "$(YELLOW)                            aColombiaCol                    "
	@echo "$(YELLOW)                           _lombiaColom                    "
	@echo "$(YELLOW)                          biaColombiaCo-                    "
	@echo "$(YELLOW)                    ,, _-lombiaColombiaCo                    "
	@echo "$(YELLOW)                     l,lombiaColombiaColom                    "
	@echo "$(YELLOW)                     .biaColombiaColombia,                    "
	@echo "$(YELLOW)                   ,ColombiaColombiaColom.                    "
	@echo "$(YELLOW)                   biaColombiaColombiaColom                    "
	@echo "$(YELLOW)                    biaColombiaColombiaColombiaColo.                    "
	@echo "$(YELLOW)                     mbiaColombiaColombiaColombiaColo\                        "
	@echo "$(YELLOW)                     'mbiaColombiaColombiaColombiaColombiaComb'                    "
	@echo "$(BLUE)                      iaColombiaColombiaColombiaColombiaColomb                    "
	@echo "$(BLUE)                       iaColombiaColombiaColombiaColombiaColomb                    "
	@echo "$(BLUE)                       iaColombiaColombiaColombiaColombiaColo                    "
	@echo "$(BLUE)                      ,mbiaColombiaColombiaColombiaColombiaColo                    "
	@echo "$(BLUE)                       '-mbiaColombiaColombiaColombiaColombiaCo,                    "
	@echo "$(BLUE)                       /lombiaColombiaColombiaColombiaColombiaCo-                    "
	@echo "$(BLUE)                     ,/lombiaColombiaColombiaColombiaColombiaCol'                    "
	@echo "$(BLUE)                  _..ombiaColombiaColombiaColombiaColombiaColom\.                    "
	@echo "$(BLUE)                  biaColombiaColombiaColombiaColombiaColombiaColo,                    "
	@echo "$(BLUE)                .^.mbiaColombiaColombiaColombiaColombiaColomb'i'':                    "
	@echo "$(BLUE)                'aColombiaColombiaColombiaColombiaColo|          :                    "
	@echo "$(BLUE)                  'mbiaColombiaColombiaColombiaColombia..                            "
	@echo "$(BLUE)                    ColombiaColombiaColombiaColombiaC^^''                    "
	@echo "$(RED)                      '::'':olombiaColombiaColombiaC                    "
	@echo "$(RED)                              '--olombiaColombiaColomb                    "
	@echo "$(RED)                                   'iaColombiaColombiaCol                    "
	@echo "$(RED)                                    'ombiaColombiaColombi,                    "
	@echo "$(RED)                                      '-aColombiaColombia,                    "
	@echo "$(RED)                                        '-ColombiaColombi                    "
	@echo "$(RED)                                          aColombiaColomb                    "
	@echo "$(RED)                                           \!!!!  !  !aC,                    "
	@echo "$(RED)                                                       /o.         dacastil                    "
	@echo "$(RED)                                                      /lo                    "
	@echo "$(RED)                                                     /.mb                    "
	@echo "$(RED)                                                       !.                    "

$(LIBFT):
	@ $(MAKE) -C $(LIBFT_DIR) bonus > /dev/null 2>&1

$(EXEC): $(OBJS) $(LIBFT)
	@ $(AR) $(EXEC) $(LIBFT) $(OBJS) > /dev/null 2>&1

%.o: %.c
	@ $(CC) $(FLAGS) -c $< -o $@ > /dev/null 2>&1

clean:
	@ echo "$(RED) Deleting objects..."
	@ $(RM) $(OBJS) > /dev/null 2>&1
	@ $(MAKE) -C $(LIBFT_DIR) clean > /dev/null 2>&1

fclean:
	@ echo "$(RED) Deleting all..."
	@ $(RM) $(OBJS) $(EXEC) > /dev/null 2>&1
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
