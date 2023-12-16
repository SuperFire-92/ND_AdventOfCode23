#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

void parseData(vector<int>& validGames, vector<int>& maxCubes);
int getColors(string curRound, string color);

const int MAX_RED = 12;
const int MAX_GREEN = 13;
const int MAX_BLUE = 14;

int main(int argc, char const *argv[])
{
    vector<int> outputs;
    vector<int> maxCubes;
    int validGames = 0;
    int maxCubesNum = 0;

    parseData(outputs, maxCubes);

    for (int i = 0; i < outputs.size(); i++)
    {
        cout << outputs.at(i) << endl;
        validGames += outputs.at(i);
    }

    for (int i = 0; i < maxCubes.size(); i++)
    {
        maxCubesNum += maxCubes.at(i);
    }

    cout << "VALID GAMES: " << validGames << endl;
    cout << "MAX CUBES: " << maxCubesNum << endl;

    return 0;
}

void parseData(vector<int>& validGames, vector<int>& maxCubes)
{
    ifstream file;

    const string fileName = "Day2.txt";
    string line;

    file.open(fileName);

    if (file)
    {
        //cout << "File Found";

        while (getline(file, line))
        {
            int reds = 0;
            int greens = 0;
            int blues = 0;
            bool validGame = true;
            int maxReds = 0;
            int maxGreens = 0;
            int maxBlues = 0;


            //We need to parse each line, finding each individual round and tallying up the number of each color
            //Each game has a random number of rounds, and each round can have red, green, and/or blues in them
            //My code needs to accomodate for every option

            //Let's get the integer for what round we're on
            int roundNum = stoi(line.substr(5, line.find(':')));

            //Now we get rid of the round number to make further progress easier
            line = line.substr(line.find(':') + 1);
            cout << line << endl;

            //Now we cycle through each round, getting the numbers from it
            while (line.find(';') != string::npos)
            {
                //First get the current round
                string curRound = line.substr(0 ,line.find(';') - line.find(':'));
                

                //Now we get each relevant number
                //Start with the reds
                
                reds = getColors(curRound, "red");
                if (maxReds < reds)
                {
                    maxReds = reds;
                }

                //Now the greens
                
                greens = getColors(curRound, "green");
                if (maxGreens < greens)
                {
                    maxGreens = greens;
                }

                //Now the blues
                
                blues = getColors(curRound, "blue");
                if (maxBlues < blues)
                {
                    maxBlues = blues;
                }

                if (reds > MAX_RED || greens > MAX_GREEN || blues > MAX_BLUE)
                {
                    validGame = false;
                }

                line = line.substr(line.find(';') + 1);
            }
            //Run through one more time

            //First get the current round
            string curRound = line;

            //Now we get each relevant number
            //Start with the reds
                
            reds = getColors(curRound, "red");
            if (maxReds < reds)
            {
                maxReds = reds;
            }

            //Now the greens
            
            greens = getColors(curRound, "green");
            if (maxGreens < greens)
            {
                maxGreens = greens;
            }

            //Now the blues
            
            blues = getColors(curRound, "blue");
            if (maxBlues < blues)
            {
                maxBlues = blues;
            }

            if (reds > MAX_RED || greens > MAX_GREEN || blues > MAX_BLUE)
            {
                validGame = false;
            }
            

            if (validGame)
            {
                validGames.push_back(roundNum);
            }

            cout << "MAXES - RED: " << maxReds << " GREEN: " << maxGreens << " BLUE: " << maxBlues << endl;
            cout << "MULTIPLED: " << maxReds * maxGreens * maxBlues << endl;
            maxCubes.push_back(maxReds * maxGreens * maxBlues);

        }
    }
    else
    {
        //cout << "File Not Found";
    }
}

int getColors(string curRound, string color)
{
    if (curRound.find(color) != string::npos)
    {
        int i = -2;
        char curRead = curRound.at(curRound.find(color) + i);

        //Find the start of the number
        while (curRead != ' ')
        {
            i--;
            curRead = curRound.at(curRound.find(color) + i);
        }

        i++;

        int j = 0;

        //Find the end of the number
        while (curRound.at(curRound.find(color) + i + j) != ' ')
        {
            j++;
        }

        return stoi(curRound.substr(curRound.find(color) + i, j));
    }
    else
    {
        return 0;
    }
}