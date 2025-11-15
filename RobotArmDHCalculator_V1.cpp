// RobotArmDHCalculator_V1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <vector>
using namespace std;


class Joint {
private:

    // Joint Number
    int JointIndex;
    // World Frame Orientation
    // 0 = +X, 1 = -X, 2 = +Y, 3 = -Y, 4 = +Z, 5 = -Z
    int WorldFrameOrientation;
    // World Frame Position
    vector<int> WorldFramePosition;

public:

    Joint(int index, int orientation, vector<int> position) {
        JointIndex = index;
        WorldFrameOrientation = orientation;
        WorldFramePosition = position;
    }

    // Getters

    int getJointIndex() {
        return JointIndex;
    };

    int getOrientation() {
        return WorldFrameOrientation;
    };

    vector<int> getPosition() {
        return WorldFramePosition;
    };

    int getXposition() {
        return WorldFramePosition[0];
    };

    int getYposition() {
        return WorldFramePosition[1];
    };

    int getZposition() {
        return WorldFramePosition[2];
    };

    // Setters

    void setJointIndex(int index) {
        JointIndex = index;
        return;
    };

    void getWFOri(int orientation) {
        WorldFrameOrientation = orientation;
        return;
    };

    void getWFPos(vector<int> vecPos) {
        WorldFramePosition = vecPos;
        return;
    };

    void getWFPosX(int xPos) {
        WorldFramePosition[0] = xPos;
        return;
    };

    void getWFPosY(int yPos) {
        WorldFramePosition[1] = yPos;
        return;
    };

    void getWFPosZ(int zPos) {
        WorldFramePosition[2] = zPos;
        return;
    };
};

//int OrientationConvertStringToInt(string stringOrientation){
//    int intOrientation;
//    return intOrientation;
//}


string OrientationConvertIntToString(int intOrientation) {
    string stringOrientation;
    switch (intOrientation) {
        case 0:
            stringOrientation = "+X";
            break;
        case 1:
            stringOrientation = "-X";
            break;
        case 2:
            stringOrientation = "+Y";
            break;
        case 3:
            stringOrientation = "-Y";
            break;
        case 4:
            stringOrientation = "+Z";
            break;
        case 5:
            stringOrientation = "-Z";
            break;
        default:
            stringOrientation = "+Z";
    }
        return stringOrientation;
}


int main()
{
    cout << "Welcome to the DH Calculator!\n";
    cout << "Please start by inputting the number of joints in your robot arm: ";

    int numJoints;
    cin >> numJoints; 

    vector<Joint> Joints;
    Joints.reserve(numJoints);

    for (int currentJoint = 0; currentJoint < numJoints; currentJoint++) {
            cout << "\nJoint Orientations are limited to 90 degree rotations\n";
            cout << "Enter the orientation of the Z axis of Joint " << currentJoint << " relative to the world frame. eg +Y, -Y, +X, -X, +Z, -Z: ";
            int jointOrientation;
            cin >> jointOrientation;
            cout << "\nEnter the X position of the Joint: ";
            int xPosition;
            cin >> xPosition;
            cout << "\nEnter the Y position of the Joint: ";
            int yPosition;
            cin >> yPosition;
            cout << "\nEnter the Z position of the Joint: ";
            int zPosition;
            cin >> zPosition;
            vector<int> jointPosition = { xPosition, yPosition, zPosition };

        Joints.push_back(Joint(currentJoint, jointOrientation, jointPosition));

    };
    for (int i = 0; i < numJoints; i++) {
        cout << "\n===========================\n";
        cout << "\nAutomatic Output of Joints:\n";
        cout << "\n===========================\n";

        cout << "|       Joint " << i + 1 << ":      |\n";
        cout << "|  Joint Index: " << Joints[i].getJointIndex() << endl;
        cout << "|  Joint Orientation: " << Joints[i].getOrientation() << endl;
        cout << "|  Joint Position: (" << Joints[i].getXposition() << ", " << Joints[i].getYposition() << ", " << Joints[i].getZposition() << ")" << endl;
    };
    cout << "!\n";


}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
