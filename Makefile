CC	= gcc -Wall -Wextra -Werror
RM	= rm -f

CLIENT = client
SERVER = server

SRCS_C = client.c tools.c
SRCS_S = server.c tools.c

OBJSC = $(SRCS_C:.c=.o)
OBJSS = $(SRCS_S:.c=.o)

all: $(CLIENT) $(SERVER)

$(CLIENT) :
	@gcc $(SRCS_C) $(FLAGS) -o $(CLIENT)

$(SERVER) :
	@gcc $(SRCS_S) $(FLAGS) -o $(SERVER)

clean:
	@$(RM) $(OBJS_C) 
	@$(RM) $(OBJS_S) 
	@echo "suck my dick"

fclean: clean
	 	@$(RM) $(CLIENT)
	 	@$(RM) $(SERVER)

re: fclean all

so:	re
	@$(RM) $(OBJS_C)
	@$(RM) $(OBJS_S)
	@echo "muy bueno mi ijo"

.PHONY:		all clean fclean re so