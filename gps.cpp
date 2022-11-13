#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <sstream>
#include <fstream>
#include <array>
#include <iomanip>

std::vector<std::string> get_data(const int &argc, char* argv[]){
    // get names of files from command line and store in vector
    std::vector<std::string> names;
    for(int i = 1; i < argc; i++){
        names.push_back(argv[i]);
    }
    return names;
}


void store_coordinates(std::vector<double> &longitude, std::vector<double> &latitude, std::ifstream &input){
    std::string line;
    while(std::getline(input, line)){
        std::stringstream ss(line);
        std::string temp1;
        ss >> temp1;
        if(temp1 == "longitude:"){
            double coordinate;
            ss >> coordinate;
            longitude.push_back(coordinate);
        } else if(temp1 == "latitude:"){
            double coordinate;
            ss >> coordinate;
            latitude.push_back(coordinate);
        }
    }    
}

void create_file(const std::string &new_file_name, std::vector<double> &longitude, std::vector<double> &latitude){
    std::ofstream myfile;
    myfile.open(new_file_name);
    myfile << std::fixed << std::setprecision(14);
    // output coordinates in a new text file with specific format
    for(int round = 0; round < static_cast<int>(longitude.size()); round++){
        myfile << "Round " << round << ":\n";
        myfile << "Longitude: " << longitude[round] << "\n";
        myfile << "Latitude: " << latitude[round] << "\n\n";
    }
    myfile.close();
}

void make_files(std::vector<std::string> names){
    for(int i = 0; i < static_cast<int>(names.size()); i++){
        // declare variables
        std::string filename = names[i];
        std::ifstream input(filename);
        std::vector<double> longitude, latitude;

        // check if file opens
        if(!input.is_open()){
            std::cout << "Error opening " << filename << std::endl;
            continue;
        }

        // store coordinates in vectors
        store_coordinates(longitude, latitude, input);

        // declare new name for file and open file
        std::string new_file_name = "formatted_" + filename.substr(0, filename.find(".")) + ".txt";
        create_file(new_file_name, longitude, latitude);
    }
}

int main(int argc, char* argv[]){
    // store names of files
    std::vector<std::string> names = get_data(argc, argv);
    make_files(names);
    return 0;
}
// g++ --std=c++17 -Wall -Werror gps.cpp -o gps.exe
// ./gps.exe gps_out_square.txt gps_out_stationary.txt gps_out_straight_line_217inches.txt