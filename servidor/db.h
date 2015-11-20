#pragma once

#include <string>
#include <tuple>
#include <vector>
#include "person.h"

namespace db
{

typedef std::tuple<bool, std::string> result_t;

result_t insert_person(model::person &p);
std::vector<model::person> select_people();
model::person select_person(int id);
int count_people();

void open(const std::string &name);

}
