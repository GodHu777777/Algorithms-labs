#include <bits/stdc++.h>
#include "macro.h"

using namespace std;

bool vis[NN + 20];
bool isFull[NN + 20];
bool isOpen[NN + 20];
int id[NN + 20];
int sz[NN + 20];

// save current state to output.txt
int Visualization();

void init() {
    // quick union initialization
    for(int i = 0; i < NN; i++) {
        id[i] = i;
        sz[i] = 1;
    }

    // the topest line is with water
    for(int i = 0; i < N; i++) {
        isFull[i] = 1;
    }
}

int find(int p) {
    // a little bit slower
    // well, it's not a big deal
    // for better, you can choose 
    // an array to save the root
    // obviously, you need to record root every time
    // you find a root
    while(p != id[p]) {
        p = id[p];
    }
    return p;
}

void myUnion(int p, int q) {
    int i = find(p);
    int j = find(q);

    if(isFull[i] || isFull[j]) {
        isFull[i] = 1;
        isFull[j] = 1;
    }

    // this is important
    if(i == j) return;

    if(sz[i] < sz[j]) {
        id[i] = j;
        sz[j] += sz[i];
        if(vis[i]) {
            vis[j] = 1;
        }
    } else {
        id[j] = i;
        sz[i] += sz[j];
        if(vis[j]) {
            vis[i] = 1;
        }
    }
}

void openNode(int i, int j) {
    isOpen[site(i, j)] = 1;

    /*
                        +-------------+
                        |   Upper     |
                        | site(i-1, j)|
                        +------+------+
                                |
                                |
        +-------------+--------+--------+-------------+
        |   Left      | current node |    |   Right     |
        | site(i, j-1)|  site(i, j)  |    | site(i, j+1)|
        +-------------+--------+--------+-------------+
                                |
                                |
                        +------+------+
                        |   Lower     |
                        | site(i+1, j)|
                        +-------------+

    */
    if(i > 0        && isOpen[site(i - 1, j)]) myUnion(site(i - 1, j), site(i, j)); 
    if(i < N - 1    && isOpen[site(i + 1, j)]) myUnion(site(i + 1, j), site(i, j));
    if(j > 0        && isOpen[site(i, j - 1)]) myUnion(site(i, j - 1), site(i, j));
    if(j < N - 1    && isOpen[site(i, j + 1)]) myUnion(site(i, j + 1), site(i, j));
}

bool isPercolate() {
    for(int i = 0; i < N; i++) {
        if(isFull[site(N - 1, i)]) {
            return 1;
        }
    }
    return 0;
}


int main() {
    // 记录开始时间
    auto start_time = chrono::high_resolution_clock::now();

    init();
    srand(time(NULL));
    int cnt = 0;
    while(!isPercolate()){
        // generate a random number in [0, 400)
        int t = rand() % NN;
        while(1) {
            if(!vis[t]) {
                vis[t] = 1;
                break;
            }else {
                t = rand() % NN;
            }
            
        }

        int random_node = t;
        
        // printf("%d %d\n", random_node / N, random_node % N);

        openNode(random_node / N, random_node % N);
        
        cnt ++;
        Visualization();
    }

    printf("%d \n", cnt);

    // 记录结束时间
    auto end_time = chrono::high_resolution_clock::now();

    // 计算持续时间（以微秒为单位）
    auto duration = chrono::duration_cast<chrono::microseconds>(end_time - start_time);

    // 输出持续时间
    // cout << "Execution time of main function: " << duration.count() << " microseconds" << endl;
    
    return 0;
}


// save current state to output.txt
int Visualization() {
    // Open the output file.  Use std::ofstream for C++.
    std::ofstream outputFile("output.txt");

    // Check if the file opened successfully.  This is *crucial*.
    if (!outputFile.is_open()) {
        std::cerr << "Error opening output.txt" << std::endl;
        return 1; // Return an error code
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            int t = isOpen[site(i, j)] + isFull[site(i, j)];

            std::string colorCode; // Store the color code as a string
            if (t == 2) {
                colorCode = BG_COLOR_BLUE; // Full - Blue
            } else if (t == 1) {
                colorCode = BG_COLOR_WHITE; // Open - White
            } else {
                colorCode = BG_COLOR_RED; // Blocked - Red
            }

            // Write the color code and two spaces to the file.
            outputFile << colorCode << "  " << "\033[0m";
        }
        outputFile << std::endl; // Newline at the end of each row
    }

    // Close the file.  Good practice, and ensures data is flushed.
    outputFile.close();

    return 0;
}
