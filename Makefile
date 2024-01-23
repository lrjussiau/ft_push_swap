FILES = ft_split\
			ft_split_utils\
			func_push\
			func_reverse_rotate\
			func_rotate\
			func_swap\
			function_algo\
			function_algo_move\
			lst_utils\
			node_config_utils\
			node_config\
			parsing_list\
			parsing_list_utils\
			tiny_sort\
			main\

CFILES = $(FILES:%=%.c)
OFILES = $(FILES:%=%.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror

NAME = push_swap

all: $(NAME)

$(NAME): $(OFILES)
	@$(CC) $(CFLAGS) -o $@ $(OFILES)

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(OFILES)

fclean: clean
	@rm -f $(NAME)

re: fclean all
