/*
 * @lc app=leetcode id=289 lang=cpp
 *
 * [289] Game of Life
 *
 * https://leetcode.com/problems/game-of-life/description/
 *
 * algorithms
 * Medium (44.04%)
 * Total Accepted:    104.6K
 * Total Submissions: 237.5K
 * Testcase Example:  '[[0,1,0],[0,0,1],[1,1,1],[0,0,0]]'
 *
 * According to the Wikipedia's article: "The Game of Life, also known simply
 * as Life, is a cellular automaton devised by the British mathematician John
 * Horton Conway in 1970."
 * 
 * Given a board with m by n cells, each cell has an initial state live (1) or
 * dead (0). Each cell interacts with its eight neighbors (horizontal,
 * vertical, diagonal) using the following four rules (taken from the above
 * Wikipedia article):
 * 
 * 
 * Any live cell with fewer than two live neighbors dies, as if caused by
 * under-population.
 * Any live cell with two or three live neighbors lives on to the next
 * generation.
 * Any live cell with more than three live neighbors dies, as if by
 * over-population..
 * Any dead cell with exactly three live neighbors becomes a live cell, as if
 * by reproduction.
 * 
 * 
 * Write a function to compute the next state (after one update) of the board
 * given its current state. The next state is created by applying the above
 * rules simultaneously to every cell in the current state, where births and
 * deaths occur simultaneously.
 * 
 * Example:
 * 
 * 
 * Input: 
 * [
 * [0,1,0],
 * [0,0,1],
 * [1,1,1],
 * [0,0,0]
 * ]
 * Output: 
 * [
 * [0,0,0],
 * [1,0,1],
 * [0,1,1],
 * [0,1,0]
 * ]
 * 
 * 
 * Follow up:
 * 
 * 
 * Could you solve it in-place? Remember that the board needs to be updated at
 * the same time: You cannot update some cells first and then use their updated
 * values to update other cells.
 * In this question, we represent the board using a 2D array. In principle, the
 * board is infinite, which would cause problems when the active area
 * encroaches the border of the array. How would you address these problems?
 * 
 * 
 */
class Solution {
public:
    int computePoplation(int i, int j, vector<vector<int>>& board) {
        int neighour = 0;
        for (int k = max(0, i - 1); k <= min(i + 1); ++k) {
            for (int l = max(0, j - 1); l <= min(j + 1); ++l) {
                if (k == i && l == i) {
                    continue;
                }

                neighour += board[k][l];
            }
        }

        return (neighour == 3) ? 1 : 0;
    }

    int computeReproduction(int i, int j, vector<vector<int>>& board) {
        int neighour = 0;
        for (int k = max(0, i - 1); k <= min(i + 1); ++k) {
            for (int l = max(0, j - 1); l <= min(j + 1); ++l) {
                if (k == i && l == i) {
                    continue;
                }

                neighour += board[k][l];
            }
        }

        return (neighour > 3 || neighour < 2) ? 0 : 1;
    }

    void gameOfLifeRecursive(vector<vector<int>>& population,
                    vector<vector<int>>& reproduction,
                    vector<vector<int>>& board) {
        bool isDone = true;
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[i].size(); ++j) {
                // compute poplation
                int num = computePoplation(i, j, board);
                population[i][j] = num;
                if (num != board[i][j]) {
                    isDone = false;
                }

                // compute reproduction
                num = computeReproduction(i, j, board);
                reproduction[i][j] = num;
                if (num != board[i][j]) {
                    isDone = false;
                }
            }
        }

        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[i].size(); ++j) {
                board[i][j] = population[i][j] | reproduction[i][j];
            }
        }

        if (!isDone) {
            gameOfLifeRecursive(poplation, reproduction, board);
        }
    }

    void gameOfLife(vector<vector<int>>& board) {
        vector<vector<int>> population(board);
        vector<vector<int>> reproduction(board);
        
        gameOfLifeRecursive(population, reproduction, board);
    }
};

