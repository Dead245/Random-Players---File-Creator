// Random Players - File Creator.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>

std::string randomName();
int randomScore();

int main()
{
    int playerAmount;
    std::ofstream newFile;

    //Creates file into where the program is being ran from
    newFile.open("PlayerList.txt", std::ios::out);

    if (!newFile.is_open()) {
        std::cout << "File Failed to open!\n";
        return 1;
    }

    //Generate players
    std::cout << "How many players do you want? ";
    std::cin >> playerAmount;
    std::cout << std::endl << "Generating Players..." << std::endl;

    std::string playerName;
    int playerScore = 1;

    //Changes seed of rand() to be more randomized, otherwise would have same sequence of numbers for each start of file
    srand((unsigned int)time(NULL));

    //Creates [playerAmount] of lines formatted as: "playerID - PlayerName - Score"
    for (int i = 0; i < playerAmount; ++i) {
        playerName = randomName();
        playerScore = randomScore();
        newFile << i << " - " << playerName << " - " << playerScore << std::endl;
    }

    std::cout << "List Generated" << std::endl;
    newFile.close();
    return 0;
}

std::string randomName() {
    std::string name = "";
    //name length is between 2 and 11
    int nameLength = rand() % 10 + 2;
    for (int i = 0; i < nameLength; i++) {
        char letter = 'a' + rand() % 26;
        name.push_back(letter);
    }
    return name;
}

//generates score between 0 and RAND_MAX(), thrown into its own function to possibly be changed in the future if need be
int randomScore() {
    return rand();
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu
