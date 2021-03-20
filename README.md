# TUM-MSE-Engineering-Informatics-Basic-C-summary
This repository contains the summary of all course contents from Engineering Informatics I at TUM (Technical University Munich) MSE (Munich School of Engineering).

Main contents: Introduction into the programming language C and programming language theory. 
All knowledge presented in this paper is derived from lecture contents. These lectures took place in the wintersemester 2020/2021, lead by Prof. Dr. Bjoern Menze 
(Chair for Computer Aided Medical Procedures & Augmented Reality).

## TicTacToe
Additionally there was added an implementation of a TicTacToe game, which is closely related to the lecture contents. There exist two versions of this game. 
- TicTacToe for two human opponents
- TicTacToe with intelligent computer opponent.

For the intelligent opponent decission trees were used in form of the minimax algorithm. For nearer information on the standard minimax algorithm https://www.geeksforgeeks.org/minimax-algorithm-in-game-theory-set-1-introduction/. This basic algorithm was adapted to TicTacToe, such that there are three possible outcomes, which are 1 (computer wins), 0 (tied game), -1 (human wins). The human player is the minimizer, as he chooses the best possible for him and the maximising player is the computer. In order to find the shortest possible path to win for the computer, thedepth of the tree is included into backtracking.
