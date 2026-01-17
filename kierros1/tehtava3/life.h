#pragma once

const int maxrow = 1000, maxcol = 1000;

class Life {
public:
    void initialize();
    void print();
    void update();
private:
    int rows, cols; //  active size chosen by user
    int grid[maxrow][maxcol];  //  no hedge: exact maximum size
    int neighbor_count(int row, int col);
};