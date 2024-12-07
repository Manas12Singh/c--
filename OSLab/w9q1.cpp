#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

#define MAX_BLOCKS 200

class File {
public:
    string name;
    int start;
    int noOfBlocks;

    File(string name, int start, int noOfBlocks) : name(name), start(start), noOfBlocks(noOfBlocks) {}
};

int main() {
    int n;
    cout << "Enter the number of files: ";
    cin >> n;
    vector<File> files;
    vector<int> blockMap(MAX_BLOCKS, 0);

    for (int i = 0; i < n; i++) {
        string name;
        int start, noOfBlocks;
        cout << "Enter the name of file " << i + 1 << ": ";
        cin >> name;
        cout << "Enter the starting block of file " << i + 1 << ": ";
        cin >> start;
        cout << "Enter the number of blocks of file " << i + 1 << ": ";
        cin >> noOfBlocks;

        bool valid = true;
        for (int j = 0; j < noOfBlocks; j++) {
            if (start + j >= MAX_BLOCKS || blockMap[start + j] == 1) {
                valid = false;
                break;
            }
        }

        if (!valid) {
            cout << "Invalid block allocation for file " << name << ". Please re-enter the details.\n";
            i--;
        } else {
            for (int j = 0; j < noOfBlocks; j++)
                blockMap[start + j] = 1;
            files.emplace_back(name, start, noOfBlocks);
        }
        cout << "\n";
    }

    string search;
    cout << "Enter the file to be searched: ";
    cin >> search;
    auto it = find_if(files.begin(), files.end(), [&search](const File& file) { return file.name == search; });

    if (it != files.end()) {
        cout << "File Name\tStart Block\tNo of Blocks\tBlocks occupied\n";
        cout << it->name << "\t\t" << it->start << "\t\t" << it->noOfBlocks << "\t\t";
        for (int j = 0; j < it->noOfBlocks - 1; j++)
            cout << it->start + j << ", ";
        cout << it->start + it->noOfBlocks - 1 << endl;
    } else {
        cout << "File not found\n";
    }

    return 0;
}
