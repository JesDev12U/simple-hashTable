//Autor: Jesus Antonio Lopez Bandala
//Referencia: https://youtu.be/2_3fR-k-LzI?si=7isHvwRgqqFcL7BQ
//Proceso: Tabla Hash
//Fecha: 25/11/2023

#include <iostream>
#include <list>
#include <cstring>
#include <ctime>

using namespace std;

//Implementacion de la tabla hash. Ejemplo: 905, Jimmy

class HashTable{
    private:
        static const int hashGroups = 10;
        list<pair<int, string>> table[hashGroups]; //List 1: Index 0, List 2, Index 1...
    public:
        // bool isEmpty() const;
        // int hashFunction(int key);
        // void insertItem(int key, string value);
        // void removeItem(int key);
        // string searchTable(int key);
        // void printTable();

        bool isEmpty(){
            int sum{};
            for(int i{}; i < hashGroups; i++){
                sum += table[i].size();
            }
            if(!sum){
                return true;
            }
            return false;
        }

        int hashFunction(int key){
            return key % hashGroups;
        }

        void insertItem(int key, string value){
            int hashValue = hashFunction(key);
            auto& cell = table[hashValue];
            auto bItr = begin(cell);
            //int n = 0;
            bool keyExists = false;
            for(; bItr != end(cell); bItr++){
                if(bItr->first == key){
                    keyExists = true;
                    bItr->second = value;
                    cout << "[ADVERTENCIA] Clave existente. Valor reemplazado." << endl;
                    break;
                }
            }
            //cout<<"Iteraciones -> "<<n<<endl;
            if(!keyExists){
                cell.emplace_back(key, value);
            }
            return;
        }

        void removeItem(int key){
            int hashValue = hashFunction(key);
            auto& cell = table[hashValue];
            auto bItr = begin(cell);
            bool keyExists = false;
            for(; bItr != end(cell); bItr++){
                if(bItr->first == key){
                    keyExists = true;
                    bItr = cell.erase(bItr);
                    cout << "[INFO] Par eliminado." << endl;
                    break;
                }
            }
            if(!keyExists){
                cout << "[ADVERTENCIA] Clave no encontrada. No se elimino el par." << endl;
            }
            return;
        }

        string searchTable(int key){
            int hashValue = hashFunction(key);
            auto& cell = table[hashValue];
            auto bItr = begin(cell);
            bool keyExists = false;
            for(; bItr != end(cell); bItr++){
                if(bItr->first == key){
                    keyExists = true;
                    return bItr->second;
                    break;
                }
            }
            if(!keyExists){
                return "[ADVERTENCIA] Clave no entontrada.";
            }
        }

        void printTable(){
            for(int i{}; i < hashGroups; i++){
                if(table[i].size() == 0) continue;
                auto bItr = table[i].begin();
                for(; bItr != table[i].end(); bItr++){
                    cout << "[INFO] Clave: " << bItr->first << " Valor: " << bItr->second << endl;
                }
            }
            return;
        }
};

int main(){
    int op = 0;
    HashTable HT;
    do{
        system("cls");
        int key;
        string value;
        clock_t start, end;
        double time;
        cout<<"--------> HASHING <--------"<<endl;
        cout<<"\n1. Insertar"<<endl;
        cout<<"2. Eliminar"<<endl;
        cout<<"3. Buscar"<<endl;
        cout<<"4. Imprimir"<<endl;
        cout<<"5. Salir"<<endl;
        cout<<"\nOpcion: "; cin>>op;
        switch(op){
            case 1:
                system("cls");
                cout<<"\n--------> INSERTAR <--------"<<endl;
                cout<<"\nIngrese la clave y el valor separados por un espacio: ";
                cin>>key>>value;
                start = clock();
                HT.insertItem(key, value);
                end = clock();
                time = (double)(end - start) / CLOCKS_PER_SEC;
                cout<<"\nTiempo de ejecucion: "<<time<<" segundos."<<endl;
                cout<<endl<<endl; system("pause");
                break;
            case 2:
                system("cls");
                cout<<"\n--------> ELIMINAR <--------"<<endl;
                cout<<"\nIngrese la clave del elemento a eliminar: ";
                cin>>key;
                start = clock();
                HT.removeItem(key);
                end = clock();
                time = (double)(end - start) / CLOCKS_PER_SEC;
                cout<<"\nTiempo de ejecucion: "<<time<<" segundos."<<endl;
                cout<<endl<<endl; system("pause");
                break;
            case 3:
                system("cls");
                cout<<"\n--------> BUSCAR <--------"<<endl;
                cout<<"\nIngrese la clave del elemento a buscar: ";
                cin>>key;
                start = clock();
                cout<<HT.searchTable(key)<<endl;
                end = clock();
                time = (double)(end - start) / CLOCKS_PER_SEC;
                cout<<"\nTiempo de ejecucion: "<<time<<" segundos."<<endl;
                cout<<endl<<endl; system("pause");
                break;
            case 4:
                system("cls");
                cout<<"\n--------> IMPRIMIR <--------"<<endl;
                start = clock();
                HT.printTable();
                end = clock();
                time = (double)(end - start) / CLOCKS_PER_SEC;
                cout<<"\nTiempo de ejecucion: "<<time<<" segundos."<<endl;
                cout<<endl<<endl; system("pause");
                break;
            case 5:
                break;
        }
    } while(op != 5);
    return 0;
}