#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Usuario {
    int idUsuario;
    string nombre;
    string correoElectronico;
    string contraseña;
    string direccion;
    string metodoDePago;
};

struct CarritoDeCompras {
    int idCarrito;
    Usuario usuario;
    vector<string> productos; // Lista de nombres de productos
    double subtotal;
    double impuestos;
};

struct OrdenDeCompra {
    int idOrden;
    vector<string> productos; // Lista de nombres de productos
    double subtotal;
    double impuestos;
    double envio;
    double total;
};

struct Categoria {
    int idCategoria;
    string nombre;
};

struct Comentario {
    int idComentario;
    string producto;
    Usuario usuario;
    string comentario;
    string fecha;
};

struct Producto {
    int idProducto;
    string nombre;
    string descripcion;
    double precio;
    int stock;
};


int main (){





















  return 0;
}
