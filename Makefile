CC=g++
CFLAGS=-c -Wall
LDFLAGS= -lX11
SOURCES=main.cpp gcontext.cpp x11context.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=lines

all: $(SOURCES) $(EXECUTABLE) 

# pull in dependency info for *existing* .o files
-include $(OBJECTS:.o=.d)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(OBJECTS) $(LDFLAGS) -o $@

.cpp.o: 
	$(CC) $(CFLAGS) $< -o $@
	$(CC) -MM $(CFLAGS) $< > $*.d

clean:
	rm -rf $(OBJECTS) $(EXECUTABLE) *.d
