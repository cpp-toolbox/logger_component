# logger_component
a class that can be composed with others to add logging functionality with spdlog

## usage
If you want to add a logger to a particular subsystem, you must first make some spdlog sinks:
```cpp
  // Create console and file sinks
    auto console_sink = std::make_shared<spdlog::sinks::stdout_color_sink_mt>();
    console_sink->set_level(spdlog::level::debug);

    auto file_sink = std::make_shared<spdlog::sinks::basic_file_sink_mt>("network_logs.txt", true);
    file_sink->set_level(spdlog::level::info);

    std::vector<spdlog::sink_ptr> sinks = {console_sink, file_sink};
```
Now that you have your sinks, you can create a logger component:
```cpp
    logger_component = LoggerComponent("network", sinks);
```
Then in your logic you can do this:
```cpp
      if (logger_component.logging_enabled) {
          logger_component.get_logger()->error("An error occurred while initializing ENet.");
      }
```
