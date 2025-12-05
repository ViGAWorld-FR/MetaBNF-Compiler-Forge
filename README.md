# MetaBNF-Compiler-Forge
EN:
*A eBNF grammar that forges its own compiler — maybe the world’s smallest yet most powerful.*

FR:
La plus petite et la plus puissante forge de compilateurs au monde.
*Une eBNF grammaire qui forge son propre compilateur — sans doute la plus petite et la plus puissante au monde.*  

EN:
## Overview
MetaBNF‑Compiler‑Forge is a self‑referential EBNF grammar and a compiler generator in C.

This project demonstrates how a grammar can describe itself in just a few lines, produce C source code, and self‑generate into a C file identical to the original program that analyzed the grammar.

By simply adding external terminals, the grammar can be turned into a parser, a compiler, or an automaton driven by its text input.

Each new external terminal must be linked to a function of the same name in a C source file, which will be automatically invoked during parsing.

I wrote this program in 1991. It uses the C language syntax as it was at that time. The original 1991 version was compiled with llc, and the files were named in uppercase letters under MS‑DOS.


### 🔧 Usage under Linux in a terminal
make
# ==> generates the executable: bnf

bnf<grammaire>test.c
# ==> analyzes the grammar and generates the source code test.c
#     which is equivalent to the previously compiled bnf.c
#     and directly compilable with the command:

gcc -std=gnu90 test.c

# Then, to build a new automaton, simply add
# a terminal element named <disbonjour> in the grammar
# so that the C function disbonjour() is automatically called.
# The new grammar, called gramtest, will be compiled as follows:

bnf<gramtest>test.c
gcc -std=gnu90 test.c disbonjour.c

---

## Présentation
MetaBNF‑Compiler‑Forge est une grammaire EBNF auto‑référentielle et un générateur de compilateurs en C.

Ce projet démontre comment une grammaire peut se décrire elle‑même en quelques lignes, produire du code source C, et s’auto‑générer en un fichier C identique au programme d’origine ayant analysé la grammaire.

Il suffit ensuite d’ajouter des terminaux externes pour transformer cette grammaire en un analyseur syntaxique, un compilateur ou un automate commandé par son entrée texte.

Chaque nouveau terminal externe doit être associé à une fonction de même nom dans un fichier source C, laquelle sera appelée automatiquement lors de l’analyse.

J’ai écrit ce programme en 1991. Il utilise la syntaxe du langage C telle qu’elle était en vigueur à l’époque. La version originale de 1991 était compilée avec llc, et les fichiers étaient nommés en lettres majuscules sous MS‑DOS.

### 🔧 Utilisation sous Linux dans un terminal
make
# ==> génère l'exécutable : bnf

bnf < grammaire > test.c
# ==> analyse la grammaire et génère le code source test.c
#     équivalent au fichier bnf.c précédemment compilé
#     et directement compilable par la commande :

gcc -std=gnu90 test.c

# Ensuite, pour construire un nouvel automate, il suffit d'ajouter
# un élément terminal nommé <disbonjour> dans la grammaire
# pour que la fonction C disbonjour() soit automatiquement appelée.
# La nouvelle grammaire appelée gramtest va être compilée ainsi :

bnf < gramtest > test.c
gcc -std=gnu90 test.c disbonjour.c

