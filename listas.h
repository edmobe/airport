#include <cstdlib>
#include <iostream>
#include <vector>


using namespace std;

struct Conexion;
struct NodoConexion;
struct ListaConexiones;
struct Vecino;
struct NodoVecino;
struct ListaVecinos;
struct Pais;
struct NodoPais;
struct BaseDeDatos;
struct NodoArbol;
struct Arbol;
struct ListaSimple;
struct Nodo;
struct Arista;
struct ListaAristas;
struct Grafo;
struct grafoMatriz;




struct Conexion{
   string nombre;
   int distancia;
   int costoAvion;
   int costoBus;
   int costoTren;
   int tiempoOptimo;
   int tiempoPesimo; 
   
   Conexion(string n, int d, int ca, int cb, int ct, int to, int tp)
   {
		nombre = n;
		distancia = d;
		costoAvion = ca;
		costoBus = cb;
		costoTren = ct;
		tiempoOptimo = to;
		tiempoPesimo = tp;                
   }
   
   void imprimir()
   {

   		cout <<"        "<< nombre<< endl;
        cout <<"            Distancia: "<<distancia<<endl;
        cout <<"            Costo de viajar en avion: "<<costoAvion<<endl;
        cout <<"            Costo de viajar en bus: "<<costoBus<<endl;
        cout <<"            Costo de viajar en tren: "<<costoTren<<endl;
        cout <<"            Tiempo de viaje optimo: "<<tiempoOptimo<<endl;
        cout <<"            Tiempo de viaje pesimo: "<<tiempoPesimo<<endl;
        
   }
};


struct NodoConexion{
   Conexion * conexion;     
   NodoConexion * siguiente;  

   NodoConexion(Conexion * c)
   {
        conexion = c;
        siguiente = NULL;                      
   }  

   void imprimir()
   {
        conexion->imprimir();            
   }
};


struct ListaConexiones
{
   NodoConexion * primerNodo;
   
   ListaConexiones()
   {
        primerNodo = NULL;                
   }
   
   void insertarAlInicio(Conexion * c)
   {
       if (primerNodo == NULL)
          primerNodo = new NodoConexion(c);
       else
       {
           NodoConexion * nuevo = new NodoConexion(c);
           nuevo->siguiente = primerNodo;
           primerNodo = nuevo;    
       }     
   }
   void imprimir()
   {
        NodoConexion * tmp = primerNodo;
        while (tmp != NULL)
        {
              tmp->imprimir();
              tmp = tmp->siguiente;     
        }     
   } 
   
   NodoConexion * buscar(string nombre)
   {
       NodoConexion * tmp = primerNodo;
        while (tmp != NULL)
        {
              if (tmp->conexion->nombre == nombre)
                 return tmp;

              tmp = tmp->siguiente;     
        }                 
        return NULL;
   }
};


struct Vecino {
	string nombre;  
	
	Vecino (string n)
	{
	      nombre = n;
	}
	void imprimir()
	{
	   cout <<"        "<< nombre << endl;
	}
};


struct NodoVecino {
   Vecino * vecino;
   NodoVecino * siguiente;
   
   NodoVecino (Vecino * v)
   {
       vecino = v;
       siguiente = NULL;     
   }
   
   void imprimir()
   { 
        vecino->imprimir();
   }
};


struct ListaVecinos {
       
   NodoVecino *primerNodo, *ultimoNodo;
   
   void ListaSimple()
   {
       primerNodo = ultimoNodo = NULL;
   }
   
   void insertarAlInicio (Vecino * v)
	{
		if (primerNodo == NULL)
		   primerNodo = new NodoVecino(v);
		else
		{
		    NodoVecino * nuevo = new NodoVecino(v);
		    nuevo -> siguiente = primerNodo;
		    primerNodo = nuevo;    
		}     
	}
	
	void imprimir()
	{
		NodoVecino * tmp = primerNodo;
		while(tmp!=NULL)
		{      
		   tmp->imprimir();
		   tmp = tmp->siguiente;                
		}     
	}
	
	NodoVecino * buscar (string nombre)
	{
	    NodoVecino * tmp = primerNodo;
	    
	    while (tmp!=NULL)
	    {
	          if (tmp->vecino->nombre == nombre)
	             return tmp;
	          
	          tmp = tmp->siguiente;      
	    }    
	    
	    return NULL;
	}
};

struct Pais {
	string nombre;  
	string continente;
	int extension;
	int poblacion;
	int natalidad;
	int estados;
	string moneda;
	ListaVecinos * vecinos;
	ListaConexiones * conexiones;
	
	Pais (string nom, string c, int ext, int p, int nat, int est, string m)
	{
	      nombre = nom;
	      continente = c;
	      extension = ext;
	      poblacion = p;
	      natalidad = nat;
	      estados = est;
	      moneda = m;
	      vecinos = new ListaVecinos();
	      conexiones = new ListaConexiones();
	}
	void imprimir()
	{
	   cout << "Pais: "<< nombre << endl;
	   cout << "    Continente: " << continente <<endl;
	   cout << "    Extension en km cuadrados: " << extension <<endl;
	   cout << "    Poblacion: " << poblacion <<endl;
	   cout << "    Porcentaje de natalidad: " << natalidad <<endl;
	   cout << "    Numero de estados o provincias: " << estados <<endl;
	   cout << "    Moneda: " << moneda <<endl;
	   cout << "    Lista de paises vecinos: " << endl;
	   vecinos->imprimir();
	   cout << "    Lista de conexiones: " << endl;
	   conexiones->imprimir();
	}
};


struct NodoPais {
   Pais * pais;
   NodoPais * siguiente;
   
   NodoPais (Pais * p)
   {
       pais = p;
       siguiente = NULL;     
   }
   
   void imprimir()
   { 
        pais->imprimir();
   }
};

struct NodoArbol
{
       string nombre;
       int poblacion;
       int extension;
       NodoArbol* hijoizquierdo;
       NodoArbol* hijoderecho;
       
       
       NodoArbol (string n, int p, int e)
       {
            nombre = n;
            poblacion = p;
            extension = e;
            hijoizquierdo = hijoderecho = NULL;     
       }                 
};     

struct Arbol
{
       NodoArbol* raiz;
       
       Arbol ()
       {
 	      raiz = NULL;      
       }
       
	NodoArbol* insertarPorNombre(string nom, int pob, int ext, NodoArbol* nodoA)
	{     
	      if (nodoA == NULL)
		  {
	        	return new NodoArbol(nom, pob, ext);
		  }      
	      else if (nodoA->nombre < nom)
	      {
	        nodoA->hijoderecho = insertarPorNombre(nom, pob, ext, nodoA->hijoderecho);
	      }
	      else if (nodoA->nombre >= nom)
	      {
	         nodoA->hijoizquierdo = insertarPorNombre(nom, pob, ext, nodoA->hijoizquierdo);
	      }
	      return nodoA;
	}
	
	NodoArbol* insertarPorPoblacion(string nom, int pob, int ext, NodoArbol* nodoA)
	{     
	      if (nodoA == NULL)
		  {
	        	return new NodoArbol(nom, pob, ext);
		  }      
	      else if (nodoA->poblacion < pob)
	      {
	        nodoA->hijoderecho = insertarPorPoblacion(nom, pob, ext, nodoA->hijoderecho);
	      }
	      else if (nodoA->poblacion >= pob)
	      {
	         nodoA->hijoizquierdo = insertarPorPoblacion(nom, pob, ext, nodoA->hijoizquierdo);
	      }
	      return nodoA;
	}  
	
	NodoArbol* insertarPorExtension(string nom, int pob, int ext, NodoArbol* nodoA)
	{     
	      if (nodoA == NULL)
		  {
	        	return new NodoArbol(nom, pob, ext);
		  }      
	      else if (nodoA->extension < ext)
	      {
	        nodoA->hijoderecho = insertarPorExtension(nom, pob, ext, nodoA->hijoderecho);
	      }
	      else if (nodoA->extension >= ext)
	      {
	         nodoA->hijoizquierdo = insertarPorExtension(nom, pob, ext, nodoA->hijoizquierdo);
	      }
	      return nodoA;
	}
	
	int maximo (int a, int b)
	{
	    if (a>b)
	       return a;
	       else return b;    
	}
	
	int altura (NodoArbol* nodoA)
	{
	    if (nodoA == NULL)
	        return -1;
	    else 
	         return 1 + maximo(altura(nodoA->hijoizquierdo),altura(nodoA->hijoderecho));
	}
	
	string sumastrings (string expresion, int veces)
	{
		if (veces == 0)
			return "";
		int cnt = 1;
		string multiplicador = expresion;
		while (cnt!=veces)
		{
			expresion=expresion+multiplicador;
			cnt=cnt+1;
		}
		return expresion;
	}
	
	void imprimirRaiz()
	{
		if (raiz!=NULL)
		{
			cout << "Raiz: " << raiz->nombre<<endl;
		}
	}
	void imprimirArbol(NodoArbol * nodoA)
	{
		if (nodoA!=NULL and nodoA->hijoizquierdo!=NULL and nodoA->hijoderecho!=NULL)
		{
			cout << sumastrings("    ", altura(raiz)-altura(nodoA))<< "Hijo izquierdo: "<<nodoA->hijoizquierdo->nombre<< endl;
			imprimirArbol(nodoA->hijoizquierdo);
			cout << sumastrings("    ", altura(raiz)-altura(nodoA))<< "Hijo derecho: "<<nodoA->hijoderecho->nombre<< endl;
			imprimirArbol(nodoA->hijoderecho);
		}
		else if (nodoA!=NULL and nodoA->hijoizquierdo!=NULL)
		{
			cout << sumastrings("    ", altura(raiz)-altura(nodoA))<< "Hijo izquierdo: "<<nodoA->hijoizquierdo->nombre<< endl;
			imprimirArbol(nodoA->hijoizquierdo);
		}
		else if (nodoA!=NULL and nodoA->hijoderecho!=NULL)
		{
			cout << sumastrings("    ", altura(raiz)-altura(nodoA))<< "Hijo derecho: "<<nodoA->hijoderecho->nombre<< endl;
			imprimirArbol(nodoA->hijoderecho);
		}
	}
		
	NodoArbol * mayor (NodoArbol* arbol)
	{
		if (arbol == NULL)
		    return NULL;
		else if (arbol->hijoderecho == NULL)
		    return arbol;
		else
		    return mayor (arbol->hijoderecho);
	}
	
	NodoArbol * menor (NodoArbol* arbol)
	{
		if (arbol == NULL)
		    return NULL;
		else if (arbol->hijoizquierdo == NULL)
		    return arbol;
		else
		    return menor(arbol->hijoizquierdo);
	}

};


struct Arista {
	string destino;
	int distancia;
	int costoAvion;
	int costoBus;
	int costoTren;
	Arista * siguiente;
	
	Arista(string dest, int d, int ca, int cb, int ct)
	{
		destino = dest;
		distancia = d;
		costoAvion = ca;
		costoBus = cb;
		costoTren = ct;   
		siguiente = NULL;         
	}
	
	void imprimir()
	{
	
		cout <<"        "<< destino<< endl;
	    cout <<"            Distancia: "<<distancia<<endl;
	    cout <<"            Costo de viajar en avion: "<<costoAvion<<endl;
	    cout <<"            Costo de viajar en bus: "<<costoBus<<endl;
	    cout <<"            Costo de viajar en tren: "<<costoTren<<endl;   
	}
};


struct ListaAristas {
       Arista *primerNodo, *ultimoNodo;
       
       ListaAristas()
       {
           primerNodo = ultimoNodo = NULL;
       }
       
	void insertarAlInicio (string desti, int distan, int cav, int cbu, int ctr)
	{
	     if (primerNodo == NULL)
	     {
	         primerNodo = new Arista(desti, distan, cav, cbu, ctr);
	         ultimoNodo = primerNodo;             
	     }
	     else
	     {
	         Arista *nuevo = new Arista(desti, distan, cav, cbu, ctr);
	         nuevo->siguiente = primerNodo;
	         primerNodo = nuevo; 
	     }
	}
	
	void imprimir(void)
	{
	     Arista *tmp = primerNodo;
	     while (tmp != NULL)
	     {
	           tmp->imprimir();
	           tmp = tmp->siguiente;
	     }
	}
	
	bool vacia()
	{
	     if (primerNodo == NULL)
	        return true;
	     else
	         return false;     
	}
	
	int largo(void)
	{
	    int contador = 0;
	     Arista *tmp = primerNodo;
	     while (tmp != NULL)
	     {
	           contador++;
	           tmp = tmp->siguiente;
	     }
	     return contador;
	}
	

	Arista * buscar(string dest)
	{
	       Arista * tmp = primerNodo;
	       while (tmp!=NULL)
	       {
	             if (tmp->destino == dest)
	                return tmp;
	             tmp = tmp->siguiente;      
	       }       
	       return NULL;
	}
	
	int posicion(string dest)
	{
	    int pos = 0;
	       Arista * tmp = primerNodo;
	       while (tmp!=NULL)
	       {
	             if (tmp->destino == dest)
	                return pos;
	             
	             pos++;
	             tmp = tmp->siguiente;      
	       }       
	       return -1;
	}
	
	void insertarAlFinal (string desti, int distan, int cav, int cbu, int ctr)
	{
	     if (primerNodo == NULL)
	     {
	         primerNodo = new Arista(desti, distan, cav, cbu, ctr);
	         ultimoNodo = primerNodo;              
	     }
	     else
	     {
	         Arista *nuevo = new Arista(desti, distan, cav, cbu, ctr);
	         ultimoNodo->siguiente = nuevo;
	         ultimoNodo = nuevo;

	     }
	}         
};


struct Nodo {
	string pais;  
	string continente;
	int extension;
	int poblacion;
	int natalidad;
	int estados;
	string moneda;
	ListaAristas * aristas;
	bool visitado;
	Nodo* siguiente;
	
	Nodo (string pa, string c, int ext, int p, int nat, int est, string m)
	{
		pais = pa;
		continente = c;
		extension = ext;
		poblacion = p;
		natalidad = nat;
		estados = est;
		moneda = m;	      
		aristas = new ListaAristas(); 
		visitado = false;
		siguiente = NULL; 
	}
	
	void imprimir()
	{
	   cout << "Vertice: "<< pais << endl;
	   cout << "    Continente: " << continente <<endl;
	   cout << "    Extension en km cuadrados: " << extension <<endl;
	   cout << "    Poblacion: " << poblacion <<endl;
	   cout << "    Porcentaje de natalidad: " << natalidad <<endl;
	   cout << "    Numero de estados o provincias: " << estados <<endl;
	   cout << "    Moneda: " << moneda <<endl;
	   cout << "    Aristas: "<<endl;
	   aristas->imprimir();
	}       
};


struct ListaSimple {
       Nodo *primerNodo, *ultimoNodo;
       
       ListaSimple()
       {
            primerNodo = ultimoNodo = NULL;
       }
       
       
	void insertarAlInicio (string pa, string cont, int ext, int pob, int nat, int est, string mon)
	{
	     if (primerNodo == NULL)
	     {
	         primerNodo = new Nodo(pa, cont, ext, pob, nat, est, mon);
	         ultimoNodo = primerNodo;            
	     }
	     else
	     {
	         Nodo *nuevo = new Nodo(pa, cont, ext, pob, nat, est, mon);
	         nuevo->siguiente = primerNodo;
	         primerNodo = nuevo; 
	     }
	}
	
	void imprimir(void)
	{

	     Nodo *tmp = primerNodo;
	     while (tmp != NULL)
	     {
	           tmp->imprimir();
	           tmp = tmp->siguiente;
	     }
	     cout << endl;
	}
	

	void insertarAlFinal (string pa, string cont, int ext, int pob, int nat, int est, string mon)
	{
	     if (primerNodo == NULL)
	     {
	         primerNodo = new Nodo(pa, cont, ext, pob, nat, est, mon);
	         ultimoNodo = primerNodo;          
	     }
	     else
	     {
	         Nodo *nuevo = new Nodo(pa, cont, ext, pob, nat, est, mon);
	         ultimoNodo->siguiente = nuevo;
	         ultimoNodo = nuevo;
	     }
	}


	bool vacia()
	{
	     if (primerNodo == NULL)
	        return true;
	     else
	         return false;     
	}
	
	Nodo * buscar(string pai)
	{
	       Nodo * tmp = primerNodo;
	       while (tmp!=NULL)
	       {
	             if (tmp->pais == pai)
	                return tmp;
	             tmp = tmp->siguiente;      
	       }       
	       return NULL;
	}
	
	int posicion(string pai)
	{
	    int pos = 0;
	       Nodo * tmp = primerNodo;
	       while (tmp!=NULL)
	       {
	             if (tmp->pais == pai)
	                return pos;
	             pos++;
	             tmp = tmp->siguiente;      
	       }       
	       return -1;
	}
};


struct Grafo
{
       ListaSimple * vertices;
       
       Grafo()
       {
              vertices = new ListaSimple();       
       } 
       
       void insertarVertice(string pa, string cont, int ext, int pob, int nat, int est, string mon)
       {
            Nodo * tmp = vertices->buscar(pa);
            if (tmp == NULL)
            {          
                vertices->insertarAlFinal(pa, cont, ext, pob, nat, est, mon);
            }
            else
            {
                cout << "El nodo "<< pa << " ya existe"<<endl;    
            }
       } 
       
       void insertarArista(string origen, string destino, int distan, int cav, int cbu, int ctr)
       {
            Nodo * tmp = vertices->buscar(origen);
            Nodo * tmpDest = vertices->buscar(destino);
            if (tmp != NULL)
            {
               if (tmpDest != NULL)
               {     
                 Arista * arista = tmp->aristas->buscar(destino);
                 if (arista == NULL)
                 {
                    tmp->aristas->insertarAlFinal(destino, distan, cav, cbu, ctr);         
                 }
                 else
                 {
                     cout << "Arista ya existe";    
                 }
               }
               else
               {
                   cout << "Destino no existe";    
               } 
            }
            else
            {
                cout << "Nodo origen no existe"<< endl;    
            }
       }
       

      
       void imprimir ()
       {
            vertices->imprimir();
            cout << endl; 
       }
};




struct BaseDeDatos {
       
	NodoPais *primerNodo, *ultimoNodo;
	Arbol * a = new Arbol();
	Grafo * g = new Grafo();
   
   void ListaSimple()
   {
       primerNodo = ultimoNodo = NULL;
   }
   
   void insertarAlInicio (Pais * p)
	{
		if (primerNodo == NULL)
		   primerNodo = new NodoPais(p);
		else
		{
		    NodoPais * nuevo = new NodoPais(p);
		    nuevo -> siguiente = primerNodo;
		    primerNodo = nuevo;    
		}     
	}

	NodoPais * buscar (string nombre)
	{
	    NodoPais * tmp = primerNodo;
	    
	    while (tmp!=NULL)
	    {
	          if (tmp->pais->nombre == nombre)
	             return tmp;
	          
	          tmp = tmp->siguiente;      
	    }    
	    
	    return NULL;
	}

	void insertaConexion(string pais, string nombre, int distancia, int costoAvion, int costoBus, int costoTren, int tiempoOptimo, int tiempoPesimo)
	{
	      NodoPais * buscado = buscar(pais);   
	      
	      if (buscado == NULL)
	         cout << "Pais no encontrado." <<endl;
	      else
	      {
	          buscado->pais->conexiones->insertarAlInicio(new Conexion(nombre, distancia, costoAvion, costoBus, costoTren, tiempoOptimo, tiempoPesimo));                  
	      }          
	}
	
	void insertaVecino(string pais, string nombre)
	{
		NodoPais * buscado = buscar(pais);   
	      
	      if (buscado == NULL)
	         cout << "Pais no encontrado." <<endl;
	      else
	      {
	          buscado->pais->vecinos->insertarAlInicio(new Vecino(nombre));                  
	      }         
	}

































	//métodos de la progra
	
	//1
	void agregarPais()
	{
		bool correcto = false;
		Pais * nuevoPais;
		int salir;
		while (correcto != true)
		{
			cout << "Digite el nombre del pais: ";
			string nombrePais;
			getline(cin, nombrePais);
			if (buscar(nombrePais) != NULL)
			{
				cout << "El pais ya existe, intentelo de nuevo." << endl;
				cout << endl;
			}
			else
			{
				cout << "Digite el continente del pais: ";
				string continentePais;
				getline(cin, continentePais);
				cout << "Digite la extension del pais en km cuadrados: ";		
				int ext;
				cin >> ext;
				cin.ignore();
				cout << "Digite la cantidad de personas del pais: ";		
				int pob;
				cin >> pob;
				cin.ignore();
				cout << "Digite el porcentaje de natalidad: ";		
				int nat;
				cin >> nat;
				cin.ignore();
				cout << "Digite el numero de estados o provincias: ";		
				int est;
				cin >> est;
				cin.ignore();
				cout << "Digite la moneda utilizada en el pais: ";		
				string moneda;
				getline(cin, moneda);
				nuevoPais = new Pais(nombrePais, continentePais, ext, pob, nat, est, moneda);
				insertarAlInicio(nuevoPais);
				correcto = true;
			}
		}
	}
		
		
	//2
	void agregarVecinos()
	{
		 bool correcto = false;
		 cout << "Ingrese el nombre del pais al que desea agregar vecinos: ";
		 string nombrePais;
		 getline(cin, nombrePais);
		 cout<<endl;
		 if (buscar(nombrePais)!=NULL)
		 {
			correcto = false;
			while (correcto != true)
			{
				int salir = 0;
				cout << "Digite un vecino: ";
				string nombreVecino;
				getline(cin, nombreVecino);
				if (buscar(nombreVecino) == NULL)
				{
					cout << "El pais vecino no existe en la base de datos, intentelo de nuevo." << endl;
					cout << endl;
				}
				else if (nombrePais == nombreVecino)
				{
					cout << "El pais no puede tenerse a si mismo como vecino, intentelo de nuevo." << endl;
					cout << endl;	
				}
				else if (buscar(nombrePais)->pais->vecinos->buscar(nombreVecino)!=NULL)
				{
					cout << "Este pais ya tiene ese vecino. Intentelo de nuevo." << endl;
					cout << endl;
				}
				else
				{	
					insertaVecino(nombrePais, nombreVecino);
					while (salir != 2)
					{
						cout << "Digite '1' si desea agregar otro vecino o '2' para volver al menu principal: ";
						cin >> salir;
						cin.ignore();
						if (salir == 1)
						{
							correcto = false;
							salir = 2;
						}
						else if (salir != 1 and salir != 2)
						{
							cout << "El numero digitado debe ser '1' o '2'." << endl;
						}
						else
							correcto = true;
					}
				}
			}	
		 }
		 else
		 {
		     cout << "El pais no existe en la base de datos." << endl;
		     cout << endl;
		 }
	}  

	//3
	
	void insertarConexiones()
		{
			 cout << "Ingrese el nombre del pais al que desea agregar conexiones: ";
			 string nombrePais;
			 getline(cin, nombrePais);
			 cout<<endl;
			 if (buscar(nombrePais)!=NULL)
		 	 {
				cout << "Digite el nombre de la conexion: ";
				string nombreConexion;
				getline(cin, nombreConexion);
				if (buscar(nombreConexion) == NULL)
				{
					cout << "El pais no existe en nuestra base de datos." << endl;
					cout << endl;
				}
				else if (nombrePais == nombreConexion)
				{
					cout << "El pais no puede tenerse a si mismo como conexion." << endl;
					cout << endl;	
				}
				else if (buscar(nombrePais)->pais->conexiones->buscar(nombreConexion)!=NULL)
				{
					cout << "Este pais ya tiene esa conexion." << endl;
					cout << endl;
				}
				else
				{	
					cout << "Digite la distancia en km del pais a la conexion: ";		
					int dist;
					cin >> dist;
					cin.ignore();
					cout << "Digite el costo de viajar en avion al pais de conexion: ";		
					int ca;
					cin >> ca;
					cin.ignore();
					cout << "Digite el costo de viajar en bus al pais de conexion: ";		
					int cb;
					cin >> cb;
					cin.ignore();
					cout << "Digite el costo de viajar en tren al pais de conexion: ";		
					int ct;
					cin >> ct;
					cin.ignore();
					cout << "Digite el tiempo de viaje optimo al pais de conexion: ";		
					int to;
					cin >> to;
					cin.ignore();
					cout << "Digite el tiempo de viaje pesimo al pais de conexion: ";		
					int tp;
					cin >> tp;
					cin.ignore();
					insertaConexion(nombrePais, nombreConexion, dist, ca, cb, ct, to, tp);
				}
			 }	
			 else
			 {
			     cout << "El pais no existe en la base de datos." << endl;
			     cout << endl;
			 }
		}
		
		
	//4
	void crearArbol()
	{
		bool salir = false;
		int opcion;
		while (salir != true)
		{	
			a = new Arbol();
			cout << "Digite 1 si desea crear un arbol ordenado por el nombre del pais."<<endl;
			cout << "Digite 2 si desea crear un arbol ordenado por la poblacion del pais."<<endl;
			cout << "Digite 3 si desea crear un arbol ordenado por la extension del pais." <<endl;
			cout << "Digite 4 si desea volver al menu principal." << endl;
			cout << "Opcion que desea: ";
			cin >> opcion;
			cin.ignore();
			if (opcion == 1)
			{
				NodoPais * tmp = primerNodo;
			    while (tmp!=NULL)
			    {
			          a->raiz = a->insertarPorNombre(tmp->pais->nombre, tmp->pais->poblacion, tmp->pais->extension, a->raiz);
			          tmp = tmp->siguiente;      
			    }
				cout << "Se ha creado el arbol." << endl;
				salir = true;	
			}
			else if (opcion == 2)
		    {
		    	NodoPais * tmp = primerNodo;
			    while (tmp!=NULL)
			    {
			          a->raiz = a->insertarPorPoblacion(tmp->pais->nombre, tmp->pais->poblacion, tmp->pais->extension, a->raiz);
			          tmp = tmp->siguiente;      
			    }
				cout << "Se ha creado el arbol." << endl;
				salir = true;	
			}
			else if (opcion == 3)
			{
				NodoPais * tmp = primerNodo;
			    while (tmp!=NULL)
			    {
			          a->raiz = a->insertarPorExtension(tmp->pais->nombre, tmp->pais->poblacion, tmp->pais->extension, a->raiz);
			          tmp = tmp->siguiente;      
			    }
				cout << "Se ha creado el arbol." << endl;
				salir = true;	
			}
			else if (opcion == 4)
			{
				salir = true;
			}
			else
			{
				cout << "Debe digitar una opcion valida." << endl;
				cout << "---------------------------" << endl;
				cout << endl;
			}
		}
	}
	
	//5
	void imprimirArbol()
	{
		a->imprimirRaiz();
		a->imprimirArbol(a->raiz);
	}

	//6
	void crearGrafo()
	{
		g = new Grafo();
		NodoPais * tmp = primerNodo;
		NodoPais * tmp2 = primerNodo;
		while (tmp!=NULL)
		{
			g->insertarVertice(tmp->pais->nombre, tmp->pais->continente, tmp->pais->extension,
			tmp->pais->poblacion, tmp->pais->natalidad, tmp->pais->estados, tmp->pais->moneda);
			tmp = tmp->siguiente;
		}
		while (tmp2!=NULL)
		{
			NodoConexion * tmp3 = tmp2->pais->conexiones->primerNodo;
			while (tmp3!=NULL)
			{
				g->insertarArista(tmp2->pais->nombre, tmp3->conexion->nombre,
				tmp3->conexion->distancia, tmp3->conexion->costoAvion,
				tmp3->conexion->costoBus, tmp3->conexion->costoTren);
				tmp3=tmp3->siguiente;
			}
			tmp2=tmp2->siguiente;
		}
		
		

		cout<<"Se ha creado el grafo."<<endl;
	}
	
	//7
	void imprimirGrafo()
	{
		g->imprimir();
	}
	
	
	//8
	void imprimir()
	{
		NodoPais * tmp = primerNodo;
		while(tmp!=NULL)
		{
		   tmp->imprimir();
		   cout<< endl;
		   tmp = tmp->siguiente;                
		}     
	}	  

	//9
	void * consultaGrafo()
	{
		cout << "No creado por incumplimiento de compañero." << endl;
	}


	//10
	NodoArbol * consultaArbol()
	{
		bool salir = false;
		int opcion;
		while (salir != true)
		{	
			cout << "Digite 1 si desea ver el pais mayor."<<endl;
			cout << "Digite 2 si desea ver el pais menor."<<endl;
			cout << "Digite 3 si desea volver al menu principal." << endl;
			cout << "Opcion que desea: ";
			cin >> opcion;
			cin.ignore();
			if (opcion == 1)
			{
				cout << "Pais: "<< a->mayor(a->raiz)->nombre<<endl;
				cout << "Poblacion: "<< a->mayor(a->raiz)->poblacion<<endl;	
				cout << "Extension: "<< a->mayor(a->raiz)->extension<<endl;	
				return a->mayor(a->raiz);
			}
			else if (opcion == 2)
		    {
		    	cout << "Pais: "<< a->menor(a->raiz)->nombre<<endl;
				cout << "Poblacion: "<< a->menor(a->raiz)->poblacion<<endl;	
				cout << "Extension: "<< a->menor(a->raiz)->extension<<endl;	
				return a->menor(a->raiz);	
			}
			else if (opcion == 3)
			{
				return NULL;
			}
			else
			{
				cout << "Debe digitar una opcion valida." << endl;
				cout << "---------------------------" << endl;
				cout << endl;
			}
		}	
	}
	
};
