CC = gcc
CFLAGS = -Wall -ansi -pedantic -Werror -lm -g
OBJ = tvguide.o interface.o fileIO.o comparison.o linkedList.o
OBJTEST = UnitTestList.o linkedList.o
EXEC = program
UNITTEST = listTest

all: $(EXEC) $(UNITTEST)

$(EXEC)	: $(OBJ)
		$(CC)  $(OBJ) -o $(EXEC)

$(UNITTEST)	: $(OBJTEST)
		$(CC)  $(OBJTEST) -o $(UNITTEST)

tvguide.o : tvguide.c tvguide.h
		 $(CC) -c tvguide.c $(CFLAGS)

interface.o : interface.c interface.h boolean.h
		 $(CC) -c interface.c $(CFLAGS)

fileIO.o : fileIO.c fileIO.h boolean.h interface.h
		 $(CC) -c fileIO.c $(CFLAGS)

comparison.o : comparison.c comparison.h data.h
		 $(CC) -c comparison.c $(CFLAGS)
		 
linked_list.o : linkedList.c linkedList.h
		$(CC) -c linkedList.c $(CFLAGS)
		 
UnitTestList.o : UnitTestList.c linkedList.h
		$(CC) -c UnitTestList.c $(CFLAGS)
 
clean:
		rm -f $(EXEC) $(UNITTEST)  $(OBJ) $(OBJTEST)
		
run:
	$(RUN)	
