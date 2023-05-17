// En este archivo, guardaremos los 16807 elementos de la lista en el vector de registro.
// Código del profesor.

#ifndef _REGISTRO_H_
#define _REGISTRO_H_

#include <string>
#include <vector>
#include <ctime> // transformar una fecha a numero decimal 
#include <iostream>

// La siguiente clase representa un evento (o registro) dentro de la bitacora:
class Registro {
  private:
    std::string mes, dia, horas, minutos, segundos, ip, puerto, falla;
    std::vector<std::string> meses = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
    // Info struct tm https://cplusplus.com/reference/ctime/tm/
    struct tm dateStruct;
    // Unix timestamp (segundos transcurridos desde el 1 de enero de 1970)
    time_t fechaHora;
  public:
    Registro();
    Registro(std::string _mes, std::string _dia, std::string _horas, std::string _minutos, std::string _segundos, std::string _ip, std::string _puerto, std::string _falla);
    std::string getAll();
    std::string getIP() const { return ip; }
    std::string getPuerto() const { return puerto; }
    std::string getFalla() const { return falla; }

    // Sobre carga de operadores
    bool operator ==(const Registro&);
    bool operator !=(const Registro&);
    bool operator >(const Registro&);
    bool operator <(const Registro&);
    bool operator >=(const Registro&);
    bool operator <=(const Registro&);
};
#endif