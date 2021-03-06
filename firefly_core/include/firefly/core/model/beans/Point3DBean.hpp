// Copyright 2017 <Célian Garcia>

#pragma once

#include <vector>
#include <opencv2/opencv.hpp>

namespace firefly {

class Point3DBean {
 public:

    Point3DBean(cv::Vec3f value,
                int cloud_id, std::vector<int> operations_ids);

    Point3DBean(int id, cv::Vec3f value,
                int cloud_id, std::vector<int> operations_ids);

    int const &getId() const;

    cv::Vec3f const &getValue() const;

    int const &getTaskId() const;

    std::vector<int> const &getOperationsIds() const;

    void setValue(const cv::Vec3f &value);

    void setOperationsIds(const std::vector<int> &operations_ids);

    void setTaskId(const int &task_id);

    void addOperationId(const int &operation_id);

 private:
    int m_id = 0;
    cv::Vec3f m_value;
    int m_task_id;
    std::vector<int> m_operations_ids;
};

}  // namespace firefly

