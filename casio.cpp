#include<iostream>
#include<stdlib.h>
#include<fstream>
using namespace std;
//________________________________________________
class pen65 {
private:
    string nombre;
    int edad;

public:
    pen65(string _nombre, int _edad);
    void mostrar1();
};
pen65::pen65(string _nombre, int _edad) {
    this->nombre = _nombre;
    this->edad = _edad;
}
void pen65::mostrar1() {
    ofstream archivo("casio.txt", ios::app);
    archivo<<"[][]"<< nombre <<"|: [][]"<<endl;
    if (edad >= 65)
        archivo << "-[][]le corresponde s/.250.00 del programa ||pension 65|| [][]  " << endl;
    else
        archivo << "-[][]no le corresponde s/.250.00 del programa ||pension 65|| [][] " << endl;
    archivo<<endl;
    archivo.close();
}
//___________________________________________________________________________
class vasl{
    private:
        string nombre;
        int hijos;
        int weeks;
    public:
        vasl(string,int,int);
        void mostrar2();
};
vasl::vasl(string _nombre, int _hijos, int _weeks) {
    this->nombre = _nombre;
    this->hijos = _hijos;
    this->weeks = _weeks;
}
void::vasl::mostrar2(){
    int ed,ovl=200,junt=200;
    for (int i = 1; i <= hijos; i++) { 
        cout << "Ingrese la edad del hijo #" << i << ": ";
        cin >> ed;
        if(ed<=18 and ed>-1){
            if(ed>13){
                junt=ed;
            }else{
                ovl=ed;
            }
        }
    } 
    system("cls");
    ofstream archivo("casio.txt", ios::app);
    archivo<<"[][]"<<nombre<<"|: |[][]"<<endl;
    if(weeks>0 and (ovl==200 or ovl!=200)and(junt==200 or junt!=200 )){
        archivo<<"-[][]le corresponde el programa ||vaso de leche||[][]"<<endl;
        archivo<<"-[][] le corresponde el programa ||juntos ||[][]"<<endl;
        archivo<<endl;
    }else {
        if((ovl<13)and(junt==200 or junt!=200)){
            archivo<<"-[][] le corresponde el programa ||vaso de leche||[][]"<<endl;
            archivo<<"-[][] y le corresponde s/.200 del programa||juntos || cada dos meses[][]"<<endl;
        }
        else{
            if(junt>13 and junt<=18){
                archivo<<"-[][]solo le corresponde s/.200 del programa ||juntos || cada dos meses [][]"<<endl;
            }
        }
    }
    archivo.close();
}
//-------------------------------------------------------------
class Gen{
    public:
        string nombre;
        int edad;
    public:
        Gen(string,int);
        virtual void mostrar();
};

Gen::Gen(std::string _nombre, int _edad){
    nombre=_nombre;
    edad=_edad;
}
void Gen::mostrar(){
    ofstream archivo("casio.txt", ios::app);
    cout<<"[][]"<<nombre<<"|: |[][]"<<endl;
    archivo.close();
}

class Beca18:public Gen{
    private:
        int nota;
    public:

        Beca18(string,int,int);
        void mostrar();
};

Beca18::Beca18(std::string _nombre, int _edad, int _nota):Gen(_nombre, _edad){
    nota=_nota;
}

void Beca18::mostrar(){
    ofstream archivo("casio.txt", ios::app);
    archivo<<"[][]"<< nombre <<"|: [][]"<<endl;
    if ((edad>=17) and (edad<=22)){
        if(nota>=14){
            archivo<<"-[][]cumples los requisitos para postular a la ordinaria ||beca 18|| "<<endl;
        }
        else{
            archivo<<"-[][]NO cumples los requisitos para postular a la ordinaria ||beca 18|| "<<endl;
        }
    }else{
            archivo<<"-[][]NO cumples los requisitos para postular a la ordinaria ||beca 18|| "<<endl;
    }
    archivo.close();
}
//-----------------------------------------------
class BecaEIB:public Gen{
    private:
        int nota;
        string language;
    public:

        BecaEIB(string,int,int,string);
        void mostrar();
};

BecaEIB::BecaEIB(std::string _nombre, int _edad, int _nota, string _language):Gen(_nombre, _edad){
    nota=_nota;
    language=_language;
}

void BecaEIB::mostrar(){
    ofstream archivo("casio.txt", ios::app);
    archivo<<"[][]"<< nombre <<"|: [][]"<<endl;
    if ((nota<=12) and (edad<=20)){
        if(language=="ashaninka" or language=="kichwa" or language=="shawi" or language=="kukama" or language=="kukamiria" or language=="achuar" or language=="awajún"){
            archivo<<"-[][]cumples los requisitos para postular a la  ||beca educacion interculrural bilingue(EIB|| "<<endl;
        }
        else{
            archivo<<"-[][]NO cumples los requisitos para postular a la  ||beca educacion interculrural bilingue(EIB|| "<<endl;
        }
    }else{
        archivo<<"-[][]cumples los requisitos para postular a la  ||beca educacion interculrural bilingue(EIB|| "<<endl;
    }
    archivo.close();
}
//-------------
class proteccion:public Gen{
    private:
        int nota;
        string discapacidad;
        string albergue;
    public:

        proteccion(string,int,int,string,string);
        void mostrar();
};

proteccion::proteccion(std::string _nombre, int _edad, int _nota, string _discapacidad,string _albergue):Gen(_nombre, _edad){
    nota=_nota;
    discapacidad=_discapacidad;
    albergue=_albergue;  
}

void proteccion::mostrar(){
    ofstream archivo("casio.txt", ios::app);
    archivo<<"[][]"<< nombre <<"|: [][]"<<endl;
    if(discapacidad=="si"){
        archivo<<"-[][]cumples los requisitos para postular a la  ||beca PROTECCION|| "<<endl;
    }else{
        if(albergue=="si" and nota>=14){
            archivo<<"-[][]cumples los requisitos para postular a la  ||beca PROTECCION|| "<<endl;
        }else{
            archivo<<"-[][]NO cumples los requisitos para postular a la  ||beca PROTECCION|| "<<endl;
        }

    }
    archivo.close(); 
}
//------
class repared:public Gen{
    private:
        int nota;
        string conflicto;
    public:

        repared(string,int,int,string);
        void mostrar();
};

repared::repared(std::string _nombre, int _edad, int _nota, string _conflicto):Gen(_nombre, _edad){
    nota=_nota;
    conflicto=_conflicto;  
}
void repared::mostrar(){
    ofstream archivo("casio.txt", ios::app);
    archivo<<"[][]"<< nombre <<"|: [][]"<<endl;
    if(conflicto =="si" and nota>=12){
        archivo<<"-[][]cumples los requisitos para postular a la  ||beca REPARED|| "<<endl;
    }else{
        archivo<<"-[][]NO cumples los requisitos para postular a la  ||beca REPARED|| "<<endl;
    }
    archivo.close();
}
//---------
class cnapa:public Gen{
    private:
        int nota;
        string poblacion;
    public:

        cnapa(string,int,int,string);
        void mostrar();
};

cnapa::cnapa(std::string _nombre, int _edad, int _nota, string _poblacion):Gen(_nombre, _edad){
    nota=_nota;
    poblacion=_poblacion;  
}
void cnapa::mostrar(){
    ofstream archivo("casio.txt", ios::app);
    archivo<<"[][]"<< nombre <<"|: [][]"<<endl;
    if(poblacion =="si" and nota>=14){
        archivo<<"-[][]cumples los requisitos para postular a la  ||beca CNA/PA|| "<<endl;
    }else{
        archivo<<"-[][]NO cumples los requisitos para postular a la  ||beca CNA/PA|| "<<endl;
    }
    archivo.close();
}
//--------------------------------
class ffaa:public Gen{
    private:
        int nota;
        string militar;
    public:

        ffaa(string,int,int,string);
        void mostrar();
};

ffaa::ffaa(std::string _nombre, int _edad, int _nota, string _militar):Gen(_nombre, _edad){
    nota=_nota;
    militar=_militar;  
}
void ffaa::mostrar(){
    ofstream archivo("casio.txt", ios::app);
    archivo<<"[][]"<< nombre <<"|: [][]"<<endl;
    if(edad>=20 and edad<=30){
        if(militar =="si"){
            if(nota==13){
                archivo<<"-[][]cumples los requisitos para postular a la  ||beca FF.AA|| (para isntituto) "<<endl;
            }else{
                if(nota>=14 and nota<=20){
                    archivo<<"-[][]cumples los requisitos para postular a la  ||beca FF.AA|| (para universidad) "<<endl;
                }else{
                    archivo<<"-[][]NO cumples los requisitos para postular a la  ||beca FF.AA|| "<<endl;
                }
            }
        }else{
            archivo<<"-[][]NO cumples los requisitos para postular a la  ||beca FF.AA|| "<<endl;
        }
    }
    else{
        archivo<<"-[][]NO cumples los requisitos para postular a la  ||beca FF.AA|| "<<endl;
    }
    archivo.close();
}
//---------------------
class vraem:public Gen{
    private:
        string region;
        int nota;
    public:
        vraem(string,int,string,int);
        void mostrar();
};

vraem::vraem(std::string _nombre, int _edad,string _region,int _nota ):Gen(_nombre,_edad){
    region=_region;
    nota=_nota;
}
void vraem::mostrar(){
    ofstream archivo("casio.txt", ios::app);
    archivo<<"[][]"<< nombre <<"|: [][]"<<endl;
    if(region=="cusco" or region=="apurimac" or region=="junin" or region=="huancavelica " or region=="ayacucho"){
        if(nota>=13 and nota<=20){
            archivo<<"-[][]cumple los requisitos para postular a la  ||beca VRAEM||"<<endl;
        }else{
            archivo<<"-[][]NO cumple los requisitos para postular a la  ||beca VRAEM||"<<endl;
        }
    }else{
        archivo<<"-[][]NO cumple los requisitos para postular a la  ||beca VRAEM||"<<endl;
    }
    archivo.close();
}
//---------
class huallaga:public Gen{
    private:
        string region;
        int nota;
    public:
        huallaga(string,int,string,int);
        void mostrar();
};

huallaga::huallaga(std::string _nombre, int _edad,string _region,int _nota ):Gen(_nombre,_edad){
    region=_region;
    nota=_nota;
}
void huallaga::mostrar(){
    ofstream archivo("casio.txt", ios::app);
    archivo<<"[][]"<< nombre <<"|: [][]"<<endl;
    if(region=="huanuco" or region=="san martin" or region=="ucayali"){
        if(nota>=13 and nota<=20){
            archivo<<"-[][]cumple los requisitos para postular a la  ||beca HUALLAGA||"<<endl;
        }else{
            archivo<<"-[][]NO cumple los requisitos para postular a la  ||beca HUALLAGA||"<<endl;
        }
    }else{
        archivo<<"-[][]NO cumple los requisitos para postular a la  ||beca HUALLAGA||"<<endl;
    } 
    archivo<<endl;
    archivo.close();
}
//--------------------------
class dis:public Gen{
    private:
        string discapacidad;
    public:
        dis(string,int,string);
        void mostrar();
};

dis::dis(std::string _nombre, int _edad,string _discapacidad):Gen(_nombre,_edad){
    discapacidad=_discapacidad;
}
void dis::mostrar(){
    ofstream archivo("casio.txt", ios::app);
    archivo<<"[][]"<< nombre <<"|: [][]"<<endl;
    if (discapacidad=="si"){
        archivo<<"-[][]califica para precibir S/.3000.00 del programa ||CONTIGO||"<<endl;

    }else{
        archivo<<"-[][]NO califica para precibir S/.3000.00 del programa ||CONTIGO||"<<endl;
    }
    archivo.close();
}



int main() {
    int lu, ca,ce,ci;
    int nott;
    string nombre,lengua,discapaz,albergue,conflicto,poblacion,militar,region;
    int edad;
    int hijos;
    int gestacion;
    
    do {
        cout << "|||elige la opcion segun corresponda|||\n";
        cout << "1: consultar\n";
        cout << "0: salir\n";
        cin >> lu;
        system("cls");

        if (lu == 1) {
            do {
                cout<<endl,
                cout << "|||CONSULTAR COMO:|||\n";
                cout << "1: PADRE DE FAMILIA\n";
                cout << "2: ESTUDIANTE\n";
                cout << "3: ADULTO MAYOR\n";
                cout << "4: PACIENTE EN CON DISCAPACIDAD\n";
                cout << "0: salir\n";
                cin >> ca;
                system("cls");
                if(ca==1){
                    do{
                        cout<<"|||DIGITE SU GENERO|||";
                        cout<<endl;
                        cout<<"1:hombre "<<endl;
                        cout<<"2:mujer "<<endl;
                        cout<<"enter:";cin>>ce;
                        system("cls");
                    }while(ce<1 or ce>2 );
                    if (ce==2){
                            cout << "Ingrese su nombre: ";
                            cin.ignore();
                            getline(cin, nombre);
                            cout<<"ingrese el numero de hijos: ";
                            cin>>hijos;
                            cout<<"ingrese semanas de gestacion: ";
                            cin>>gestacion;
                            system("cls");
                            vasl peo(nombre,hijos,gestacion);
                            peo.mostrar2();
                    }
                    else{

                            cout << "Ingrese su nombre: ";
                            cin.ignore();
                            getline(cin, nombre);
                            cout<<"ingrese el numero de hijos: ";
                            cin>>hijos;
                            cout<<"ingrese semanas de gestacion de su esposa: ";
                            cin>>gestacion;
                            system("cls"); 
                            vasl peo(nombre,hijos,gestacion);
                            peo.mostrar2();
                    }
                    

                    
                    
                }
                if(ca==2){
                    do{
                        cout<<"|||elija paraa averiguar a que beca puede acceder|||"<< endl;
                        cout<<"1: beca 18"<< endl;
                        cout<<"2: beca IEB"<< endl;
                        cout<<"3: beca PROTECCION"<< endl;
                        cout<<"4: beca REPARED"<< endl;
                        cout<<"5: beca CNA/PA"<< endl;
                        cout<<"6: beca FF.AA"<< endl;
                        cout<<"7: beca VRAEM"<< endl;
                        cout<<"8: beca HUALLAGA"<< endl;
                        cout<<"0:salir"<<endl;
                        cin>>ci;
                        system("cls");
                        cout<<endl;
                        
                        if(ci==1){
                            cout<<"ingrese el promedio notas finales de 3° 4° 5° de secunadria : ";
                            cin>>nott;
                            cout<<"ingrese su nombre :";
                            cin.ignore();
                            getline(cin, nombre);
                            cout << "Ingrese su edad: ";
                            cin >> edad;
                            cout<<endl;
                            Beca18 obj(nombre,edad,nott);
                            system("cls");
                            obj.mostrar();
                        }
                        //---
                        if(ci==2){
                            cout<<"ingrese el promedio notas finales de 3° 4° 5° de secunadria : ";
                            cin>>nott;
                            cout<<"ingrese su nombre :";
                            cin.ignore();
                            getline(cin, nombre);
                            cout << "Ingrese su edad: ";
                            cin >> edad;
                            cout<<"ingrese lengua nativa que domina :";
                            cin.ignore();
                            getline(cin, lengua);
                            cout<<endl;
                            BecaEIB obj(nombre,edad,nott,lengua);
                            system("cls");
                            obj.mostrar();
                        }
                        //--
                        if(ci==3){
                            cout<<"ingrese el promedio notas finales de 3° 4° 5° de secunadria : ";
                            cin>>nott;
                            cout<<"ingrese su nombre :";
                            cin.ignore();
                            getline(cin, nombre);
                            cout << "Ingrese su edad: ";
                            cin >> edad;
                            cout<<"sufre alguna discapacidad(si o no):";
                            cin.ignore();
                            getline(cin, discapaz);
                            cout<<"ha estado en algun albergue?(si o no):";
                            getline(cin, albergue);
                            cout<<endl;
                            proteccion ogh(nombre,edad,nott,discapaz,albergue);
                            system("cls");
                            ogh.mostrar();
                        }
                        if(ci==4){
                            cout<<"ingrese el promedio notas finales de 3° 4° 5° de secunadria : ";
                            cin>>nott;
                            cout<<"ingrese su nombre :";
                            cin.ignore();
                            getline(cin, nombre);
                            cout << "Ingrese su edad: ";
                            cin >> edad;
                            cout<<"su familia ha sido victima del conflicto armado?(si o no):";
                            cin.ignore();
                            getline(cin, conflicto);
                            cout<<endl;
                            repared ogh(nombre,edad,nott,conflicto);
                            system("cls");
                            ogh.mostrar();
                        }
                        if(ci==5){
                            cout<<"ingrese el promedio notas finales de 3° 4° 5° de secunadria : ";
                            cin>>nott;
                            cout<<"ingrese su nombre :";
                            cin.ignore();
                            getline(cin, nombre);
                            cout << "Ingrese su edad: ";
                            cin >> edad;
                            cout<<"PERTENECES A POBLACIONES NATIVAS AMAZONICAS O A POLBLACIONES AFROPERUANAS?"<<endl;
                            cout<<"(si o no) :";
                            cin.ignore();
                            getline(cin, poblacion);
                            cout<<endl;
                            cnapa ogh(nombre,edad,nott,poblacion);
                            system("cls");
                            ogh.mostrar();
                        }
                        if(ci==6){
                            cout<<"ingrese el promedio notas finales de 3° 4° 5° de secunadria : ";
                            cin>>nott;
                            cout<<"ingrese su nombre :";
                            cin.ignore();
                            getline(cin, nombre);
                            cout << "Ingrese su edad: ";
                            cin >> edad;
                            cout<<"ha pertenecido al Servicio Militar Voluntario del Perú... "<<endl;
                            cout<<"(si o no) :";
                            cin.ignore();
                            getline(cin, militar);
                            cout<<endl;
                            ffaa ogh(nombre,edad,nott,militar);
                            system("cls");
                            ogh.mostrar();
                        }
                        if(ci==7){
                            cout<<"ingrese el promedio notas finales de 3° 4° 5° de secunadria :";
                            cin>>nott;
                            cout<<"ingrese su nombre :";
                            cin.ignore();
                            getline(cin, nombre);
                            cout << "Ingrese su edad :";
                            cin >> edad;
                            cout<<"ingrese su region natural :";
                            cin.ignore();
                            getline(cin, region);
                            cout<<endl;
                            vraem ogh(nombre,edad,region,nott);
                            system("cls");
                            ogh.mostrar();
                        }
                        if(ci==8){
                            cout<<"ingrese el promedio notas finales de 3° 4° 5° de secunadria :";
                            cin>>nott;
                            cout<<"ingrese su nombre :";
                            cin.ignore();
                            getline(cin, nombre);
                            cout << "Ingrese su edad :";
                            cin >> edad;
                            cout<<"ingrese su region natural :";
                            cin.ignore();
                            getline(cin, region);
                            cout<<endl;
                            huallaga ogh(nombre,edad,region,nott);
                            system("cls");
                            ogh.mostrar();
                        }  
                    }while(ci!=0);
                                           
                    
                    
                }
                if(ca==3){
                    cout << "Ingrese su nombre: ";
                    cin.ignore();
                    getline(cin, nombre);
                    cout << "Ingrese su edad: ";
                    cin >> edad;

                    system("cls");
                    pen65 per(nombre, edad);
                    per.mostrar1();
                }
                if(ca==4){
                    cout<<"ingrese su nombre :";
                    cin.ignore();
                    getline(cin, nombre);
                    cout << "Ingrese su edad :";
                    cin >> edad;
                    cout<<"tiene discapacidad severa?(si o no) :";
                    cin.ignore();
                    getline(cin, discapaz);
                    dis obj(nombre,edad,discapaz);
                    system("cls");
                    obj.mostrar();
                }  
            } while (ca != 0);
        }
        system("cls");
    } while (lu != 0);

    std::ifstream archivo("casio.txt");

    if (!archivo.is_open()) {
        std::cout << "No se pudo abrir el archivo." << std::endl;
        return 1;
    }

    std::string linea;
    while (std::getline(archivo, linea)) {
        std::cout << linea << std::endl;
    }

    archivo.close();
    return 0;
}