#ifndef LOGGER_COMPONENT_HPP
#define LOGGER_COMPONENT_HPP

#include <memory>
#include <string>
#include <vector>
#include <spdlog/spdlog.h>
#include <spdlog/sinks/stdout_color_sinks.h>
#include <spdlog/sinks/basic_file_sink.h>

class LoggerComponent {
  public:
    LoggerComponent(const std::string &logger_name, const std::vector<spdlog::sink_ptr> &sinks);
    LoggerComponent();

    void set_logging(bool enable, const std::string &logger_name, const std::vector<spdlog::sink_ptr> &sinks);

    std::shared_ptr<spdlog::logger> get_logger() const;
    bool logging_enabled;

  private:
    std::shared_ptr<spdlog::logger> logger;
};

#endif // LOGGER_COMPONENT_HPP
