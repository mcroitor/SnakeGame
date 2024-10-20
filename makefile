CC=g++
CXXFLAGS=-std=c++17 -Wall -Wextra -pedantic -g

SRCDIR=src
OBJDIR=obj
BINDIR=bin
APPNAME=Snake
DLLS=apple.dll board.dll direction.dll point.dll snake.dll

RM=rm -f
MD=mkdir -p

all: init $(APPNAME)

init:
	$(MD) $(OBJDIR) $(BINDIR)

$(APPNAME): game_engine.o painter.o main.o $(DLLS)
	$(CC) -o $(BINDIR)/$(APPNAME) \
		$(OBJDIR)/game_engine.o $(OBJDIR)/painter.o $(OBJDIR)/main.o \
		-L$(BINDIR) -lapple -lboard -ldirection -lpoint -lsnake

apple.o:
	$(CC) $(SRCDIR)/apple.cpp -o $(OBJDIR)/apple.o -c

board.o:
	$(CC) $(SRCDIR)/board.cpp -o $(OBJDIR)/board.o -c

direction.o:
	$(CC) $(SRCDIR)/direction.cpp -o $(OBJDIR)/direction.o -c

game_engine.o:
	$(CC) $(SRCDIR)/game_engine.cpp -o $(OBJDIR)/game_engine.o -c

painter.o:
	$(CC) $(SRCDIR)/painter.cpp -o $(OBJDIR)/painter.o -c

point.o:
	$(CC) $(SRCDIR)/point.cpp -o $(OBJDIR)/point.o -c

snake.o:
	$(CC) $(SRCDIR)/snake.cpp -o $(OBJDIR)/snake.o -c

main.o:
	$(CC) $(SRCDIR)/main.cpp -o $(OBJDIR)/main.o -c

apple.dll: point.dll
	$(CC) $(OBJDIR)/apple.o -shared -o $(BINDIR)/apple.dll -L$(BINDIR) -lpoint

board.dll: point.dll
	$(CC) $(OBJDIR)/board.o -shared -o $(BINDIR)/board.dll -L$(BINDIR) -lpoint

direction.dll:
	$(CC) $(OBJDIR)/direction.o -shared -o $(BINDIR)/direction.dll

point.dll:
	$(CC) $(OBJDIR)/point.o -shared -o $(BINDIR)/point.dll

snake.dll: point.dll apple.dll
	$(CC) $(OBJDIR)/snake.o -shared -o $(BINDIR)/snake.dll -L$(BINDIR) -lpoint -lapple

clean:
	$(RM) $(OBJDIR)/*.o $(BINDIR)/$(APPNAME)
