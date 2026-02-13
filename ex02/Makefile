Name = identify

SRC = Base.cpp main.cpp A.cpp B.cpp C.cpp

OBJ = $(SRC:.cpp=.o)

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

all: $(Name)

$(Name): $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(Name)

%.o: %.cpp Base.hpp A.hpp B.hpp C.hpp

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(Name)

re: fclean all

.PHONY: all clean fclean re