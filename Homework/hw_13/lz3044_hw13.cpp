#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
using namespace std;

const int GRID_SIZE = 20;
const int INITIAL_ANTS = 100;
const int INITIAL_DOODLEBUGS = 5;

// Base class for all organisms
class Organism {
protected:
    int x, y; // position
    int timeSteps;
    bool hasMoved;
    char symbol;
public:
    Organism(int x, int y) : x(x), y(y), timeSteps(0), hasMoved(false) {}
    virtual ~Organism() {}

    virtual void move() = 0;
    virtual void breed() = 0;
    virtual bool isDoodlebug() const = 0;

    char getSymbol() const { return symbol; }

    void setMoved() { hasMoved = true; }
    bool getMoved() const { return hasMoved; }
    void resetMoved() { hasMoved = false; }

    int getX() const { return x; }
    int getY() const { return y; }
};

// Global grid
Organism* grid[GRID_SIZE][GRID_SIZE]; 

class Ant : public Organism {
public:
    Ant(int x, int y) : Organism(x, y) { symbol = 'o'; }

    bool isDoodlebug() const { return false; }

    void move();
    void breed();
};

class Doodlebug : public Organism {
private:
    int starveSteps;
public:
    Doodlebug(int x, int y) : Organism(x, y), starveSteps(0) { symbol = 'X'; }

    bool isDoodlebug() const { return true; }
    bool isStarved() { return starveSteps >= 3; }

    void move();
    void breed();
};

void Ant :: move() {
    if (hasMoved) return;

    // Random direction
    int direction = rand() % 4;
    int newX = x;
    int newY = y;

    switch (direction) {
        case 0: newY--; break; // Up
        case 1: newY++; break; // Down
        case 2: newX--; break; // Left
        case 3: newX++; break; // Right
    }

    // Check direction
    if (newX >= 0 && newX < GRID_SIZE && 
        newY >= 0 && newY < GRID_SIZE && 
        grid[newY][newX] == nullptr) {
        // Move to the new cell
        grid[newY][newX] = this;
        grid[y][x] = nullptr;
        x = newX;
        y = newY;
    }
    
    timeSteps++;
    hasMoved = true;
}

void Ant :: breed() {
    if (timeSteps >= 3) {
        vector<int> possibleDirections;

        // Check four directions
        for (int dir = 0; dir < 4; dir++) {
            int newX = x;
            int newY = y;
        
            switch (dir) {
                case 0: newY--; break; // Up
                case 1: newY++; break; // Down
                case 2: newX--; break; // Left
                case 3: newX++; break; // Right
            }

            if (newX >= 0 && newX < GRID_SIZE && 
                newY >= 0 && newY < GRID_SIZE && 
                grid[newY][newX] == nullptr) { 
                possibleDirections.push_back(dir);
            }
        }

        // Breed new ant
        if (!possibleDirections.empty()) {
            int selectDir = possibleDirections[rand() % possibleDirections.size()];

            int newX = x;
            int newY = y;
        
            switch (selectDir) {
                case 0: newY--; break; // Up
                case 1: newY++; break; // Down
                case 2: newX--; break; // Left
                case 3: newX++; break; // Right
            }

            grid[newY][newX] = new Ant(newX, newY);
            timeSteps = 0;
        }
    }
}

void Doodlebug :: move() {
    if (hasMoved) return;

    // Find ant
    vector<int> antDirections;

    for (int dir = 0; dir < 4; dir++) {
        int newX = x;
        int newY = y;
    
        switch (dir) {
            case 0: newY--; break; // Up
            case 1: newY++; break; // Down
            case 2: newX--; break; // Left
            case 3: newX++; break; // Right
        }

        if (newX >= 0 && newX < GRID_SIZE && 
            newY >= 0 && newY < GRID_SIZE && 
            grid[newY][newX] != nullptr && 
            !grid[newY][newX]->isDoodlebug()) { 
            antDirections.push_back(dir);
        }
    }
    
    // Eat ant
    if (!antDirections.empty()) {
        int selectDir = antDirections[rand() % antDirections.size()];

        int newX = x;
        int newY = y;
    
        switch (selectDir) {
            case 0: newY--; break; // Up
            case 1: newY++; break; // Down
            case 2: newX--; break; // Left
            case 3: newX++; break; // Right
        }

        delete grid[newY][newX];

        grid[newY][newX] = this;
        grid[y][x] = nullptr;

        x = newX;
        y = newY;
        starveSteps = 0;
    }
    else {
        // No ant to eat, random move
        int direction = rand() % 4;
        int newX = x;
        int newY = y;
    
        switch (direction) {
            case 0: newY--; break; // Up
            case 1: newY++; break; // Down
            case 2: newX--; break; // Left
            case 3: newX++; break; // Right
        }
    
        // Check direction
        if (newX >= 0 && newX < GRID_SIZE && 
            newY >= 0 && newY < GRID_SIZE && 
            grid[newY][newX] == nullptr) {
            // Move to the new cell
            grid[newY][newX] = this;
            grid[y][x] = nullptr;
            x = newX;
            y = newY;
        }
        starveSteps++;
    }

    timeSteps++;
    hasMoved = true;
}

void Doodlebug :: breed() {
    if (timeSteps >= 8) {
        vector<int> possibleDirections;

        // Check four directions
        for (int dir = 0; dir < 4; dir++) {
            int newX = x;
            int newY = y;
        
            switch (dir) {
                case 0: newY--; break; // Up
                case 1: newY++; break; // Down
                case 2: newX--; break; // Left
                case 3: newX++; break; // Right
            }

            if (newX >= 0 && newX < GRID_SIZE && 
                newY >= 0 && newY < GRID_SIZE && 
                grid[newY][newX] == nullptr) { 
                possibleDirections.push_back(dir);
            }
        }

        // Breed new doodlebug
        if (!possibleDirections.empty()) {
            int selectDir = possibleDirections[rand() % possibleDirections.size()];

            int newX = x;
            int newY = y;
        
            switch (selectDir) {
                case 0: newY--; break; // Up
                case 1: newY++; break; // Down
                case 2: newX--; break; // Left
                case 3: newX++; break; // Right
            }

            grid[newY][newX] = new Doodlebug(newX, newY);
            timeSteps = 0;
        }
    }
}


// Init grid with ants and doodlebugs
void initializeGrid() {
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            grid[i][j] = nullptr;
        }
    }

    int doodlebugsPlaced = 0;
    while (doodlebugsPlaced < INITIAL_DOODLEBUGS) {
        int x = rand() % GRID_SIZE;
        int y = rand() % GRID_SIZE;

        if (grid[y][x] == nullptr) {
            grid[y][x] = new Doodlebug(x, y);
            doodlebugsPlaced++;
        }
    }

    int antsPlaced = 0;
    while (antsPlaced < INITIAL_ANTS) {
        int x = rand() % GRID_SIZE;
        int y = rand() % GRID_SIZE;

        if (grid[y][x] == nullptr) {
            grid[y][x] = new Ant(x, y);
            antsPlaced++;
        }
    }
}

// Print grid
void printGrid() {
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            if (grid[i][j] == nullptr) {
                cout << "-";
            }
            else {
                cout << grid[i][j]->getSymbol();
            }
        }
        cout << endl;
    }
    cout << endl;

    // Count organisms
    int antCount = 0;
    int doodlebugCount = 0;
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            if (grid[i][j] != nullptr) {
                if (grid[i][j]->isDoodlebug()) {
                    doodlebugCount++;
                } else {
                    antCount++;
                }
            }
        }
    }
    cout << "Doodlebugs: " << doodlebugCount << ", Ants: " << antCount << endl;
}

// Rest moved flags
void resetMovedFlags() {
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            if (grid[i][j] != nullptr) {
                grid[i][j]->resetMoved();
            }
        }
    }
}

void doodlebugsMove() {
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            if (grid[i][j] != nullptr && 
                grid[i][j]->isDoodlebug() && 
                !grid[i][j]->getMoved()) {
                grid[i][j]->move();
            }
        }
    }
}

void antsMove() {
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            if (grid[i][j] != nullptr && 
                !grid[i][j]->isDoodlebug() && 
                !grid[i][j]->getMoved()) {
                grid[i][j]->move();
            }
        }
    }
}

void organismsBreed() {
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            if (grid[i][j] != nullptr) {
                grid[i][j]->breed();
            }
        }
    }
}

void removeStarved() {
    // Check for starving doodlebugs
    vector<Organism*> toRemove;
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            if (grid[i][j] != nullptr && grid[i][j]->isDoodlebug()) {
                if (static_cast<Doodlebug*>(grid[i][j])->isStarved()) {
                    toRemove.push_back(grid[i][j]);
                    grid[i][j] = nullptr;
                }
            }
        }
    }
    
    // Delete starved doodlebugs
    for (int i = 0; i < toRemove.size(); i++) {
        delete toRemove[i];
    }
    toRemove.clear();
}

int main () {
    srand(time(0));

    int time = 0;
    char input;

    initializeGrid();

    do {
        cout << "World at time " << time << ":" << endl;
        printGrid();
        cout << "Press ENTER to continue (q to quit): ";
        input = cin.get();
        
        if (input != 'q') {
            resetMovedFlags();
            doodlebugsMove();
            antsMove();
            removeStarved();
            organismsBreed();
            time++;
        }

    } while (input != 'q');

    return 0;
}