#ifndef FECHA_H_
#define FECHA_H_

typedef struct{
        int dia;
        int mes;
        int anio;
}eFecha;

#endif /* FECHA_H_ */

int validarFecha( int dia, int mes, int anio);
/** @brief Valida que la fecha ingresada sea una fecha valida
 *
 * @param Un entero, el dia que el usuario ingreso
 * @param Un entero, el mes que el usuario ingreso
 * @param Un entero, el año que el usuario ingreso
 * @return Un entero, 0 si la fecha no es valida y 1 si es valida
 */
