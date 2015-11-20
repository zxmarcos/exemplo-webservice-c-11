#ifndef PERSON_H
#define PERSON_H

#include <string>
#include <vector>
#include <json.h>
#include <vector>
#include <sstream>
#include "cereal/cereal.hpp"
#define CEREAL_XML_STRING_VALUE "pessoas_srv"
#include "cereal/archives/xml.hpp"
#include "cereal/archives/json.hpp"
#include "cereal/types/vector.hpp"

namespace model
{

struct person
{
    int id;
    std::string name;
    int age;
    double weight;

    person() : id(-1), age(0), weight(0.0)
    {
    }

    person(const std::string &name, int age, double weight) :
        id(-1), name(name), age(age), weight(weight)
    {
    }

    person(int id, const std::string &name, int age, double weight) :
        id(id), name(name), age(age), weight(weight)
    {
    }

    template<class Archive>
    void serialize(Archive & archive)
    {
        archive(cereal::make_nvp("id", id),
                cereal::make_nvp("nome", name),
                cereal::make_nvp("idade", age),
                cereal::make_nvp("peso", weight));
    }
};

inline std::string to_json(const person &p)
{
    std::stringstream stream;
    {
        cereal::JSONOutputArchive out(stream);
        out(cereal::make_nvp("pessoa", p));
    }
    return stream.str();
}

inline std::string to_xml(const person &p)
{
    std::stringstream stream;
    {
        cereal::XMLOutputArchive out(stream);
        out(cereal::make_nvp("pessoa", p));
    }
    return stream.str();
}

inline std::string to_json(std::vector<person> &&p)
{
    std::stringstream stream;
    {
        cereal::JSONOutputArchive out(stream);
        out(cereal::make_nvp("pessoas", p));
    }
    return stream.str();
}


inline std::string to_xml(std::vector<person> &&p)
{
    std::stringstream stream;
    {
        cereal::XMLOutputArchive out(stream);
        out.setNextName("pessoas");
        out.startNode();
        for (auto &x : p)
        {
            out(cereal::make_nvp("pessoa", x));
        }
        out.finishNode();
    }
    return stream.str();
}


}


#endif // PERSON_H

