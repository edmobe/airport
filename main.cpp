#include "listas.h"
#include <typeinfo>

int main(int argc, char *argv[])
{
	BaseDeDatos * bd = new BaseDeDatos();
	int opcion;
	while (opcion != 11)
	{
		cout << "---------BASE DE DATOS DE AEROPUERTO---------" << endl;
		cout << endl;
		cout << "Digite el numero de la opcion que desee: "<< endl;
		cout << "1: Agregar pais." << endl;
		cout << "2: Agregar vecino a un pais." << endl;
		cout << "3: Agregar conexion a un pais." << endl;
		cout << "4: Crear un arbol binario." << endl;
		cout << "5: Imprimir el arbol binario." << endl;
		cout << "6: Crear un grafo." << endl;
		cout << "7: Imprimir el grafo." << endl;
		cout << "8: Imprimir la lista." << endl;
		cout << "9: Consultas de grafo." << endl;
		cout << "10: Consultas de arbol."<<endl;
		cout << "11: Salir." << endl;
		cout << "Opcion que desea: ";
		cin >> opcion;
		cin.ignore();
		if (opcion == 1)
		{
			cout << "---------------------------" << endl;
			bd->agregarPais();
			cout << endl;
		}
		else if (opcion == 2)
		{
			cout << "---------------------------" << endl;
			bd->agregarVecinos();
			cout << endl;
		}
		else if (opcion == 3)
		{
			cout << "---------------------------" << endl;
			bd->insertarConexiones();
			cout << endl;
		}
		else if (opcion == 4)
		{
			cout << "---------------------------" << endl;
			bd->crearArbol();
			cout << endl;
		}
		else if (opcion == 5)
		{
			cout << "---------------------------" << endl;
			bd->imprimirArbol();
			cout << endl;
		}
		else if (opcion == 6)
		{
			cout << "---------------------------" << endl;
			bd->crearGrafo();
			cout << endl;
		}
		else if (opcion == 7)
		{
			cout << "---------------------------" << endl;
			bd->imprimirGrafo();
			cout << endl;
		}
		else if (opcion == 8)
		{
			cout << "---------------------------" << endl;
			bd->imprimir();
			cout << endl;
		}
		else if (opcion == 9)
		{
			cout << "---------------------------" << endl;
			bd->consultaGrafo();
			cout << endl;
		}
		else if (opcion == 10)
		{
			cout << "---------------------------" << endl;
			bd->consultaArbol();
			cout << endl;
		}
		else if (opcion != 11)
		{
			cout << "---------------------------" << endl;
			cout << "La opcion digitada no es valida, intentelo de nuevo."<< endl;
			cout << endl;
		}
	}

    system("PAUSE");
    return EXIT_SUCCESS;
}

// Hecho por Eduardo Moya
