# Source Files
SRCS =	main.cpp \
	Account.cpp \
	Bank.cpp

# Object Files
OBJS = $(SRCS:.cpp=.o)

# NAME Executable
NAME = DivideAndRule

# Compiler
CXX = g++

# Compiler flags  
CXXFLAGS = -std=c++98 -Wall -Wextra -Werror -fsanitize=address

# Library needed
# LIBS = 

# Default rule to build and run the executable
all: $(NAME)

# Rule to compile directly to executable (no .o files created)
$(NAME): $(SRCS)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(SRCS)

# Clean rule to remove generated files
clean:
	rm -f $(OBJS)
	
fclean: 
	rm -f $(OBJS)
	rm -f $(NAME)

re:fclean all

# Rule to run the executable
run: $(NAME)
	./$(NAME)

.PHONY: all clean fclean re run
