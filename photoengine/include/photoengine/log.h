#pragma once

#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"

namespace PhotoEngine
{
    class Log
    {
    private:
        static std::shared_ptr<spdlog::logger> s_engine_logger;
        static std::shared_ptr<spdlog::logger> s_app_logger;
    public:
        static void init();

        static std::shared_ptr<spdlog::logger> get_engine_logger();
        static std::shared_ptr<spdlog::logger> get_app_logger();
    };
}

#define PE_ENGINE_TRACE(...)    PhotoEngine::Log::get_engine_logger()->trace(__VA_ARGS__)
#define PE_ENGINE_INFO(...)     PhotoEngine::Log::get_engine_logger()->info(__VA_ARGS__)
#define PE_ENGINE_WARN(...)     PhotoEngine::Log::get_engine_logger()->warn(__VA_ARGS__)
#define PE_ENGINE_ERROR(...)    PhotoEngine::Log::get_engine_logger()->error(__VA_ARGS__)


#define PE_APP_TRACE(...)    PhotoEngine::Log::get_app_logger()->trace(__VA_ARGS__)
#define PE_APP_INFO(...)     PhotoEngine::Log::get_app_logger()->info(__VA_ARGS__)
#define PE_APP_WARN(...)     PhotoEngine::Log::get_app_logger()->warn(__VA_ARGS__)
#define PE_APP_ERROR(...)    PhotoEngine::Log::get_app_logger()->error(__VA_ARGS__)
