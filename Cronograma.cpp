#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Materia {
    string nome;
    int horas;
};

class CronogramaEstudos {
private:
    vector<Materia> materias;

public:
    void adicionarMateria(const string& nome, int horas) {
        Materia novaMateria = { nome, horas };
        materias.push_back(novaMateria);
        cout << "Materia adicionada: " << nome << " - " << horas << " horas." << endl;
    }

    void listarMaterias() {
        cout << "\nCronograma de Estudos:\n";
        if (materias.empty()) {
            cout << "Nenhuma materia cadastrada.\n";
            return;
        }
        for (size_t i = 0; i < materias.size(); ++i) {
            cout << i + 1 << ". Materia: " << materias[i].nome << ", Horas: " << materias[i].horas << endl;
        }
    }

    void removerMateria(int indice) {
        if (indice >= 0 && indice < materias.size()) {
            cout << "Materia removida: " << materias[indice].nome << endl;
            materias.erase(materias.begin() + indice);
        } else {
            cout << "Indice invalido!\n";
        }
    }

    void editarMateria(int indice, const string& novoNome, int novasHoras) {
        if (indice >= 0 && indice < materias.size()) {
            materias[indice].nome = novoNome;
            materias[indice].horas = novasHoras;
            cout << "Materia editada com sucesso.\n";
        } else {
            cout << "Indice invalido!\n";
        }
    }
};

int main() {
    CronogramaEstudos cronograma;
    int opcao;
    string nome;
    int horas;

    do {
        cout << "\nMenu:\n";
        cout << "1. Adicionar materia\n";
        cout << "2. Listar materias\n";
        cout << "3. Remover materia\n";
        cout << "4. Editar materia\n";
        cout << "5. Sair\n";
        cout << "Escolha uma opcao: ";
        cin >> opcao;

        switch (opcao) {
            case 1:
                cout << "Digite o nome da materia: ";
                cin.ignore(); // Limpa o buffer
                getline(cin, nome);
                cout << "Digite o numero de horas de estudo: ";
                cin >> horas;
                if (horas > 0) {
                    cronograma.adicionarMateria(nome, horas);
                } else {
                    cout << "O numero de horas deve ser positivo.\n";
                }
                break;
            case 2:
                cronograma.listarMaterias();
                break;
            case 3: {
                cout << "Digite o numero da materia a ser removida: ";
                int indice;
                cin >> indice;
                cronograma.removerMateria(indice - 1);
                break;
            }
            case 4: {
                cout << "Digite o numero da materia a ser editada: ";
                int indice;
                cin >> indice;
                cout << "Digite o novo nome da materia: ";
                cin.ignore(); // Limpa o buffer
                getline(cin, nome);
                cout << "Digite o novo numero de horas de estudo: ";
                cin >> horas;
                if (horas > 0) {
                    cronograma.editarMateria(indice - 1, nome, horas);
                } else {
                    cout << "O numero de horas deve ser positivo.\n";
                }
                break;
            }
            case 5:
                cout << "Saindo do programa...\n";
                break;
            default:
                cout << "Opcao invalida. Tente novamente.\n";
        }
    } while (opcao != 5);

    return 0;
}
