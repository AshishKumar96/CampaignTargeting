#include <iostream>
#include <string>
#include <time.h>
#include <fstream>

using namespace std;

int main()
{
    int camps, lines, tID, x, y;

    cout << "Number of potential UNIQUE campaigns for example_data.txt: ";
    cin >> camps;

    cout << "Number of lines generated for example_data.txt: ";
    cin >> lines;

    cout << "Maximum potential target IDs assigned to each campaign line: ";
    cin >> tID;

    cout << "Number of lines generated for input.txt: ";
    cin >> x;

    cout << "Maximum potential target IDs assigned to each input line: ";
    cin >> y;


    srand(time(NULL));
    ofstream outfile("example_data.txt");

    for(int i = 0; i < lines; i++)
    {
      int camp = rand()%camps;
      outfile << camp << " ";
      for(int j = 0; j < rand()%tID + 1; j++)
        outfile << rand()%65535 << " ";
      outfile << endl;
    }

    outfile.close();

    ofstream outfile2("input.txt");

    for(int k = 0; k < x; k++)
    {
        for(int l = 0; l < (rand()%y + 1); l++)
          outfile2 << rand()%65535 << " ";
        outfile2 << endl;
    }

    outfile2.close();
}
