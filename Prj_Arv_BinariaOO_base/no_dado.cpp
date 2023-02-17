//no_dado.cpp
#include "no_dado.h"

//contrutor
NoArv::NoArv(){
	this->dir = 0;
	this->esq = 0; 
}

NoArv::NoArv(int i, NoArv* abb){
	this->info = i;
	this->dir = abb;
	this->esq = abb;
}
