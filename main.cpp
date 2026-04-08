#include <iostream>
#include <vector>
#include <string>


class Item {
protected: 
    std::string titulo;
    int ano;

public:
    Item(std::string t, int a) : titulo(t), ano(a) {}
    
    virtual ~Item() {}

    virtual void exibirInfo() const {
        std::cout << "Título: " << titulo << " | Ano: " << ano << std::endl;
    }


    std::string getTitulo() const { return titulo; }
};


class Livro : public Item {
private:
    std::string autor;

public:
    Livro(std::string t, int a, std::string aut) : Item(t, a), autor(aut) {}


    void exibirInfo() const override {
        std::cout << "[Livro] Título: " << titulo << " | Autor: " << autor << " | Ano: " << ano << std::endl;
    }
};


class Usuario {
private:
    std::vector<Item*> itens;

public:
    void adicionarItem(Item* novoItem) {
        itens.push_back(novoItem);
    }

    void listarItens() const {
        std::cout << "\n--- Lista de Itens do Usuário ---" << std::endl;

        for (const auto& item : itens) {
            item->exibirInfo();
        }
    }
};


int main() {
    Livro livroStack("Dom Casmurro", 1899, "Machado de Assis");

    Livro* livroHeap = new Livro("O Hobbit", 1937, "J.R.R. Tolkien");

    Usuario usuario;

    usuario.adicionarItem(&livroStack);
    usuario.adicionarItem(livroHeap);

    usuario.listarItens();

    delete livroHeap;

    return 0;
}
