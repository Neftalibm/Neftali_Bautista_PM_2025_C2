#include <stdio.h>
#include <string.h>

#define MAX_VEHICULOS 100
#define ARCHIVO "vehiculos.dat"

typedef struct
{
    char placa[20];
    char marca[50];
    char modelo[50];
    char tipoCombustible[10];
    float kmGalonCarretera;
    float kmGalonCiudad;
    float costoGomas;
    float kmGomas;
    float costoSeguroAnual;
    float costoMantenimiento;
    float kmMantenimiento;
    float costoVehiculo;
    float vidaUtil;
    float depreciacion;
    float kmAnuales;
} Vehiculo;

Vehiculo vehiculos[MAX_VEHICULOS];
int totalVehiculos = 0;

// Guardar en archivo
void guardarDatos()
{
    FILE *f = fopen(ARCHIVO, "wb");
    if (!f)
    {
        printf("Error guardando datos.\n");
        return;
    }
    fwrite(&totalVehiculos, sizeof(int), 1, f);
    fwrite(vehiculos, sizeof(Vehiculo), totalVehiculos, f);
    fclose(f);
}

// Cargar desde archivo
void cargarDatos()
{
    FILE *f = fopen(ARCHIVO, "rb");
    if (!f) return; // si no existe, empezamos vacío
    fread(&totalVehiculos, sizeof(int), 1, f);
    fread(vehiculos, sizeof(Vehiculo), totalVehiculos, f);
    fclose(f);
}

// Agregar vehiculo
void agregarVehiculo()
{
    if (totalVehiculos >= MAX_VEHICULOS)
    {
        printf("No se pueden agregar mas vehículos.\n");
        return;
    }
    Vehiculo *v = &vehiculos[totalVehiculos];

    printf("Placa: ");
    scanf("%s", v->placa);
    printf("Marca: ");
    scanf("%s", v->marca);
    printf("Modelo: ");
    scanf("%s", v->modelo);
    printf("Tipo Combustible (Gasolina/Gasoil): ");
    scanf("%s", v->tipoCombustible);
    printf("Km/galon Carretera: ");
    scanf("%f", &v->kmGalonCarretera);
    printf("Km/galon Ciudad: ");
    scanf("%f", &v->kmGalonCiudad);
    printf("Costo Gomas: ");
    scanf("%f", &v->costoGomas);
    printf("Km de Gomas: ");
    scanf("%f", &v->kmGomas);
    printf("Costo Seguro Anual: ");
    scanf("%f", &v->costoSeguroAnual);
    printf("Costo Mantenimiento: ");
    scanf("%f", &v->costoMantenimiento);
    printf("Km por mantenimiento: ");
    scanf("%f", &v->kmMantenimiento);
    printf("Costo Vehiculo: ");
    scanf("%f", &v->costoVehiculo);
    printf("Vida Util (years): ");
    scanf("%f", &v->vidaUtil);
    printf("Depreciacion anual: ");
    scanf("%f", &v->depreciacion);
    printf("Km promedio anuales: ");
    scanf("%f", &v->kmAnuales);

    totalVehiculos++;
    guardarDatos(); // Guardar después de agregar
    printf("Vehiculo agregado correctamente.\n");
}

// Listar vehiculos
void listarVehiculos()
{
    if (totalVehiculos == 0)
    {
        printf("No hay vehiculos registrados.\n");
        return;
    }
    for (int i = 0; i < totalVehiculos; i++)
    {
        Vehiculo *v = &vehiculos[i];
        printf("%d - %s %s %s (%s)\n", i+1, v->placa, v->marca, v->modelo, v->tipoCombustible);
    }
}

// Borrar vehiculo
void borrarVehiculo()
{
    listarVehiculos();
    int indice;
    printf("Ingrese el numero de vehiculo a borrar: ");
    scanf("%d", &indice);
    indice--;

    if (indice < 0 || indice >= totalVehiculos)
    {
        printf("Indice no valido.\n");
        return;
    }

    for (int i = indice; i < totalVehiculos - 1; i++)
    {
        vehiculos[i] = vehiculos[i + 1];
    }

    totalVehiculos--;
    guardarDatos(); // Guardar después de borrar
    printf("Vehiculo borrado correctamente.\n");
}

// Modificar vehículo
void modificarVehiculo()
{
    listarVehiculos();
    int indice;
    printf("Ingrese el numero de vehiculo a modificar: ");
    scanf("%d", &indice);
    indice--;

    if (indice < 0 || indice >= totalVehiculos)
    {
        printf("Indice no valido.\n");
        return;
    }

    Vehiculo *v = &vehiculos[indice];

    printf("Placa (%s): ", v->placa);
    scanf("%s", v->placa);
    printf("Marca (%s): ", v->marca);
    scanf("%s", v->marca);
    printf("Modelo (%s): ", v->modelo);
    scanf("%s", v->modelo);
    printf("Tipo Combustible (%s): ", v->tipoCombustible);
    scanf("%s", v->tipoCombustible);
    printf("Km/galon Carretera (%.2f): ", v->kmGalonCarretera);
    scanf("%f", &v->kmGalonCarretera);
    printf("Km/galon Ciudad (%.2f): ", v->kmGalonCiudad);
    scanf("%f", &v->kmGalonCiudad);
    printf("Costo Gomas (%.2f): ", v->costoGomas);
    scanf("%f", &v->costoGomas);
    printf("Km de Gomas (%.2f): ", v->kmGomas);
    scanf("%f", &v->kmGomas);
    printf("Costo Seguro Anual (%.2f): ", v->costoSeguroAnual);
    scanf("%f", &v->costoSeguroAnual);
    printf("Costo Mantenimiento (%.2f): ", v->costoMantenimiento);
    scanf("%f", &v->costoMantenimiento);
    printf("Km por mantenimiento (%.2f): ", v->kmMantenimiento);
    scanf("%f", &v->kmMantenimiento);
    printf("Costo Vehiculo (%.2f): ", v->costoVehiculo);
    scanf("%f", &v->costoVehiculo);
    printf("Vida Util (%.2f): ", v->vidaUtil);
    scanf("%f", &v->vidaUtil);
    printf("Depreciacion anual (%.2f): ", v->depreciacion);
    scanf("%f", &v->depreciacion);
    printf("Km promedio anuales (%.2f): ", v->kmAnuales);
    scanf("%f", &v->kmAnuales);

    guardarDatos(); // Guardar después de modificar
    printf("Vehiculo modificado correctamente.\n");
}

// Calcular costo de viaje
void calcularCostoViaje()
{
    int indice;
    float kmViaje, porcCiudad;
    printf("Seleccione el numero de vehiculo: ");
    listarVehiculos();
    scanf("%d", &indice);
    indice--;

    if (indice < 0 || indice >= totalVehiculos)
    {
        printf("Vehiculo no valido.\n");
        return;
    }

    Vehiculo *v = &vehiculos[indice];

    printf("Kilometros del viaje: ");
    scanf("%f", &kmViaje);
    printf("Porcentaje de km en ciudad: ");
    scanf("%f", &porcCiudad);

    float kmCiudad = kmViaje * (porcCiudad / 100.0);
    float kmCarretera = kmViaje - kmCiudad;

    float galonesCiudad = kmCiudad / v->kmGalonCiudad;
    float galonesCarretera = kmCarretera / v->kmGalonCarretera;

    float costoCombustible;
    if (strcmp(v->tipoCombustible, "Gasolina") == 0)
        costoCombustible = (galonesCiudad + galonesCarretera) * 300;
    else
        costoCombustible = (galonesCiudad + galonesCarretera) * 250;

    float costoGomas = (kmViaje / v->kmGomas) * v->costoGomas;
    float costoSeguro = (v->costoSeguroAnual / v->kmAnuales) * kmViaje;
    float costoMantenimiento = (kmViaje / v->kmMantenimiento) * v->costoMantenimiento;
    float costoDepreciacion = (v->depreciacion / v->kmAnuales) * kmViaje;

    float costoTotal = costoCombustible + costoGomas + costoSeguro + costoMantenimiento + costoDepreciacion;

    printf("\n--- Detalle de Costos ---\n");
    printf("Combustible: %.2f\n", costoCombustible);
    printf("Gomas: %.2f\n", costoGomas);
    printf("Seguro: %.2f\n", costoSeguro);
    printf("Mantenimiento: %.2f\n", costoMantenimiento);
    printf("Depreciacion: %.2f\n", costoDepreciacion);
    printf("Costo por km: %.2f\n", costoTotal / kmViaje);
    printf("Costo total del viaje: %.2f\n", costoTotal);
    printf("Costo del vehiculo: %.2f\n", v->costoVehiculo);
}

int main()
{
    cargarDatos(); // Cargar al inicio
    int opcion;
    do
    {
        printf("\n1. Agregar vehiculo\n");
        printf("2. Listar vehiculos\n");
        printf("3. Modificar vehiculo\n");
        printf("4. Borrar vehiculo\n");
        printf("5. Calcular costo viaje\n");
        printf("0. Salir\nOpcion: ");
        scanf("%d", &opcion);

        switch (opcion)
        {
        case 1:
            agregarVehiculo();
            break;
        case 2:
            listarVehiculos();
            break;
        case 3:
            modificarVehiculo();
            break;
        case 4:
            borrarVehiculo();
            break;
        case 5:
            calcularCostoViaje();
            break;
        }
    }
    while (opcion != 0);
    return 0;
}
