program = megaphone
CFLAGE = -Wall -Wextra -Werror -std=c++98
comp = c++

sur = megaphone.cpp

obj =$(sur:.cpp=.o)

all: $(program)

$(program): $(obj)
	$(comp) $(CFLAGE) $(obj) -o $(program)

%.o : %.cpp
	$(comp) $(CFLAGE) -c $< -o $@

clean:
	rm -rf $(obj)

fclean:	clean
	rm -rf $(program)

re: fclean all
