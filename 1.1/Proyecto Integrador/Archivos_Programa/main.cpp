#include <iostream>
#include <fstream>
#include <string>
using namespace std;
#include "Cliente.h"
#include "Producto.h"
#include "Compra.h"
#include "Envio.h"

int buscaProducto(Producto listaPro[], int cantPro, int idProductoABuscar)
{
    for (int i = 0; i < cantPro; i++)
    {
        if (listaPro[i].getidProducto() == idProductoABuscar)
        {
            return i;
        }
    }
    return -1;
}

int buscaCliente(Cliente listaCli[], int cantCli, int idClienteABuscar)
{
    for (int i = 0; i < cantCli; i++)
    {
        if (listaCli[i].getidCliente() == idClienteABuscar)
        {
            return i;
        }
    }
    return -1;
}

int buscaEnvio(Envio listaEnv[], int cantEnv, int idEnvioABuscar)
{
    for (int i = 0; i < cantEnv; i++)
    {
        if (listaEnv[i].getId() == idEnvioABuscar)
        {
            return i;
        }
    }
    return -1;
}

void cargaProductos(Producto listaProductos[], int &cantProductos)
{
    int numPro, precio;
    string nombrePro;
    cantProductos = 0;
    ifstream archivoPro;
    archivoPro.open("Productos.txt");
    while (archivoPro >> numPro >> nombrePro >> precio)
    {
        listaProductos[cantProductos].setidProducto(numPro);
        listaProductos[cantProductos].setNombre(nombrePro);
        listaProductos[cantProductos].setPrecio(precio);
        cantProductos++;
    }
    archivoPro.close();
}

void cargaClientes(Cliente listaCliente[], int &cantClientes)
{
    int numCli;
    string nombreCli;
    string direccionCli;
    cantClientes = 0;
    ifstream archivoCli;
    archivoCli.open("Clientes.txt");
    while (archivoCli >> numCli >> nombreCli >> direccionCli)
    {
        listaCliente[cantClientes].setidCliente(numCli);
        listaCliente[cantClientes].setNombre(nombreCli);
        listaCliente[cantClientes].setDireccion(direccionCli);
        cantClientes++;
    }
    archivoCli.close();
}

void cargaCompras(Compra listaCom[], int &cantCom, Producto listaPro[], int cantPro, Cliente listaCli[], int cantCli, Envio listaEnv[], int &cantEnv)
{
    int idCom, idPro, idCli, numPro, numCli;
    string fecha;
    cout << "Cuantas compras deseas realizar? ";
    cin >> cantCom;
    cantEnv = cantCom;
    for (int i = 0; i < cantCom; i++)
    {
        cout << "------------------------------------------------" << endl;
        cout << "Teclee la fecha de compra: ";
        cin >> fecha;
        do
        {
            cout << "Teclee el ID del cliente: ";
            cin >> idCli;
            numCli = buscaCliente(listaCli, cantCli, idCli);
        } while (numCli == -1);
        do
        {
            cout << "Teclee el ID del producto: ";
            cin >> idPro;
            numPro = buscaProducto(listaPro, cantPro, idPro);
        } while (numPro == -1);
        listaCom[i].setID(i);
        listaCom[i].setCliente(listaCli[numCli]);
        listaCom[i].setProducto(listaPro[numPro]);
        listaEnv[i].setID(i);
        listaEnv[i].setCompra(listaCom[i]);
        listaEnv[i].setFecha(fecha);
        listaEnv[i].setEstatus(0);
    }
}

void muestraProductos(Producto listaPro[], int cantPro)
{
    cout << "Productos de la tienda:" << endl;
    for (int cont = 0; cont < cantPro; cont++)
    {
        listaPro[cont].imprime();
    }
}

void muestraClientes(Cliente listaCli[], int cantCli)
{
    cout << "Clientes de la tienda:" << endl;
    for (int cont = 0; cont < cantCli; cont++)
    {
        listaCli[cont].imprime();
    }
}

void muestraCompra(Compra listaCom[], int cantCom)
{
    cout << "Compras de la tienda:" << endl;
    for (int i = 0; i < cantCom; i++)
    {
        listaCom[i].imprime();
    }
}

void muestraEnvio(Envio listaEnv[], int cantEnv)
{
    cout << "Envios de la tienda:" << endl;
    for (int i = 0; i < cantEnv; i++)
    {
        listaEnv[i].imprime();
    }
}

void estatusEnvio(Envio listaEnv[], int cantEnv)
{
    int numEnv, est, idEnv;
    do
    {
        cout << "Teclee el ID del envio: ";
        cin >> idEnv;
        numEnv = buscaEnvio(listaEnv, cantEnv, idEnv);
    } while (numEnv == -1);
    for (int i = 0; i < cantEnv; i++)
    {
        if (listaEnv[i].getId() == numEnv)
        {
            do
            {
                cout << "Opciones del envio:" << endl;
                cout << "0) No enviado." << endl;
                cout << "1) Enviado." << endl;
                cout << "Teclee el estatus del envio: ";
                cin >> est;
            } while (est < 0 || est > 1);
            listaEnv[i].setEstatus(est);
            cout << "Estatus del envio " << numEnv << " cambiado con exito." << endl;
            listaEnv[i].imprime();
        }
    }
}

int main()
{
    char opcion;
    int numPro, cantPro, cantCom, cantCli, cantEnv;
    Producto listaPro[10];
    Compra listaCom[10];
    Cliente listaCli[10];
    Envio listaEnv[10];
    cargaProductos(listaPro, cantPro);
    cargaClientes(listaCli, cantCli);
    cargaCompras(listaCom, cantCom, listaPro, cantPro, listaCli, cantCli, listaEnv, cantEnv);
    do
    {   system("cls");
        cout << endl;
        cout << "Menu:" << endl;
        cout << " 1) Muestra los productos." << endl;
        cout << " 2) Muestra los clientes." << endl;
        cout << " 3) Muestra las compras." << endl;
        cout << " 4) Muestra los envios." << endl;
        cout << " 5) Cambia estatus de los envios." << endl;
        cout << " 6) Salir del programa." << endl;
        cin >> opcion;
        system("cls");
        switch (opcion)
        {
        case '1':
            muestraProductos(listaPro, cantPro);
            system("pause");
            system("cls");
            break;
        case '2':
            muestraClientes(listaCli, cantCli);
            system("pause");
            system("cls");
            break;
        case '3':
            muestraCompra(listaCom, cantCom);
            system("pause");
            system("cls");
            break;
        case '4':
            muestraEnvio(listaEnv, cantEnv);
            system("pause");
            system("cls");
            break;
        case '5':
            estatusEnvio(listaEnv, cantEnv);
            system("pause");
            system("cls");
            break;
        case '6':
            cout << "Gracias por comprar con nosotros." << endl;
            break;
        default:
            cout << "Opcion invalida." << endl;
        }
    } while (opcion != '6');
    return 0;
}