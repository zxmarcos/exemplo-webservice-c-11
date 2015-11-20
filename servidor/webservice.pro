TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    cppfmt/format.cpp \
    sqlite/sqlite3.c \
    db.cpp

HEADERS += \
    cppfmt/format.h \
    crow/ci_map.h \
    crow/common.h \
    crow/crow.h \
    crow/dumb_timer_queue.h \
    crow/http_connection.h \
    crow/http_parser_merged.h \
    crow/http_request.h \
    crow/http_response.h \
    crow/http_server.h \
    crow/json.h \
    crow/logging.h \
    crow/middleware.h \
    crow/middleware_context.h \
    crow/mustache.h \
    crow/parser.h \
    crow/query_string.h \
    crow/routing.h \
    crow/settings.h \
    crow/socket_adaptors.h \
    crow/utility.h \
    sqlite/sqlite3.h \
    sqlite_modern_cpp.h \
    person.h \
    db.h \
    cereal/access.hpp \
    cereal/cereal.hpp \
    cereal/macros.hpp \
    cereal/archives/json.hpp \
    cereal/archives/xml.hpp \
    cereal/archives/adapters.hpp \
    cereal/archives/binary.hpp \
    cereal/archives/portable_binary.hpp \
    cereal/details/helpers.hpp \
    cereal/details/polymorphic_impl.hpp \
    cereal/details/static_object.hpp \
    cereal/details/traits.hpp \
    cereal/details/util.hpp \
    cereal/external/rapidjson/internal/pow10.h \
    cereal/external/rapidjson/internal/stack.h \
    cereal/external/rapidjson/internal/strfunc.h \
    cereal/external/rapidjson/document.h \
    cereal/external/rapidjson/filestream.h \
    cereal/external/rapidjson/genericstream.h \
    cereal/external/rapidjson/prettywriter.h \
    cereal/external/rapidjson/rapidjson.h \
    cereal/external/rapidjson/reader.h \
    cereal/external/rapidjson/stringbuffer.h \
    cereal/external/rapidjson/writer.h \
    cereal/external/rapidxml/rapidxml.hpp \
    cereal/external/rapidxml/rapidxml_iterators.hpp \
    cereal/external/rapidxml/rapidxml_print.hpp \
    cereal/external/rapidxml/rapidxml_utils.hpp \
    cereal/external/base64.hpp \
    cereal/types/array.hpp \
    cereal/types/base_class.hpp \
    cereal/types/bitset.hpp \
    cereal/types/boost_variant.hpp \
    cereal/types/chrono.hpp \
    cereal/types/common.hpp \
    cereal/types/complex.hpp \
    cereal/types/deque.hpp \
    cereal/types/forward_list.hpp \
    cereal/types/list.hpp \
    cereal/types/map.hpp \
    cereal/types/memory.hpp \
    cereal/types/polymorphic.hpp \
    cereal/types/queue.hpp \
    cereal/types/set.hpp \
    cereal/types/stack.hpp \
    cereal/types/string.hpp \
    cereal/types/tuple.hpp \
    cereal/types/unordered_map.hpp \
    cereal/types/unordered_set.hpp \
    cereal/types/utility.hpp \
    cereal/types/valarray.hpp \
    cereal/types/vector.hpp

INCLUDEPATH += crow format sqlite
INCLUDEPATH += C:\boost\boost_1_58_0
LIBPATH += C:\boost\boost_1_58_0\stage\lib
LIBS += -lboost_system-mgw48-mt-1_58 \
    -lws2_32 \
    -lwsock32

QMAKE_CXXFLAGS += -Wno-unused-parameter
