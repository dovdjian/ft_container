NAME = container

NAME_STL = container_stl

CPP	=	@clang++

CFLAGS	=	-Wall -Wextra -Werror #-std=c++98

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

TESTS = test_vector.cpp \
		test_stack.cpp \
		test_map.cpp \

TESTS_STL = test_vector_stl.cpp \
		test_stack_stl.cpp \
		test_map_stl.cpp \

MAIN = main.cpp

SRCS = $(addprefix srcs/, $(MAIN)) \
		$(addprefix srcs/tests/ft_tests/, $(TESTS)) \

SRCS_STL = $(addprefix srcs/, $(MAIN)) \
		$(addprefix srcs/tests/stl_tests/, $(TESTS_STL)) \

OBJ = $(SRCS:.cpp=.o)

OBJ_STL = $(SRCS_STL:.cpp=.o)

%.o: %.cpp
		@printf "${PURPLE}%-35.35s\r${END}" $@
		${CPP} $(HEADER) ${CFLAGS} -c $< -o $@

all : $(NAME) $(NAME_STL)

$(NAME) : $(OBJ)
	$(CPP) $(CFLAGS) $(HEADER) -o $(NAME) $(OBJ)
	@echo "The ${RED} $(NAME) ${END} has been build !"

$(NAME_STL) : $(OBJ_STL)
	$(CPP) $(CFLAGS) $(HEADER) -o $(NAME_STL) $(OBJ_STL)
	@echo "The ${RED} $(NAME_STL) ${END} has been build !"

clean :
	$(RM) $(OBJ) $(OBJ_STL)

fclean : clean
	@$(RM) $(NAME) $(NAME_STL)
	@echo "The ${BLUE} $(NAME) ${END} has been deleted !"
	@echo "The ${BLUE} $(NAME_STL) ${END} has been deleted !"

re : fclean all

.PHONY: all clean fclean re
