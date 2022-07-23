#include <iostream>
#include <vector>

using namespace std;

struct Coordinate
{
    int x;
    int y;
};

const int NO_SOLUTION = -1;
const string SEQUENCE_DELIMETER = " ";
const int SEQUENCE_THRESHOLD = 3;
const int EMPTY = 0;
const int JUMP_DIFFERENCE = 1;
const Coordinate POSSIBLE_MOVES[] = {
    {-1, 0},
    {0, 1},
    {1, 0},
    {0, -1},
};


typedef vector<int> CityRow;
typedef vector<CityRow> CityMap;
typedef vector<Coordinate> JumpingPath;



CityMap readCityMap(int cityLength, int cityWidth) {
    CityMap cityMap;
    CityRow row;
    int height;

    for(int i = 0; i < cityWidth; i++) {
        row.clear();
        for(int j = 0; j < cityLength; j++) {
            cin >> height;
            row.push_back(height);
        }
        cityMap.push_back(row);
    }

    return cityMap;
}

void printJumpintPath(const CityMap &cityMap, JumpingPath path) {
    if(path.size() != SEQUENCE_THRESHOLD) 
        cout << NO_SOLUTION;
    else {
        for(auto cell : path)
            cout << cityMap[cell.x][cell.y] << SEQUENCE_DELIMETER;
    }
}

bool isSeen(JumpingPath path, Coordinate cell) {
    for(int i = 0; i < path.size(); i++) {
        if(path[i].x == cell.x && path[i].y == cell.y)
            return true;
    }
    return false;
}

bool isInMapRange(const CityMap &cityMap, Coordinate cell) {
    int cityWidth = cityMap.size();
    int cityLength = cityMap[0].size();

    return (cell.x >= 0 && cell.x < cityWidth && cell.y >= 0 && cell.y < cityLength);
}

bool canJump(const CityMap &cityMap, Coordinate cell, Coordinate nextCell) {
    int cellsHeightDiff = cityMap[nextCell.x][nextCell.y] - cityMap[cell.x][cell.y];
    if(cellsHeightDiff == JUMP_DIFFERENCE || -cellsHeightDiff == JUMP_DIFFERENCE)
        return true;
    return false;
}

bool isValidCellForJump(const CityMap &cityMap, Coordinate currentCell, Coordinate nextCell, JumpingPath path) {
    return isInMapRange(cityMap, nextCell) && (!isSeen(path, nextCell)) && canJump(cityMap, currentCell, nextCell);
}

JumpingPath findBestJumpingSequence(const CityMap &cityMap, JumpingPath path) {
    JumpingPath bestPath = path;
    Coordinate currentCell = path.back();

    if(path.size() < SEQUENCE_THRESHOLD) {
        for(auto move : POSSIBLE_MOVES) {
            Coordinate nextCell = {currentCell.x + move.x, currentCell.y + move.y};
            if(isValidCellForJump(cityMap, currentCell, nextCell, path)) {
                path.push_back(nextCell);
                JumpingPath adjacentCellBestPath = findBestJumpingSequence(cityMap, path);

                if (adjacentCellBestPath.size() > bestPath.size())
                    bestPath = adjacentCellBestPath;

                path.pop_back();
            }
        }
    }

    return bestPath;
}

JumpingPath findBestJumpingSequence(const CityMap &cityMap, int cityLength, int cityWidth) {
    JumpingPath bestPath;
    
    for(int i = 0; i < cityWidth; i++){
        for(int j = 0; j < cityLength; j++){
            JumpingPath path;
            Coordinate start_point = {i, j};
            path.push_back(start_point);
            path = findBestJumpingSequence(cityMap, path);
            if(path.size() > bestPath.size()) 
                bestPath = path;
        }
    }

    return bestPath;
}

int main() {
    CityMap cityMap;
    JumpingPath bestJumpingPath;
    int cityLength, cityWidth;

    cin >> cityLength >> cityWidth;
    cityMap = readCityMap(cityLength, cityWidth);

    bestJumpingPath = findBestJumpingSequence(cityMap, cityLength, cityWidth);
    printJumpintPath(cityMap, bestJumpingPath);
}

