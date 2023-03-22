NAME = cub3d

SRC = $(wildcard ./*.c)

OBJ = $(patsubst %.c, %.o, $(SRC))

FLAGS = -Wall -Werror -Wextra

LINKS = -lmlx -framework OpenGL -framework AppKit

CC = cc

RM = rm -rf

%.o: %.c
	@$(CC) $(FLAGS) -c $< -o $@

all: $(NAME)
	@echo Compiled

$(NAME): $(OBJ)
	@$(CC) $(FLAGS) -o $(NAME) $(OBJ) $(LINKS)

clean:
	@$(RM) $(OBJ)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
