// #ifndef TRANSFORM_MATRIX_H
// #define TRANSFORM_MATRIX_H

// // Standard Libraries
// #include <cmath>
// #include <vector>
// #include <iostream>

// // Using standard namespace
// using namespace std;

// // Transform Matrix Class Definition
// class DH_Entry{
//     private:
//         // Matrix Index
//         int index;
//         // DH length 'a' between xi and the intersection of xi and zi-1
//         int aLength_i;
//         // DH angle 'alpha' between zi-1 and zi measured about xi
//         int alpha_i;
//         // DH length 'd' between zi-1 and the intersection of xi and zi-1
//         string dLength_i_str;
//         int dLength_i;
//         // DH angle 'theta' between xi-1 and xi measured about zi-1
//         string theta_i_str;
//         int theta_i;
//         // 4x4 Homogeneous Transformation Matrix filled with DH parameters
//         // vector<vector<float>> homogenous4x4;

//     public:
        
//         // Transform Matrix Constructor
//         DH_Entry(int idx, float aLength, float alpha, float dLength, float theta){
//             index = idx;
//             aLength_i = aLength;
//             alpha_i = alpha;
//             dLength_i = dLength;
//             theta_i = theta;

//             // // initialize the 4x4 homogeneous transformation matrix
//             // homogenous4x4 = {
//             //     { static_cast<float>(cos(theta_i)), static_cast<float>(-(sin(theta_i)*cos(alpha_i))), static_cast<float>(sin(theta_i)*sin(alpha_i)), static_cast<float>(aLength_i*cos(theta_i)) },
//             //     { static_cast<float>(sin(theta_i)), static_cast<float>(cos(theta_i)*cos(alpha_i)),  static_cast<float>(-(cos(theta_i)*sin(alpha_i))), static_cast<float>(aLength_i*sin(theta_i)) },
//             //     { 0.0f,                                 static_cast<float>(sin(alpha_i)),            static_cast<float>(cos(alpha_i)),               dLength_i },
//             //     { 0.0f,                                 0.0f,                                        0.0f,                                          1.0f    }
//             // };
//         };

//         // Getters

//         // Get index of transform matrix
//         int getIndex(){
//             return index;
//         };

//         // Get length of DH table 'a' variable
//         float getAlength(){
//             return aLength_i;
//         };

//         // Get angle of DH table 'alpha' variable
//         float getalpha(){
//             return alpha_i;
//         };

//         // Get length of DH table 'd' variable
//         float getDlength(){
//             return dLength_i;
//         };

//         // Get angle of DH table 'theta' variable
//         float gettheta(){
//             return theta_i;
//         };

//         // Get entire homogenous matrix
//         vector<vector<float>> getHomogenousMatrix(){
//             return homogenous4x4;
//         };

//         // Get individual entry in homogenous matrix
//         float getHomogenousMatrixEntry(int row, int col){
//             return homogenous4x4[row][col];
//         };

//         // Setters

//         // Set index of transform matrix
//         void setIndex(int idx){
//             index = idx;
//             return;
//         };

//         // Set length of DH table 'a' variable 
//         void setAlength(float aLength){
//             aLength_i = aLength;
//             return;
//         };

//         // Set angle of DH table 'alpha' variable
//         void setAlpha(float alpha){
//             alpha_i = alpha;
//             return;
//         };

//         // Set length of DH table 'd' variable
//         void setDlength(float dLength){
//             dLength_i = dLength;
//             return;
//         };

//         // Set angle of DH table 'theta' variable
//         void setTheta(float theta){
//             theta_i = theta;
//             return;
//         };

//         // Set entire homogenous matrix
//         void setHomogenousMatrix(const vector<vector<float>>& matrix){
//             homogenous4x4 = matrix;
//             return;
//         };

//         // Set individual entry in homogenous matrix
//         void setHomogenousMatrixEntry(int row, int col, float value){
//             homogenous4x4[row][col] = value;
//             return;
//         };

//         // General Methods

//         // Temp Display Function
//         void printHomogenousMatrix(){
//             for (int i = 0; i < 4; i++){
//                 for (int j = 0; j < 4; j++){
//                     cout << homogenous4x4[i][j] << ", ";
//                 }
//                 cout << "\n";
//             }
//             return;
//         };
// };

// #endif // TRANSFORM_MATRIX_H