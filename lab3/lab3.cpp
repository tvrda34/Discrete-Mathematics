#include<iostream>
#include<string>
#include<vector>
#include<fstream>
#include<sstream>
using namespace std;

bool paintable (int c, int n, vector<int> vertexCollors, vector<int> matrix, int v){
    for(int i=0; i<n; i++){
        if(matrix[v*n+i] == 1 && vertexCollors[i] == c) //pregled matrice susjedstva ako je susjed obojan vec istom bojom
            return false;
    }       
    return true;
}

bool findChromeNumber (int c, vector<int> matrix, int n, int vertex, vector<int> vertexCollors){
    if(vertex == n) //ako je vrh jednak n kraj
        return true;
    
    for(int i=1; i <= c; i++){
            if(paintable(i, n, vertexCollors, matrix, vertex)){ //provjera obojivosti vrha tom bojom
                vertexCollors[vertex] = i;
                if(findChromeNumber(c, matrix, n, vertex+1, vertexCollors)){ //sljedeci
                    return true;
                vertexCollors[vertex]=0;    
            }
        }
    }
    return false;
    
}

int chroma (int n, vector<int> matrix){
    vector<int> vertexCollors (n, 0); //vektor bojanja sve na 0
    int chromeNum;

    //for petlja koja zadaje broj boja kojima se boji od 1- n
    for(int i=1; i<=n; i++){
       if(findChromeNumber(i, matrix, n, 0, vertexCollors)){ //poziv funkcije za provjeru
            chromeNum = i; 
            break; //izadi iz petlje ako je obojiv
       }
    }
    return chromeNum;
}



int main(void){
    
    string name, line;
    vector<int> matrix; //matrica susjedstva u vektoru
    int n;

    cout << "Unesite ime datoteke: "; //unos .txt filea s imenom datoteke
    cin >> name; 
    std::ifstream infile(name);
    infile >> n; //broj vrhova

    //citanje iz datoteke u vektor koji predstavlja matricu susjedstva
    while(std::getline(infile, line)){
        int v;                      
        std::stringstream ss (line);  
        while ((ss >> v))           
        matrix.push_back (v);
    }
   
    cout<<  chroma(n, matrix) <<endl;
    
    
    return 0;
}