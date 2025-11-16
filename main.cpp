#include <iostream>
#include <string>
#include <vector>
#include <sstream>

#include "joint.h"
using namespace std;

int getInputInt(){
    int num;
    string line;
    getline(cin, line);
    stringstream ss(line);
    ss >> num;
    return num;
};

string getInputStr(){
    string line;
    getline(cin, line);
    return line;
};

// Convert string input to boolean for joint type
bool strToBool(const string& str) {
    if (str == "R" || str == "r") {
        return true; // Revolute
    } else if (str == "P" || str == "p") {
        return false; // Prismatic
    } else {
        throw invalid_argument("Invalid joint type. Use 'R' for Revolute or 'P' for Prismatic.");
    }
}

vector<int> BuildIntVectorFromString(string inputStr) {
    vector<int> result;
    stringstream ss(inputStr);
    string item;
    while (getline(ss, item, ',')) {
        result.push_back(stoi(item));
    }
    return result;
}

vector<float> BuildFloatVectorFromString(string inputStr) {
    vector<float> result;
    stringstream ss(inputStr);
    string item;
    while (getline(ss, item, ',')) {
        result.push_back(stoi(item));
    }
    return result;
}

int main() {

    string line;
    bool mainloop = true;
    string startCode;
    string confirmCode;
    int numJoints;

    while (mainloop) {

        cout << "Welcome to the DH Calculator!\n";
        cout << "This program takes robotic arm joint info and produces a DH table\n";
        cout << "and the Forward Kinematic Equations for a given arm configuration.\n";
        cout << "If you are ready to begin, press Y to continue, otherwise press N to exit: ";

        // Read Y/N input
        startCode = getInputStr(line);
        if (startCode.empty() || !(startCode[0] == 'Y' || startCode[0] == 'y')) {
            mainloop = false;
            break;
        }
        
        cout << "\nGlad to have you onboard!\n";

        // Input number of Joints
        while (true) {
            cout << "\nHow many joints are in your robotic arm: ";
            numJoints = getInputInt(line);
            if (numJoints > 0) {
                break;  // success
            };
            cout << "Invalid input. Please enter a positive integer.\n";
            cout << "\n You have specified that your arm will have " << numJoints << " joints.\n";
            cout << "Is this correct? (Y/N): ";
            confirmCode = getInputStr(line);
            if (!(confirmCode.empty() || !(startCode[0] == 'Y' || startCode[0] == 'y'))) {
                break;
            }
            cout << "Let's try again.\n";
        }

        cout << "Let's begin inputting the joint parameters.\n";
        
        vector<Joint> Joints;
        Joints.reserve(numJoints);



    }

    cout << "Exiting Program. Goodbye!\n";
    return 0;
}

void BuildJointVector(int currentJoint, vector<Joint>& Joints) {
        string temp;
        cout << "\nIs this Joint Revolute or Prismatic? (R/P): ";
        bool jointType = strToBool(getInputStr());
        cout << "\nJoint Orientations are limited to 90 degree rotations\n";
        cout << "Enter the orientation of the Z axis of Joint " << currentJoint << " eg (0,0,1) for +Z, (0,-1,0) for -Y, etc: ";
        vector<int> jointOrientation = BuildIntVectorFromString(getInputStr());
        cout << jointOrientation[0];
        cout << jointOrientation[1];
        cout << jointOrientation[2];
        cout << "Enter the position of Joint " << currentJoint << ": ";
        vector<float> jointPosition = BuildFloatVectorFromString(getInputStr());
        Joints.push_back(Joint(currentJoint, jointType, jointOrientation, jointPosition));

    };

