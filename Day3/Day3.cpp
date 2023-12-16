#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

void parseData(vector<int>& validNums);
void displayData(char engine[140][140]);
bool checkEntry(char engine[140][140], int i, int j);


int main(int argc, char const *argv[])
{
    int partSum = 0;
    vector<int> validNums;

    parseData(validNums);

    for (int i = 0; i < validNums.size(); i++)
    {
        cout << validNums.at(i) << " ";
        partSum += validNums.at(i);
    }

    cout << "FINAL ENGINE NUMBER: " << partSum << endl;

    return 0;
}

void parseData(vector<int>& validNums)
{
    //STEP 1, store the whole file into a 2D array
    char engine[140][140];

    //Next, open the file
    ifstream file;
    string line;

    file.open("Day3.txt");

    if (file)
    {
        //Fill the engine with the file
        int j = 0;
        while(getline(file, line))
        {
            for (int i = 0; i < line.length(); i++)
            {
                engine[i][j] = line.at(i);
            }
            j++;
        }

        //Display data to ensure it looks correct
        displayData(engine);

        //Look through every entry, and if it is a number, compare the surrounding tiles
        // for (int j = 0; j < 1; j++)
        // {
        //     int curNumber;
        //     for (int i = 0; i < 140; i++)
        //     {
        //         //If this entry is a number, look through each surrounding character to see if it is not a period or a number
        //         if (engine[i][j] <= '9' && engine[i][j] >= '0')
        //         {
        //             if (checkEntry(engine, i, j))
        //             {
        //                 if (curNumber == 0)
        //                 {
        //                     (int) engine[i][j] - 48;
        //                 }
                        
        //             }
        //             else
        //             {
        //                 validNums.push_back(curNumber);
        //             }
        //         }
        //     }
        // }

        //Scratching old plan
        //Every time we find a number, we find the full length of the number. Using that,
        //We will figure out if it is a part number or not.
        for (int j = 0; j < 140; j++)
        {
            int curNumber;
            for (int i = 0; i < 140; i++)
            {
                //Check if the selected character is a number
                if (engine[i][j] <= '9' && engine[i][j] >= '0')
                {
                    int start = i;
                    int curLength = 1;
                    curNumber = (int) engine[i][j] - 48;
                    i++;
                    while (engine[i][j] <= '9' && engine[i][j] >= '0')
                    {
                        curLength++;
                        curNumber = curNumber * 10;
                        curNumber += (int) engine[i][j] - 48;
                        i++;
                    }

                    bool validNumber = false;
                    for (int k = 0; k < curLength; k++)
                    {
                        if (checkEntry(engine, start + k, j))
                        {
                            validNumber = true;
                        }
                    }
                    if (validNumber)
                    {
                        validNums.push_back(curNumber);
                    }
                }
            }
        }
    }
    else
    {
        cout << "UNABLE TO OPEN" << endl;
    }
}

void displayData(char engine[140][140])
{
    for (int j = 0; j < 140; j++)
    {
        for (int i = 0; i < 140; i++)
        {
            cout << engine[i][j];
        }
        cout << endl;
    }
}

//Check an entry's surrounding variables for symbols
bool checkEntry(char engine[140][140], int i, int j)
{

    //Horizontals
    if ((i - 1 >= 0 ? !(engine[i - 1][j] >= '0' && engine[i - 1][j] <= '9' || engine[i - 1][j] == '.') : false))
    {
        cout << "TRUE H- " << i << " " << j << endl;
        return true;
    }
    if ((i + 1 < 140 ? !(engine[i + 1][j] >= '0' && engine[i + 1][j] <= '9' || engine[i + 1][j] == '.') : false))
    {
        cout << "TRUE H+ " << i << " " << j << endl;
        return true;
    }
    //Verticals
    if ((j - 1 >= 0 ? !(engine[i][j - 1] >= '0' && engine[i][j - 1] <= '9' || engine[i][j - 1] == '.') : false))
    {
        cout << "TRUE V- " << i << " " << j << endl;
        return true;
    }
    if ((j + 1 < 140 ? !(engine[i][j + 1] >= '0' && engine[i][j + 1] <= '9' || engine[i][j + 1] == '.') : false))
    {
        cout << "TRUE V+ " << i << " " << j << endl;
        return true;
    }
    //Diagonals
    if ((j + 1 >= 0 && i + 1 >= 0 ? !(engine[i + 1][j + 1] >= '0' && engine[i + 1][j + 1] <= '9' || engine[i + 1][j + 1] == '.') : false))
    {
        cout << "TRUE D+ " << i << " " << j << endl;
        return true;
    }
    if ((j + 1 >= 0 && i - 1 < 140 ? !(engine[i - 1][j + 1] >= '0' && engine[i - 1][j + 1] <= '9' || engine[i - 1][j + 1] == '.') : false))
    {
        cout << "TRUE D+ " << i << " " << j << endl;
        return true;
    }
    if ((j - 1 < 140 && i + 1 >= 0 ? !(engine[i + 1][j - 1] >= '0' && engine[i + 1][j - 1] <= '9' || engine[i + 1][j - 1] == '.') : false))
    {
        cout << "TRUE D- " << i << " " << j << endl;
        return true;
    }
    if ((j - 1 < 140 && i - 1 < 140 ? !(engine[i - 1][j - 1] >= '0' && engine[i - 1][j - 1] <= '9' || engine[i - 1][j - 1] == '.') : false))
    {
        cout << "TRUE D- " << i << " " << j << endl;
        return true;
    }

    return false;
}