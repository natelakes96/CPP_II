CC = g++
CFLAGS= -Wall -Wextra -pedantic -std=c++11 -g
DEPS = item.h player.h
OBJS = main.o
LIBS = fortnite.a
TARGET = a.out

all: $(TARGET)

%.o: %.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS) 

$(TARGET): $(OBJS) $(LIBS)
	$(CC) -o $@ $^ $(CFLAGS)

.PHONY: clean

clean:
	rm $(OBJS) $(TARGET)
	