//
// Created by Yuting Xie on 03/12/2022.
//

#include "Routine.h"
#include <glog/logging.h>

namespace gogort {
Routine::Routine(std::function<void()> func) : id_(get_next_uuid()) {
  // At generation, set this routine as not finished.
  is_finished_ = false;
  func_ = func;
}
Routine::~Routine() { // LOG(INFO) << "Routine " << id_ << " is destroyed";
}
bool Routine::Run() {
  func_();
  return true;
}

gogo_id_t Routine::get_id() const { return id_; }

} // namespace gogort