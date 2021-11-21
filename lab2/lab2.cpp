#include<iostream>
#include<vector>
#include<fstream>
#include<sstream>
#include<string>
using namespace std;


void DFS(vector<int> matrix, vector<bool> visited, int v, int n, int vertex,int& circle, int& max){
    for(int i=0; i <n; i++){
        if(matrix[v*n+i] == 1 && i != v && !visited[i]){
            visited[i] = true;
            //cout<< v + 1 << " -> " << i + 1 <<endl; //ispis pretrage
            ++circle;
            DFS(matrix, visited, i, n, vertex, circle, max);
            visited[i]=false;
            --circle;
            }
        if(matrix[v*n+i] == 1 && i == vertex && circle > 1){
            //cout<< "ciklus: "<< circle + 1 << endl; //ispis ciklusa
            if(circle+1>max && circle>1)
                max = circle+1;
            }
        if(max == n)
            break;
        }
        
}

int findCircle(vector<int> matrix, int n){
    vector<bool> visited (n, 0);
    int max = 0, circle=0;

    for(int i=0; i<n; i++){
        if(!visited[i]){
            visited[i] = true;
                DFS(matrix, visited, i, n, i, circle, max); 
            }
    }
    return max;

}


int main(void){
    
    string name, line;
    vector<int> matrix;
    int n;

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

    cout << findCircle(matrix, n);
    
    return 0;
}