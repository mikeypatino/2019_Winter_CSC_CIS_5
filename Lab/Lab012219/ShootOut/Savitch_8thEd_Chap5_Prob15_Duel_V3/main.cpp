/* 
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr
 * Created on January 22, 2019, 12:46 PM
 * Purpose:  Shoot out problem, step by step
 */

//System Libraries
#include <iostream>  //Input/Output Library
#include <cstdlib>   //Srand
#include <ctime>     //Time to set random number seed
#include <cmath>     //Math Library
#include <iomanip>   //Format Library
using namespace std;

//User Libraries

//Global Constants, no Global Variables are allowed
//Math/Physics/Conversions/Higher Dimensions - i.e. PI, e, etc...
const float MAXRAND=pow(2,31)-1;

//Function Prototypes
float pUnifrm();
bool  pKill(float);

//Execution Begins Here!
int main(int argc, char** argv) {
    //Set the random number seed
    srand(static_cast<unsigned>(time(0)));
    
    //Declare Variables
    unsigned int nLoops;
    int count;
    float klPrcnt;
    
    //Initialize or input i.e. set variable values
    nLoops=1000000000;
    count=0;
    klPrcnt=1/3.0f;
    
    //Map inputs -> outputs
    for(int i=1;i<=nLoops;i++){
        count+=(pKill(klPrcnt)?1:0);
    }
    
    //Display the outputs
    cout<<"The Probability of Kill = "
            <<100.0f*klPrcnt<<"%"<<endl;
    cout<<"The Probability of Kill Simulated = "
            <<100.0f*count/nLoops<<"%"<<endl;

    //Exit stage right or left!
    return 0;
}

bool  pKill(float prb){
    return pUnifrm()<=prb?true:false;
}

float pUnifrm(){
    return rand()/MAXRAND;
}