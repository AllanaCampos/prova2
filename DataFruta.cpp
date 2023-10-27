#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Data {
	int dia, mes, ano;
	public:
	
	/*
	O m�todo abaixo retornar� -1 se d1 � anterior a d2
	Retornar� 0 se d1 = d2
	Retornar� +1 se d1 � posterior a d2
	*/	
	static int compara(Data d1, Data d2) { 
		return 0;
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

class ListaNomes : public Lista {
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

class ListaDatas : public Lista {
	vector<Data> lista;
	
	public:
		
	/*
	O m�todo abaixo pergunta ao usu�rios quantos
	elementos v�o existir na lista e depois
	solicita a digita��o de cada um deles
	*/	
	void entradaDeDados() override{
		
	}
	
	void mostraMediana() override{
		cout << "Aqui vai mostrar a mediana da lista de datas" << endl;
	}
	
	void mostraMenor() override{
		cout << "Aqui vai mostrar a primeira data cronologicamente" << endl;
	}
	void mostraMaior() override{
		cout << "aqui vai mostrar a ultima data cronologicamente" << endl;
	}
    void listarEmOrdem() override{

    }
    void imprimeNElementos(int n) override{
        
    }
};

class ListaSalarios  : public Lista {
	vector<float> lista;
	
	public:
	
	/*
	O m�todo abaixo pergunta ao usu�rios quantos
	elementos v�o existir na lista e depois
	solicita a digita��o de cada um deles
	*/	
	void entradaDeDados() override{
		
	}
			
	void mostraMediana() override{
		cout << "Aqui vai mostrar a mediana da lista de salarios" << endl;
	}
	
	void mostraMenor() override{
		cout << "Aqui vai mostrar o menor dos salarios" << endl;
	}
	void mostraMaior() override{
		cout << "aqui vai mostrar o maior dos salarios" << endl;
	}
    void listarEmOrdem() override{

    }
    void imprimeNElementos(int n) override{
        
    }
};

class ListaIdades  : public Lista {
	vector<int> lista;
	
	public:
		
		/*
	O m�todo abaixo pergunta ao usu�rios quantos
	elementos v�o existir na lista e depois
	solicita a digita��o de cada um deles
	*/	
	void entradaDeDados() override{
		
	}
	
	void mostraMediana() override{
		cout << "Aqui vai mostrar a mediana da lista de idades" << endl;
	}
	
	void mostraMenor() override{
		cout << "Aqui vai mostrar a menor das idades" << endl;
	}
	void mostraMaior() override{
		cout << "aqui vai mostrar a maior das idades" << endl;
	}
    void listarEmOrdem() override{

    }
    void imprimeNElementos(int n) override{
        
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
	}
	
}