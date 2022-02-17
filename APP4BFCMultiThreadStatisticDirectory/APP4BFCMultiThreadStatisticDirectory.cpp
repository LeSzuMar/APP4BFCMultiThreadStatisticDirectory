#include <fstream>
#include <iostream>
#include <filesystem>
#include <thread>

#include<string>
namespace fs = std::filesystem;
using namespace std;


void task1() {

    ifstream f1;
    char c;
    int numchars, numlines;

    f1.open("Sample.txt");

    numchars = 0;
    numlines = 0;
    f1.get(c);
    while (f1) {
        while (f1 && c != '\n') {
            numchars = numchars + 1;
            f1.get(c);
        }
        numlines = numlines + 1;
        f1.get(c);
    }
    cout << "The file has " << numlines << " lines and "
        << numchars << " characters" << endl;
}
void task2() {
    streampos begin, end;
    ifstream myfile("Sample.txt", ios::binary);
    begin = myfile.tellg();
    myfile.seekg(0, ios::end);
    end = myfile.tellg();
    myfile.close();
    cout << "File Size is: " << (end - begin) << " bytes.\n";
}

int main(int count, string)
{   
    //Creating Directories
    const std::filesystem::path PhoneDirectory{ "PhoneDirectory" };
    std::filesystem::create_directories(PhoneDirectory / "Contact_List");
    std::filesystem::create_directories(PhoneDirectory / "Messages" / "Sended");
    std::filesystem::create_directories(PhoneDirectory / "Messages" / "Recived");
    std::filesystem::create_directories(PhoneDirectory / "Calls" / "Income");
    std::filesystem::create_directories(PhoneDirectory / "Calls" / "Outcome");
    std::filesystem::create_directories(PhoneDirectory / "Gallery");
    std::filesystem::create_directories(PhoneDirectory / "Gallery" / "Wallpaper" / "Nature");
    std::filesystem::create_directories(PhoneDirectory / "Settings");
    std::filesystem::create_directories(PhoneDirectory / "Settings" / "Default");
    std::filesystem::create_directories(PhoneDirectory / "Settings" / "User1");

    ofstream MyFile("Sample.txt");
    // Write to the file
    MyFile << "Hello My name is Marcin\n im begginer in C++\n everyday for me is a school day if you know what I mean\n Enjoy your Day. ";
    // Close the file
    MyFile.close();

    std::ofstream{ PhoneDirectory / "Settings" / "User1"/ "SampleFile" }; // create regular file


    // Iterate over the `std::filesystem::directory_entry` elements
    std::cout << "    ---Directory_Iterator---\n";

    for (auto const& dir_entry : std::filesystem::directory_iterator{ PhoneDirectory })
    {
        std::cout << dir_entry << '\n';
    }


    // Iterate over the `std::filesystem::recursive_directory_entry` elements
    std::cout << "\n    ---Recursive_directory_iterator---\n";
    for (auto const& dir_entry : std::filesystem::recursive_directory_iterator{ PhoneDirectory })
    {

        std::cout << dir_entry << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << '\n';

    }

    std::cout << "\n";

    std::thread t1{ task1 };
    t1.join();
    std::thread t2{ task2 };
    t2.join();

    // delete the PhoneDirectory dir and all contents within it, including subdirs/files
    std::filesystem::remove_all(PhoneDirectory);
    return 0;
}



