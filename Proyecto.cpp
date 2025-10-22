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

vector<Usuario> usuarios;
vector<Producto> productos;
vector<Comentarios> comentarios;
vector<Carrito> carritos;
vector<orden> ordenes;
vector<Categoria> categorias;

void cargarDatos(){
usuarios.push_back({1,"Juan Pérez", "juan.perez@email.com", "Qwerty123", "Carrera 45 #10-20", "Tarjeta de crédito"});
	usuarios.push_back({2, "Ana Gómez", "ana.gomez@email.com", "Pass456", "Calle 21 #35-50", "PayPal"});
    usuarios.push_back({3, "Carlos Ruiz", "carlos.ruiz@email.com", "Segura789", "Avenida Principal #100", "Transferencia bancaria"});
    usuarios.push_back({4, "Sofía Martínez", "sofia.martinez@email.com", "Clave987", "Calle 8 #20-30", "Efectivo"});
    usuarios.push_back({5, "Diego Fernández", "diego.fernandez@email.com", "Contra654", "Carrera 77 #40-60", "Tarjeta débito"});
    
    productos.push_back({1, "Laptop", "Portátil con pantalla Full HD y SSD de 512GB", 89999, 10});
    productos.push_back({2, "Smartphone", "Teléfono con cámara de 108MP y carga rápida", 49950, 20});
    productos.push_back({3, "Tablet", "Pantalla táctil de 10 pulgadas", 29999, 15});
    productos.push_back({4, "Auriculares", "Audífonos inalámbricos con cancelación de ruido", 12999, 25});
    productos.push_back({5, "Teclado", "Teclado mecánico con iluminación RGB", 8999, 30});
    productos.push_back({6, "Mouse", "Ratón inalámbrico con sensor óptico de alta precisión", 5999, 50});
    productos.push_back({7, "Monitor", "Pantalla LED 4K de 27 pulgadas", 5999, 50});
    productos.push_back({8, "Impresora", "Láser multifuncional con Wi-Fi", 17999, 18});
    productos.push_back({9, "Cámara", "Cámara digital con lente profesional", 79999, 8});
    productos.push_back({10, "Smartwatch", "Reloj inteligente con GPS y monitoreo cardíaco", 19999, 22});
    productos.push_back({11, "Silla Gamer", "Silla ergonómica ajustable con soporte lumbar", 29999, 14});
    productos.push_back({12, "Microondas", "Horno microondas con múltiples funciones", 12999, 400});
    productos.push_back({13, "Refrigerador", "Frigorífico doble puerta con sistema No Frost", 119999, 5});
    productos.push_back({14, "Lavadora", "Lavadora automática con capacidad de 10kg", 59999, 7});
    productos.push_back({15, "Cafetera", "Cafetera express con vaporizador de leche", 14999, 35});
    productos.push_back({16, "Drone", "Drone con cámara 4K y estabilizador", 69999, 9});
    productos.push_back({17, "Bocina Bluetooth", "Altavoz portátil con sonido envolvente", 8999, 33});
    productos.push_back({18, "Videocámara", "Videocámara profesional con grabación en 4K", 99999, 6});
    productos.push_back({19, "TV LED", "Televisor inteligente de 55 pulgadas con HDR", 74999, 11});
    productos.push_back({20, "Batería Externa", "Batería de 20000mAh con carga rápida", 3999, 45});
    productos.push_back({21, "Disco Duro", "Disco duro externo de 2TB", 12999, 28});
    productos.push_back({22, "Memoria USB", "Pendrive de 128GB", 2999, 60});
    productos.push_back({23, "Router", "Router Wi-Fi 6 de alta velocidad", 19999, 16});
    productos.push_back({24, "Joystick", "Control inalámbrico para videojuegos", 7999, 20});
    productos.push_back({25, "Fuente de Poder", "Fuente de alimentación para PC de 750W", 8999, 17});
    productos.push_back({26, "SSD", "Unidad de almacenamiento SSD de 1TB", 14999, 32});
    productos.push_back({27, "Altavoces", "Par de bocinas estéreo con subwoofer", 13999, 23});
    productos.push_back({28, "Webcam", "Cámara web Full HD con micrófono integrado", 6999, 37});
    productos.push_back({29, "Procesador", "CPU Intel i7 de última generación", 34999, 9});
    productos.push_back({30, "Motherboard", "Placa base compatible con procesadores modernoss", 19999, 13});
    productos.push_back({31, "Memoria RAM", "Módulo de RAM DDR4 de 16GB", 7999, 41});
    productos.push_back({32, "Fuente Solar", "Panel solar portátil con batería integrada", 24999, 4});
    productos.push_back({33, "Control Remoto", "Mando universal para TV y dispositivos", 2499, 50});
    productos.push_back({34, "Termostato", "Termostato digital programable", 9999, 22});
    productos.push_back({35, "Smart Lock", "Cerradura electrónica con huella digital", 19999, 6});
    productos.push_back({36, "Proyector", "Proyector LED con resolución Full HD", 29999, 12});
    productos.push_back({37, "Switch Ethernet", "Switch de red de 8 puertos", 5999, 38});
    productos.push_back({38, "Reloj Digital", "Reloj inteligente con pantalla AMOLED", 8999, 26});
    productos.push_back({39, "Luces LED", "Tiras LED RGB con control remoto", 3999, 55});
    productos.push_back({40, "Estabilizador", "Estabilizador de voltaje para dispositivos electrónicos", 15999, 10});
    productos.push_back({41, "Cargador Inalámbrico", "Base de carga inalámbrica rápida", 4999, 30});
    productos.push_back({42, "HDD Externo", "Disco duro portátil de 4TB", 17999, 15});
    productos.push_back({43, "Micrófono", "Micrófono profesional para grabación", 14999, 7});
    productos.push_back({44, "Altavoz Inteligente", "Asistente de voz con altavoz integrado", 12999, 20});
    productos.push_back({45, "Antena Wi-Fi", "Amplificador de señal inalámbrico", 7999, 33});
    productos.push_back({46, "Climatizador", "Aire acondicionado portátil con control remoto", 29999, 5});
    productos.push_back({47, "Raspberry Pi", "Kit de desarrollo con Raspberry Pi 4", 12999, 19});
    productos.push_back({48, "Capturadora", "Placa de captura de video en alta resolución", 19999, 8});
    productos.push_back({49, "Smart Plug", "Enchufe inteligente compatible con asistentes virtuales", 3999, 42});
    productos.push_back({50, "Timbre Inteligente", "Timbre con cámara y conexión a Wi-Fi", 14999, 10});
   
    comentarios.push_back({1, productos[0], usuarios[0], "Excelente rendimiento; muy rápida.", "01/05/2025"});
    comentarios.push_back({2, productos[1], usuarios[1], "Buena cámara pero la batería dura poco.", "03/05/2025"});
    comentarios.push_back({3, productos[2], usuarios[2], "No me gustó; pantalla de baja calidad.", "5/05/2025"});
    comentarios.push_back({4, productos[3], usuarios[3], "Sonido aceptable pero el material parece frágil.", "6/05/20"});
	comentarios.push_back({5, productos[4], usuarios[4], "Muy buen teclado mecánico; excelente respuesta.", "8/05/2025"});
	comentarios.push_back({6, productos[5], usuarios[1], "El sensor no es tan preciso como esperaba.", "10/05/2025"});
	comentarios.push_back({7, productos[6], usuarios[2], "Colores vibrantes y buena resolución. Muy satisfecho.", "12/05/2025"});
	comentarios.push_back({8, productos[7], usuarios[0], "Tarda mucho en imprimir; no me convence.", "13/05/2025"});
	comentarios.push_back({9, productos[8], usuarios[3], "Increíble calidad de imagen; fotos súper nítidas.", "15/05/2025"});
	comentarios.push_back({10, productos[9], usuarios[4], "Buena batería; pero la pantalla no es muy brillante.", "18/05/2025"});
}

void mostrarDatosCargados() {
    cout << "\nUsuarios cargados:\n";
    for (Usuario* u = &usuarios[0]; u < &usuarios[0] + usuarios.size(); ++u) {
        cout << u->idUsuario << " - " << u->nombre << " - " << u->email << endl;
    }

    cout << "\nProductos cargados:\n";
    for (Producto* p = &productos[0]; p < &productos[0] + productos.size(); ++p) {
        cout << p->idProducto << " - " << p->nombre << " - Stock: " << p->stock << endl;
    }

    cout << "\nComentarios cargados:\n";
    for (Comentarios* c = &comentarios[0]; c < &comentarios[0] + comentarios.size(); ++c) {
        cout << c->idComentario << " - " << c->Usuario.nombre 
             << " comentó sobre " << c->producto.nombre << ": " << c->comentario << endl;
    }
}


int main (){
	setlocale(LC_ALL,"spanish");
    cargarDatos();
    mostrarDatosCargados();
    return 0;



















  return 0;
}
