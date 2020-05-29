##
##
##

NAME		= nanotekspice

SRCS		=   main.cpp                    \
                src/entries/Input.cpp       \
                src/entries/Output.cpp      \
                src/entries/True.cpp        \
                src/entries/False.cpp       \
                src/gates/AndGate.cpp       \
                src/gates/OrGate.cpp        \
                src/gates/NAndGate.cpp      \
                src/gates/NOrGate.cpp       \
                src/gates/NotGate.cpp       \
                src/gates/XorGate.cpp       \
                src/core/Core.cpp           \
                src/core/Parser.cpp         \
                src/core/Factory.cpp        \
                src/core/Circuit.cpp        \
                src/chipsets/C4001.cpp      \
                src/chipsets/C4011.cpp      \
                src/chipsets/C4030.cpp      \
                src/chipsets/C4069.cpp      \
                src/chipsets/C4071.cpp      \
                src/chipsets/C4081.cpp      \
                src/entries/Clock.cpp

OBJS		= $(SRCS:.cpp=.o)

CPPFLAGS	= -g -Wall -Wextra -W -Iinclude

GPP		= g++

RM		= rm -f

all:		$(NAME)

$(NAME):	$(OBJS)
	$(GPP) -o $(NAME) $(OBJS) $(CPPFLAGS) -L.

clean:
	$(RM) $(OBJS)

fclean:		clean
	$(RM) $(NAME)

re:		fclean all

.PHONY:		all clean fclean re
