NAME	= PmergeMe

SRCS	= main.cpp \
				PmergeMe.cpp

OBJS		= $(SRCS:%.cpp=%.o)

CXX			= c++

CXXFLAGS	= -std=c++98

all		: $(NAME)

$(NAME)	: $(OBJS)
		$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

clean	:
		rm -f $(OBJS)

fclean	: clean
	rm -f $(NAME)

re : fclean all


# =================== test ===================
long	:
		./PmergeMe `shuf -i 1-100000 -n 3000 | tr "\n" " "`

test1	:
		./PmergeMe `shuf -i 1-10 -n 3000 | tr "\n" " "`

test2	:
		./PmergeMe `shuf -i 1-60 -n 3000 | tr "\n" " "`

error1	:
	./PmergeMe 0 8 10 -10