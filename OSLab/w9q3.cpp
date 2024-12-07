#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
#include <algorithm>

using namespace std;

#define MAX_BLOCKS 200

class File {
public:
    string name;
    int start;
    int noOfBlocks;
    vector<int> blocks;

    File(string name, int start, int noOfBlocks, vector<int> blocks)
        : name(name), start(start), noOfBlocks(noOfBlocks), blocks(blocks) {}
};

int main() {
    int n;
    cout << "Enter the number of files: ";
    cin >> n;
    vector<File> files;
    unordered_set<int> allocatedBlocks;

    for (int i = 0; i < n; i++) {
        string name;
        int start, noOfBlocks;
        vector<int> blocks;

        cout << "Enter the name of file " << i + 1 << ": ";
        cin >> ws; // to consume any leading whitespace
        getline(cin, name);

        cout << "Enter the starting block of file " << i + 1 << ": ";
        cin >> start;

        while (allocatedBlocks.find(start) != allocatedBlocks.end()) {
            cout << "Block " << start << " is already allocated. Enter a different starting block: ";
            cin >> start;
        }

        cout << "Enter the number of blocks of file " << i + 1 << ": ";
        cin >> noOfBlocks;

        cout << "Enter the blocks for file " << i + 1 << ": ";
        for (int j = 0; j < noOfBlocks; j++) {
            int block;
            cin >> block;
            while (allocatedBlocks.find(block) != allocatedBlocks.end()) {
                cout << "Block " << block << " is already allocated. Enter a different block: ";
                cin >> block;
            }
            blocks.push_back(block);
            allocatedBlocks.insert(block);
        }

        files.emplace_back(name, start, noOfBlocks, blocks);
    }

    string search;
    cout << "Enter the file to be searched: ";
    cin >> ws; // to consume any leading whitespace
    getline(cin, search);

    auto it = find_if(files.begin(), files.end(), [&search](const File& file) {
        return file.name == search;
    });

    if (it != files.end()) {
        cout << "File Name\tStart Block\tNo of Blocks\tBlocks occupied\n";
        cout << it->name << "\t\t" << it->start << "\t\t" << it->noOfBlocks << "\t\t";
        for (size_t j = 0; j < it->blocks.size() - 1; j++)
            cout << it->blocks[j] << ", ";
        cout << it->blocks.back() << endl;
    } else {
        cout << "File not found\n";
    }

    return 0;
}
