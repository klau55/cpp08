
# Variables
NAME = easyfind
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++20
SRCDIR = .
OBJDIR = obj
INCDIR = .

# Source files
SOURCES = main.cpp
OBJECTS = $(SOURCES:%.cpp=$(OBJDIR)/%.o)
HEADERS = easyfind.hpp

# Colors for output
RED = \033[0;31m
GREEN = \033[0;32m
YELLOW = \033[1;33m
BLUE = \033[0;34m
MAGENTA = \033[0;35m
CYAN = \033[0;36m
WHITE = \033[0;37m
RESET = \033[0m

# Rules
all: $(NAME)

$(NAME): $(OBJECTS)
	@echo "$(GREEN)Linking $(NAME)...$(RESET)"
	@$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJECTS)
	@echo "$(GREEN)✓ $(NAME) created successfully!$(RESET)"

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp $(HEADERS) | $(OBJDIR)
	@echo "$(CYAN)Compiling $<...$(RESET)"
	@$(CXX) $(CXXFLAGS) -I$(INCDIR) -c $< -o $@

$(OBJDIR):
	@mkdir -p $(OBJDIR)

clean:
	@echo "$(YELLOW)Cleaning object files...$(RESET)"
	@rm -rf $(OBJDIR)
	@echo "$(YELLOW)✓ Object files cleaned!$(RESET)"

fclean: clean
	@echo "$(RED)Removing $(NAME)...$(RESET)"
	@rm -f $(NAME)
	@echo "$(RED)✓ $(NAME) removed!$(RESET)"

re: fclean all

test: $(NAME)
	@echo "$(MAGENTA)Running tests...$(RESET)"
	@./$(NAME)

.PHONY: all clean fclean re test


# Help target
help:
	@echo "$(BLUE)Available targets:$(RESET)"
	@echo "  $(GREEN)all$(RESET)     - Build the project"
	@echo "  $(GREEN)clean$(RESET)   - Remove object files"
	@echo "  $(GREEN)fclean$(RESET)  - Remove all generated files"
	@echo "  $(GREEN)re$(RESET)      - Clean and rebuild"
	@echo "  $(GREEN)test$(RESET)    - Build and run tests"
	@echo "  $(GREEN)help$(RESET)    - Show this help message"
