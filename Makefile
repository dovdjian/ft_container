NAME = container

NAME_STL = container_stl

CPP	=	@c++

CFLAGS	=	-Wall -Wextra -Werror -std=c++98

RM	=	@rm -rf

HEADER	=	-I includes

PURPLE		:= \033[0;35m
BLACK		:= \033[1;30m
RED			:= \033[1;31m
GREEN		:= \033[1;32m
YELLOW		:= \033[1;33m
BLUE		:= \033[1;34m
PURPLE2		:= \033[1;35m
CYAN		:= \033[1;36m
WHITE		:= \033[1;37m
END			:= \033[0m

VECTOR		=	tests_iterator.cpp \
				tests_methods.cpp \
				tests_reverse_iterator.cpp \
				tests_vector.cpp \

STACK		=	tests_stack.cpp \
				tests_methods.cpp \

MAP			=	tests_map.cpp

MAIN =			main.cpp

TESTS = 		$(addprefix vector/, $(VECTOR)) \
				$(addprefix stack/, $(STACK)) \
				$(addprefix map/, $(MAP)) \

SRCS =			$(addprefix srcs/, $(MAIN)) \
				$(addprefix srcs/tests/, $(TESTS)) \

OBJ =			$(SRCS:.cpp=.o)

%.o: %.cpp
		@printf "${PURPLE}%-35.35s\r${END}" $@
		${CPP} $(HEADER) ${CFLAGS} -c $< -o $@

all : test

$(NAME) : $(OBJ)
	$(CPP) $(CFLAGS) -D prefix=ft $(HEADER) -o $(NAME) $(OBJ)
	@echo "The ${RED} $(NAME) ${END} has been build !"

$(NAME_STL) : $(OBJ)
	$(CPP) $(CFLAGS) -D prefix=std $(HEADER) -o $(NAME_STL) $(OBJ)
	@echo "The ${RED} $(NAME_STL) ${END} has been build !"

test:
			@$(RM) res
			@$(MAKE) $(NAME)
			@$(MAKE) $(NAME_STL)
			@mkdir res
			@mv $(NAME) res/
			@mv $(NAME_STL) res/
			@./res/$(NAME) > res/ft.res
			@./res/$(NAME_STL) > res/std.res
			@-diff -u res/ft.res res/std.res > res/diff.res

clean :
		$(RM) $(OBJ)

fclean : clean
		$(RM) res

re : fclean all

.PHONY: all clean fclean re
