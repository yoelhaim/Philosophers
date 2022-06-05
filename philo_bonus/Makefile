NAME ='philo'
FLAGS = -Wall -Wextra -Werror 
CC = cc
RM = rm -rf
SRC = utils_bonus.c \
		routine_bonus.c \
		philo_bonus.c \
		init_bonus.c \
		create_prossess.c 
OBJ = $(SRC:.c=.o)
$(NAME): $(OBJ)
	cc $(FLAGS) $(OBJ) -o philo -g
all : $(NAME)
%.o: %.c
	cc $(FLAGS) -c $< -o $@ -g
clean:
	$(RM) $(OBJ)
fclean: clean
	$(RM) $(NAME)
re : fclean all 