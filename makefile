CXX=g++

BINDIR=bin
OBJDIR=obj
SRCDIR=src

OBJECTS=$(OBJDIR)/apple.o \
	$(OBJDIR)/board.o \
	$(OBJDIR)/direction.o \
	$(OBJDIR)/game_engine.o \
	$(OBJDIR)/painter.o \
	$(OBJDIR)/point.o \
	$(OBJDIR)/snake.o \
	$(OBJDIR)/main.o

APP=$(BINDIR)/SnakeGame

all: $(SRCDIR) $(OBJDIR) $(BINDIR) $(APP)

$(SRCDIR):

$(OBJDIR):
	mkdir $(OBJDIR)

$(BINDIR):
	mkdir $(BINDIR)

$(APP): $(OBJECTS)
	$(CXX) -o $(APP) $(OBJECTS)

$(OBJDIR)/apple.o: $(SRCDIR)/apple.cpp
	$(CXX) $(SRCDIR)/apple.cpp -o $(OBJDIR)/apple.o -c

$(OBJDIR)/board.o: $(SRCDIR)/board.cpp
	$(CXX) $(SRCDIR)/board.cpp -o $(OBJDIR)/board.o -c

$(OBJDIR)/direction.o: $(SRCDIR)/direction.cpp
	$(CXX) $(SRCDIR)/direction.cpp -o $(OBJDIR)/direction.o -c

$(OBJDIR)/game_engine.o: $(SRCDIR)/game_engine.cpp
	$(CXX) $(SRCDIR)/game_engine.cpp -o $(OBJDIR)/game_engine.o -c

$(OBJDIR)/painter.o: $(SRCDIR)/painter.cpp
	$(CXX) $(SRCDIR)/painter.cpp -o $(OBJDIR)/painter.o -c

$(OBJDIR)/point.o: $(SRCDIR)/point.cpp
	$(CXX) $(SRCDIR)/point.cpp -o $(OBJDIR)/point.o -c

$(OBJDIR)/snake.o: $(SRCDIR)/snake.cpp
	$(CXX) $(SRCDIR)/snake.cpp -o $(OBJDIR)/snake.o -c

$(OBJDIR)/main.o: $(SRCDIR)/main.cpp
	$(CXX) $(SRCDIR)/main.cpp -o $(OBJDIR)/main.o -c

clean:
	rm -f $(OBJDIR)/*.o $(BINDIR)/*.exe