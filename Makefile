NAME			=	ircserv

INC				=	./inc/
BIN				=	./srcs/bin

RESET			=	\033[0m
GREEN			=	\033[32m
YELLOW			=	\033[33m
BLUE			=	\033[34m
RED				=	\033[31m

SRCS			=	$(shell find srcs -type f -name "*.cpp")
INCS			=	$(shell find inc -type f -name "*.hpp")
OBJS			=	$(SRCS:srcs/%.cpp=srcs/bin/%.o)
HOBJS			=	$(INCS:inc/%.hpp)

CC				=	@c++
RM				=	@rm -rf
CPPFLAGS		=	-Wall -Wextra -Werror -std=c++98

all:			$(NAME)

$(BIN):
	@mkdir $(BIN)

$(NAME):	$(BIN) $(OBJS) $(HOBJS)
			@echo "$(YELLOW)>- Compiling... [$(NAME)] $(RESET)"
			@$(CC) $(CPPFLAGS) $(OBJS) -o $(NAME)
			@echo "$(GREEN)>- Finished! $(RESET)"

clean:
			@echo "$(RED)>- Deleting... [$(NAME)] $(RESET)"
			@$(RM) $(OBJS) $(HOBJS)
			@$(RM) $(BIN)
			@echo "$(BLUE)>- Successfully! $(RESET)"

fclean:			clean
				@$(RM) $(NAME)

re:				fclean $(NAME)

$(BIN)%.o: srcs/%.cpp
	@mkdir -p $(shell dirname $@)
	@$(CC) $(CPPFLAGS) -c $< -o $@ -I$(INC)

norm:			
				norminette *.[ch]

.PHONY:			all clean fclean re bonus