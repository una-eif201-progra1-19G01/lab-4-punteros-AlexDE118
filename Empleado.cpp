#include "Empleado.h"

//librerias para rand()
#include <stdlib.h>
#include <time.h>

/*
 * =====================================================================================
 *
 *       Filename:  Empleado.cpp
 *
 *    Description:  Implementación de la Clase Empleado
 *
 *        Created:  2019-08-22
 *
 *         Author:  Maikol Guzman Alan mikeguzman@gmail.com
 *   Organization:  Universidad Nacional de Costa Rica
 *
 * =====================================================================================
 */

Empleado::Empleado()
{
	*nombre = "NULL";
	*id = -1;
	*annosExperiencia = -1;
	*salario = -1;
	*flagRevision = false;
}

Empleado::Empleado(string *nom,int *annosExp, float *salary, bool *flagValue)
{
	*nombre = *nom;
	*id = randomizerID(); //TRABAJAR RANDOMIZER!!!
	*annosExperiencia = *annosExp;
	*salario = *salary;
	*flagRevision = flagValue;
}

string Empleado::getNombre()
{
	return *nombre;
}

int Empleado::getID()
{
	return *id;
}

int Empleado::getAnnosExperiencia()
{
	return *annosExperiencia;
}

float Empleado::getSalario()
{
	return *salario;
}

bool Empleado::getFlagRevision()
{
	return *flagRevision;
}

void Empleado::setNombre(string *nom)
{
	*nombre = *nom;
}

void Empleado::setID()
{
	*id = randomizerID();
}

void Empleado::setAnnosExperiencia(int * annosExp)
{
	annosExperiencia = annosExp;
}

void Empleado::setSalario(float * salary)
{
	salario = salary;
}

void Empleado::setFlagRevision(bool * flagRevisionValue)
{
	flagRevision = flagRevisionValue;
}

int Empleado::randomizerID()
{	
	srand(time(NULL));
	int id = rand() % IDMAX + IDMIN;

	return id;
}

float Empleado::aumentarSalario()
{
	if (*annosExperiencia > 1 && *annosExperiencia < 3)
		return *salario * 0.02;			//salario * 2%
	else
		if (*annosExperiencia >= 3)
			return *salario * 0.05;		//salario * 5%
}

void Empleado::revisionAleatoria()
{
	int revisionFinalValue = rand() % 1;
	bool *stateA = false;
	bool *stateB = true; //preguntar profe

	if (revisionFinalValue == 0)
		setFlagRevision(stateA);
	else
		setFlagRevision(stateB);
}
