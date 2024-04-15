/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrener- <kbrener-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 10:45:10 by kbrener-          #+#    #+#             */
/*   Updated: 2024/04/15 11:49:01 by kbrener-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
1. verifier qu'on a 2 arguments et que le fichier fini par .ber
2. check_map.c :
    - la map doit etre rectangulaire
    - la map doit contenir 1 sortie (E), au moins un item (C), une position de depart (P) (pas de doublons)
    - la map doit etre encadree par des murs
    - verifier qu'il existe un chemin valide
    -> si erreur, le programme retourne "Error\n" suivi d'un message d'erreur
3. construct_map.c :
    - map construite en utilisant 3 elements : murs, items et espaces vides
    - peut-etre compose de 5 elements : emplacements vides (0), murs (1), items (C), sortie (E), 
    position de depart (P)
4. player.c
    - doit collecter les items et rejoindre la sortie en empruntant le chemin le plus court
    - bouge avec les touches W (haut), A (gauche), S (bas), D (droite)
    - il ne doit pas pouvoir se deplacer dans les murs
    - le compte total des mouvements doit etre affiche dans le shell a chaque mouvement
    - utiliser une vue 2D (dos ou profil)
    - le jeu n'a pas a etre en temps reel
5. init_graphic.c :
    - le programme doit afficher une image dans une fenetre
    - gestion de la fenetre fluide
    - la touche ESC ou cliquer sur la croix, doit fermer la fenetre et quitter le programme
    - utiliser les images de la minilibx est obligatoire
6. bonus.c :
    - le joueur perd s'il est touche par une patrouille
    - on ajoute des sprites d'animation
    - le compte total des points est directement affiche dans la fenetre plutot que dans le shell
*/