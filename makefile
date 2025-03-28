# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dacastil <dacastil@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/27 14:17:12 by dacastil          #+#    #+#              #
#    Updated: 2025/03/28 15:56:47 by dacastil         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

EXEC = Minishell
CC = cc
CFLAGS = -g3 -I./include -I/pipex/libft_bonus
SRC_DIR = ./src
PIPEX_DIR = ./pipex
LIBFT = -L./pipex/libft_bonus -lft
INCLUDE_DIR = ./include
PIPEX = $(PIPEX_DIR)/libpipex.a
SRCS = $(wildcard $(SRC_DIR)/*.c)
INCLUDE = $(wildcard $(INCLUDE)/*.h)
RED             = \033[1;31m
YELLOW          = \033[1;33m
BLUE            = \033[1;34m
RESTART			= \033[0m
ARTS = art1 art2 art3 art3_5 art4_5 art4 art5 art6
OBJS = $(SRCS:.c=.o)

all: $(PIPEX) $(EXEC) # $(ARTS)

$(PIPEX):
	@$(MAKE) -C $(PIPEX_DIR) > /dev/null 2>&1

$(EXEC): $(OBJS) $(PIPEX)
	@$(CC) $(OBJS) -L$(PIPEX_DIR) -o $(EXEC) $(CFLAGS) $(LIBFT) -lpipex -lreadline -lncurses -L/usr/lib -I/usr/include/readline > /dev/null 2>&1

%.o: $(SRC_DIR)/%.c
	@$(CC) $(CFLAGS) -c $< -o $@ > /dev/null 2>&1

clean:
	@ echo "$(RED) Deleting objects..."
	@ $(RM) $(OBJS) > /dev/null 2>&1
	@$(MAKE) -C $(PIPEX_DIR) clean > /dev/null 2>&1

fclean:

	@clear
	@echo "$(RED) Deleting all..."

	@ $(RM) $(OBJS) $(EXEC) > /dev/null 2>&1
	@ $(MAKE) -C $(PIPEX_DIR) fclean > /dev/null 2>&1

	@echo "$(RED)       ▄   ▄"
	@echo "$(RED)       █▀█▀█"
	@echo "$(RED)       █▄█▄█"
	@echo "$(RED)        ███  ▄▄"
	@echo "$(RED)        ████▐█ █"
	@echo "$(RED)        ████   █"
	@echo "$(RED)        ▀▀▀▀▀▀▀"
	@echo "$(RED)   |$(RESTART)██        $(RED)|"
	@sleep 0.5
	@clear
	@echo "$(RED) Deleting all..."
	@echo "$(RED)       ▄   ▄"
	@echo "$(RED)       █▀█▀█"
	@echo "$(RED)       █▄█▄█"
	@echo "$(RED)        ███  ▄▄"
	@echo "$(RED)        ████▐█ █"
	@echo "$(RED)        ████   █"
	@echo "$(RED)        ▀▀▀▀▀▀▀"
	@echo "$(RED)   |$(RESTART)█████     $(RED)|"
	@sleep 0.5
	@clear
	@echo "$(RED) Deleting all..."
	@echo "$(RED)       ▄   ▄"
	@echo "$(RED)       █▀█▀█"
	@echo "$(RED)       █▄█▄█"
	@echo "$(RED)        ███  ▄▄"
	@echo "$(RED)        ████▐█ █"
	@echo "$(RED)        ████   █"
	@echo "$(RED)        ▀▀▀▀▀▀▀"
	@echo "$(RED)   |$(RESTART)████████  $(RED)|"
	@sleep 0.5
	@clear
	@echo "$(RED) Deleting all..."
	@echo "$(RED)       ▄   ▄"
	@echo "$(RED)       █▀█▀█"
	@echo "$(RED)       █▄█▄█"
	@echo "$(RED)        ███  ▄▄"
	@echo "$(RED)        ████▐█ █"
	@echo "$(RED)        ████   █"
	@echo "$(RED)        ▀▀▀▀▀▀▀"
	@echo "$(RED)   |██████████| OK!"
	@sleep 0.5

art1:

	@clear
	@echo "$(YELLOW)           X     ,MMMPP&&.            X                $(RESTART)"
	@echo "$(YELLOW)                MMMM88&&&&&    .                $(RESTART)"
	@echo "$(YELLOW)               MMMM88&&&&&&&                $(RESTART)"
	@echo "$(YELLOW)   *           MMM88&&&&&&&&                $(RESTART)"
	@echo "$(YELLOW)               MMM88&&&&&&&&                $(RESTART)"
	@echo "$(YELLOW)               'MMM88&&&&&&'                $(RESTART)"
	@echo "$(YELLOW)                 'MMM8&&&'      *                "
	@echo "$(BLUE)        |\___/|                $(RESTART)"
	@echo "$(BLUE)        )     (             .              '                $(RESTART)"
	@echo "$(BLUE)       =\     /=                "
	@echo "$(BLUE)         )===(       *                "
	@echo "$(BLUE)        /     \                "
	@echo "$(BLUE)        |     |                "
	@echo "$(BLUE)       /       \                "
	@echo "$(BLUE)       \       /                "
	@echo "$(RED)_/\_/\_/$(BLUE)\__  _/$(RED)_/\_/\_/\_/\_/\_/\_/\_/\_/\_                $(RESTART)"
	@echo "$(RED)|  |  |  |$(BLUE)( ( $(RED) |  |  |  |  |  |  |  |  |  |                "
	@echo "$(RED)|  |  |  |$(BLUE) ) )$(RED) |  |  |  |  |  |  |  |  |  |                "
	@echo "$(RED)|  |  |  |$(BLUE)(_( $(RED) |  |  |  |  |  |  |  |  |  |                "
	@echo "$(RED)|  |  |  |  |  |  |  |  |  |  |  |  |  |  |                "
	@echo "$(RED)jgs|  |  |  |  |  |  |  |  |  |  |  |  |  |                "
	@sleep 0.3

art2:

	@clear
	@echo "$(YELLOW)           *     ,MMM8&&&.            *          "
	@echo "$(YELLOW)                MMMM88&&&&&    .          "
	@echo "$(YELLOW)               MMMM88&&&&&&&          "
	@echo "$(YELLOW)   *           MMM88&&&&&&&&          "
	@echo "$(YELLOW)               MMM88&&&&&&&&          "
	@echo "$(YELLOW)               'MMM88&&&&&&'          "
	@echo "$(YELLOW)                 'MMM8&&&'      *          "
	@echo "$(BLUE)        |\___/|          "
	@echo "$(BLUE)       =) ^Y^ (=            .              '          "
	@echo "$(BLUE)        \  ^  /          "
	@echo "$(BLUE)         )=*=(       *          "
	@echo "$(BLUE)        /     \          "
	@echo "$(BLUE)        |     |          "
	@echo "$(BLUE)       /| | | |\          "
	@echo "$(BLUE)       \| | |_|/\          "
	@echo "$(RED)jgs_/\_$(BLUE)//_// ___/\$(RED)_/\_/\_/\_/\_/\_/\_/\_/\_          "
	@echo "$(RED)|  |  |  | $(BLUE)\_)$(RED) |  |  |  |  |  |  |  |  |  |          "
	@echo "$(RED)|  |  |  |  |  |  |  |  |  |  |  |  |  |  |          "
	@echo "$(RED)|  |  |  |  |  |  |  |  |  |  |  |  |  |  |          "
	@echo "$(RED)|  |  |  |  |  |  |  |  |  |  |  |  |  |  |          "
	@echo "$(RED)|  |  |  |  |  |  |  |  |  |  |  |  |  |  |          "
	@sleep 0.3

art3:

	@clear
	@echo "$(YELLOW)           *     ,MMM8&&&.            *             "
	@echo "$(YELLOW)                MMMM88&&&&&    .             "
	@echo "$(YELLOW)               MMMM88&&&&&&&             "
	@echo "$(YELLOW)   *           MMM88&&&&&&&&             "
	@echo "$(YELLOW)               MMM88&&&&&&&&             "
	@echo "$(YELLOW)               'MMM88&&&&&&'             "
	@echo "$(YELLOW)                 'MMM8&&&'      *                 "
	@echo "$(BLUE)        |\___/|                      \\             "
	@echo "$(BLUE)       =) ^Y^ (=   |\_/|              ||    '             "
	@echo "$(BLUE)        \  ^  /    )a a '._.-""""-.  //             "
	@echo "$(BLUE)         )=*=(    =\T_= /    ~  ~  \//             "
	@echo "$(BLUE)        /     \     '''\   ~   / ~  /             "
	@echo "$(BLUE)        |     |         |~   \ |  ~/             "
	@echo "$(BLUE)       /| | | |\         \  ~/- \ ~\             "
	@echo "$(BLUE)       \| | |_|/|        || |  // //            "
	@echo "$(RED)jgs_/\_$(BLUE)//_// __//$(RED)\_/\_/\_$(BLUE)((_|\((_//$(RED)\_/\_/\_             "
	@echo "$(RED)|  |  |  | $(BLUE)\_)$(RED) |  |  |  |  |  |  |  |  |  |             "
	@echo "$(RED)|  |  |  |  |  |  |  |  |  |  |  |  |  |  |             "
	@echo "$(RED)|  |  |  |  |  |  |  |  |  |  |  |  |  |  |             "
	@echo "$(RED)|  |  |  |  |  |  |  |  |  |  |  |  |  |  |             "
	@echo "$(RED)|  |  |  |  |  |  |  |  |  |  |  |  |  |  |             "
	@sleep 0.3

art3_5:

	@clear
	@echo "$(YELLOW)           *     ,MMM8&&&.            *            "
	@echo "$(YELLOW)                MMMM88&&&&&    .            "
	@echo "$(YELLOW)               MMMM88&&&&&&&            "
	@echo "$(YELLOW)   *           MMM88&&&&&&&&            "
	@echo "$(YELLOW)               MMM88&&&&&&&&            "
	@echo "$(YELLOW)               'MMM88&&&&&&'            "
	@echo "$(YELLOW)                 'MMM8&&&'      *                "
	@echo "$(BLUE)        |\___/|                      \\            "
	@echo "$(BLUE)        )     (    |\_/|              ||    '            "
	@echo "$(BLUE)       =\     /=   )- - '._.-""""-.  //            "
	@echo "$(BLUE)         )===(    =\T_= /    ~  ~  \//            "
	@echo "$(BLUE)        /     \     '''\   ~   / ~  /            "
	@echo "$(BLUE)        |     |         |~   \ |  ~/            "
	@echo "$(BLUE)       /       \         \  ~/- \ ~\            "
	@echo "$(BLUE)       \       /         || |  // //            "
	@echo "$(RED)jgs_/\_/$(BLUE)\_   _/$(RED)_/\_/\_/\_$(BLUE)((_|\((_//$(RED)\_/\_/\_            "
	@echo "$(RED)|  |  |  |$(BLUE)( (  $(RED)|  |  |  |  |  |  |  |  |  |            "
	@echo "$(RED)|  |  |  |$(BLUE) ) ) $(RED)|  |  |  |  |  |  |  |  |  |            "
	@echo "$(RED)|  |  |  |$(BLUE)(_(  $(RED)|  |  |  |  |  |  |  |  |  |            "
	@echo "$(RED)|  |  |  |  |  |  |  |  |  |  |  |  |  |  |            "
	@echo "$(RED)|  |  |  |  |  |  |  |  |  |  |  |  |  |  |            "
	@sleep 0.3

art4_5:

	@clear
	@echo "$(YELLOW)           *     ,MMM8&&&.            *        $(RESTART)"
	@echo "$(YELLOW)                MMMM88&&&&&    .        "
	@echo "$(YELLOW)               MMMM88&&&&&&&        "
	@echo "$(YELLOW)   *           MMM88&&&&&&&&        "
	@echo "$(YELLOW)               MMM88&&&&&&&&        "
	@echo "$(YELLOW)               'MMM88&&&&&&'        "
	@echo "$(YELLOW)                 'MMM8&&&'      *        "
	@echo "$(BLUE)        |\___/|     /\___/\        "
	@echo "$(BLUE)        )     (     )    ~( .              '        "
	@echo "$(BLUE)       =\     /=   =\~    /=        "
	@echo "$(BLUE)         )===(       ) ~ (        "
	@echo "$(BLUE)        /     \     /     \        "
	@echo "$(BLUE)        |     |     ) ~   (        "
	@echo "$(BLUE)       /       \   /     ~ \        "
	@echo "$(BLUE)       \       /   \~     ~/        "
	@echo "$(RED)jgs_/\_/$(BLUE)\__  _/$(RED)_/\_/$(BLUE)\__~__/$(RED)_/\_/\_/\_/\_/\_        "
	@echo "$(RED)|  |  |  |$(BLUE)( ($(RED)  |  |  |$(BLUE) ))$(RED)  |  |  |  |  |  |        "
	@echo "$(RED)|  |  |  |$(BLUE) ) )$(RED) |  |  |$(BLUE)//$(RED)|  |  |  |  |  |  |        "
	@echo "$(RED)|  |  |  |$(BLUE)(_($(RED)  |  |  $(BLUE)(( $(RED)|  |  |  |  |  |  |        "
	@echo "$(RED)|  |  |  |  |  |  |  |$(BLUE)\)$(RED)|  |  |  |  |  |  |        "
	@echo "$(RED)|  |  |  |  |  |  |  |  |  |  |  |  |  |  |        "
	@sleep 0.3

art4:

	@clear
	@echo "$(YELLOW)           *     ,MMMP&&M.            *             "
	@echo "$(YELLOW)                MMMM88&&&&&    .             "
	@echo "$(YELLOW)               MMMM88&&&&&&&             "
	@echo "$(YELLOW)   *           MMM88&&&&&&&&             "
	@echo "$(YELLOW)               MMM88&&&&&&&&             "
	@echo "$(YELLOW)                MMM88&&&&&&              "
	@echo "$(YELLOW)                  MMM8&&&       *             "
	@echo "$(BLUE)         /\/|_      __/\\             "
	@echo "$(BLUE)        /    -\    /-   ~\  .              '             "
	@echo "$(BLUE)        \    = Y =T_ =   /             "
	@echo "$(BLUE)         )==*(`     `) ~ \             "
	@echo "$(BLUE)        /     \     /     \             "
	@echo "$(BLUE)        |     |     ) ~   (             "
	@echo "$(BLUE)       /       \   /     ~ \             "
	@echo "$(BLUE)       \       /   \~     ~/             "
	@echo "$(RED)jgs_/\_/$(BLUE)\__  _/$(RED)_/\_/$(BLUE)\__~__/$(RED)_/\_/\_/\_/\_/\_             "
	@echo "$(RED)|  |  |  |$(BLUE) ) ) $(RED)|  |  | $(BLUE)(( $(RED) |  |  |  |  |  |             "
	@echo "$(RED)|  |  |  |$(BLUE)( (  $(RED)|  |  | $(BLUE) \\ $(RED)|  |  |  |  |  |             "
	@echo "$(RED)|  |  |  |$(BLUE) )_) $(RED)|  |  | $(BLUE) |))$(RED)|  |  |  |  |  |             "
	@echo "$(RED)|  |  |  |  |  |  |  |  $(BLUE)(/ $(RED)|  |  |  |  |  |             "
	@echo "$(RED)|  |  |  |  |  |  |  |  |  |  |  |  |  |  |             "
	@sleep 0.3

art5:

	@clear
	@echo "$(YELLOW)           *     ,MMM8&&&.            *         "
	@echo "$(YELLOW)                MMMM88&&&&&    .         "
	@echo "$(YELLOW)               MMMM88&&&&&&&         "
	@echo "$(YELLOW)   *           MMM88&&&&&&&&         "
	@echo "$(YELLOW)               MMM88&&&&&&&&         "
	@echo "$(YELLOW)               'MMM88&&&&&&'         "
	@echo "$(YELLOW)                 'MMM8&&&'      *         "
	@echo "$(BLUE)          /\/|_    __/\\         "
	@echo "$(BLUE)         /    -\  /-   ~\  .              '         "
	@echo "$(BLUE)         \    =_YT_ =   /         "
	@echo "$(BLUE)         /==*('    '\ ~ \         "
	@echo "$(BLUE)        /     \     /    '\         "
	@echo "$(BLUE)        |     |     ) ~   (         "
	@echo "$(BLUE)       /       \   /     ~ \         "
	@echo "$(BLUE)       \       /   \~     ~/         "
	@echo "$(RED)jgs_/\_/$(BLUE)\__  _/$(RED)_/\_/$(BLUE)\__~__/$(RED)_/\_/\_/\_/\_/\_         "
	@echo "$(RED)|  |  |  |$(BLUE) ) )$(RED) |  |  | $(BLUE)(( $(RED) |  |  |  |  |  |         "
	@echo "$(RED)|  |  |  |$(BLUE)( ( $(RED) |  |  | $(BLUE) \\ $(RED)|  |  |  |  |  |         "
	@echo "$(RED)|  |  |  |$(BLUE) )_)$(RED) |  |  | $(BLUE) |))$(RED)|  |  |  |  |  |         "
	@echo "$(RED)|  |  |  |  |  |  |  | $(BLUE) (/ $(RED)|  |  |  |  |  |         "
	@echo "$(RED)|  |  |  |  |  |  |  |  |  |  |  |  |  |  |         "
	@sleep 0.3

art6:

	@clear
	@echo "$(YELLOW)           *     ,MMM8&&&.            *                  "
	@echo "$(YELLOW)                MMMM88&&&&&    .                   ███╗   ███╗██╗███╗   ██╗██╗███████╗██╗  ██╗███████╗██╗     ██╗                                                                         "
	@echo "$(YELLOW)               MMMM88&&&&&&&                       ████╗ ████║██║████╗  ██║██║██╔════╝██║  ██║██╔════╝██║     ██║          "
	@echo "$(YELLOW)   *           MMM88&&&&&&&&                       ██╔████╔██║██║██╔██╗ ██║██║███████╗███████║█████╗  ██║     ██║       "
	@echo "$(YELLOW)               MMM88&&&&&&&&                       ██║╚██╔╝██║██║██║╚██╗██║██║╚════██║██╔══██║██╔══╝  ██║     ██║          "
	@echo "$(YELLOW)               'MMM88&&&&&&'                       ██║ ╚═╝ ██║██║██║ ╚████║██║███████║██║  ██║███████╗███████╗███████╗          "
	@echo "$(YELLOW)                 'MMM8&&&'      *                  ╚═╝     ╚═╝╚═╝╚═╝  ╚═══╝╚═╝╚══════╝╚═╝  ╚═╝╚══════╝╚══════╝╚══════╝         "
	@echo "$(BLUE)        |\___/|     /\___/\                                 "
	@echo "$(BLUE)        )     (     )    ~(                             "
	@echo "$(BLUE)       =\     /=   =\~    /=                        ____  _           _ _                    ___    ___     ____                      _   _ _           "
	@echo "$(BLUE)         )===(       ) ~ (                         / ___|| |__   ___ | (_)_   ____ _ _ __   ( _ )  ( _ )   |  _ \  __ _  ___ __ _ ___| |_(_) |       "
	@echo "$(BLUE)        /     \     /     \                        \___ \| '_ \ / _ \| | \ \ / / _\ | '__|  / _ \/\/ _ \/\ | | | |/ _\ |/ __/ _\ / __| __| | |        "
	@echo "$(BLUE)        |     |     ) ~   (                         ___) | |_) | (_) | | |\ V / (_| | |    | (_>  < (_>  < | |_| | (_| | (_| (_| \__ \ |_| | |         "
	@echo "$(BLUE)       /       \   /     ~ \                       |____/|_.__/ \___/|_|_| \_/ \__/_|_|     \___/\/\___/\/ |____/ \__/_|\___\__/_|___/\__|_|_|         "
	@echo "$(BLUE)       \       /   \~     ~/                           "
	@echo "$(RED)jgs_/\_/$(BLUE)\__  _/$(RED)_/\_/$(BLUE)\__~__/$(RED)_/\_/\_/\_/\_/\_              "
	@echo "$(RED)|  |  |  |$(BLUE)( ( $(RED) |  |  |$(BLUE) ))$(RED)  |  |  |  |  |  |              "
	@echo "$(RED)|  |  |  |$(BLUE) ) )$(RED) |  |  |$(BLUE)//$(RED)|  |  |  |  |  |  |              "
	@echo "$(RED)|  |  |  |$(BLUE)(_( $(RED) |  |  $(BLUE)(( $(RED)|  |  |  |  |  |  |              "
	@echo "$(RED)|  |  |  |  |  |  |  |$(BLUE)\)$(RED)|  |  |  |  |  |  |              "
	@echo "$(RED)|  |  |  |  |  |  |  |  |  |  |  |  |  |  |              "

secuence:$(ARTS)

re: fclean all

.PHONY: all clean fclean re
