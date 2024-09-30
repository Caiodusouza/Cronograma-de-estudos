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
        for (const auto& materia : materias) {
            cout << "Materia: " << materia.nome << ", Horas: " << materia.horas << endl;
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
        cout << "3. Sair\n";
        cout << "Escolha uma opcao: ";
        cin >> opcao;

        switch (opcao) {
            case 1:
                cout << "Digite o nome da materia: ";
                cin >> nome;
                cout << "Digite o numero de horas de estudo: ";
                cin >> horas;
                cronograma.adicionarMateria(nome, horas);
                break;
            case 2:
                cronograma.listarMaterias();
                break;
            case 3:
                cout << "Saindo do programa...\n";
                break;
            default:
                cout << "Opcao invalida. Tente novamente.\n";
        }
    } while (opcao != 3);

    return 0;
}
