#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

struct Nodo {
    int dato;
    Nodo* siguiente;
};

void insertarAlFinal(Nodo*& lista, int dato) {
   
    Nodo* nuevo_nodo = new Nodo();
    nuevo_nodo->dato = dato;
	
    if (!lista) {
        lista = nuevo_nodo;
    }
    else {

        Nodo* actual = lista;
        while (actual->siguiente) {
            actual = actual->siguiente;
        }
        actual->siguiente = nuevo_nodo;
    }
    nuevo_nodo->siguiente = NULL;

}

void insertarAlInicio(Nodo*& lista, int dato) {
   
    Nodo* nuevo_nodo = new Nodo();
    nuevo_nodo->dato = dato;	
    Nodo* aux = lista;
    nuevo_nodo->siguiente = aux;
    lista = nuevo_nodo;

}

void insertarDespuesDe(Nodo*& lista, int dato, int valorDespuesde) {
   
    Nodo* nuevo_nodo = new Nodo();
    nuevo_nodo->dato = dato;	
    
    Nodo* actual = lista;
    
    while(actual->dato != valorDespuesde){
    	actual = actual->siguiente;
	}
    
    nuevo_nodo->siguiente = actual->siguiente;
    actual->siguiente = nuevo_nodo;

}

void insertarAntesDe(Nodo*& lista, int dato, int valorAntesde) {
   
    Nodo* nuevo_nodo = new Nodo();
    nuevo_nodo->dato = dato;	
    
    Nodo* actual = lista;
    
    while(actual->siguiente->dato != valorAntesde){
    	actual = actual->siguiente;
	}
	
    nuevo_nodo->siguiente = actual->siguiente;
    actual->siguiente = nuevo_nodo;

}

void eliminarAlInicio(Nodo*& lista){
	Nodo* actual = lista;
	Nodo* aux = actual->siguiente;
	delete actual;
	lista = aux;
}

void eliminarAlFinal(Nodo*& lista){
	Nodo* actual = lista;
	while(actual->siguiente->siguiente){
	actual = actual->siguiente;
	}
	Nodo* ultimo = actual->siguiente;
	actual->siguiente=NULL;
	delete ultimo;
}

int buscarNodo(Nodo*& lista, int dato){
	
	int contador;
	if(lista){
		Nodo* actual = lista;
		contador = 1;
		while(actual->dato != dato && actual->siguiente){
			contador++;	
			actual = actual->siguiente;
			if(actual->siguiente == NULL){
				contador = 0;
			}
		}
	}else{
		contador=0;
	}
	
	return contador;
}

int sizeLista(Nodo*& lista){
	
	int contador=0;
	if(lista){
		contador=1;
		Nodo* actual  = lista;
		while(actual->siguiente){
			actual = actual->siguiente;
			contador++;	
		}
	}
	return contador;
}

bool comprobarListaVacia(Nodo*& lista){
	
	if(lista){
		return false;
	}else{
		return true;
	}
	
}
void vaciarLista(Nodo*& lista){
	
	int size = sizeLista(lista);
	for(int i=0; i<size; i++){
		Nodo* actual = lista;
		Nodo* aux = actual->siguiente;
		delete actual;
		lista = aux;
	}
	
}

void generarListaAleatoriamente(Nodo*& lista, int n){

	srand(time(NULL));
	int valor;
	
    for (int i = 0; i < n; i++) {
        insertarAlFinal(lista, rand() % 100);
    }
    
}

void print(Nodo*& lista, int n) {
	
	cout << "[ ";
   	if(lista){
	    Nodo* actual = lista;
	    for (int i = 0; i < n-1; i++) {
	        actual = actual->siguiente;
	    }
	    cout << actual->dato;
	}
	cout << " ]";
}

void print(Nodo*& lista) {

    cout << "[ ";
    if(lista){
	    Nodo* actual = lista;
	    while (actual->siguiente) {
	        cout << actual->dato << " ";
	        actual = actual->siguiente;
	    }
	    cout << actual->dato;
	}
	cout << " ]";
}

int opcionANumero(string n){
	if(n=="a"){
		return 1;
	} else if (n == "b"){
		return 2;
	}else if (n == "c"){
		return 3;
	}else if (n == "d"){
		return 4;
	}else if (n == "e"){
		return 5;
	}else if (n == "f"){
		return 6;
	}else if (n == "g"){
		return 7;
	}else if (n == "h"){
		return 8;
	}else{
		return 0;
	}
}

int main()
{
    Nodo* lista = NULL;
	string opcion;
	int valor = 0;
	bool continuar = true;
    
    while(continuar){
		
	    cout << "\n\nMenu:\n\n a.Insertar Nodo\n b.Eliminar Nodo\n c.Buscar Nodo\n d.Tamanio de la Lista\n e.Comprobar Lista Vacia\n f.Mostrar Lista\n g.Vaciar Lista\n h.Salir del programa.";
		
		do{
			cout << "\n\nIngrese una opcion: -> ";
			cin >> opcion;
		} while(opcion!="a" && opcion!="b" && opcion!="c" && opcion!="d" && opcion!="e" && opcion!="f" && opcion!="g" && opcion!="h");
		
		
		switch(opcionANumero(opcion)){
			
			case 1 : {
				
				cout << "\n a.Insertar Nodo al inicio. \n b.Insertar Nodo al final\n c.Insertar Nodo antes del Elemento X\n d.Insertar Nodo después del Elemento X";	
				
				do{
					cout << "\n\nIngrese una opcion: -> ";
					cin >> opcion;
				} while(opcion!="a" && opcion!="b" && opcion!="c" && opcion!="d");
				
				cout << "Ingrese el valor del nuevo nodo: ->";
				cin >> valor;
				
				switch(opcionANumero(opcion)){
					case 1: {
						insertarAlInicio(lista, valor);
						cout << "\nNuevo nodo insertado al inicio, la nueva lista es:\n\n";		
						print(lista);
						break;
					}
					
					case 2: {
						insertarAlFinal(lista, valor);
						cout << "\nNuevo nodo insertado al final, la nueva lista es:\n\n"		;
						print(lista);
						break;
					}
					
					case 3: {
						int x;
						cout << "Inserte el valor del elemento X (el nuevo nodo se inserta antes de este): -> ";
						cin >> x;
						if(lista, buscarNodo(lista, x)){
							insertarAntesDe(lista, valor, x);
							cout << "\nNuevo nodo insertado antes del elemento " << x << ", la nueva lista es:\n\n";
							print(lista);
						}else{
							cout << "\nEl elemento insertado no hace parte de la lista en este momento, intente nuevamente con un elemento preesente en la lista.";
						}
						break;
					} 
					
					case 4: {
						int x;
						cout << "Inserte el valor del elemento X (el nuevo nodo se inserta despues de este): -> ";
						cin >> x;
						if(lista, buscarNodo(lista, x)){
							insertarDespuesDe(lista, valor, x);
							cout << "\nNuevo nodo insertado despues del elemento " << x << ", la nueva lista es:\n\n";		
							print(lista);
						}
						cout << "\nEl elemento insertado no hace parte de la lista en este momento, intente nuevamente con un elemento preesente en la lista.";

						break;
					}	
				}
				break;
			}
			
			case 2: {
				
				if(lista){
				cout << "\n\nSeleccione una opcion:\n\n a. Eliminar Nodo al inicio. \n b. Eliminar Nodo al final.";			
					do{
						cout << "\n\nIngrese una opcion: -> ";
						cin >> opcion;
					} while(opcion!="a" && opcion!="b");
					
					if(opcion == "a"){
						eliminarAlInicio(lista);
						cout << "\nNodo inicial eliminado, la lista actual es:\n\n";
						print(lista);
					}else if (opcion == "b"){
						eliminarAlFinal(lista);
						cout << "\nNodo final eliminado, la lista actual es:\n\n";
						print(lista);
					}			
				}else{
					cout << "\nLa lista esta vacia, no hay nada que elminar.";
				}
							
				break;
			}
			
			case 3: {
				
				cout << "\nInserte el valor a buscar: -> ";
				cin >> valor;
				
				if (buscarNodo(lista, valor) == 0){
					cout << "El valor ingresado NO existe en la lista.";
				} else {
					cout << "\nEl valor ingresado esta en la posicion numero " << buscarNodo(lista, valor) << ".";
				}
				
				break;
			}
			
			case 4: {
				
				cout << "\nEl tamanio de la lista es: " << sizeLista(lista) << ".";
				
				break;
			}
			
			case 5: {
				if (comprobarListaVacia(lista)){
					cout << "\nVerdadero:\nLa lista esta vacia";
				}else {
					cout << "\nFalso:\nLa lista tiene elementos.";
				}
				break;
			}
			
			case 6: {
				cout << "\nLa lista actual es:\n\n ";
				print(lista);
				break;
			}
			
			case 7: {
				vaciarLista(lista);
				cout << "Lista vaciada.";
				break;
			}
			
			case 8: {
				cout << "Programa terminado.";
				continuar = false;
				break;
			}
		}
	}
}

