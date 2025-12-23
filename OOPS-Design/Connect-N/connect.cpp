#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

enum GridPosition {
    EMPTY, YELLOW, RED
};

class Grid {
private:
    int rows;
    int columns;
    vector<vector<int>> grid;
public:
    Grid(int rows, int columns) {
        this->rows = rows;
        this->columns = columns;
        initGrid();
    }

    void initGrid() {
        this->grid = vector<vector<int>>();
        for (int i = 0; i < rows; i++) {
            this->grid.push_back(vector<int>());
            for (int j = 0; j < columns; j++) {
                grid[i].push_back(GridPosition::EMPTY);
            }
        }
    }

    vector<vector<int>> getGrid() {
        return this->grid;
    }

    int getColumnCount() {
        return this->columns;
    }

    int placePiece(int column, GridPosition piece) {
        if (column < 0 || column >= this->columns) {
            throw "Invalid Column";
        }
        if (piece == GridPosition::EMPTY) {
            throw "Invalid Piece";
        }
        // place piece in the lowest empty row
        for (int row = this->rows - 1; row >= 0; row--) {
            if (this->grid[row][column] == GridPosition::EMPTY) {
                this->grid[row][column] = piece;
                return row;
            }
        }
        return -1;
    }

    /*
    bool checkWin(int connectN, int row, int col, GridPosition piece) {
        // horizontal
        int count = 0;
        for (int c = 0; c < this->columns; c++) {
            if (this->grid[row][c] == piece) count++;
            else count = 0;
            if (count == connectN) return true;
        }

        // vertical
        count = 0;
        for (int r = 0; r < this->rows; r++) {
            if (this->grid[r][col] == piece) count++;
            else count = 0;
            if (count == connectN) return true;
        }

        // diagonal
        count = 0;
        for (int r = 0; r < this->rows; r++) {
            int c = row + col - r;
            if (c >= 0 && c < this->columns && this->grid[r][c] == piece) count++;
            else count = 0;
            if (count == connectN) return true;
        }

        // anti-diagonal
        count = 0;
        for (int r = 0; r < this->rows; r++) {
            int c = row - col + r;
            if (c >= 0 && c < this->columns && this->grid[r][c] == piece) count++;
            else count = 0;
            if (count == connectN) return true;
        }

        return false;
    }
    */

    bool checkWin(int connectN, int row, int col, GridPosition piece) {
        vector<pair<int, int>> directions = {
            {0, 1},    // horizontal
            {1, 0},    // vertical
            {1, 1},    // diagonal
            {1, -1},   // anti-diagonal
        };

        for (auto [dr, dc]: directions) {
            int count = 1; // count the current piece

            // forward
            int r = row + dr, c = col + dc;
            while (r >= 0 && r < this->rows && c >= 0 && c <= this->columns && grid[r][c] == piece) {
                count++;
                r += dr;
                c += dc;
            }

            // backward
            r = row - dr;
            c = col - dc;
            while (r >= 0 && r < this->rows && c >= 0 && c < this->columns && grid[r][c] == piece) {
                count++;
                r -= dr;
                c -= dc;
            }

            if (count >= connectN) {
                return true;
            }
        }
        return false;
    }
};

class Player {
private:
    string name;
    GridPosition piece;
public:
    Player(string name, GridPosition piece) {
        this->name = name;
        this->piece = piece;
    }

    string getName() {
        return this->name;
    }

    GridPosition getPieceColor() {
        return this->piece;
    }
};

class Game {
private:
    Grid* grid;
    int connectN;
    vector<Player*> players;
    unordered_map<string, int> score;
    int targetScore;
public:
    Game(Grid* grid, int connectN, int targetScore) {
        this->grid = grid;
        this->connectN = connectN;
        this->targetScore = targetScore;

        this->players = vector<Player*> {
            new Player("Player 1", GridPosition::YELLOW),
            new Player("Player 2", GridPosition::RED)
        };

        this->score = unordered_map<string, int>();
        for (Player* player: this->players) {
            this->score[player->getName()] = 0;
        }
    }

    void printBoard() {
        cout << "Board: \n";
        vector<vector<int>> grid = this->grid->getGrid();
        for (int i = 0; i < grid.size(); i++) {
            string row = "";
            for (int piece: grid[i]) {
                if (piece == GridPosition::EMPTY) row += "0 ";
                else if (piece == GridPosition::YELLOW) row += "Y ";
                else if (piece == GridPosition::RED) row += "R ";
            }
            cout << row << "\n";
        }
        cout << "\n";
    }

    vector<int> playMove(Player* player) {
        printBoard();
        cout << player->getName() << "'s turn: \n";
        int colCnt = this->grid->getColumnCount();

        cout << "Enter column betwee 0 and " << (colCnt - 1) << " to add piece: ";
        int moveColumn = 0;
        cin >> moveColumn;

        int moveRow = this->grid->placePiece(moveColumn, player->getPieceColor());
        if (moveRow == -1) {
            throw "row is full";
        }
        return vector<int> {moveRow, moveColumn};
    }

    Player* playRound() {
        while (true) {
            for (Player* player: this->players) {
                vector<int> pos = playMove(player);
                int row = pos[0], col = pos[1];
                GridPosition pieceColor = player->getPieceColor();
                if (this->grid->checkWin(this->connectN, row, col, pieceColor)) {
                    this->score[player->getName()]++;
                    return player;
                }
            }
        }
    }

    void play() {
        int maxScore = 0;
        Player* winner = nullptr;
        while (maxScore < this->targetScore) {
            winner = playRound();
            cout << winner->getName() << " won the round.\n";
            maxScore = max(maxScore, this->score[winner->getName()]);

            this->grid->initGrid(); // reset the grid
        }
        cout << winner->getName() << " won the game.\n";
    }
};

int main(void) {
    Grid* grid = new Grid(6, 7);
    Game* game = new Game(grid, 4, 3);
    game->play();

    return 0;
}