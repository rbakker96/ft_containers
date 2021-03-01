# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: roybakker <roybakker@student.codam.nl>       +#+                      #
#                                                    +#+                       #
#    Created: 2021/02/25 14:55:06 by roybakker     #+#    #+#                  #
#    Updated: 2021/02/25 14:55:06 by roybakker     ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME			=	ft_containers

SOURCES			= 	UNIT_TEST/0_main.cpp \
					UNIT_TEST/1_Bidirectionaliterator_test.cpp \
					UNIT_TEST/2_RandomAccessIterator_test.cpp \
					UNIT_TEST/3_list_test.cpp \
					UNIT_TEST/4_vector_test.cpp \
					UNIT_TEST/5_queue_test.cpp \
					UNIT_TEST/6_stack_test.cpp \
					UNIT_TEST/7_map_test.cpp \
					UNIT_TEST/catch.cpp \

OBJECTS 		=	${SOURCES:%.c=%.o}

FLAGS 			=	-Wall -Wextra -Werror
INCLUDES 		=	-IHEADER_FILES/
UTILS			=	-IHEADER_FILES/UTILS/
UNIT_TEST		=	-IUNIT_TEST/
COMPILE			=	clang++ -std=c++14

GREEN 			= 	\033[38;5;46m
WHITE 			= 	\033[38;5;15m
GREY 			= 	\033[38;5;8m
ORANGE 			= 	\033[38;5;202m
RED 			= 	\033[38;5;160m

all: $(NAME)

$(NAME): $(OBJECTS)
	@echo "$(GREEN)----------------------------------------------------"
	@$(COMPILE) $(INCLUDES) $(UTILS) $(UNIT_TEST) $(FLAGS) -o $(NAME) $(OBJECTS)
	@echo "Executable				./ft_containers"
	@echo "$(GREEN)----------------------------------------------------"

%.o: %.c
	@echo "$(GREY)Compiling...				$(WHITE)$<"
	@$(COMPILE) $(INCLUDES) $(UTILS) $(UNIT_TEST) $(FLAGS) -c -o $@ $<

clean:
	@echo "$(RED)----------------------------------------------------"
	@echo "$(WHITE)DELETE ./ft_containers"
	@echo "$(RED)----------------------------------------------------"
	@/bin/rm -f $(NAME)

re: clean all

.PHONY: all clean re