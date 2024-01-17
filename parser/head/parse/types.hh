/**
 * @file types.hh
 * @author shagunov evgenii (shagunov2012.bob@gmail.com)
 * @brief Файл для типов, определённых в спецификации Microsoft
 * @version 0.1
 * @date 2024-01-17
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#pragma once
#include <cinttypes>

namespace otf{
    namespace parser {
        using offset32_t = uint32_t;
        using offset16_t = uint16_t;
        using tag_t = uint32_t;
        using fixed_t = uint32_t;
        /// @brief количество секунд после 12:00 полуночи, 1 Января, 1904 года, UTC.
        using long_data_time_t = uint64_t;
    }




}
