NAME ='philo_bonus'
FLAGS = -Wall -Wextra -Werror 
CC = cc
RM = rm -rf
SRC = create.c \
		parsing.c \
		main.c \
		utils.c \
		manage.c
OBJ = $(SRC:.c=.o)
$(NAME): $(OBJ)
	cc $(FLAGS) $(OBJ) -o $(NAME) -g
all : $(NAME)
%.o: %.c
	cc $(FLAGS) -c $< -o $@ -g
clean:
	$(RM) $(OBJ)
fclean: clean
	$(RM) $(NAME)
re : fclean all 
