#include <algorithm>

#ifdef TEST

#include "TasksInfo.h"

#endif

class TeamTasks {
private:
    std::map<std::string, TasksInfo> tasks;
public:
    // Получить статистику по статусам задач конкретного разработчика
    const TasksInfo& GetPersonTasksInfo(const std::string& person) const {
        return tasks.at(person);
    }

    // Добавить новую задачу (в статусе NEW) для конкретного разработчитка
    void AddNewTask(const std::string& person) {
        ++tasks[person][TaskStatus::NEW];
    }

    // Обновить статусы по данному количеству задач конкретного разработчика,
    // подробности см. ниже
    std::tuple<TasksInfo, TasksInfo> PerformPersonTasks(const std::string& person, int task_count) {
        TasksInfo updated, untouched;

        auto& tasksInfo = tasks[person];
        for (int i = 0; i < static_cast<int>(TaskStatus::DONE); ++i) {
            auto status = static_cast<TaskStatus>(i);
            auto nextStatus = static_cast<TaskStatus>(i + 1);

            auto diff = std::min(task_count, tasksInfo[status]);

            if (diff > 0) {
                updated[nextStatus] = diff;
                task_count -= diff;
            }
            if ((tasksInfo[status] - diff) > 0) {
                untouched[status] = tasksInfo[status] - diff;
            }
        }

        for (int i = 0; i < static_cast<int>(TaskStatus::DONE); ++i) {
            auto status = static_cast<TaskStatus>(i);
            auto countUpdated = (updated.count(status) > 0) ? updated.at(status) : 0;
            auto countUntouched = (untouched.count(status) > 0) ? untouched.at(status) : 0;

            tasksInfo[status] = countUpdated + countUntouched;
        }
        tasksInfo[TaskStatus::DONE] += (updated.count(TaskStatus::DONE) > 0) ? updated.at(TaskStatus::DONE) : 0;

        return {updated, untouched};
    }
};
