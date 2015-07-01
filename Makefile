# We are compiling final
EXE=final

# Main target
all: $(EXE)

# Variables for readability
AUX=src/auxiliary/
OBJ=src/objects/
AUXLIB=$(AUX)print.o $(AUX)project.o $(AUX)loadtexbmp.o $(AUX)errcheck.o $(AUX)fatal.o $(AUX)vertex.o $(AUX)point_camera.o $(AUX)animate_scene.o $(AUX)particles.o $(AUX)update_particles.o $(AUX)draw_particles.o
OBJLIB=$(OBJ)axes.o $(OBJ)board.o $(OBJ)cylinder.o $(OBJ)sphere.o $(OBJ)cone.o $(OBJ)hourglass.o $(OBJ)fountain.o $(OBJ)fountain_side.o $(OBJ)grass_blade.o $(OBJ)grass_block.o $(OBJ)hourglass_side.o $(OBJ)tree.o

#  MinGW
ifeq "$(OS)" "Windows_NT"
CFLG=-O3 -Wall
LIBS=-lglut32cu -lglu32 -lopengl32
CLEAN=del *.exe *.o *.a
else
#  OSX
ifeq "$(shell uname)" "Darwin"
CFLG=-O3 -Wall -Wno-deprecated-declarations
LIBS=-framework GLUT -framework OpenGL
#  Linux/Unix/Solaris
else
CFLG=-O3 -Wall
LIBS=-lglut -lGLU -lGL -lm
endif
#  OSX/Linux/Unix/Solaris
CLEAN=rm -f $(EXE) src/*.o src/*.a $(AUX)*.o $(OBJ)*.o
endif

# Dependencies
# Auxiliary
src/main.o: src/main.c src/main.h
src/auxiliary/print.o: $(AUX)print.c src/main.h
src/auxiliary/project.o: $(AUX)project.c src/main.h
src/auxiliary/loadtexbmp.o: $(AUX)loadtexbmp.c src/main.h
src/auxiliary/errcheck.o: $(AUX)errcheck.c src/main.h
src/auxiliary/fatal.o: $(AUX)fatal.c src/main.h
src/auxiliary/vertex.o: $(AUX)vertex.c src/main.h
src/auxiliary/point_camera.o: $(AUX)point_camera.c src/main.h
src/auxiliary/animate_scene.o: $(AUX)animate_scene.c src/main.h
src/auxiliary/particles.o: $(AUX)particles.c src/main.h
src/auxiliary/update_particles.o: $(AUX)update_particles.c src/main.h
src/auxiliary/draw_particles.o: $(AUX)draw_particles.c src/main.h
# Objects
src/objects/axes.o: $(OBJ)axes.c src/main.h
src/objects/board.o: $(OBJ)board.c src/main.h
src/objects/cylinder.o: $(OBJ)cylinder.c src/main.h
src/objects/sphere.o: $(OBJ)sphere.c src/main.h
src/objects/cone.o: $(OBJ)cone.c src/main.h
src/objects/hourglass.o: $(OBJ)hourglass.c src/main.h
src/objects/fountain.o: $(OBJ)fountain.c src/main.h
src/objects/fountain_side.o: $(OBJ)fountain_side.c src/main.h
src/objects/grass_blade.o: $(OBJ)grass_blade.c src/main.h
src/objects/grass_block.o: $(OBJ)grass_block.c src/main.h
src/objects/hourglass_side.o: $(OBJ)hourglass_side.c src/main.h
src/objects/tree.o: $(OBJ)tree.c src/main.h

# Create archives
src/main.a:$(AUXLIB) $(OBJLIB)
	ar -rcs $@ $^

# Compile rules
src/%.c.o:
	gcc -c $(CFLG) $<
src/%.cpp.o:
	g++ -c $(CFLG) $<
src/auxiliary/%.c.o:
	gcc -c $(CFLG) $<
src/%.cpp.o:
	g++ -c $(CFLG) $<

# Link
final:src/main.o src/main.a
	gcc -O3 -o $@ $^ $(LIBS)

# Clean
clean:
	$(CLEAN)	