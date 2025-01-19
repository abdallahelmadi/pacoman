CC = cc
RM = rm -rf
NAME = so_long
CFLAGS = -Wall -Wextra -Werror
CLINKINGFLAGS = -lmlx -lX11 -lXext
SOLONGFILEOBJECTS = ./srcs/utils/ft_last_node.o ./srcs/utils/ft_new_node.o \
					./srcs/utils/ft_printf.o ./srcs/utils/ft_random.o ./srcs/utils/ft_string_put.o \
					./srcs/utils/ft_strjoin.o ./srcs/utils/ft_strlen.o ./srcs/floodfill_init.o \
					./srcs/control_init.o ./srcs/finish_init.o ./srcs/game_init.o \
					./srcs/get_next_line_init.o ./srcs/loops_init.o ./srcs/map_generate.o \
					./srcs/map_includes.o ./srcs/map_init.o ./srcs/solong_init.o

all : $(NAME)

$(NAME) : $(SOLONGFILEOBJECTS)
	@$(CC) $(CFLAGS) $(SOLONGFILEOBJECTS) -o $(NAME) $(CLINKINGFLAGS)

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	@$(RM) $(SOLONGFILEOBJECTS)

fclean : clean
	@$(RM) $(NAME)

re : fclean all