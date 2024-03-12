CC = cc
CFLAGS = -g -Wall -Wextra -Werror
NAME = pipex

SOURCES = pipex.c path_utils.c cmd_utils.c exec.c

OBJS_DIR = obj
OBJECTS = $(addprefix $(OBJS_DIR)/, $(SOURCES:%.c=%.o))

LIBFT_DIR = ./libft/
LIBFT = $(LIBFT_DIR)libft.a

all: $(NAME)

$(NAME): $(OBJECTS) $(LIBFT)
		$(CC) $(CFLAGS) $(OBJECTS) -o $@ $(LIBFT)

$(OBJS_DIR)/%.o:%.c
	mkdir -p $(OBJS_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

clean:
		$(MAKE) clean -C $(LIBFT_DIR)
		rm -rf $(OBJS_DIR)

fclean: clean
		$(MAKE) fclean -C $(LIBFT_DIR)
		rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re