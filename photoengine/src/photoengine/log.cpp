#include "photoengine/log.h"

namespace PhotoEngine
{
    std::shared_ptr<spdlog::logger> Log::s_engine_logger = spdlog::stdout_color_mt("CORE");
    std::shared_ptr<spdlog::logger> Log::s_app_logger = spdlog::stdout_color_mt("APP");

    void Log::init()
    {
        spdlog::set_level(spdlog::level::trace);
        spdlog::set_pattern("%^[%T][%n]: %v%$");
    }

    std::shared_ptr<spdlog::logger> Log::get_engine_logger()
    {
        return s_engine_logger;
    }

    std::shared_ptr<spdlog::logger> Log::get_app_logger()
    {
        return s_app_logger;
    }
}