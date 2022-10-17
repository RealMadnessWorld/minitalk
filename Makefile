CC	= gcc
FLAGS = -Wall -Wextra -Werror
RM	= rm -f

CLIENT = client
SERVER = server

SRCS_C = client.c tools.c
SRCS_S = server.c tools.c
SRCS_C_B = client_bonus.c tools_bonus.c tools_bonus2.c
SRCS_S_B = server_bonus.c tools_bonus.c tools_bonus2.c

OBJSC = $(SRCS_C:.c=.o)
OBJSS = $(SRCS_S:.c=.o)
OBJSC_B = $(SRCS_C_B:.c=.o)
OBJSS_B = $(SRCS_S_B:.c=.o)

all: $(CLIENT) $(SERVER)

$(CLIENT) :
	@$(CC) $(SRCS_C) $(FLAGS) -o $(CLIENT)

$(SERVER) :
	@$(CC) $(SRCS_S) $(FLAGS) -o $(SERVER)

bonus:
	@$(CC) $(SRCS_C_B) $(FLAGS) -o $(CLIENT)
	@$(CC) $(SRCS_S_B) $(FLAGS) -o $(SERVER)

clean:
	@$(RM) $(OBJS_C)
	@$(RM) $(OBJS_S)
	@$(RM) $(OBJSC_B)
	@$(RM) $(OBJSS_B)
	@echo "everything cleaned"

fclean: clean
	 	@$(RM) $(CLIENT)
	 	@$(RM) $(SERVER)

re: fclean all

so:	re
	@$(RM) $(OBJS_C) 
	@$(RM) $(OBJS_S)
	@echo "muy bueno mi ijo"

.PHONY:		all bonus clean fclean re so