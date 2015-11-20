#include <iostream>
#include <crow.h>
#include <cppfmt/format.h>
#include <algorithm>
#include "db.h"

using namespace std;

int main()
{
    crow::SimpleApp app;
    db::open("pessoas.db");

    CROW_ROUTE(app, "/pessoas/total")([]()
    {
        return fmt::sprintf("Total de pessoas %d", db::count_people());
    });
    CROW_ROUTE(app, "/pessoas/json")([]()
    {
        return model::to_json(db::select_people());
    });
    CROW_ROUTE(app, "/pessoas/xml")([]()
    {
        return model::to_xml(db::select_people());
    });
    CROW_ROUTE(app, "/pessoas/<int>/json")([](int id)
    {
        auto p = db::select_person(id);
        return model::to_json(p);
    });
    CROW_ROUTE(app, "/pessoas/<int>/xml")([](int id)
    {
        auto p = db::select_person(id);
        return model::to_xml(p);
    });
    CROW_ROUTE(app, "/pessoa/inserir/json")
        .methods("POST"_method)([](const crow::request& req)
    {
        auto var = crow::json::load(req.body);
        if (!var)
            return crow::response(400);

        model::person p(var["nome"].s(), var["idade"].i(), var["peso"].d());
        db::insert_person(p);
        return crow::response{"Ok"};
    });

    app.port(18080).multithreaded().run();
}

