#include <iostream>
using namespace std;

void preProcess(string inFileName)
{
    string outFileName = inFileName.substr(0, inFileName.length() - 2) + ".ii";
    cout << outFileName << endl;
    FILE *inFile = fopen(inFileName.c_str(), "r");
    FILE *outFile = fopen(outFileName.c_str(), "w");
    char c;
    bool isnewLine
    while ((c = fgetc(inFile)) != EOF)
    {

    }
}

int main(int argc, char const *argv[])
{
    if (argc != 2)
    {
        cerr << "Invalid number of arguments\n";
        return 1;
    }
    string file = string(argv[1]);
    int n = file.length();
    if (n < 3 || file[n - 2] != '.' || file[n - 1] != 'c')
    {
        cerr << "Invlid file\n";
        return 1;
    }

    preProcess(string(argv[1]));
    return 0;
}