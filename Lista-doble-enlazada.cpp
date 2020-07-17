#include <iostream>
#include <stdlib.h>

using namespace std;

struct nodo{
	int dato;
	nodo *siguiente;
	nodo *anterior;
	struct nodo *izq, *der;
}*primero, *ultimo;

typedef struct nodo *ARBOL;

void menu1()
{
	cout << "Lista doble" << endl;
	cout << "1. Insertar siguiente (Derecha)" << endl;
	cout << "2. Insertar anterior (Izquierda)" << endl;
	cout << "3. Imprimir siguiente (Derecha)" << endl;
	cout << "4. Imprimir anterior (Izquierda)" << endl;
	cout << "5. Buscar siguiente (Derecha)" << endl;
	cout << "6. Buscar anterior (Izquierda)" << endl;
	cout << "7. Eliminar siguiente (Derecha)" << endl;
	cout << "8. Eliminar anterior (Izquierda)" << endl;
	cout << "9. Ver arbol" << endl;
	cout << "10. Preorden" << endl;
	cout << "11. Postorden" << endl;
	cout << "12. Inorden" << endl;
	cout << "13. Salir" << endl;
	cout << endl;
	cout << "Ingrese la opcion:\t>>  ";
}

//primero=45	ultimo=45		nuevo=67	45,67,78,12
//lista 		NULL <><45><> NULL

void insertarANT()
{
	nodo* nuevo = new nodo();
	cout << "Ingrese el dato del nuevo nodo: >> ";
	cin >> nuevo->dato;
	
	if (primero==NULL)
	{
		primero = nuevo;
		primero->siguiente = NULL;
		primero->anterior = NULL;
		ultimo = primero;
	}else{
		primero->anterior = nuevo;
		nuevo->anterior = NULL;
		nuevo->siguiente=primero;
		primero=nuevo;
	}
	cout << "Nodo ingresado!" << endl;
}

void insertarSIG()
{
	nodo* nuevo = new nodo();
	cout << "Ingrese el dato del nuevo nodo: >> ";
	cin >> nuevo->dato;
	
	if (primero==NULL)
	{
		primero = nuevo;
		primero->siguiente = NULL;
		primero->anterior = NULL;
		ultimo = primero;
	}else{
		ultimo->siguiente = nuevo;
		nuevo->siguiente = NULL;
		nuevo->anterior=ultimo;
		ultimo=nuevo;
	}
	cout << "Nodo ingresado!" << endl;
}

void buscarANT()
{
	nodo* actual = new nodo();
	actual = primero;
	int i= 1, band = 0,valor;
	cout << "Ingrese el valor a ingresar: >>  "; cin >> valor;
	if(primero!=NULL)
	{
		while(actual!=NULL)
		{
			if(actual->dato==valor)
			{
				cout << "Valor encontrado en la posicion #" << i << endl;
				band = 1;
			}
			actual = actual->siguiente;
			i++;
		}
		if(band==0)
		{
			cout << "Numero no encontrado..!" << endl;
		}
	}else{
		cout << "Lista vacia!!" << endl;
	}
}

void buscarSIG()
{
	nodo* actual = new nodo();
	actual = ultimo;
	int i= 1, band = 0,valor;
	cout << "Ingrese el valor a ingresar: >>  "; cin >> valor;
	if(primero!=NULL)
	{
		while(actual!=NULL)
		{
			if(actual->dato==valor)
			{
				cout << "Valor encontrado en la posicion #" << i << endl;
				band = 1;
			}
			actual = actual->anterior;
			i++;
		}
		if(band==0)
		{
			cout << "Numero no encontrado..!" << endl;
		}
	}else{
		cout << "Lista vacia!!" << endl;
	}
}

void imprimirANT()
{
	nodo* actual = new nodo();
	actual = primero;
	if(primero!=NULL)
	{
		cout << "(ANT)NULL <> ";
		while(actual!=NULL)
		{
			cout << actual->dato << " <> ";
			actual = actual->siguiente;
		}
		cout << "NULL(SIG)" << endl;
		cout << "Lista vacia!!" << endl;
	}
}

void imprimirSIG()
{
	nodo* actual = new nodo();
	actual = ultimo;
	if(primero!=NULL)
	{
		cout << "(SIG)NULL <> ";
		while(actual!=NULL)
		{
			cout << actual->dato << " <> ";
			actual = actual->anterior;
		}
		cout << "NULL(ANT)" << endl;
	}else{
		cout << "Lista vacia!!" << endl;
	}
}

void eliminarANT(){
	nodo* actual = new nodo();
	actual = primero;
	if(primero!=NULL){			
		primero = primero->siguiente;
		primero->anterior = NULL;		
	}else{
		cout << "\n La listas se encuentra Vacia\n\n";
	}
	cout << "Nodo eliminado!" << endl;
}

void eliminarSIG(){
	nodo* actual = new nodo();
	actual = ultimo;
	if(ultimo!=NULL){			
		ultimo = ultimo->anterior;
		ultimo->siguiente = NULL;		
	}else{
		cout << "\n La listas se encuentra Vacia\n\n";
	}
	cout << "Nodo eliminado!" << endl;
}

void verArbol(ARBOL &arbol, int dato)
{
	ARBOL temporal = new(struct nodo);
	temporal = arbol;
	if (temporal == NULL)
	return;
	
	verArbol(temporal->der, dato+1);
	for(int i=0; i<dato; i++)
		cout << " ";
	cout << temporal->dato << endl;
	verArbol(temporal->izq, dato+1);
}

int main()
{
	ARBOL arbol = NULL;
	int h,x;
	int opcion;
	int valor;
	do
	{
		menu1(); cin >> opcion;
		cout << endl;
		switch (opcion)
		{
			case 1:
				insertarSIG();
				break;
			case 2:
				insertarANT();
				break;
			case 3:
				imprimirSIG();
				break;
			case 4:
				imprimirANT();
				break;
			case 5:
				buscarSIG();
				break;
			case 6:
				buscarANT();
				break;
			case 7:
				eliminarSIG();
				break;
			case 8:
				eliminarANT();
				break;
			case 9:
				verArbol(arbol, 0);
				break;
			case 10:
				cout << "Gracias por visitarnos!!" << endl;
				exit(1);
				break;
			default:
				cout << "Ingrese una opcion valida!!" << endl;
		}
		cout << endl;
		system("pause");
		system("cls");
	}while(opcion!=13);
	return 0;
}
