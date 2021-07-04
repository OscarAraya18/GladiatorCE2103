//
// Created by oscar_araya_x on 05/05/19.
//

#include "Algoritmo.h"
#include <math.h>
#include <random>

using namespace std;

Algoritmo::Algoritmo(){

}



int Algoritmo::calcularResistencia(Nodo *gladiador) {
    return(int ((gladiador->getFuerzaTroncoInferior()*0.01+gladiador->getFuerzaTroncoSuperior()*0.01
               +gladiador->getCondicionFisica()*0.07+gladiador->getInteligenciaEmocional()*0.07+gladiador->getGeneracionesParaLaSupervivencia()*0.01
               +gladiador->getProbabilidadSupervivencia()*0.01+gladiador->getEdad()*0.01+gladiador->getFitness()*0.01))*0.78);
}



int Algoritmo::convertidorbin_dec(string num1)
{
    int b,d=0,e=0,c=0;
    b=atoi(num1.c_str());
    while(b>=10){
        c=0;
        while(b>=10){
            b-=10;
            c++;
        }
        d =d+ b*pow(2,e);
        e++;
        b=c;
    }
    d=d+ c*pow(2,e);
    return d;

}

string Algoritmo::convertidordec_bin(int num2)
{
    int numero, dividendo, resto, divisor = 2;
    string binario = "";
    dividendo = num2;
    while(dividendo >= divisor){ //Mientras el dividendo sea mayor o igual que el divisor, es decir, mayor o igual que 2.
        resto = dividendo % 2;
        if(resto == 1)
            binario = "1" + binario; //Si el resto es igual a 1 concatenamos 1 a la variable string llamada binario
        else
            binario = "0" + binario; // Sino concatemanos 0
        //Es importante este orden de concatenación (primero el bit y luego el valor de la variable) esto para que nuestro número
        //en sistema binario esté ordenado correctamente.
        dividendo = dividendo/divisor; // Actualizamos el valor del dividendo dividiendolo entre 2.
    }
    if(dividendo == 1)
        binario = "1" + binario; // Por último sí el valor final del dividendo es 1 concatenamos 1 sino concatenamos 0.
    else
        binario = "0" + binario;
    return binario;
}

string Algoritmo::sumabin(string num1, string num2){
//    cout <<"estos son los padres 1 "<<num1<<" 2 "<<num2<<endl;
    random_device generadorAzar;
    mt19937 aux(generadorAzar());
    uniform_int_distribution<int> uni(1,1000);
    string hijo="";
    string mitad1="";
    string mitad2="";
    if (num2.size()<num1.size()){
        string aux=num2;
        num2=num1;
        num1=aux;
    }
    int maximo= (num2.size()/2);
    //cout <<"REALIZANDO CALCULO GENETICO..."<<endl;
    /**if((maximo == 1 || maximo ==2) && num1.size()>maximo ){
        cout <<"si aqui es x2 "<<endl;
    }*/
    if (num1.size()>maximo){
        maximo+=1;
    }
    if (num1.size()<maximo){
        maximo=num1.size();
    }
    //cout <<"si aqui es x2.5 "<<endl;
    //maximo+=1;
    for (int i=0;i<maximo;i++) {
        if (num2.at(i)==1){
        hijo+=num2.at(i);
        hijo+=num1.at(i);
        }
        else {
        hijo+=num1.at(i);
        hijo+=num2.at(i);
        }
    }
    //cout <<"si aqui es x3 "<<endl;

        //hijo+=mitad1;
        //hijo+=mitad2;//cout<<"esto es con modificiacion"<<hijo<<endl;
    srand(time(NULL));
    int probabilidad =uni(aux);
    if (hijo !=""){
    if (probabilidad<=5){
        //cout<<"mutacion "<<hijo<<" sin cambios"<<endl;
        srand(time(NULL));
        int mutacion =0 + rand() % (hijo.size());
        if (hijo.at(mutacion)=='0'){
            hijo.at(mutacion)='1';
        }
        if (hijo.at(mutacion)=='1'){
            hijo.at(mutacion)='0';
        }
        //cout <<"mutado "<<hijo<<endl;
    }
    if (probabilidad<=2){
        if(hijo!="" && hijo.size()>1){
        //cout<<"Insersion "<<hijo<<endl;
            srand(time(NULL));
            int insercion =0 + rand() % (hijo.size()-1);
            if (hijo.at(insercion)=='0'){
            hijo.at(insercion)='1';
            if(hijo.at(insercion+1)=='0'){
                hijo.at(insercion+1)='1';}
            if(hijo.at(insercion+1)=='1'){
                hijo.at(insercion+1)='0';}
            }
            if (hijo.at(insercion)=='1'){
                hijo.at(insercion)='0';
                if(hijo.at(insercion+1)=='0'){
                    hijo.at(insercion+1)='1';}
                if(hijo.at(insercion+1)=='1'){
                    hijo.at(insercion+1)='0';}
            }
            //cout<<"insersado "<<hijo<<endl;
        }

    }}
    return hijo;

}

void Algoritmo::calcular_fitness(Nodo gladiador){
    int fitness =0;
    fitness = gladiador.getFuerzaTroncoInferior()*0.13+gladiador.getFuerzaTroncoSuperior()*0.13
              +gladiador.getCondicionFisica()*0.20+gladiador.getInteligenciaEmocional()*0.20+gladiador.getGeneracionesParaLaSupervivencia()*0.08
              +gladiador.getProbabilidadSupervivencia()*0.13+gladiador.getEdad()*0.13;
    gladiador.setFitness(fitness);

    vec_gladiadores.push_back(gladiador);
}






void Algoritmo::fitness_menor()
{
    for (int i = 0; i <10;i++) {
       vec_gladiadores.erase(vec_gladiadores.begin());
        }
}

void Algoritmo::fitness_mejor()
{
    for (int i = 1; i <21 ; i++) {
        vec_mejores_gladiadores.push_back(vec_gladiadores.at(vec_gladiadores.size()-i));
}
    //cout<<vec_mejores_gladiadores.size()<<" mae funciona "<<endl;
}

void Algoritmo::nuevos_hijos()
{ random_device generadorAzar;
    mt19937 aux(generadorAzar());
    uniform_int_distribution<int> uni(1,100);
    uniform_int_distribution<int> idUni(10000000,99999999);

    for (int i=0;i<10;i++) {
        int id = idUni(aux);
        int edad = uni(aux);

        int pro_sup = convertidorbin_dec(sumabin(convertidordec_bin(vec_mejores_gladiadores.at(i).getProbabilidadSupervivencia()),
                                                 convertidordec_bin(vec_mejores_gladiadores.at(10+i).getProbabilidadSupervivencia())));
        int gen_sup =convertidorbin_dec(sumabin(convertidordec_bin(vec_mejores_gladiadores.at(i).getGeneracionesParaLaSupervivencia() ),
                                                convertidordec_bin(vec_mejores_gladiadores.at(i+10).getGeneracionesParaLaSupervivencia())));
        int int_emo =convertidorbin_dec(sumabin(convertidordec_bin(vec_mejores_gladiadores.at(i).getInteligenciaEmocional() ),
                                                convertidordec_bin(vec_mejores_gladiadores.at(i+10).getInteligenciaEmocional())));
        int fuerza_inf =convertidorbin_dec(sumabin(convertidordec_bin(vec_mejores_gladiadores.at(i).getFuerzaTroncoInferior() ),
                                                   convertidordec_bin(vec_mejores_gladiadores.at(i+10).getFuerzaTroncoInferior())));
        int fuerza_sup =convertidorbin_dec(sumabin(convertidordec_bin(vec_mejores_gladiadores.at(i).getFuerzaTroncoSuperior()),
                                                   convertidordec_bin(vec_mejores_gladiadores.at(i+10).getFuerzaTroncoSuperior())));
        Nodo *hijo = new Nodo(id,edad,pro_sup,gen_sup,int_emo,5,fuerza_inf,fuerza_sup);
        hijo->setFitness(cal_fitness_hijos(*hijo));
        vec_gladiadores.push_back(*hijo);
    }
}

int Algoritmo::cal_fitness_hijos(Nodo hijo)
{   int fitness=0;
    fitness = hijo.getFuerzaTroncoInferior()*0.13+hijo.getFuerzaTroncoSuperior()*0.13
              +hijo.getCondicionFisica()*0.20+hijo.getInteligenciaEmocional()*0.20+hijo.getGeneracionesParaLaSupervivencia()*0.08
              +hijo.getProbabilidadSupervivencia()*0.13+hijo.getEdad()*0.13;
    //cout<<fitness<< " fitnes hijos"<<endl;
    if (fitness<=100){
    return fitness;} else{
        while (fitness>100){
            fitness=fitness/10;
        }
        return fitness;
    }
}




Nodo* Algoritmo::mejor_jugador()
{
    Nodo *mejorJugador = &vec_gladiadores.back();
    mejorJugador->setResistencia(calcularResistencia(mejorJugador));
    //cout<<mejorJugador->getResistencia()<<" esta es la resistencia del mejor mae"<<endl;
    return mejorJugador;
}


double Algoritmo::pro_fitness()
{
    double promedio=0;
    for (int i=0;i<vec_gladiadores.size();i++) {
        //cout<<"fitness de todos "<<vec_gladiadores.at(i).getFitness()<<endl;
        promedio+= vec_gladiadores.at(i).getFitness();
    }
    //cout <<promedio<<" sumatoria "<<endl;
    promedio = promedio/100;
    //cout <<promedio<<" El promedio es de todos "<<endl;
    return promedio;
}


void Algoritmo::rungenetico(listaEnlazada *listaGenetica) {
    vec_gladiadores.clear();
    vec_hijos.clear();
    vec_mejores_gladiadores.clear();
    vect_posiciones.clear();
    this->listaGenetica = listaGenetica;


    int contador = listaGenetica->getTamano();

    while (contador!=0) {
        calcular_fitness(*listaGenetica->recorrerLista(abs(contador-listaGenetica->getTamano())));
        contador--;
    }


    quickSort(0,vec_gladiadores.size()-1);
    for (int i = 0; i <vec_gladiadores.size() ; i++) {
            //cout<<vec_gladiadores.at(i).getFitness()<<"   ";

    }
    //cout <<"mae tengo esto al inicio "<<vec_gladiadores.size()<<endl;
    fitness_mejor();
    fitness_menor();
    nuevos_hijos();
    //cout<<vec_gladiadores.size()<< "   mae batido"<<endl;
    quickSort(0,vec_gladiadores.size()-1);
    for (int i = 0; i <vec_gladiadores.size() ; i++) {
        //cout<<vec_gladiadores.at(i).getFitness()<<"   ";

    }
    calcular_fitness(*mejor_jugador());
    //cout<<"mae tengo esto "<<mejor_jugador()->getFitness()<<endl;

    mejor_jugador();

}


    void Algoritmo::swap(Nodo* a,Nodo* b) {
        Nodo t = *a;
        *a = *b;
        *b = t;
    }


    int Algoritmo::partition(int low, int high) {
        Nodo pivot = vec_gladiadores.at(high);    // pivot
        int i = (low - 1);  // Index of smaller element

        for (int j = low;j <= high - 1; j++) {
            // If current element is smaller than or
            // equal to pivot
            if (vec_gladiadores.at(j).getFitness() <= pivot.getFitness())
            {
                i++;    // increment index of smaller element
                swap(&vec_gladiadores.at(i), &vec_gladiadores.at(j));
            }
        }
        swap(&vec_gladiadores.at(i + 1), &vec_gladiadores.at(high));
        return (i + 1);
    }

/**
 * Quick sort algorithm for sorting the pop by smallest to biggest fitness
 * @param low first element of the pop
 * @param high last element of the pop
 */
    void Algoritmo::quickSort(int low, int high) {
        if (low < high) {
            /* pi is partitioning index, arr[p] is now
               at right place */
            int pi = partition(low, high);

            // Separately sort elements before
            // partition and after partition
            quickSort(low, pi - 1);
            quickSort(pi + 1, high);
        }
    }
