NAME	= floating

CC	= g++

RM	= rm -f

SRCS	= ./srcs/main.cpp	\
	  ./srcs/Camera.cpp	\
	  ./srcs/Map.cpp

OBJS	= $(SRCS:.cpp=.o)

CPPFLAGS = -I ./includes/
CPPFLAGS += -W -Wall -Wextra

LDFLAGS = `pkg-config sfml-all --libs`

all: $(NAME)

$(NAME): $(OBJS)
	 $(CC) $(OBJS) -o $(NAME) $(LDFLAGS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
