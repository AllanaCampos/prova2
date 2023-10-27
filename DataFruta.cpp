#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Data {
	int dia, mes, ano;
	public:

	int getDia(){
		return  this->dia;
	}
	int getMes(){
		return this->mes;
	}
	int getAno(){
		return this->ano;
	}
	/*
	O m�todo abaixo retornar� -1 se d1 � anterior a d2
	Retornar� 0 se d1 = d2
	Retornar� +1 se d1 � posterior a d2
	*/	
	static int compara(Data *d1, Data *d2) { 
		if(d1->getAno() < d2->getAno()){
			return -1;
		}
		if(d1->getAno() > d2->getAno()){
			return 1;
		}
		if(d1->getAno() == d2->getAno()){
			if(d1->getMes() < d2->getMes()){
				return -1;
			}
			if(d1->getMes() > d2->getMes()){
				return 1;
			}
			if(d1->getMes() == d2->getMes()){
				if(d1->getDia() < d2->getDia()){
					return -1;
				}
				if(d1->getDia() > d2->getDia()){
					return 1;
				}
				if(d1->getDia() == d2->getDia()){
					return 0;
				}
			}
		}
		return 2;
	}
	
	Data (int _dia, int _mes, int _ano) {
		dia = _dia;
		mes = _mes;
		ano = _ano;
	}
	
	string toString() {
		string ret = "";
		ret.append(to_string(dia));
		ret.append("/");
		ret.append(to_string(mes));
		ret.append("/");
		ret.append(to_string(ano));
		return ret;
	}
};

class Lista {
	public:
	virtual void entradaDeDados() = 0;
	virtual void mostraMediana() = 0;
	virtual void mostraMenor() = 0;
	virtual void mostraMaior() = 0;
    virtual void listarEmOrdem() = 0;
    virtual void imprimeNElementos(int n) = 0;
};

class ListaNomes : public Lista{
	vector<string> lista;
	
	public:
	
	/*
	O m�todo abaixo pergunta ao usu�rios quantos
	elementos v�o existir na lista e depois
	solicita a digita��o de cada um deles
	*/	
	void entradaDeDados() override {
		int qtd;
		string valor;
		cout << "Quantos elementos existirao na lista de nomes?" << endl;
		cin >> qtd;
        cin.ignore();
		for(int i = 0; i < qtd; i++){
			cout << "Digite o nome "<< i+1 << ": " << endl;
			getline(cin >> ws, valor);
			lista.push_back(valor);
		}
	}
		
	void mostraMediana() override{
        vector <string> l = this->lista;
        ListaNomes::ordena(l);
        int pos;
        if(l.size()%2 == 0)
            pos = (l.size()/2) - 1;
        else pos = (l.size()/2);
		cout << "Mediana dos nomes: " << l[pos] << endl;
	}
	
	void mostraMenor() override{
        vector <string> l = this->lista;
        ListaNomes::ordena(l);
		cout << "Primeiro nome: " << l[0] << endl;
	}

	void mostraMaior() override{
        vector <string> l = this->lista;
        ListaNomes::ordena(l);
		cout << "Ultim nome: " << l[l.size()-1] << endl;
	}

    void listarEmOrdem() override{
        int i = 0;
        vector <string> l = this->lista;
        ListaNomes::ordena(l);
        cout << "Nomes ordenados" << endl;
        for(auto el : l){
            i++;
            cout << "Nome " << i << ": " << el << endl;
        }
    }

    void imprimeNElementos(int n) override{
		cout << "Imprimindo " << n <<" elementos da lista de nomes" << endl;
        for(int i = 0; i < n; i++){
            cout << "Nome " << i+1 << ": " << this->lista[i] << endl;
        }
    }

	static void ordena(vector<string> &l){
		string aux, s1, s2;
		for(int i = 0; i < int(l.size()); i++){
			for(int j = 0; j < int(l.size()) - i - 1; j++){
				s1 = l[j];
				s2 = l[j+1];
				if(ListaNomes::comparaString(s1, s2) == 1){
					aux = l[j];
					l[j] = l[j+1];
					l[j+1] = aux;
				}
			}
		}
	}

	static int comparaString(string s1, string s2){
		int i = 0;
		if(s1.size() < s2.size()){
			for(char c : s1){
				if(c > s2[i]){
					return 1;
				}
				if(c < s2[i]){
					return -1;
				}
				i++;
			}
			return -1;
		}
		else{
			for(char c : s2){
				if(c > s1[i]){
					return -1;
				}
				if(c < s1[i]){
					return 1;
				}
				i++;
			}
			if(s1.size() == s2.size()){
				return 0;
			}
			return 1;
		}
	}
};

class ListaDatas  : public Lista{
	vector<Data *> lista;
	
	public:
		
	/*
	O m�todo abaixo pergunta ao usu�rios quantos
	elementos v�o existir na lista e depois
	solicita a digita��o de cada um deles
	*/	
	void entradaDeDados() override{
		int qtd, dia, mes, ano;
		cout << "Quantos elementos existirao na lista de datas?" << endl;
		cin >> qtd;
		for(int i = 0; i < qtd; i++){
			cout << "Digite a data "<< i+1 << " utilizando o formato a seguir: DD MM AAAA" << endl;
			cin >> dia >> mes >> ano;
			Data * data = new Data(dia, mes, ano);
			lista.push_back(data);
		}
	}
	
	void mostraMediana() override{
        int pos;
        vector <Data *> l = this->lista;
        ListaDatas::ordena(l);
        if(l.size()%2 == 0)
            pos = (l.size()/2) - 1;
        else pos = (l.size()/2);
		cout << "Mediana das datas: " << l[pos]->toString() << endl;
	}
	
	void mostraMenor() override{
        vector <Data *> l = this->lista;
        ListaDatas::ordena(l);
		cout << "Primeira data: " << l[0]->toString() << endl;
	}

	void mostraMaior() override{
        vector <Data *> l = this->lista;
        ListaDatas::ordena(l);
		cout << "Ultima data: " << l[l.size()-1]->toString() << endl;
	}

    void listarEmOrdem() override{
        int i = 0;
        vector <Data *> l = this->lista;
        ListaDatas::ordena(l);
        cout << "Datas ordenados" << endl;
        for(auto el : l){
            i++;
            cout << "Data " << i << ": " << el->toString() << endl;
        }
    }

    void imprimeNElementos(int n) override{
		cout << "Imprimindo " << n <<" elementos da lista de datas" << endl;
        for(int i = 0; i < n; i++){
            cout << "Data " << i+1 << ": " << this->lista[i]->toString() << endl;
        }
    }

	static void ordena(vector <Data *> &l) {
		Data *aux;
		for(int i = 0; i < int(l.size()); i++){
			for(int j = 0; j < int(l.size()) - i - 1; j++){
				if(Data::compara(l[j], l[j+1]) == 1){
					aux = l[j];
					l[j] = l[j+1];
					l[j+1] = aux;
				}
			}
		}
	}
};

class ListaSalarios : public Lista {
	vector<float> lista;
	
	public:
	/*
	O m�todo abaixo pergunta ao usu�rios quantos
	elementos v�o existir na lista e depois
	solicita a digita��o de cada um deles
	*/	
	void entradaDeDados() override{
		int qtd;
		float salario;
		cout << "Quantos elementos existirao na lista de salarios?" << endl;
		cin >> qtd;
		for(int i = 0; i < qtd; i++){
			cout << "Digite o salario "<< i+1 << ": " << endl;
			cin >> salario;
			lista.push_back(salario);
		}
	}
			
	void mostraMediana() override{
        vector <float> l = this->lista;
        ListaSalarios::ordena(l);
        float resultado;
        if(l.size()%2 == 0)
            resultado = ListaSalarios::calculaMedia(l[(l.size()/2)-1], l[(l.size()/2)]);
        else resultado = l[(l.size()/2)];
		cout << "Mediana dos salarios: " << resultado << endl;
	}
	
	void mostraMenor() override{
        vector <float> l = this->lista;
        ListaSalarios::ordena(l);
		cout << "Menor salario: " << l[0] << endl;
	}

	void mostraMaior() override{
        vector <float> l = this->lista;
        ListaSalarios::ordena(l);
		cout << "Maior salario: " << l[l.size()-1] << endl;
	}

    void listarEmOrdem() override{
        int i = 0;
        vector <float> l = this->lista;
        ListaSalarios::ordena(l);
        cout << "Salarios ordenados" << endl;
        for(auto el : l){
            i++;
            cout << "Salario " << i << ": " << el << endl;
        }
    }

    void imprimeNElementos(int n) override{
		cout << "Imprimindo " << n <<" elementos da lista de salarios" << endl;
        for(int i = 0; i < n; i++){
            cout << "Salario " << i+1 << ": " << this->lista[i] << endl;
        }
    }

    static float calculaMedia(float a, float b){
        float media;
        media = (a+b)/2;
        return media;
    }

	static void ordena(vector<float> &l) {
		float aux;
		for(int i = 0; i < int(l.size()); i++){
			for(int j = 0; j < int(l.size()) - i - 1; j++){
				if(l[j] > l[j+1]){
					aux = l[j];
					l[j] = l[j+1];
					l[j+1] = aux;
				}
			}
		}
	}
};

class ListaIdades : public Lista {
	vector<int> lista;
	
	public:
		
		/*
	O m�todo abaixo pergunta ao usu�rios quantos
	elementos v�o existir na lista e depois
	solicita a digita��o de cada um deles
	*/	
	void entradaDeDados() override{
		int qtd;
		int idade;
		cout << "Quantos elementos existirao na lista de idades?" << endl;
		cin >> qtd;
		for(int i = 0; i < qtd; i++){
			cout << "Digite a idade "<< i+1 << ": " << endl;
			cin >> idade;
			lista.push_back(idade);
		}
	}
	
	void mostraMediana() override{
        float resultado;
        vector <int> l = this->lista;
        ListaIdades::ordena(l);
        if(l.size()%2 == 0)
            resultado = ListaIdades::calculaMedia(l[(l.size()/2)-1], l[(l.size()/2)]);
        else resultado = l[(l.size()/2)];
		cout << "Mediana das idades: " << resultado << endl;
	}
	
	void mostraMenor() override{
        vector <int> l = this->lista;
        ListaIdades::ordena(l);
		cout << "Menor idade: " << l[0] << endl;
	}
	void mostraMaior() override{
        vector <int> l = this->lista;
        ListaIdades::ordena(l);
		cout << "Maior idade: " << l[l.size()-1] << endl;
	}

    void listarEmOrdem() override{
        int i = 0;
        vector <int> l = this->lista;
        ListaIdades::ordena(l);
        cout << "Idades ordenadas" << endl;
        for(auto el : l){
            i++;
            cout << "Idade " << i << ": " << el << endl;
        }
    } 

    void imprimeNElementos(int n) override{
		cout << "Imprimindo " << n <<" elementos da lista de idades" << endl;
        for(int i = 0; i < n; i++){
            cout << "Idade " << i+1 << ": " << this->lista[i] << endl;
        }
    }

	static void ordena(vector<int> &l) {
		int aux;
		for(int i = 0; i < int(l.size()); i++){
			for(int j = 0; j < int(l.size()) - i - 1; j++){
				if(l[j] > l[j+1]){
					aux = l[j];
					l[j] = l[j+1];
					l[j+1] = aux;
				}
			}
		}
	}

    static float calculaMedia(int a, int b){
        float media;
        media = (a+b)/2;
        return media;
    }
};
 
int main () {
	vector<Lista*> listaDeListas;
	
	ListaNomes listaNomes;
	listaNomes.entradaDeDados();
	listaDeListas.push_back(&listaNomes);
	
	ListaDatas listaDatas;
	listaDatas.entradaDeDados();
	listaDeListas.push_back(&listaDatas);
	
	ListaSalarios listaSalarios;
	listaSalarios.entradaDeDados();
	listaDeListas.push_back(&listaSalarios);
	
	ListaIdades listaIdades;
	listaIdades.entradaDeDados();
	listaDeListas.push_back(&listaIdades);
	
	for (Lista* l : listaDeListas) {
		l->mostraMediana();
		l->mostraMenor();
		l->mostraMaior();
		l->listarEmOrdem();
		l->imprimeNElementos(2);
	}
	
}