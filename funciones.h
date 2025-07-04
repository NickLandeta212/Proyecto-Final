#ifndef FUNCIONES_H
#define FUNCIONES_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ZONAS 5
#define DIAS_HISTORICO 30
#define MAX_CIUDADES 10   // Máximo número de ciudades que se pueden manejar

// Estructura para almacenar los límites de contaminación
struct Limites {
    float co2;    // Dióxido de carbono
    float so2;    // Dióxido de azufre
    float no2;    // Dióxido de nitrógeno
    float pm25;   // Partículas finas (PM2.5)
};

// Estructura para almacenar los niveles de contaminantes
struct Contaminantes {
    float co2;
    float so2;
    float no2;
    float pm25;
    char estado[20]; // Normal, Riesgo o Crítico
};

// Estructura para almacenar las condiciones climáticas
struct CondicionesClimaticas {
    float temperatura;
    float humedad;
    float velocidad_viento;
};

// Estructura para almacenar predicciones
struct Prediccion {
    struct Contaminantes niveles_predichos;
    char alerta[100];
};

// Estructura para almacenar datos históricos
struct DatosHistoricos {
    struct Contaminantes datos[DIAS_HISTORICO];
    float promedios_co2;
    float promedios_so2;
    float promedios_no2;
    float promedios_pm25;
};

// Estructura para representar una zona
struct Zona {
    char nombre[50];
    struct Contaminantes niveles_actuales;
    struct CondicionesClimaticas clima_actual;
    struct Prediccion prediccion;
    struct DatosHistoricos historico;
    char recomendaciones[500];
};

// Estructura para representar una ciudad
struct Ciudad {
    char nombre[50];
    int num_zonas;
    struct Zona zonas[MAX_ZONAS];
};

// Estructura para gestionar múltiples ciudades
struct SistemaMonitoreo {
    struct Ciudad ciudades[MAX_CIUDADES];
    int num_ciudades;
};



// Funciones para manejo de límites
void cargar_limites_oms(struct Limites *limites);
void guardar_limites(struct Limites limites);
void ingresar_limites_personalizados(struct Limites *limites);
int cargar_limites_desde_archivo(struct Limites *limites);

// Funciones para monitoreo y predicción
void ingresar_datos_zona(struct Zona *zona);
void evaluar_niveles_contaminacion(struct Zona *zona, struct Limites limites);
void predecir_niveles(struct Zona *zona);
void calcular_promedios_historicos(struct Zona *zona);
void generar_recomendaciones(struct Zona *zona, struct Limites limites);

// Funciones para manejo del sistema
void inicializar_ciudad(struct Ciudad *ciudad);
void exportar_informacion(struct Ciudad ciudad, struct Limites limites);
void simular_datos_historicos(struct Zona *zona, struct Limites limites);
void mostrar_estado_actual(struct Ciudad ciudad, struct Limites limites);
void mostrar_predicciones(struct Ciudad ciudad);
void mostrar_promedios_historicos(struct Ciudad ciudad, struct Limites limites);
void mostrar_recomendaciones(struct Ciudad ciudad);

// Funciones para manejo de múltiples ciudades
void inicializar_sistema(struct SistemaMonitoreo *sistema);
void agregar_ciudad(struct SistemaMonitoreo *sistema, struct Limites limites);
int seleccionar_ciudad(struct SistemaMonitoreo sistema);
void guardar_ciudades(struct SistemaMonitoreo sistema);
int cargar_ciudades(struct SistemaMonitoreo *sistema);

#endif // FUNCIONES_H
