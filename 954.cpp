#include <vector>
#include <iostream>
#include <fstream>

using namespace std;

void updateTable(vector<vector<long>>& Table) {
    for (int i = 1; i <= 9; i++) {
        for (int j = 1; j <= 3; j++) {
            Table[i][j] = Table[i + 1][j];
        }
    }
}

void createTowers(vector<vector<long>>& Table) {
    long x, y, z;

    x = (Table[1][1] + Table[1][2] + Table[1][3]) % 1000000;
    y = Table[10][1];
    z = Table[10][2];

    updateTable(Table);

    Table[10][1] = x;
    Table[10][2] = y;
    Table[10][3] = z;
 }

vector<vector<long>> createTable() {
    vector<vector<long>> Table(11, vector<long>(4, 0));
    Table[10][1] = 2;
    return Table;
}

int countMethods(int heightTower) {
    int heightGlass = 10;
    vector<vector<long>> Table = createTable();
    while (heightTower > heightGlass) {
        createTowers(Table);
        heightTower--;
    }
    return (Table[10][1] + Table[10][2] + Table[10][3]) % 1000000;
}

int readHeightFromFile() {
    ifstream heightFromFile("INPUT.TXT");
    int heightTower;
    heightFromFile >> heightTower;
    return heightTower;
}

void writeToFileCountMethods(const int countMethods) {
    ofstream ToFileCountMethods("OUTPUT.TXT");
    ToFileCountMethods << countMethods;
}

int main() {
    int heightTower = readHeightFromFile();
    writeToFileCountMethods(countMethods(heightTower));
}