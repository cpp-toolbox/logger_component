#include "logger_component.hpp"

LoggerComponent::LoggerComponent(const std::string &logger_name, const std::vector<spdlog::sink_ptr> &sinks) {
    if (!sinks.empty()) {
        // Create a logger with multiple sinks
        logger = std::make_shared<spdlog::logger>(logger_name, sinks.begin(), sinks.end());
        logger->set_level(spdlog::level::debug);
        spdlog::register_logger(logger);
        logging_enabled = true;
    } else {
        logger = nullptr;
        logging_enabled = false;
    }
}

LoggerComponent::LoggerComponent() : logger(nullptr), logging_enabled(false) {}

void LoggerComponent::set_logging(bool enable, const std::string &logger_name,
                                  const std::vector<spdlog::sink_ptr> &sinks) {
    if (enable && !logger && !sinks.empty()) {
        // Create the logger with multiple sinks
        logger = std::make_shared<spdlog::logger>(logger_name, sinks.begin(), sinks.end());
        logger->set_level(spdlog::level::debug);
        spdlog::register_logger(logger);
    }
    logging_enabled = enable;
}

std::shared_ptr<spdlog::logger> LoggerComponent::get_logger() const { return logger; }
