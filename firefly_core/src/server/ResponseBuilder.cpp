// Copyright 2017 <Célian Garcia>

#include "firefly/core/server/ResponseBuilder.hpp"

namespace firefly {
    void ResponseBuilder::build(nlohmann::json json_content, std::shared_ptr<HttpResponse> response) {
        ResponseBuilder::build(json_content.dump(), response);
    }

    void ResponseBuilder::build(std::string raw_content, std::shared_ptr<HttpResponse> response) {
        *response << "HTTP/1.1 200 \r\n";
        *response << "Content-Type: application/json\r\n";
        *response << "Content-Length: " << raw_content.length() << "\r\n\r\n";
        *response << raw_content;
    }
}
