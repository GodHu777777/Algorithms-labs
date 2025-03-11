#include<bits/stdc++.h>
#include"macro.h"

using namespace std;


bool isOpen[NN + 20];
int id[NN + 20];
bool isFull[NN + 20];

// to save current state to output.txt
int Visualization();

// to save whether the node has been random generated
bool vis[NN + 20];

void init() {
    // quick find initialization
    for(int i = 0; i < NN; i++) {
        id[i] = i;
    }

    // the topest line is with water
    for(int i = 0; i < N; i++) {
        isFull[i] = 1;
    }
}

void myUnion(int p, int q) {
    int pid = id[p];
    int qid = id[q];

    int flag = 0;
    if(isFull[p] || isFull[q]) flag = 1;

    for(int i = 0; i < NN; i ++) {
        if(id[i] == pid) {
            id[i] = qid;
            if(flag == 1) {
                isFull[i] = 1;
            }
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
        
        openNode(random_node / N, random_node % N);
        
        cnt ++;
        Visualization();
    }

    // 记录结束时间
    auto end_time = chrono::high_resolution_clock::now();

    // 计算持续时间（以微秒为单位）
    auto duration = chrono::duration_cast<chrono::microseconds>(end_time - start_time);

    // 输出持续时间
    // cout << "Execution time of main function: " << duration.count() << " microseconds" << endl;
    
    printf("%d \n", cnt);
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
