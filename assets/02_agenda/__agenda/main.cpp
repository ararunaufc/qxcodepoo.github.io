#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

//utilizar apenas vector e stringstream

//pega uma string da entrada e retorna
string readString(){
    string value;
    cin >> value;
    return value;
}

//le um float da entrada e retorna
float readFloat(){
    float value;
    cin >> value;
    return value;
}

class Contato{
private:
    string nome, email;
    vector<string> fones;
public:

    Contato(string _nome = ""){
        nome = _nome;
    }

    static bool validateFone(string fone){
        for(auto c : fone)
            if(c < '0' || c > '9')
                return false;
        return true;
    }

    static bool validateEmail(string value){
        size_t posArroba = value.find("@");
        size_t posPonto = value.find(".");
        if(posArroba == string::npos)//nao encontrou
            return false;
        if(posPonto == string::npos)
            return false;
        if(posPonto <= posArroba + 1)//ponto depois de arroba
            return false;
        if(posPonto == (value.size() - 1))//algo depois de ponto
            return false;
        return true;
    }

    string getNome() const{
        return this->nome;
    }

    bool setNome(string nome){
        if(nome == "")
            return false;
        this->nome = nome;
        return true;
    }

    string getEmail() const{
        return email;
    }

    bool setEmail(const string &value){
        if(!validateEmail(value))
            return false;
        email = value;
        return true;
    }

    bool addFone(string fone){
        //numero invalido
        if(Contato::validateFone(fone) == false)
            return false;
        //ja existe esse numero
        for(string& tel : fones)
            if(tel == fone)
                return false;
        fones.push_back(fone);
        return true;
    }

    bool rmFone(string fone){
        //procura o telefone
        for(int i = 0; i < (int) fones.size(); ++i)
            if(fones[i] == fone){
                fones.erase(fones.begin() + i);
                return true;
            }
        return false;
    }

    vector<string> getAllFones() const{
        return fones;
    }

    string toString() const{
        stringstream ss;
        ss << "Nome: " << nome << "; Email: " << email
           << "; Fones:";

        for(int i = 0; i < (int) fones.size(); i++)
            ss  << " " << fones[i] << ",";
        string saida = ss.str();
        saida.back() = ' ';//removendo ultima virgula
        return saida;
    }
    bool haveMatch(string pattern){
            string serial = this->toString();
            if(serial.find(pattern) != string::npos)
                return true;
            return false;
        }
};

class Agenda{
private:
    vector<Contato> contatos;
public:
    bool addContato(Contato cont){
        if(cont.getNome() == "")
            return false;
        for(Contato &contato : contatos)
            if(contato.getNome() == cont.getNome())
                return false;
        //adiciona no mapa
        contatos.push_back(cont);
        return true;
    }
    bool rmContato(string nome){
        for(int i = 0; i < (int) contatos.size(); ++i)
            if(contatos.at(i).getNome() == nome){
                contatos.erase(contatos.begin() + i);
                return true;
            }
        return false;
    }

    //returna endereço para o contato ou null
    Contato * getContato(string nome){
        //observe a necessidade da referencia aqui!!!!!!!!
        for(Contato &contato : contatos)
            if(contato.getNome() == nome)
                return &contato;
        return nullptr;
    }

    vector<Contato> getAllContatos(){
        return contatos;
    }

    vector<Contato> search(string pattern){
        vector<Contato> matches;
        for(auto cont : contatos)
            if(cont.haveMatch(pattern))
                matches.push_back(cont);
        return matches;
    }

    string toString(){
        stringstream ss;
        cout << "--------------AGENDA-------------" << endl;
        cout << "Foram encontrados " << contatos.size() << " contatos em sua agenda\n";
        for(Contato &contato : contatos)
            cout << contato.toString() << endl;
        return ss.str();
    }
};

class Gui{
private:
    Agenda * agenda;
public:
    Gui(Agenda * agenda){
        this->agenda = agenda;
    }

    void guiContato(Contato * contato){
        string op = "";
        while(op != "sair"){
            cout << "---------------\n";
            cout << contato->toString() << endl;
            cout << "Menu Contato\nnome _nome, email _email; add _fone, rm _fone, sair\n>> ";
            cin >> op;

            if(op == "nome"){
                string nomeAtual = contato->getNome();
                string nome = readString();
                if(nome != nomeAtual){
                    if(agenda->getContato(nome) == nullptr)//nao ha outro contato com esse nome
                        contato->setNome(nome);
                    else
                        cout << "Ja existe contato com esse nome" << endl;
                }
            }
            else if(op == "email"){
                if(!contato->setEmail(readString()))
                    cout << "Email invalido" << endl;
            }
            else if(op == "add"){
                if(!contato->addFone(readString()))
                    cout << "Telefone ja existe ou invalido" << endl;
            }
            else if(op == "rm"){
                if(!contato->rmFone(readString()))
                    cout << "Telefone nao existe" << endl;

            }
        }
    }

    void guiPrincipal(){
        string op;
        while(op != "sair"){
            cout << "---------------\n";
            cout << "Menu agenda\nshow, add, rm _nome, update _nome, search _pattern, sair\n>> ";
            cin >> op;
            if(op == "add"){
                Contato cont;
                guiContato(&cont);
                if(cont.getNome() == "")
                    cout << "Contato nao pode ser inserido sem um nome" << endl;
                else
                    agenda->addContato(cont);
            }
            else if(op == "show"){
                cout << agenda->toString() << endl;
            }
            else if(op == "update"){
                Contato * cont = agenda->getContato(readString());
                if(cont == nullptr)
                    cout << "Contato nao existe" << endl;
                else
                    guiContato(cont);
            }
            else if(op == "rm"){
                if(agenda->rmContato(readString()))
                    cout << "Sucesso\n";
                else
                    cout << "Contato nao existe" << endl;
            }
            else if(op == "search"){
                string pattern;
                cin >> pattern;

                for(auto cont : agenda->search(pattern))
                    cout << cont.toString() << endl;
            }
        }
    }
};

void inicializar(Agenda * agenda){
    Contato ze("ze");
    ze.setEmail("ze@bol.com");
    ze.addFone("1234");
    ze.addFone("4321");
    ze.addFone("5432");
    agenda->addContato(ze);

    Contato rui("rui");
    rui.setEmail("rui_da_silva@gmail.com");
    rui.addFone("2345");
    rui.addFone("5431");
    rui.addFone("1111");
    agenda->addContato(rui);

    Contato rex("rex");
    rex.setEmail("rex_da_silva@bol.com");
    rex.addFone("2222");
    rex.addFone("3111");
    agenda->addContato(rex);
}

int main()
{
    Agenda agenda;
    inicializar(&agenda);

    Gui controller(&agenda);
    controller.guiPrincipal();
    return 0;
}


