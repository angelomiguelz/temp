NAME = pipex

SRC_NAME =	pipex.c file_handler.c pipe_handler.c utils.c


CC = gcc
CFLAGS = -Wall -Wextra -Werror -g #-fsanitize=address
RM = rm -f

$(VERBOSE).SILENT:
LIBFT = ./libft/libft.a
LIBFT_PATH = ./libft

FT_PRINTF = ./ft_printf/libftprintf.a
FT_PRINTF_PATH = ./ft_printf

INC = -I ./inc	-I ./libft	-I ./ft_printf

SRC_PATH = ./

OBJ_PATH = ./objects

OBJS = $(addprefix $(OBJ_PATH)/, $(SRC_NAME:.c=.o))

SRC = $(addprefix $(SRC_PATH)/, $(SRC_NAME))

all: $(NAME)

$(NAME) : $(SRC)
	make -C $(FT_PRINTF_PATH) 
	make -C $(LIBFT_PATH)
	$(CC) $(CFLAGS) $(SRC) $(INC) $(FT_PRINTF) $(LIBFT) -o $(NAME)
	clear

$(OBJ_PATH)/%.o : $(SRC_PATH)/%.c
	mkdir -p objects
	$(CC) -c $(CFLAGS) $(INCLUDES) $< -o $@
	@printf "                                                \n"
	@printf " ********************************************** \n"
	@printf " ********* Very good, Very nice!!! ************ \n"
	@printf " ********************************************** \n"
	@printf "                                                \n"

clean:
	$(RM)	$(SRC:=.o)
	make clean -C $(FT_PRINTF_PATH)
	make clean -C $(LIBFT_PATH)
	clear
	@echo "                                                "
	@echo " ********************************************** "
	@echo " **********  So Clean It Shines!  ************* "
	@echo " ********************************************** "
	@echo "                                                "

fclean: clean
		make fclean -C $(FT_PRINTF_PATH)
		make fclean -C $(LIBFT_PATH)
	$(RM)	$(NAME)

re:	fclean	$(NAME)