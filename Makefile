NAME ='philo'
FLAGS = -Wall -Wextra -Werror 
CC = cc
RM = rm -rf
SRC = utils.c \
		routine.c \
		philo.c \
		init.c \
		create_threads.c
OBJ = $(SRC:.c=.o)
$(NAME): $(OBJ)
	cc $(FLAGS) $(OBJ) -o philo
all : $(NAME)
%.o: %.c
	cc $(FLAGS) -c $< -o $@
clean:
	$(RM) $(OBJ)
fclean: clean
	$(RM) $(NAME)