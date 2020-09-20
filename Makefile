CXX=g++
CXXFLAGS=-std=c++14 -Wall -O -g -MMD -Werror=vla
SOURCES=$(wildcard *.cc)    # all .cc files
OBJECTS=${SOURCES:.cc=.o}   # object files
DEPENDS = ${OBJECTS:.o=.d}  # dependency files
EXEC = tictactoe

$(EXEC): $(OBJECTS)
	$(CXX) $(CXXFLAGS) $(OBJECTS) -o $(EXEC)

%.o: %.cc
	$(CXX) -c -o $@ $< $(CXXFLAGS) 

-include ${DEPENDS}

.PHONY: clean
clean :
	rm -f ${DEPENDS} ${OBJECTS} ${EXEC}
