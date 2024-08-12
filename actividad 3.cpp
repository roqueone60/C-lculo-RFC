
// ACTIVIDAD 3 CÁLCULO DE RFC SIN HOMOCLAVE



#include <iostream>
#include <string>

//Función para obtener la primer vocal del apellido paterno
char PrimerVocalInterna(const std::string & str){
    for(size_t i=1; i < str.length(); i++){
        char c = str[i]; 
        if (c=='A' || c=='E' || c=='I' || c=='O' || c=='U')
            return c;
    }
    return 'X'; //Si no se encuentra una vocal interna, se usa letra X
}

//la Función principal para calcular el RFC
std::string CalcularRFC (const std::string&Nombre,const std::string&ApellidoPaterno,const std::string&ApellidoMaterno,const std::string&FechaNacimiento)
{
    std::string RFC;
    
    //Se obtiene la primera letra y la primer vocal del apellido paterno
    char LetraInicialP = ApellidoPaterno[0];
    char VocalInterna = PrimerVocalInterna (ApellidoPaterno);
    
    //Se obtiene la primer letra del apellido materno y en caso de no haber apellido materno, estará asignando la letra X 
    char LetraInicialM = (!ApellidoMaterno.empty()) ? ApellidoMaterno[0]:'X';
    
    //Se obtiene la inicial del Nombre
    char LetraInicialNombre = Nombre[0];
    
    //Se obtienen los digitos correspondientes a la fecha de nacimiento
    std::string aa = FechaNacimiento.substr(2,2); //dos últimos digítos del año del año de nacimiento
    std::string mm = FechaNacimiento.substr(5,2); // digítos correspondientes al mes de nacimiento
    std::string dd = FechaNacimiento.substr(8,2); // digítos correspondientes al día de nacimiento
    
    //Con la estructura realizada vamos a construir el RFC 
    RFC = LetraInicialP;
    RFC += VocalInterna;
    RFC += LetraInicialM;
    RFC += LetraInicialNombre;
    RFC += aa;
    RFC += mm;
    RFC += dd;
    
    return RFC;
}

int main()
{
    //Declaración de las variables en las cuales estaremos almacenando los datos ingresados por el usuario
    std:: string Nombre, ApellidoPaterno, ApellidoMaterno, FechaNacimiento;
    
    std::cout<<"Cálculo de RFC en C++ (sin homoclave)" <<std::endl;
    std::cout<<"NOTA: ingresar sus datos en letras mayúsculas" <<std::endl;
    
    //Solicitamos al usuario sus datos y los vamos almacenando en las variables
    
    std::cout << "Ingrese su Nombre: ";
    std::getline (std::cin,Nombre);
    
    std::cout << "Ingrese su Apellido Paterno: ";
    std::getline (std::cin,ApellidoPaterno);
    
    std::cout << "Ingrese su Apellido Materno, en caso de que no tenga, solo de enter: ";
    std::getline (std::cin,ApellidoMaterno);
    
    std::cout << "Ingrese su fecha de nacimiento (YYYY/MM/DD): ";
    std::getline (std::cin,FechaNacimiento);
    
    //CalcularRFC que declaramos en líneas arriba
    std::string RFC = CalcularRFC (Nombre,ApellidoPaterno,ApellidoMaterno,FechaNacimiento);
    std::cout << "El RFC es: " << RFC << std::endl; //finalmente hacemos la impresión del resultado final

    return 0;
}