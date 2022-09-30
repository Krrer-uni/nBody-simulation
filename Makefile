CC = g++
IDIR = ../include
SDLDIR=/usr/include/SDL2
CFLAGS=-I$(SDLDIR) -I$(IDIR) -g

ODIR=obj

_OBJ = CApp_OnCleanup.o CApp_OnEvent.o CApp_OnInit.o CApp_OnLoop.o CApp_OnRender.o utility.o planet.o quadtree.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))


LINKER_FLAGS = -lSDL2
DEPS = CApp.h

$(ODIR)/%.o : %.cpp $(DEPS)
	$(CC)  -o $@ -c $< $(CFLAGS) $(LINKER_FLAGS)

CApp: $(OBJ) CApp.cpp
	$(CC) -o $@  $^ $(CFLAGS) $(LINKER_FLAGS)
	