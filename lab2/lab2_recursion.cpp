#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<sstream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;

//trazenje ciklusa
bool ciklus(vector<int>& vect, int& n, int i, int& v, int& put, int prosli){
    int loop = i+n;
    for(i; i<loop; i++){

        if((vect[i] == 1) && ((i%n) != v) && (i%n) != prosli){
            ++put; 
            return ciklus(vect, n, (i%n)*n, v, put, (loop/8)-1);
        }

        if(vect[i] == 1 && (i%n) == v && put != 1){
                ++put;
                return true;
            }
        }
            return false;
    }

//fja za racunanje najduljeg ciklusa
int najduljiCiklus(vector<int>& vect, int n){
    int max = 0, put=1;
    int i=0, size=n, v=0;
    while(i<n*n){
    for(i; i<size; i++){
        if(vect[i] == 1){
            if(ciklus(vect, n, (i%n)*n, v, put, v)){
                if(put > max)
                    max = put;
                    if(max == n)
                        return max;
            }
        }
        put = 1;
    }
     ++v;
     size = n+size;
     
    }
    return max;
}
   

int main(void){
    string ime, line;
    int n, ciklus;
    vector<int> vect;
    cout<< "Unesite ime datoteke: ";
    cin>> ime;
    std::ifstream infile (ime);
    infile >> n; // broj vrhova

    //citanje matrice susjedstva u vektor
    while(std::getline(infile, line)){
       int f;                      
       std::stringstream ss (line);  
       while ((ss >> f))           
        vect.push_back (f);
    }
    
    
    
     /*vector<int> b(64);
   for(vector<int>::iterator p = b.begin(); p !=b.end(); ++p)
    *p=0;
    b[1] = 1; b[3] = 1; b[4] = 1; b[7] = 1;
    b[8] = 1; b[10] = 1;
    b[17] = 1; b[19] = 1;
    b[24] = 1; b[26] = 1;
    b[32] = 1; b[37] = 1;
    b[44] = 1; b[46] = 1;
    b[53] = 1; b[55] = 1;
    b[56] = 1; b[62] = 1;
    */
    
    

    ciklus = najduljiCiklus(vect, n);
    cout << ciklus << endl;
    return 0;


}