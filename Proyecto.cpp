//Integrantes:
//Luis miranda, Orlando Arroyo, Samuel Porto.
#include <iostream>
#include <vector>
#include <string>
#include <cctype>
#include <cstdlib>
using namespace std;

struct Usuario {
    int idUsuario;
    string nombre;
    string correoElectronico;
    string contrasena; 
    string direccion;
    string metodoDePago;
};

struct CarritoDeCompras {
    int idCarrito;
	string nombreUsuario;     
    vector<int> productosIds; // IDs de productos en el carrito
    double subtotal;
    double impuestos;
};

struct OrdenDeCompra {
    int idOrden;
    vector<int> productosIds; // IDs de productos
    long subtotal;
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
    string nombreProducto;       // Nombre del producto
    string nombreUsuario;        // Nombre del usuario
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
vector<Comentario> comentarios;        
vector<CarritoDeCompras> carritos;     
vector<OrdenDeCompra> ordenes;         
vector<Categoria> categorias;

void cargarDatos(){
    // Cargar usuarios
    usuarios.push_back({1,"Juan Pérez", "juan.perez@email.com", "Qwerty123", "Carrera 45 #10-20", "Tarjeta de crédito"});
    usuarios.push_back({2, "Ana Gómez", "ana.gomez@email.com", "Pass456", "Calle 21 #35-50", "PayPal"});
    usuarios.push_back({3, "Carlos Ruiz", "carlos.ruiz@email.com", "Segura789", "Avenida Principal #100", "Transferencia bancaria"});
    usuarios.push_back({4, "Sofía Martínez", "sofia.martinez@email.com", "Clave987", "Calle 8 #20-30", "Efectivo"});
    usuarios.push_back({5, "Diego Fernández", "diego.fernandez@email.com", "Contra654", "Carrera 77 #40-60", "Tarjeta débito"});
    
    // Cargar productos (según el PDF)
    productos.push_back({1, "Laptop", "Portátil con pantalla Full HD y SSD de 512GB", 89999, 10});
    productos.push_back({2, "Smartphone", "Teléfono con cámara de 108MP y carga rápida", 49950, 20});
    productos.push_back({3, "Tablet", "Dispositivo con pantalla táctil de 10 pulgadas", 29999, 15});
    productos.push_back({4, "Auriculares", "Audífonos inalámbricos con cancelación de ruido", 12999, 25});
    productos.push_back({5, "Teclado", "Teclado mecánico con iluminación RGB", 8999, 30});
    productos.push_back({6, "Mouse", "Ratón inalámbrico con sensor óptico de alta precisión", 5999, 50});
    productos.push_back({7, "Monitor", "Pantalla LED 4K de 27 pulgadas", 49900, 12});  // Corregido el precio
    productos.push_back({8, "Impresora", "Láser multifuncional con Wi-Fi", 17999, 18});
    productos.push_back({9, "Cámara", "Cámara digital con lente profesional", 79999, 8});
    productos.push_back({10, "Smartwatch", "Reloj inteligente con GPS y monitoreo cardíaco", 19999, 22});
    productos.push_back({11, "Silla Gamer", "Silla ergonómica ajustable con soporte lumbar", 29999, 14});
    productos.push_back({12, "Microondas", "Horno microondas con múltiples funciones", 12999, 40});  // Corregido stock
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
    productos.push_back({30, "Motherboard", "Placa base compatible con procesadores modernos", 19999, 13});
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
   
    // Cargar TODOS los 50 comentarios 
    comentarios.push_back({1, "Laptop", "Juan Pérez", "Excelente rendimiento; muy rápida. ¡Me encanta!", "1/05/2025"});
    comentarios.push_back({2, "Smartphone", "Ana Gómez", "Buena cámara pero la batería dura poco.", "3/05/2025"});
    comentarios.push_back({3, "Tablet", "Carlos Ruiz", "No me gustó; pantalla de baja calidad.", "5/05/2025"});
    comentarios.push_back({4, "Auriculares", "Sofía Martínez", "Sonido aceptable pero el material parece frágil.", "6/05/2025"});
    comentarios.push_back({5, "Teclado", "Diego Fernández", "Muy buen teclado mecánico; excelente respuesta.", "8/05/2025"});
    comentarios.push_back({6, "Mouse", "Ana Gómez", "El sensor no es tan preciso como esperaba.", "10/05/2025"});
    comentarios.push_back({7, "Monitor", "Carlos Ruiz", "Colores vibrantes y buena resolución. Muy satisfecho.", "12/05/2025"});
    comentarios.push_back({8, "Impresora", "Juan Pérez", "Tarda mucho en imprimir; no me convence.", "13/05/2025"});
    comentarios.push_back({9, "Cámara", "Sofía Martínez", "Increíble calidad de imagen; fotos súper nítidas.", "15/05/2025"});
    comentarios.push_back({10, "Smartwatch", "Diego Fernández", "Buena batería; pero la pantalla no es muy brillante.", "18/05/2025"});
    comentarios.push_back({11, "Silla Gamer", "Lucía Rodríguez", "Comodidad espectacular; perfecto para largas sesiones de juego.", "20/05/2025"});
    comentarios.push_back({12, "Microondas", "Andrés Ramírez", "Calienta bien pero hace mucho ruido.", "22/05/2025"});
    comentarios.push_back({13, "Refrigerador", "María García", "Espacioso y enfría rápido; muy recomendado.", "24/05/2025"});
    comentarios.push_back({14, "Lavadora", "Javier Martínez", "Lava bien pero el ciclo es muy largo.", "26/05/2025"});
    comentarios.push_back({15, "Cafetera", "Carolina López", "Hace café delicioso; fácil de usar.", "28/05/2025"});
    comentarios.push_back({16, "Drone", "Daniel Castro", "Muy divertido pero la batería dura poco.", "30/05/2025"});
    comentarios.push_back({17, "Bocina Bluetooth", "Paola Herrera", "Sonido potente y buena conexión Bluetooth.", "1/06/2025"});
    comentarios.push_back({18, "Videocámara", "Esteban Rojas", "Perfecta para grabaciones profesionales.", "3/06/2025"});
    comentarios.push_back({19, "TV LED", "Fernanda Sánchez", "Imagen excelente pero el sonido podría mejorar.", "5/06/2025"});
    comentarios.push_back({20, "Batería Externa", "Camilo Torres", "Carga bien pero es un poco pesada.", "7/06/2025"});
    comentarios.push_back({21, "Disco Duro", "Gabriela Suárez", "Gran capacidad de almacenamiento; funciona rápido.", "9/06/2025"});
    comentarios.push_back({22, "Memoria USB", "Raúl Espinosa", "Buen tamaño pero la velocidad de transferencia es baja.", "11/06/2025"});
    comentarios.push_back({23, "Router", "Verónica Mendoza", "Señal potente; cubre toda la casa.", "13/06/2025"});
    comentarios.push_back({24, "Joystick", "Fabio Jiménez", "Comodo y resistente; ideal para gaming.", "15/06/2025"});
    comentarios.push_back({25, "Fuente de Poder", "Ricardo Vargas", "Funciona bien pero los cables son muy cortos.", "17/06/2025"});
    comentarios.push_back({26, "SSD", "Silvia Gómez", "Velocidad increíble; mi PC va mucho más rápido ahora.", "19/06/2025"});
    comentarios.push_back({27, "Altavoces", "Martín Aguilar", "Sonido envolvente; muy buena compra.", "21/06/2025"});
    comentarios.push_back({28, "Webcam", "Valentina Pérez", "Imagen clara pero el micrófono es deficiente.", "23/06/2025"});
    comentarios.push_back({29, "Procesador", "José Ramírez", "Rendimiento impecable; ideal para gaming y diseño.", "25/06/2025"});
    comentarios.push_back({30, "Motherboard", "Natalia Correa", "Buenas prestaciones pero la instalación fue complicada.", "27/06/2025"});
    comentarios.push_back({31, "Memoria RAM", "Julio Fernández", "Expande muy bien el rendimiento del sistema.", "29/06/2025"});
    comentarios.push_back({32, "Fuente Solar", "Amanda Castro", "Energía confiable pero la batería es pequeña.", "1/07/2025"});
    comentarios.push_back({33, "Control Remoto", "Pedro Duarte", "Fácil de usar; reconoce muchos dispositivos.", "3/07/2025"});
    comentarios.push_back({34, "Termostato", "Isabela Medina", "Regula bien la temperatura; intuitivo de usar.", "5/07/2025"});
    comentarios.push_back({35, "Smart Lock", "Oscar Rodríguez", "Seguridad y tecnología en un solo dispositivo.", "7/07/2025"});
    comentarios.push_back({36, "Proyector", "Cristina Vargas", "Imagen nítida pero requiere una sala oscura.", "9/07/2025"});
    comentarios.push_back({37, "Switch Ethernet", "Mario Hernández", "Buena velocidad de conexión; estable.", "11/07/2025"});
    comentarios.push_back({38, "Reloj Digital", "Sofía Ramírez", "Pantalla atractiva pero la batería dura poco.", "13/07/2025"});
    comentarios.push_back({39, "Luces LED", "Andrea Gutiérrez", "Buenas opciones de colores; buen diseño.", "15/07/2025"});
    comentarios.push_back({40, "Estabilizador", "Pablo Medina", "Protege bien contra variaciones de voltaje.", "17/07/2025"});
    comentarios.push_back({41, "Cargador Inalámbrico", "Patricia López", "Carga rápido pero requiere posicionamiento preciso.", "19/07/2025"});
    comentarios.push_back({42, "HDD Externo", "Gonzalo Espinoza", "Mucho espacio; resistente y confiable.", "21/07/2025"});
    comentarios.push_back({43, "Micrófono", "Elena Herrera", "Calidad de sonido profesional; ideal para podcast.", "23/07/2025"});
    comentarios.push_back({44, "Altavoz Inteligente", "Diego Soto", "Responde bien a comandos de voz; útil en casa.", "25/07/2025"});
    comentarios.push_back({45, "Antena Wi-Fi", "Miguel Rojas", "Amplifica bien la señal pero el rango es limitado.", "27/07/2025"});
    comentarios.push_back({46, "Climatizador", "Estefanía Carrillo", "Enfría rápido pero es algo ruidoso.", "29/07/2025"});
    comentarios.push_back({47, "Raspberry Pi", "Manuel Vargas", "Perfecto para proyectos electrónicos y programación.", "31/07/2025"});
    comentarios.push_back({48, "Capturadora", "Luisa Mejía", "Ideal para streaming y grabaciones en alta calidad.", "2/08/2025"});
    comentarios.push_back({49, "Smart Plug", "Victoria Torres", "Muy práctico; fácil de conectar y configurar.", "4/08/2025"});
    comentarios.push_back({50, "Timbre Inteligente", "Federico Montoya", "Buena cámara; útil para seguridad.", "6/08/2025"});
}

// =====================================================
// FUNCIÓN: mostrarDatosCargados() - CORREGIDA
// =====================================================
void mostrarDatosCargados() {
    cout << "\n========== DATOS CARGADOS ==========\n";
    
    cout << "\n--- Usuarios cargados: " << usuarios.size() << " ---\n";
    for (int i = 0; i < usuarios.size(); i++) {
        cout << usuarios[i].idUsuario << " - " << usuarios[i].nombre 
             << " - " << usuarios[i].correoElectronico << endl;
    }

    cout << "\n--- Productos cargados: " << productos.size() << " ---\n";
    for (int i = 0; i < productos.size(); i++) {
        cout << productos[i].idProducto << " - " << productos[i].nombre 
             << " - Stock: " << productos[i].stock << endl;
    }

    cout << "\n--- Comentarios cargados: " << comentarios.size() << " ---\n";
    for (int i = 0; i < comentarios.size(); i++) {
        cout << comentarios[i].idComentario << " - " << comentarios[i].nombreUsuario 
             << " comentó sobre " << comentarios[i].nombreProducto << endl;
    }
}

// =====================================================
// FUNCIÓN: iniciarSesion() - NUEVA
// Busca el usuario por correo y contraseña
// Retorna el índice del usuario si existe, -1 si no
// =====================================================
int iniciarSesion(){
	string correo, contrasena;
	cout << "\n========== INICIAR SESIÓN =========\n";
	cout << "Correo electrónico: ";
	cin >> correo;
	cout << "Contraseña: ";
	cin >> contrasena;

	 // Buscar usuario en el vector
    for (int i = 0; i < usuarios.size(); i++) {
        if (usuarios[i].correoElectronico == correo && usuarios[i].contrasena == contrasena) {
            cout << "\n? ¡Bienvenido " << usuarios[i].nombre << "!\n";
            return i; // Retorna índice del usuario
        }
    }
    
    // Si no se encuentra el usuario
    cout << "\n? Usuario inválido. Correo o contraseña incorrectos.\n";
    return -1;

	
}

// =====================================================
// FUNCIÓN: listarProductosBajoStock() - NUEVA
// Lista productos con stock menor a 15 unidades
// =====================================================
void listarProductosBajoStock() {
    cout << "\n========== PRODUCTOS CON STOCK BAJO (<15) ==========\n";
    
    bool encontrado = false;
    for (int i = 0; i < productos.size(); i++) {
        if (productos[i].stock < 15) {
            cout << "\nID: " << productos[i].idProducto << endl;
            cout << "Nombre: " << productos[i].nombre << endl;
            cout << "Descripción: " << productos[i].descripcion << endl;
            cout << "Precio: $" << productos[i].precio << endl;
            cout << "Stock: " << productos[i].stock << " unidades ??" << endl;
            cout << "----------------------------------------\n";
            encontrado = true;
        }
    }
    
    if (!encontrado) {
        cout << "No hay productos con stock bajo.\n";
    }
}

// =====================================================
// FUNCIÓN: convertirFecha() - NUEVA
// Convierte fecha DD/MM/YYYY a número YYYYMMDD para comparar
// =====================================================
int convertirFecha(string fecha) {
    int dia, mes, anio;
    
    // Buscar las posiciones de las barras
    size_t pos1 = fecha.find('/');
    size_t pos2 = fecha.find('/', pos1 + 1);
    
    // Extraer día, mes y año
    dia = stoi(fecha.substr(0, pos1));
    mes = stoi(fecha.substr(pos1 + 1, pos2 - pos1 - 1));
    anio = stoi(fecha.substr(pos2 + 1));
    
    // Retornar como YYYYMMDD
    return anio * 10000 + mes * 100 + dia;
}

// =====================================================
// FUNCIÓN: listarComentariosDesdeFecha() - NUEVA
// Lista comentarios desde una fecha en adelante
// =====================================================
void listarComentariosDesdeFecha() {
    string fechaBusqueda;
    
    cout << "\n========== COMENTARIOS DESDE UNA FECHA ==========\n";
    cout << "Ingrese la fecha (formato DD/MM/YYYY): ";
    cin >> fechaBusqueda;
    
    int fechaComparar = convertirFecha(fechaBusqueda);
    bool encontrado = false;
    
    cout << "\nComentarios desde " << fechaBusqueda << ":\n";
    
    for (int i = 0; i < comentarios.size(); i++) {
        int fechaComentario = convertirFecha(comentarios[i].fecha);
        
        if (fechaComentario >= fechaComparar) {
            cout << "\n--- Comentario #" << comentarios[i].idComentario << " ---\n";
            cout << "Usuario: " << comentarios[i].nombreUsuario << endl;
            cout << "Producto: " << comentarios[i].nombreProducto << endl;
            cout << "Comentario: " << comentarios[i].comentario << endl;
            cout << "Fecha: " << comentarios[i].fecha << endl;
            encontrado = true;
        }
    }
    
    if (!encontrado) {
        cout << "\nNo hay comentarios desde esa fecha.\n";
    }
}

// =====================================================
// FUNCIÓN: convertirAMayusculas() - NUEVA
// Convierte un string a mayúsculas
// =====================================================
string convertirAMayusculas(string texto) {
    for (int i = 0; i < texto.length(); i++) {
        texto[i] = toupper(texto[i]);
    }
    return texto;
}

// =====================================================
// FUNCIÓN: listarUsuarios() - NUEVA
// Lista todos los usuarios SIN mostrar contraseñas
// Muestra nombres en MAYÚSCULAS
// =====================================================
void listarUsuarios() {
    cout << "\n========== LISTA DE USUARIOS ==========\n";
    
    for (int i = 0; i < usuarios.size(); i++) {
        cout << "\nID: " << usuarios[i].idUsuario << endl;
        cout << "Nombre: " << convertirAMayusculas(usuarios[i].nombre) << endl;
        cout << "Correo: " << usuarios[i].correoElectronico << endl;
        cout << "Dirección: " << usuarios[i].direccion << endl;
        cout << "Método de Pago: " << usuarios[i].metodoDePago << endl;
        cout << "----------------------------------------\n";
    }
}

// =====================================================
// FUNCIÓN: obtenerUltimoIdCarrito() - NUEVA
// Obtiene el último ID de carrito y suma 1
// Si no hay carritos, retorna 1
// =====================================================
int obtenerUltimoIdCarrito() {
    if (carritos.empty()) {
        return 1;
    }
    
    int maxId = 0;
    for (int i = 0; i < carritos.size(); i++) {
        if (carritos[i].idCarrito > maxId) {
            maxId = carritos[i].idCarrito;
        }
    }
    return maxId + 1;
}

// =====================================================
// FUNCIÓN: buscarProductoPorId() - NUEVA
// Busca un producto por ID
// Retorna índice si lo encuentra, -1 si no
// =====================================================
int buscarProductoPorId(int idProducto) {
    for (int i = 0; i < productos.size(); i++) {
        if (productos[i].idProducto == idProducto) {
            return i;
        }
    }
    return -1;
}

// =====================================================
// FUNCIÓN: adicionarProductosCarrito() - NUEVA
// Permite agregar productos al carrito
// Descuenta automáticamente del stock
// =====================================================
void adicionarProductosCarrito(int indiceUsuario) {
    int nuevoIdCarrito = obtenerUltimoIdCarrito();
    CarritoDeCompras nuevoCarrito;
    nuevoCarrito.idCarrito = nuevoIdCarrito;
    nuevoCarrito.nombreUsuario = usuarios[indiceUsuario].nombre;
    nuevoCarrito.subtotal = 0;
    nuevoCarrito.impuestos = 0;
    
    char continuar = 's';
    
    cout << "\n========== ADICIONAR PRODUCTOS AL CARRITO ==========\n";
    
    while (continuar == 's' || continuar == 'S') {
        // Mostrar productos disponibles
        cout << "\n--- PRODUCTOS DISPONIBLES ---\n";
        for (int i = 0; i < productos.size(); i++) {
            if (productos[i].stock > 0) {
                cout << "ID: " << productos[i].idProducto 
                     << " | " << productos[i].nombre 
                     << " | Precio: $" << productos[i].precio 
                     << " | Stock: " << productos[i].stock << endl;
            }
        }
        
        int idProducto, cantidad;
        cout << "\nIngrese el ID del producto: ";
        cin >> idProducto;
        
        int indiceProducto = buscarProductoPorId(idProducto);
        
        if (indiceProducto == -1) {
            cout << "? Producto no encontrado.\n";
        } else {
            cout << "Ingrese la cantidad: ";
            cin >> cantidad;
            
            // Validar stock disponible
            if (cantidad > productos[indiceProducto].stock) {
                cout << "? Stock insuficiente. Solo hay " 
                     << productos[indiceProducto].stock << " unidades.\n";
            } else if (cantidad <= 0) {
                cout << "? Cantidad inválida.\n";
            } else {
                // Agregar IDs de productos al carrito (según cantidad)
                for (int i = 0; i < cantidad; i++) {
                    nuevoCarrito.productosIds.push_back(idProducto);
                    nuevoCarrito.subtotal += productos[indiceProducto].precio;
                }
                
                // Descontar del stock
                productos[indiceProducto].stock -= cantidad;
                
                // Calcular impuestos (19%)
                nuevoCarrito.impuestos = nuevoCarrito.subtotal * 0.19;
                
                cout << "? " << cantidad << " unidad(es) de " 
                     << productos[indiceProducto].nombre 
                     << " agregado(s) al carrito.\n";
                cout << "Stock restante: " << productos[indiceProducto].stock << endl;
            }
        }
        
        cout << "\n¿Desea agregar otro producto? (s/n): ";
        cin >> continuar;
    }
    
    // Guardar el carrito si tiene productos
    if (!nuevoCarrito.productosIds.empty()) {
        carritos.push_back(nuevoCarrito);
        cout << "\n? Carrito creado exitosamente con ID: " << nuevoCarrito.idCarrito << endl;
        cout << "Subtotal: $" << nuevoCarrito.subtotal << endl;
        cout << "Impuestos (19%): $" << nuevoCarrito.impuestos << endl;
        cout << "Total: $" << (nuevoCarrito.subtotal + nuevoCarrito.impuestos) << endl;
    } else {
        cout << "\n?? No se agregaron productos al carrito.\n";
    }
}

// =====================================================
// FUNCIÓN: listarProductosCarrito() - NUEVA
// Lista todos los productos del carrito del usuario
// =====================================================
void listarProductosCarrito(int indiceUsuario) {
    cout << "\n========== MIS CARRITOS DE COMPRAS ==========\n";
    
    bool encontrado = false;
    
    // Buscar todos los carritos del usuario
    for (int i = 0; i < carritos.size(); i++) {
        if (carritos[i].nombreUsuario == usuarios[indiceUsuario].nombre) {
            encontrado = true;
            cout << "\n--- Carrito ID: " << carritos[i].idCarrito << " ---\n";
            cout << "Usuario: " << carritos[i].nombreUsuario << endl;
            cout << "\nProductos en el carrito:\n";
            
            // Contar productos repetidos
            vector<int> productosUnicos;
            vector<int> cantidades;
            
            for (int j = 0; j < carritos[i].productosIds.size(); j++) {
                int idProd = carritos[i].productosIds[j];
                bool encontradoUnico = false;
                
                // Buscar si ya está en productosUnicos
                for (int k = 0; k < productosUnicos.size(); k++) {
                    if (productosUnicos[k] == idProd) {
                        cantidades[k]++;
                        encontradoUnico = true;
                        break;
                    }
                }
                
                if (!encontradoUnico) {
                    productosUnicos.push_back(idProd);
                    cantidades.push_back(1);
                }
            }
            
            // Mostrar productos con sus cantidades
            for (int j = 0; j < productosUnicos.size(); j++) {
                int indiceProducto = buscarProductoPorId(productosUnicos[j]);
                if (indiceProducto != -1) {
                    cout << "  - " << productos[indiceProducto].nombre 
                         << " x" << cantidades[j]
                         << " | Precio unitario: $" << productos[indiceProducto].precio
                         << " | Subtotal: $" << (productos[indiceProducto].precio * cantidades[j])
                         << endl;
                }
            }
            
            cout << "\nSubtotal: $" << carritos[i].subtotal << endl;
            cout << "Impuestos (19%): $" << carritos[i].impuestos << endl;
            cout << "Total: $" << (carritos[i].subtotal + carritos[i].impuestos) << endl;
            cout << "========================================\n";
        }
    }
    
    if (!encontrado) {
        cout << "\n?? No tienes carritos de compras.\n";
    }
}

// =====================================================
// FUNCIÓN: mostrarMenu() - NUEVA
// Muestra el menú principal del usuario autenticado
// =====================================================
void mostrarMenu(int indiceUsuario) {
    int opcion;
    
    do {
        cout << "\n+----------------------------------------+\n";
        cout << "¦        MENÚ PRINCIPAL                  ¦\n";
        cout << "+----------------------------------------+\n";
        cout << "  Usuario: " << usuarios[indiceUsuario].nombre << endl;
        cout << "----------------------------------------\n";
        cout << "  1. Listar Productos (stock < 15)\n";
        cout << "  2. Comentarios desde una fecha\n";
        cout << "  3. Listar Usuarios\n";
        cout << "  4. Adicionar productos al carrito\n";
        cout << "  5. Listar mis carritos\n";
        cout << "  0. Cerrar sesión\n";
        cout << "----------------------------------------\n";
        cout << "  Seleccione una opción: ";
        cin >> opcion;
        
        switch(opcion) {
            case 1:
                listarProductosBajoStock();
                break;
            case 2:
                listarComentariosDesdeFecha();
                break;
            case 3:
                listarUsuarios();
                break;
            case 4:
                adicionarProductosCarrito(indiceUsuario);
                break;
            case 5:
                listarProductosCarrito(indiceUsuario);
                break;
            case 0:
                cout << "\n?? Cerrando sesión...\n";
                break;
            default:
                cout << "\n? Opción inválida. Intente nuevamente.\n";
        }
        
        // Pausa para que el usuario pueda ver los resultados
        if (opcion != 0) {
            cout << "\nPresione Enter para continuar...";
            cin.ignore();
            cin.get();
        }
        
    } while(opcion != 0);
}

// =====================================================
// FUNCIÓN PRINCIPAL: main()
// =====================================================
int main() {
    setlocale(LC_ALL, "spanish");
    
    // Cargar datos iniciales
    cargarDatos();
    
    cout << "\n+----------------------------------------+\n";
    cout << "¦   SISTEMA DE TIENDA ONLINE - PARCIAL II¦\n";
    cout << "+----------------------------------------+\n";
    
    // Mostrar resumen de datos cargados
    mostrarDatosCargados();
    
    // Sistema de login
    int indiceUsuario = -1;
    char intentarNuevamente;
    
    do {
        indiceUsuario = iniciarSesion();
        
        if (indiceUsuario != -1) {
            // Usuario válido - mostrar menú
            mostrarMenu(indiceUsuario);
            intentarNuevamente = 'n';
        } else {
            // Usuario inválido - preguntar si quiere reintentar
            cout << "\n¿Desea intentar nuevamente? (s/n): ";
            cin >> intentarNuevamente;
        }
        
    } while (intentarNuevamente == 's' || intentarNuevamente == 'S');
    
    cout << "\n+----------------------------------------+\n";
    cout << "¦   Gracias por usar el sistema          ¦\n";
    cout << "+----------------------------------------+\n";
    
    return 0;
>>>>>>> c7194d4057bc5dec9f248e96509e8d1a98543311
}
