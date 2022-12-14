//
// Created by Yuting Xie
// 22-12-8

#include "Scheduler.h"

namespace gogort {

Scheduler::Scheduler(std::vector<std::shared_ptr<Worker>> &workers)
    : workers_(workers) {}

bool Scheduler::AddRoutine(std::shared_ptr<Routine> routine) {
  routines_.emplace_back(std::move(routine));
  return true;
}
bool Scheduler::DoSchedule() { return DoOnce(); }

} // namespace gogort