#include <iostream>
#include <fstream>
#include <vector>
#include <cstring>

using namespace std;

const int MAXN = 1005; // maximum labyrinth size

char labyrinth[MAXN][MAXN]; // matrix to represent the labyrinth
int visited[MAXN][MAXN]; // matrix to keep track of visited holes
int longest_path = 0; // length of longest path found so far

int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1}; // horizontal directions
int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1}; // vertical directions

int dfs(int x, int y, int count) {
    visited[x][y] = count;
    int max_count = count;
    for (int i = 0; i < 8; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx >= 0 && nx < MAXN && ny >= 0 && ny < MAXN &&
            labyrinth[nx][ny] == '.' && visited[nx][ny] == 0) {
            max_count = max(max_count, dfs(nx, ny, count+1));
        }
    }
    if (max_count > longest_path) {
        longest_path = max_count;
    }
    return max_count;
}

int main() {
    ifstream fin("input.txt"); // input file
    ofstream fout("output.txt"); // output file

    int n, m; // labyrinth size
    fin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            fin >> labyrinth[i][j];
        }
    }

    memset(visited, 0, sizeof(visited));
    for (int i = 0; i < m; i++) {
        if (labyrinth[0][i] == '.') {
            dfs(0, i, 1);
        }
    }

    if (longest_path == 0) {
        fout << "-1\n";
    } else {
        fout << longest_path << "\n";
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (visited[i][j] > 0) {
                    fout << visited[i][j] - 1;
                } else {
                    fout << labyrinth[i][j];
                }
            }
            fout << "\n";
        }
    }

    return 0;
}
