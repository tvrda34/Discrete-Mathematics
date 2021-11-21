#include<iostream>
#include<string>
#include<vector>
#include<fstream>
#include<sstream>
using namespace std;

bool paintable (int c, int n, vector<int> vertexCollors, vector<int> matrix, int v){
    for(int i=0; i<n; i++){
        if(matrix[v*n+i] == 1 && vertexCollors[i] == c)
            return false;
    }       
    return true;
}

bool findChromeNumber (int c, vector<int> matrix, int n, int vertex, vector<int> vertexCollors){
    if(vertex == n)
        return true;
    
    for(int i=c; i > 0; i--){
            if(paintable(i, n, vertexCollors, matrix, vertex)){
                vertexCollors[vertex] = i;
                if(findChromeNumber(c, matrix, n, vertex+1, vertexCollors)){
                    return true;
                vertexCollors[vertex]=c;    
            }
        }
    }
    return false;
    
}

int chroma (int n, vector<int> matrix){

    //for petlja koja zadaje broj boja kojima se boji
    for(int i=1; i<=n; i++){
        vector<int> vertexCollors (n, i); //vektor bojanja sve na 0
       
        if(findChromeNumber(i, matrix, n, 0, vertexCollors)){ //poziv funkcije za provjeru
            return i;
       }
    }
    return 0;

}



int main(void){
    
    string name, line;
  vector<int> matrix;
    int n,c;

    cout << "Unesite ime datoteke: ";
    cin >> name;
    std::ifstream infile(name);
    infile >> n; //broj vrhova

    //citanje iz matrice susjedstva u vektor
    while(std::getline(infile, line)){
        int v;                      
        std::stringstream ss (line);  
       while ((ss >> v))           
        matrix.push_back (v);
    }

    cout << chroma(n, matrix)<< endl;
    
    return 0;
}