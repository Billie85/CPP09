NAME	= RPN

SRCS	= main.cpp \
		  RPN.cpp

OBJS		= $(SRCS:%.cpp=%.o)

CXX			= c++

CXXFLAGS	= -Wall -Wextra -Werror -std=c++98

all		: $(NAME)

$(NAME)	: $(OBJS)
		$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

test1	: $(NAME)
	./$(NAME) "8 9 * 9 - 9 - 9 - 4 - 1 +"
#42

test2	: $(NAME)
	./$(NAME) "3 4 5 * + 6 -"
#17

test3	: $(NAME)
	./$(NAME) "2 3 + 4 5 - *"
#-5

test4	: $(NAME)
	./$(NAME) "5 2 3 + * 8 4 / +"
#27

test5	: $(NAME)
	./$(NAME) "9 2 3 * + 5 - 7 8 * +"
#66

test6	: $(NAME)
	./$(NAME) "4 2 + 3 5 1 - * +"
#18

test7	: $(NAME)
	./$(NAME) "2 3 4 + * 5 6 * -"
#-16

test8	: $(NAME)
	./$(NAME) "6 2 / 3 4 * + 5 -"
#10

test9	: $(NAME)
	./$(NAME) "8 2 3 * 4 + 5 - /"
#1.6 -> 1

test10	: $(NAME)
	./$(NAME) "7 2 / 3 5 * + 4 -"
#14.5 -> 14

#==========ERROR TEST============
test11	: $(NAME)
	./$(NAME) "7 2 / 3 5 * + 4 9"

test12	: $(NAME)
	./$(NAME) "7 2 / 3 5 * + 4 + 7 + 10 + 9 * 8 * 10 +"

test13	: $(NAME)
	./$(NAME) "7 2 / 3 5 * + 4 + 7 + 10 + 9 * 8 * 10 + 11 / 100"

test14	: $(NAME)
	./$(NAME) "7 2 / 3 5 * + 4 + 7 + 10 + 9 **+*"

test15	: $(NAME)
	./$(NAME) "7 2 / 3 5 * + 4 + 7 + 10 + 9 **+*/////"

test16	: $(NAME)
	./$(NAME) "(1 + 1)"

clean	:
		rm -f $(OBJS)

fclean	: clean
	rm -f $(NAME)

re : fclean all