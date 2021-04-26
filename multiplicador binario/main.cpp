#include <iostream>
#include <bitset>

using namespace std;

string suma_bit(string n1, string n2){ //suma 2 numeros binarios del mismo tamaño y devuelve el ersultado
    char almacen[n1.size()];
    string result;
    bool up = false;
    for (int i = n1.size()-1; i >= 0; i--) {
        if (n1[i] == '0' and n2[i] == '0' and up == true){
            almacen[i] = '1';
            up = false;
        }
        else if(((n1[i] == '0' and n2[i] == '1') or (n1[i] == '1' and n2[i] == '0')) and up == true){
            almacen[i] = '0';
            up = true;
        }
        else if (n1[i] == '1' and n2[i] == '1' and up == true){
            almacen[i] = '1';
            up = true;
        }

        else if (n1[i] == '0' and n2[i] == '0' and up == false){
            almacen[i] = '0';
            up = false;
        }
        else if(((n1[i] == '0' and n2[i] == '1') or (n1[i] == '1' and n2[i] == '0')) and up == false){
            almacen[i] = '1';
            up = false;
        }
        else if (n1[i] == '1' and n2[i] == '1' and up == false){
            almacen[i] = '0';
            up = true;
        }
    }
    for (int i = 0; i < n1.size(); ++i) {
        result.push_back(almacen[i]);
    }
    return result;
}

string derecha(string arr){ //mueve cada caracter del numero binario una posicion a la derecha y repite en la primera posicion el numero que le sigue
    for (int i = arr.size()-1; i > 0; i--) {
        arr[i] = arr[i-1];
    }
    arr[0] = arr[1];
    return arr;
}

int main(){
    string Mult;
    bitset<4> comp;
    bitset<4> mul (string("0101"));
    bitset<4> mur (string("0011"));
    bitset<4> uno (string("1"));
    comp = mul;
    comp.flip(); //invierte el numero binario
    string M = mul.to_string<char,string::traits_type,string::allocator_type>(); //convierte bitset a string
    string Q = mur.to_string<char,string::traits_type,string::allocator_type>();
    string A = comp.to_string<char,string::traits_type,string::allocator_type>();
    string un = uno.to_string<char,string::traits_type,string::allocator_type>();
    A = suma_bit(A, un);
    int tam = M.size();
    Q.push_back('0');
    for (int i = 0; i < tam; ++i) {
        Q.insert(0, "0");
    }
    for (int i = 0; i < tam+1; ++i) {
        M.push_back('0');
        A.push_back('0');
    }
    cout<<"PROCESO: "<<endl;
    cout<<M<<endl<<A<<endl<<Q<<endl;
    for (int i = 0; i < tam; ++i) {
        if (Q[Q.size()-2] == '0' and Q[Q.size()-1] == '0'){ // "00", desplaza a la derecha
            Q = derecha(Q);
        }
        else if (Q[Q.size()-2] == '1' and Q[Q.size()-1] == '0'){ //"10", suma Q y A, y desplaza a la derecha
            Q = suma_bit(Q, A);
            Q = derecha(Q);
        }
        else if (Q[Q.size()-2] == '0' and Q[Q.size()-1] == '1'){ //"01", suma Q y M, y desplaza a la derecha
            Q = suma_bit(Q, M);
            Q = derecha(Q);
        }
        else if (Q[Q.size()-2] == '1' and Q[Q.size()-1] == '1'){ // "11", desplaza a la derecha
            Q = derecha(Q);
        }
        cout<<Q<<endl;
    }
    cout<<endl<<"RESPUESTA: ";
    for (int i = tam; i < Q.size()-1; ++i) {
        cout<<Q[i];
    }
}