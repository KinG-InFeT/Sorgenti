#0xChat file Makefile

VERSION = 0.0.1

# flags
CFLAGS = -DVERSION=\"${VERSION}\"

SERVER = src/server.c
BINS = server

CLIENT = src/client.c
BINC = client

all:
	gcc -o $(BINS) $(SERVER) $(CFLAGS)
	gcc -o $(BINC) $(CLIENT) $(CFLAGS)

clean:
	rm -f $(BINS)
	rm -f $(BINC)
	rm -f /usr/bin/$(BINS)
	rm -f /usr/bin/$(BINC)

install: all
	
	cp -f $(BINS) /usr/bin/
	cp -f $(BINC) /usr/bin/

#DO NOT DELETE!
