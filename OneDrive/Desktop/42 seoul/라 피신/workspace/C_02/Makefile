CC=gcc
CFLAGS=-Wall -Wextra -Werror
EXNUM=$(ex)
SRC=$(wildcard ./ex$(EXNUM)/*.c)
TARGET=a.out
NFLAGS=-R CheckForbiddenSourceHeader

all : $(TARGET)

$(TARGET) : $(SRC) main$(EXNUM).c
	$(CC) $(CFLAGS) $(SRC) main$(EXNUM).c

norm : $(SRC)
	norminette $(NFLAGS) $(SRC)

clean : 
	rm $(TARGET)
