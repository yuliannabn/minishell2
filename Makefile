##
## EPITECH PROJECT, 2023
## MAKEFILE
## File description:
## makefile
##

NAME = mysh

TARGET =	src/main.c							\
		src/builtins/paths_misc.c				\
		src/builtins/unset_env/unset_env.c		\
		src/builtins/set_env/set_env.c			\
		src/builtins/set_env/env.c				\
		src/builtins/set_env/env_variable_find.c\
		src/builtins/cd/cd.c					\
		src/builtins/cd/cd_misc.c				\
		src/builtins/exit/exit.c				\
		src/toolkit/exec/exec_misc.c			\
		src/toolkit/exec/exec_try.c				\
		src/toolkit/exec/exec_bools.c			\
		src/toolkit/exec/signals_read.c			\
		src/toolkit/input/input_read.c	  		\
		src/toolkit/input/prompt_tools.c	  	\
		src/toolkit/prompt_run.c	  			\
		src/commands/and_or.c					\
		src/commands/pipe.c 					\
		src/commands/redirection.c				\
		src/commands/redirection_tools.c		\
		src/commands/here_document.c			\
		src/commands/tree.c						\
		src/commands/tree_tools.c				\

FLAGS = -W -Wall -Wpedantic -Wno-long-long -g -Werror

INCLUDE = -I include/

all = $(NAME)

$(NAME):
	cd lib; make
	gcc -o $(NAME) $(TARGET) $(INCLUDE) $(FLAGS) -L lib/ -lmy

clean:
	cd lib; make clean
	rm -f *#
	rm -f *~

fclean: clean
	cd lib; make fclean
	rm -f $(NAME)

re: fclean $(NAME)
