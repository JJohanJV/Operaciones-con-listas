// Pilas.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>

struct Nodo {

    int dato;
    Nodo* siguiente;

};

void push(Nodo*& top, int dato) {

    Nodo* nuevo_nodo = new Nodo;
    nuevo_nodo->dato = dato;

    Nodo* aux = top;
    top = nuevo_nodo;
    top->siguiente = aux;

}


void pop(Nodo*& top){
    
    Nodo* aux = top;
    top = top->siguiente;
    delete aux;

}

void print(Nodo*& top) {
         
    Nodo* actual = new Nodo;
    actual = top;

    std::cout << "\n";
    
    std::cout << actual->dato;
    while (actual->siguiente) {
        actual = actual->siguiente;
        std::cout << actual->dato << " ";
    }
}


int main()
{
    int opcion;
    Nodo* top = NULL;

    while(true) {
        std::cout << "\n\n1.Para push 2.Para pop 3.Para imprimir ->";
        std::cin >> opcion;
        switch (opcion)
        {
            case 1:  

                std::cout << "Ingrese el dato ->";
                std::cin >> opcion;
                push(top, opcion);
                break;

            case 2:
                pop(top);
                std::cout << "\nHecho\n";
                break;
            case 3:
                print(top);

        }
    }


}

// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
