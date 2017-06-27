// Copyright 2017 <Célian Garcia>

#ifndef FIREFLY_PROCESSING_HPP
#define FIREFLY_PROCESSING_HPP

#include <string>
#include "ProcessingType.hpp"
#include "Module.hpp"

namespace firefly {
    class Task {
    public:

        enum State {
            CREATED,
            STARTED,
            PAUSED,
            FINISHED,
            ABORTED
        };

        Task() = default;

        Task(const Task&) = default;

        Task(const std::string &name, const std::string &description,
             const ProcessingType &type, const Module &module, const std::string &userName, const std::string &date);

        Task(const int &identifier, const std::string &name, const std::string &description,
             const ProcessingType &type, const Module &module, const std::string &userName, const std::string &date);

        const int &getIdentifier() const;

        const std::string &getName() const;

        const std::string &getDescription() const;

        const ProcessingType &getType() const;

        const Module &getModule() const;

        const std::string &getUserName() const;

        State getState() const;

        const std::string &getDate() const;

        void setState(State state);

        void setName(const std::string &name);

        void setIdentifier(const int &identifier);

        void setDescription(const std::string &description);

        void setType(const ProcessingType &type);

        void setModule(const Module &module);

        void setUserName(const std::string &userName);

        void setDate(const std::string &date);

    private:

        int identifier;
        std::string name;
        std::string description;
        ProcessingType type;
        Module module;
        std::string userName;
        State state = State::CREATED;
        std::string date;

    };

}
namespace nlohmann {
    template<>
    struct adl_serializer<firefly::Task> {
        static void to_json(json &j, const firefly::Task &task) {
            j = json{
                    {"id",          task.getIdentifier()},
                    {"name",        task.getName()},
                    {"description", task.getDescription()},
                    {"type",        task.getType().getId()},
                    {"module",      task.getModule().getId()},
                    {"user_name",   task.getUserName()},
                    {"date",        task.getDate()},
                    {"state",       task.getState()}
            };
        }
    };
}

#endif //FIREFLY_PROCESSING_HPP
