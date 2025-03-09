#include <iostream>
#include <vector>
#include <unordered_map>

#define MAX_BLOCKS 200

using namespace std;

class DiskBlock {
public:
    int blockNo;
    DiskBlock* next;

    DiskBlock(int blockNo) : blockNo(blockNo), next(nullptr) {}
};

class File {
public:
    char name;
    int start;
    int noOfBlocks;
    DiskBlock* block;

    File(char name, int start, int noOfBlocks) : name(name), start(start), noOfBlocks(noOfBlocks), block(nullptr) {}
};

int main() {
    vector<bool> assignedBlocks(MAX_BLOCKS, false);
    int n;
    cout << "Enter the number of files: ";
    cin >> n;

    vector<File> files;
    for (int i = 0; i < n; i++) {
        char name;
        int start, noOfBlocks;

        cout << "Enter the name of file " << i + 1 << ": ";
        cin >> name;

        while (true) {
            cout << "Enter the starting block of file " << i + 1 << ": ";
            cin >> start;
            if (start < MAX_BLOCKS && !assignedBlocks[start])
                break;
            cout << "Invalid block allocation for file " << name << ".\n";
        }

        cout << "Enter the number of blocks of file " << i + 1 << ": ";
        cin >> noOfBlocks;

        File file(name, start, noOfBlocks);
        file.block = nullptr;
        DiskBlock** temp = &file.block;
        bool valid = true;
        int j = 0;
        while (j < noOfBlocks) {
            int block;
            cout << "Enter block " << j + 1 << " for file " << i + 1 << ": ";
            cin >> block;
            if (block >= MAX_BLOCKS || assignedBlocks[block]) {
                valid = false;
                cout << "Invalid block allocation for file " << name << ".\n";
                continue;
            }

            assignedBlocks[block] = true;
            *temp = new DiskBlock(block);
            temp = &((*temp)->next);
            j++;
        }

        files.push_back(file);
        cout << "\n";
    }

    char search;
    cout << "Enter the file to be searched: ";
    cin >> search;

    bool found = false;
    for (const auto& file : files) {
        if (file.name == search) {
            cout << "File Name\tStart Block\tNo of Blocks\tBlocks occupied\n";
            cout << file.name << "\t\t" << file.start << "\t\t" << file.noOfBlocks << "\t\t";

            DiskBlock* temp = file.block;
            while (temp) {
                cout << temp->blockNo;
                temp = temp->next;
                if (temp)
                    cout << ", ";
            }
            cout << "\n";
            found = true;
            break;
        }
    }

    if (!found)
        cout << "File not found\n";

    for (auto& file : files) {
        DiskBlock* temp = file.block;
        while (temp) {
            DiskBlock* next = temp->next;
            delete temp;
            temp = next;
        }
    }

    return 0;
}
