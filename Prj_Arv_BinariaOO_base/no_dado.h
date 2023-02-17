//no_dado.h

class NoArv{
	public:
		int info;
		NoArv* dir;
		NoArv* esq; 
	public:
		NoArv(); //construtor
		NoArv(int i, NoArv* abb);
			
};
