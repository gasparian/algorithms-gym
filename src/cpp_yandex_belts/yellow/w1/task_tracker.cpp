#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>
#include <utility>
#include <string>
#include <tuple>
#include <map>

using namespace std;

// // Перечислимый тип для статуса задачи
// enum class TaskStatus {
//   NEW,          // новая
//   IN_PROGRESS,  // в разработке
//   TESTING,      // на тестировании
//   DONE          // завершена
// };

// // Объявляем тип-синоним для map<TaskStatus, int>,
// // позволяющего хранить количество задач каждого статуса
// using TasksInfo = map<TaskStatus, int>;

class TeamTasks {
public:
  // Получить статистику по статусам задач конкретного разработчика
  const TasksInfo GetPersonTasksInfo(const string& person) const {
      TasksInfo output = tasks.at(person);
      vector<TaskStatus> to_drop;
      for ( pair<TaskStatus, int> task : output ) {
          if ( !output[task.first] )
            to_drop.push_back(task.first);
      }

      for ( auto key : to_drop )
        output.erase(key);

      return output;
  }
  
  // Добавить новую задачу (в статусе NEW) для конкретного разработчитка
  void AddNewTask(const string& person) {
      tasks[person][TaskStatus::NEW]++; 
  }
  
  // Обновить статусы по данному количеству задач конкретного разработчика,
  // подробности см. ниже
  tuple<TasksInfo, TasksInfo> PerformPersonTasks(const string& person, int task_count) {
      TasksInfo person_tasks = tasks[person];
      TasksInfo updated, untouched;
      person_tasks.erase(TaskStatus::DONE);
      int total_tasks = 0;
      for ( pair<TaskStatus, int> task : person_tasks )
        total_tasks += task.second;
      task_count = min({task_count, total_tasks});

      for ( pair<TaskStatus, int> task : person_tasks ) {

        // if ( task_count <= 0 )
        //     break;

        int n = min({task.second, task_count});

        TaskStatus next_status;
        switch(task.first) {
            case TaskStatus::NEW : {
              next_status = TaskStatus::IN_PROGRESS;
              break;
            }
            case TaskStatus::IN_PROGRESS : {
              next_status = TaskStatus::TESTING;
              break;
            }
            case TaskStatus::TESTING : {
              next_status = TaskStatus::DONE;
              break;
            }
        }

        tasks[person][task.first] -= n;
        tasks[person][next_status] += n;

        untouched[task.first] = task.second - n;
        updated[next_status] += n;

        task_count = max({task_count-n, 0});

      }

      for ( pair<TaskStatus, int> task : tasks[person] ) {
          if ( !untouched[task.first] )
            untouched.erase(task.first);

          if ( !updated[task.first] )
            updated.erase(task.first);
      }

      return make_tuple(updated, untouched);
  }

private:
    map<string, TasksInfo> tasks;
};

// // Принимаем словарь по значению, чтобы иметь возможность
// // обращаться к отсутствующим ключам с помощью [] и получать 0,
// // не меняя при этом исходный словарь
// void PrintTasksInfo(TasksInfo tasks_info) {
//   cout << tasks_info[TaskStatus::NEW] << " new tasks" <<
//       ", " << tasks_info[TaskStatus::IN_PROGRESS] << " tasks in progress" <<
//       ", " << tasks_info[TaskStatus::TESTING] << " tasks are being tested" <<
//       ", " << tasks_info[TaskStatus::DONE] << " tasks are done" << endl;
// }

// int main() {
//   TeamTasks tasks;
//   tasks.AddNewTask("Ilia");
//   for (int i = 0; i < 3; ++i) {
//     tasks.AddNewTask("Ivan");
//   }
//   cout << "Ilia's tasks: ";
//   PrintTasksInfo(tasks.GetPersonTasksInfo("Ilia"));
//   cout << "Ivan's tasks: ";
//   PrintTasksInfo(tasks.GetPersonTasksInfo("Ivan"));
  
//   TasksInfo updated_tasks, untouched_tasks;
  
//   tie(updated_tasks, untouched_tasks) =
//       tasks.PerformPersonTasks("Ivan", 2);
//   cout << "Updated Ivan's tasks: ";
//   PrintTasksInfo(updated_tasks);
//   cout << "Untouched Ivan's tasks: ";
//   PrintTasksInfo(untouched_tasks);
  
//   tie(updated_tasks, untouched_tasks) =
//       tasks.PerformPersonTasks("Ivan", 2);
//   cout << "Updated Ivan's tasks: ";
//   PrintTasksInfo(updated_tasks);
//   cout << "Untouched Ivan's tasks: ";
//   PrintTasksInfo(untouched_tasks);

//   return 0;
// }

// Output: 
// Ilia's tasks: 1 new tasks, 0 tasks in progress, 0 tasks are being tested, 0 tasks are done
// Ivan's tasks: 3 new tasks, 0 tasks in progress, 0 tasks are being tested, 0 tasks are done

// Updated Ivan's tasks: 0 new tasks, 2 tasks in progress, 0 tasks are being tested, 0 tasks are done
// Untouched Ivan's tasks: 1 new tasks, 0 tasks in progress, 0 tasks are being tested, 0 tasks are done
// Updated Ivan's tasks: 0 new tasks, 1 tasks in progress, 1 tasks are being tested, 0 tasks are done
// Untouched Ivan's tasks: 0 new tasks, 1 tasks in progress, 0 tasks are being tested, 0 tasks are done
