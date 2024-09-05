CC=g++
CFLAGS=-Wall -g
LDFLAGS=
SOURCES=lstack.h lqueue.h empty_collection_exception.h infix_to_postfix_converter.cpp main.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=Converter

all: $(SOURCES) $(EXECUTABLE)
	
$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

%.o : %.cpp
	$(CC) $(CFLAGS) -c $<

clean:
	rm -rf *.o $(EXECUTABLE)
