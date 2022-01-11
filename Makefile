CC = cc
NAME = so_long
FLAGS = -Wall -Wextra -Werror
INCLUDE = -lmlx -framework OpenGL -framework AppKit

SRC =  ft_split.c ft_strlen_newline.c get_next_line/get_next_line_utils.c\
	  get_next_line/get_next_line.c so_long.c check_map.c  error_message.c exit_game.c\
	  map.c mov_player.c put_image.c window_game.c window_map.c 


OBJ = $(SRC:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ) so_long.h
	$(CC) $(OBJ) $(INCLUDE) -o $(NAME)  
	
%.o : %.c so_long.h
	$(CC)  $(FLAGS) -c $< -o $@ 

clean :
	rm -rf $(OBJ)
fclean : clean
	rm -rf $(NAME)

re : fclean all