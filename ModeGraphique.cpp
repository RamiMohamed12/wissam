#include "ModeGraphique.h"
#include <thread>
#include <chrono>

ModeGraphique::ModeGraphique(const Grille& initialGrille, int refreshRate)
    : grille(initialGrille),
      window(sf::VideoMode(initialGrille.getLargeur() * 20, initialGrille.getLongueur() * 20), "Jeu de la Vie"),
      largeurCellule(20),
      longueurCellule(20),
      refreshRate(refreshRate)
{
}

void ModeGraphique::run() {
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        grille.MiseAJourGrille();
        drawGrid();
        std::this_thread::sleep_for(std::chrono::milliseconds(refreshRate));
    }
}

void ModeGraphique::drawGrid() {
    window.clear(sf::Color::Black);

    for (int i = 0; i < grille.getLongueur(); ++i) {
        for (int j = 0; j < grille.getLargeur(); ++j) {
            sf::RectangleShape cellule(sf::Vector2f(static_cast<float>(largeurCellule), 
                                                   static_cast<float>(longueurCellule)));
            cellule.setPosition(static_cast<float>(j * largeurCellule), 
                              static_cast<float>(i * longueurCellule));

            if (grille.getEtat(i, j)) {
                cellule.setFillColor(sf::Color::Green);
            }
            else {
                cellule.setFillColor(sf::Color::Black);
            }

            cellule.setOutlineThickness(1);
            cellule.setOutlineColor(sf::Color::White);
            window.draw(cellule);
        }
    }

    window.display();
}
