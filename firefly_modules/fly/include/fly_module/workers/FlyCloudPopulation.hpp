// Copyright 2017 <Célian Garcia>

#pragma once

#include <vector>
#include <thread>
#include <string>

#include <fly/CloudFiller.hpp>

#include <firefly/core/data/Operation.hpp>

#include <firefly/core/model/DatabaseManager.hpp>
#include <firefly/core/model/beans/Point3DBean.hpp>
#include <firefly/core/model/TaskModel.hpp>
#include <firefly/core/model/OperationModel.hpp>

#include <firefly/core/exception/FireflyException.hpp>
#include <firefly/core/utils/ThreadPool.hpp>
#include <firefly/core/utils/ConcurrentOperationQueue.hpp>

namespace firefly {
namespace fly_module {

class FlyCloudPopulation {
 public:
    static int start(int task_id, ThreadPool *pool, ProcessingType type);

    static void stop();

 private:
    static const char *DATABASE_NAME;

    static void run_compute_thread(ConcurrentOperationQueue *queue, ProcessingType type);

    static void run_populate_thread(int cloud_id, ConcurrentOperationQueue *queue);
};

}  // namespace fly_module
}  // namespace firefly

