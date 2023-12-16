#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

void parseData(vector<int>& listOfOutputs);
int checkSpelledNumbers(string num);


int main(int argc, char const *argv[])
{
    int finalAnswer = 0;
    vector<int> listOfOutputs;

    parseData(listOfOutputs);

    cout << listOfOutputs.size() << endl;

    for (int i = 0; i < listOfOutputs.size(); i++)
    {
        finalAnswer += listOfOutputs.at(i);
    }

    cout << "FINAL ANSWER: " << finalAnswer << endl;

    return 0;
}

void parseData(vector<int>& listOfOutputs)
{
    ifstream file;
    string line;

    file.open("Day1text.txt");
    if (file)
    {
        //cout << "File Open" << endl;
        
        while (getline(file, line))
        {
            int num1;
            int num2;
            
            for (int i = 0; i < line.length(); i++)
            {
                if (line.at(i) >= '0' && line.at(i) <= '9')
                {
                    num1 = ((int) line.at(i) - 48) * 10;
                    break;
                }
                else if (checkSpelledNumbers(line.substr(i,line.length() - 1)) != 0)
                {
                    num1 = checkSpelledNumbers(line.substr(i,line.length() - 1)) * 10;
                    break;
                }
            }

            for (int i = line.length() - 1; i >= 0; i--)
            {
                if (line.at(i) >= '0' && line.at(i) <= '9')
                {
                    num2 = (int) line.at(i) - 48;
                    break;
                }
                else if (checkSpelledNumbers(line.substr(i, line.length() - 1)) != 0)
                {
                    num2 = checkSpelledNumbers(line.substr(i,line.length() - 1));
                    break;
                }
            }

            listOfOutputs.push_back(num1 + num2);
        }
    }
    else
    {
        //cout << "File Not Open" << endl;
    }

    
}

int checkSpelledNumbers(string num)
{
    if (num.substr(0, 3) == "one")
    {
        return 1;
    }
    else if (num.substr(0, 3) == "two")
    {
        return 2;
    }
    else if (num.substr(0, 5) == "three")
    {
        return 3;
    }
    else if (num.substr(0, 4) == "four")
    {
        return 4;
    }
    else if (num.substr(0, 4) == "five")
    {
        return 5;
    }
    else if (num.substr(0, 3) == "six")
    {
        return 6;
    }
    else if (num.substr(0, 5) == "seven")
    {
        return 7;
    }
    else if (num.substr(0, 5) == "eight")
    {
        return 8;
    }
    else if (num.substr(0, 4) == "nine")
    {
        return 9;
    }
    else
    {
        return 0;
    }
}