//
// Created by Yuting Xie on 27/12/2022.
//

#include "DummyTask3.h"
#include "../gogoRT/Comm/CommBuffer.h"
#include "../gogoRT/Invoker.h"
#include "glog/logging.h"

namespace task {

DummyTask3::DummyTask3(const std::string task_name)
    : Task<DummyMessage, DummyMessage2>(task_name), count(0) {
  for (int i = 0; i < M_SIZE; ++i) {
    vec[i] = i;
  }
}

bool DummyTask3::Deal(const std::shared_ptr<DummyMessage> in_msg1,
                      const std::shared_ptr<DummyMessage2> in_msg2) {
  // DummyTask3 simply do matmul
  LOG(INFO) << "DummyTask3::Deal() starts";

  float res[M_SIZE];
  for (int i = 0; i < M_SIZE; ++i) {
    res[i] = 0;
    for (int j = 0; j < M_SIZE; ++j) {
      res[i] += in_msg1->matrix[i][j] * vec[j];
    }
    res[i] += in_msg2->bias[i];
  }

  for (int i = 0; i < M_SIZE; ++i) {
    vec[i] = res[i];
  }

  LOG(INFO) << "DummyTask3::Deal() ends, total count: " << ++count << "\n";
  return true;
}

std::shared_ptr<gogort::InvokerBase> DummyTask3::get_invoker() {
  auto comm_buffer = gogort::CommBuffer::Instance();
  // Todo(yuting): read frequency_ms from config
  return std::make_shared<gogort::Invoker<DummyMessage, DummyMessage2>>(
      static_cast<std::shared_ptr<Task<DummyMessage, DummyMessage2>>>(this),
      gogort::AcquireReader<DummyMessage>("dummy_pipe_1"),
      gogort::AcquireReader<DummyMessage2>("dummy_pipe_2"));
}

} // namespace task