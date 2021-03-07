CC=gcc
CFLAGS=-g -Wall

BIN=up

all: $(BIN);

%: %.c
	$(CC) $(CFLAGS) $< -o $@ -lcurl

clean:
	$(RM) -rf $(BIN) *.dYSM
