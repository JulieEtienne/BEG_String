
NAME = cookie

SRCS = main.cpp \
	String.cpp \

OBJS = $(SRCS:.cpp=.o)

CXXFLAGS = -Wall -Wextra -Werror -g3 -O0 -std=gnu++0x
 

all: $(NAME)

$(NAME): $(OBJS)
	$(EXTRA) $(CXX) $(OBJS) -o $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
