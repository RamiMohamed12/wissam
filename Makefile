CXX = g++
CXXFLAGS = -Wall -std=c++17 -I.
LDFLAGS = -lsfml-graphics -lsfml-window -lsfml-system -lstdc++fs

SRCS = main.cpp Cellule.cpp CelluleMort.cpp CelluleVie.cpp Fichier.cpp FileService.cpp Grille.cpp Jeu.cpp ModeConsole.cpp ModeGraphique.cpp
OBJS = $(SRCS:.cpp=.o)
TARGET = GameOfLife

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) -o $@ $(OBJS) $(LDFLAGS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(TARGET) $(OBJS)

.PHONY: all clean
