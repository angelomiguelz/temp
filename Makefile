NAME = pipex
NAME_BONUS = pipex_bonus

SRC = utils.c utils2.c pipex.c
OBJS = $(SRC:.c=.o)

SRC_BONUS = pipex_bonus.c utils.c utils2.c
OBJS_BONUS = $(SRC_BONUS:.c=.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror -g #-fsanitize=address
RM = rm -f

LIBFT = ./libft/libft.a
LIBFT_PATH = ./libft

INC = -I ./libft

all: $(NAME)

$(NAME) : $(SRC)
	make -C $(LIBFT_PATH)
	$(CC) $(CFLAGS) $(SRC) $(INC) $(LIBFT) -o $(NAME)
	clear

clean:
	$(RM)	$(SRC:=.o)
	make clean -C $(LIBFT_PATH)
	clear

fclean: clean
		make fclean -C $(LIBFT_PATH)
		$(RM)	$(NAME)
		clear

re:	fclean	$(NAME)

bonus: $(NAME_BONUS)

$(NAME_BONUS): $(SRC_BONUS)
	make -C $(LIBFT_PATH)
	make re
	$(CC) $(CFLAGS) $(SRC_BONUS) $(INC) $(LIBFT) -o $(NAME)
	clear

rebonus: fclean $(NAME_BONUS) 