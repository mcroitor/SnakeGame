CC=g++
CXXFLAGS=-std=c++17 -Wall -Wextra -pedantic -g

SRCDIR=src
OBJDIR=obj
BINDIR=bin
TESTSDIR=tests

APPNAME=Snake
DLLS=apple.dll board.dll direction.dll point.dll snake.dll
LDFLAGS=-L$(BINDIR) -lapple -lboard -ldirection -lpoint -lsnake
TESTS=$(wildcard $(TESTSDIR)/*.cpp)

RM=rm -f
MD=mkdir -p

all: init $(APPNAME)

init:
	$(MD) $(OBJDIR) $(BINDIR)

$(APPNAME): game_engine.o painter.o main.o $(DLLS)
	$(CC) -o $(BINDIR)/$(APPNAME) \
		$(OBJDIR)/game_engine.o $(OBJDIR)/painter.o $(OBJDIR)/main.o \
		$(LDFLAGS)

apple.o: $(SRCDIR)/apple.cpp
	$(CC) $(SRCDIR)/apple.cpp -o $(OBJDIR)/apple.o -c

board.o: $(SRCDIR)/board.cpp
	$(CC) $(SRCDIR)/board.cpp -o $(OBJDIR)/board.o -c

direction.o: $(SRCDIR)/direction.cpp
	$(CC) $(SRCDIR)/direction.cpp -o $(OBJDIR)/direction.o -c

game_engine.o: $(SRCDIR)/game_engine.cpp
	$(CC) $(SRCDIR)/game_engine.cpp -o $(OBJDIR)/game_engine.o -c

painter.o: $(SRCDIR)/painter.cpp
	$(CC) $(SRCDIR)/painter.cpp -o $(OBJDIR)/painter.o -c

point.o: $(SRCDIR)/point.cpp
	$(CC) $(SRCDIR)/point.cpp -o $(OBJDIR)/point.o -c

snake.o: $(SRCDIR)/snake.cpp
	$(CC) $(SRCDIR)/snake.cpp -o $(OBJDIR)/snake.o -c

main.o: $(SRCDIR)/main.cpp
	$(CC) $(SRCDIR)/main.cpp -o $(OBJDIR)/main.o -c

apple.dll: apple.o point.dll
	$(CC) $(OBJDIR)/apple.o -shared -o $(BINDIR)/apple.dll -L$(BINDIR) -lpoint

board.dll: board.o point.dll
	$(CC) $(OBJDIR)/board.o -shared -o $(BINDIR)/board.dll -L$(BINDIR) -lpoint

direction.dll: direction.o
	$(CC) $(OBJDIR)/direction.o -shared -o $(BINDIR)/direction.dll

point.dll: point.o
	$(CC) $(OBJDIR)/point.o -shared -o $(BINDIR)/point.dll

snake.dll: snake.o point.dll apple.dll
	$(CC) $(OBJDIR)/snake.o -shared -o $(BINDIR)/snake.dll -L$(BINDIR) -lpoint -lapple

clean:
	$(RM) $(OBJDIR)/*.o  $(BINDIR)/*.dll $(BINDIR)/$(APPNAME) $(BINDIR)/tests

tests: apple.dll board.dll direction.dll point.dll snake.dll
	$(CC) $(TESTSDIR)/catch2/catch_amalgamated.cpp $(TESTS) \
		-o $(BINDIR)/tests -I$(TESTSDIR) -I$(TESTSDIR)/catch2 -I$(SRCDIR) \
		$(CXXFLAGS) $(LDFLAGS) -L$(BINDIR) -lapple -lboard -ldirection -lpoint -lsnake
	$(BINDIR)/tests --verbosity=high
