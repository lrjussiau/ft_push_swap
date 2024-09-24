# Push_swap - Sorting Algorithm Project

## Description

*Push_swap* est un projet de l'école 42 qui consiste à trier une pile d'entiers en utilisant un ensemble limité d'opérations de pile. Ce projet met l'accent sur l'optimisation des algorithmes pour trier efficacement la pile avec le moins d'instructions possible. C'est un défi qui combine à la fois des compétences en algorithmique et une compréhension de la gestion de la mémoire en C.

## Objectifs du projet

- Implémenter des algorithmes de tri efficaces.
- Optimiser le nombre de mouvements nécessaires pour trier une pile.
- Comprendre les structures de données comme les piles (LIFO).
- Développer des compétences en gestion de la complexité algorithmique.

## Fonctionnalités

Le projet utilise plusieurs opérations pour manipuler deux piles : `a` et `b`. Voici un aperçu des opérations disponibles :

### Opérations sur les piles

- `sa`: Échanger les deux premiers éléments de la pile `a`.
- `sb`: Échanger les deux premiers éléments de la pile `b`.
- `ss`: Effectuer `sa` et `sb` en même temps.
- `pa`: Empiler l'élément du dessus de la pile `b` sur la pile `a`.
- `pb`: Empiler l'élément du dessus de la pile `a` sur la pile `b`.
- `ra`: Faire tourner la pile `a` vers le haut (décalage de tous les éléments).
- `rb`: Faire tourner la pile `b` vers le haut.
- `rr`: Effectuer `ra` et `rb` en même temps.
- `rra`: Faire tourner la pile `a` vers le bas (rotation inversée).
- `rrb`: Faire tourner la pile `b` vers le bas.
- `rrr`: Effectuer `rra` et `rrb` en même temps.

## Installation

Pour utiliser le projet *push_swap*, clonez le dépôt, compilez-le, et exécutez-le avec les nombres à trier en tant qu'arguments.

\`\`\`bash
git clone https://github.com/votre-repo/push_swap.git
cd push_swap
make
\`\`\`

Ensuite, exécutez le programme avec une liste d'entiers en arguments :

\`\`\`bash
./push_swap 5 2 3 6 1 8
\`\`\`

## Usage

L'objectif est de générer une suite d'instructions pour trier les nombres donnés en argument, tout en minimisant le nombre de mouvements effectués.

Voici comment exécuter le programme et obtenir le nombre d'instructions :

\`\`\`bash
./push_swap 4 67 3 87 23
\`\`\`

## Analyse de la complexité

L'une des parties clés de ce projet est d'analyser et d'optimiser la complexité des algorithmes. Vous devrez évaluer votre solution en termes de nombre de mouvements pour différentes tailles de piles.

## Tests

Pour tester l'efficacité de votre algorithme, vous pouvez utiliser le programme `checker`, qui vérifie si les nombres sont correctement triés après avoir appliqué les instructions générées par *push_swap*.

\`\`\`bash
ARG="4 67 3 87 23"; ./push_swap $ARG | ./checker $ARG
\`\`\`

## Auteur

- **Louis** - Étudiant à 42 Lausanne
