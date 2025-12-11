CC = gcc
CFLAGS = -Wall -Wextra -O2
TARGET = sort_students
OBJS = main.o student.o

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

main.o: main.c student.h
	$(CC) $(CFLAGS) -c main.c

student.o: student.c student.h
	$(CC) $(CFLAGS) -c student.c

clean:
	rm -f $(OBJS) $(TARGET)
