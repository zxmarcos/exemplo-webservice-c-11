#include <stdexcept>
#include <string>
#include <memory>
#include <iostream>
#include <sqlite_modern_cpp.h>
#include "person.h"
#include "db.h"

namespace sql = sqlite;

namespace db
{

std::unique_ptr<sql::database> s_database;

/**
 * @brief open Abre ou cria (se não existir) um arquivo de banco de dados SQLite
 * @param name nome do arquivo
 */
void open(const std::string &name)
{
    // script de criação do banco de dados
    static auto init_script =
        R"(
            create table if not exists person (
                _id integer primary key autoincrement not null,
                age int,
                name text,
                weight real
            );
        )";

    try
    {
        std::cout << "Iniciando o banco de dados " << name << std::endl;
        s_database = std::unique_ptr<sql::database>(new sql::database(name));
        *s_database << init_script;
        std::cout << "Banco de dados iniciado com sucesso!" << std::endl;
    }
    catch (std::exception const &e)
    {
        std::cerr << e.what() << std::endl;
        exit(-1);
    }

//    auto p1 = model::person("Marcos Medeiros", 24, 80.0);
//    insert_person(p1);
}

result_t insert_person(model::person& p)
{

    try
    {
        *s_database << "insert into person (name,age,weight) values (?,?,?);"
            << p.name
            << p.age
            << p.weight;
        p.id = s_database->last_insert_rowid();
    }
    catch (const sql::sqlite_exception& e)
    {
        std::cerr << "Erro ao inserir pessoa: " << e.what() << std::endl;
        return result_t(false, e.what());
    }
    return result_t(false,"");
}


std::vector<model::person> select_people()
{
    std::vector<model::person> list;
    try
    {
        *s_database << "select _id,name,age,weight from person;" >>
            [&](long long id, std::string name, int age, double weight)
            {
                list.emplace_back(id,name,age,weight);
            };

    }
    catch (const sql::sqlite_exception& e)
    {
        std::cerr << e.what() << std::endl;
    }

    std::cout << "Selecionado " << list.size() << " pessoas do banco de dados" << std::endl;
    return list;
}

int count_people()
{
    int count = 0;
    try
    {
        *s_database << "select count(*) from person;" >> count;
    }
    catch (const sql::sqlite_exception& e) {
        std::cerr << e.what() << std::endl;
    }
    return count;
}

model::person select_person(int id)
{
    model::person p;
    try
    {
        *s_database << "select _id,name,age,weight from person where _id=?;"
            << id >>
            [&](long long id, std::string name, int age, double weight)
            {
                p.id = id;
                p.name = name;
                p.age = age;
                p.weight = weight;
            };

    }
    catch (const sql::sqlite_exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    return p;
}

}
