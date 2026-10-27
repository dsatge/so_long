# so_long — Jeu 2D en C avec la MiniLibX

![Screenshot of so_long game.](/assets/images/gamescreenshot.png)
so_long est un projet de l'école 42 dont l'objectif est de développer un petit jeu vidéo 2D en vue du dessus en langage C. Le joueur y incarne un personnage devant ramasser tous les consommables d'une carte fermée avant de rejoindre la sortie en un minimum de déplacements.
Enjeux et objectifs pédagogiques
Ce projet marque une transition clé dans le cursus : le passage de programmes purement textuels dans le terminal à une interface graphique interactive gérée par des fenêtres et des événements.
Gestion événementielle : intercepter et traiter les entrées clavier (déplacements, fermeture) et les interactions système en temps réel via des boucles d'événements.
- **Algorithmique et parsing** : valider la conformité d'une carte .ber (dimensions rectangulaires, clôture complète par des murs, présence exacte des éléments requis) et vérifier son accessibilité (ex. algorithme de Flood Fill pour s'assurer que la sortie et les items sont atteignables).
- **Rendu graphique 2D** : charger et convertir des sprites au format XPM en mémoire pour les positionner sur une grille dynamique de tuiles.
- **Gestion mémoire rigoureuse** : allouer et libérer l'ensemble des buffers, textures, fenêtres et contextes graphiques sans fuite de mémoire ni segfault à la fermeture du programme.

## Contraintes techniques
Le projet initial est soumis aux standards de l'école 42 :
Langage C et respect strict de la Norme 42 (limite de fonctions par fichier, de lignes par fonction, interdiction de certaines structures de contrôle, etc.), le projet ayant par la suite été plus approfondi, certaines règles auront été compromises tel que l'ajout de variable statiques et certaines fonction dépassant les 25 lignes pour permettre plus de lisibilité dans le code.\
Composants obligatoires de la carte :
- 1 : Mur
- 0 : Sol vide
- C : Consommable / Collectible (au moins un)
- E : Sortie (exactement une)
- P : Position de départ du joueur (exactement une)
- T : Pièges (optionnel) 

Contraintes d'affichage : afficher le nombre de pas en direct (dans le terminal ou sur la fenêtre) et quitter proprement à l'appui sur Échap ou au clic sur la croix rouge de la fenêtre.

## La MiniLibX et la portabilité (Linux / macOS vs Windows)
Le moteur graphique repose sur la MiniLibX, une bibliothèque simplifiée développée pour les étudiants de 42 servant d'interface d'accès bas niveau au serveur d'affichage graphique.

### *Pourquoi le jeu ne tourne-t-il que sur macOS et Linux ?*
La MiniLibX n'est pas une bibliothèque portable et agnostique du système : elle a été conçue pour s'interfacer directement avec les couches graphiques natives des environnements Unix :
- **Sous Linux** : la MiniLibX s'appuie sur le protocole X11 / Xlib. Elle dialogue directement avec le serveur d'affichage X (gestion des fenêtres, capture des signaux d'événements matériels via X11).
- **Sous macOS** : elle repose sur l'API native d'Apple, Cocoa / AppKit (en Objective-C), combinée historiquement à OpenGL pour le tracé des pixels dans les vues fenêtrées.
- **Sous Windows** : le système d'exploitation Windows utilise son propre gestionnaire d'affichage (Desktop Window Manager et l'API Win32 / DirectX). Ne disposant nativement ni d'un serveur X11 ni des frameworks Apple, le binaire ne peut pas s'exécuter sous Windows. Pour le faire tourner sur une machine Windows, il est obligatoire de passer par WSL2 avec un serveur d'affichage X11 (comme VcXsrv ou WSLg).

Le projet a été initialement réalisé à destination de Linux, par la suite, il a été développé pour fonctionner également sous macOS et rendre la portabilité la plus simple pour les utilisateurs via le Makefile. Le Makefile détecte automatiquement l'OS hôte (uname -s) pour lier la version correspondante de la MiniLibX et ses dépendances spécifiques (-framework OpenGL -framework AppKit sur Mac, -lXext -lX11 -lm sur Linux).

## Compilation et exécution

### Prérequis

Un environnement de développement macOS ou Linux (Debian/Ubuntu recommandé). \
Les outils de compilation standards : clang ou gcc, et make. \
Sur Linux uniquement : les paquets X11 et Xext installés sur la machine : \
Bash : \
`sudo apt-get update && sudo apt-get install libxext-dev libx11-dev libbsd-dev` \

### Compilation

Clone le dépôt et lance la compilation à la racine : \
Bash : \
`git clone <URL_DU_DEPOT> so_long` \
`cd so_long` \
`make so_long` \
Cette commande compile les dépendances internes (libft, ft_printf, MiniLibX) puis génère l'exécutable so_long.

### Lancer le jeu

Passe un fichier de carte valide au format .ber en argument : \
Bash \
`./so_long maps/valid/map.ber` \

### Commandes en jeu

Action	macOS	Linux \
Déplacement	W, A, S, D ou Flèches	W/Z, A/Q, S, D ou Flèches \
Quitter le jeu	Touche Échap (ESC) ou Croix de la fenêtre	Touche Échap (ESC) ou Croix de la fenêtre.

### Règles du Makefile

- **make** : compile le projet.
- **make clean** : supprime les fichiers objets intermédiaires (.o).
- **make fclean** : effectue un clean et supprime l'exécutable so_long ainsi que les archives .a.
- **make re** : recompile l'intégralité du projet à partir de zéro.
