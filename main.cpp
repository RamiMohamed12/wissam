#include <iostream>
#include <string>
#include "ModeConsole.h"
#include "ModeGraphique.h"
#include "FileService.h"
#include "Jeu.h"
#include <filesystem>

void afficherMenu() {
    std::cout << "=============================\n";
    std::cout << "  Jeu de la Vie - Menu\n";
    std::cout << "=============================\n";
    std::cout << "1. Mode Console\n";
    std::cout << "2. Mode Graphique\n";
    std::cout << "3. Quitter\n";
    std::cout << "Choisissez une option : ";
}

int main() {
    int choix;
    do {
        afficherMenu();
        std::cin >> choix;

        switch (choix) {
            case 1: { // Mode Console
                std::string inputFile = "FichierInitial.txt";
                std::string outputDir = "output";

                try {
                    std::cout << "Chargement de la grille depuis : " << inputFile << "\n";
                    Grille grille = FileService::ChargerDuFichier(inputFile);
                    
                    int iterations;
                    std::cout << "Entrez le nombre d'itérations : ";
                    std::cin >> iterations;

                    // Create new game with loaded grid
                    Jeu jeu(grille, iterations);
                    
                    // Create output directory if it doesn't exist
                    std::filesystem::create_directories(outputDir);
                    
                    jeu.Simulation(outputDir);

                    std::cout << "Simulation console terminée avec succès.\n";
                    std::cout << "Les résultats sont enregistrés dans : " << outputDir << "\n";
                }
                catch (const std::exception& e) {
                    std::cerr << "Erreur : " << e.what() << "\n";
                }
                break;
            }

            case 2: { // Mode Graphique
                std::string inputFile = "FichierInitial.txt";

                try {
                    std::cout << "Chargement de la grille depuis : " << inputFile << "\n";
                    Grille grille = FileService::ChargerDuFichier(inputFile);

                    int refreshRate;
                    std::cout << "Entrez le taux de rafraîchissement (ms) : ";
                    std::cin >> refreshRate;

                    ModeGraphique modeGraphique(grille, refreshRate); // Modified constructor
                    modeGraphique.run();
                }
                catch (const std::exception& e) {
                    std::cerr << "Erreur : " << e.what() << "\n";
                }
                break;
            }

            case 3:
                std::cout << "Merci d'avoir utilisé le Jeu de la Vie. À bientôt !\n";
                break;

            default:
                std::cerr << "Option invalide. Veuillez réessayer.\n";
                break;
        }
    } while (choix != 3);

    return 0;
}
