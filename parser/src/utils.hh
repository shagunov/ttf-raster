/**
 * @file utils.hh
 * @author shagunov evgenii (shagunov2012.bob@gmail.com)
 * @brief В файле написаны утилиты, используемые для парсера шрифтов
 * @version 0.1
 * @date 2024-01-17
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#pragma once
#include <cstddef>

namespace otf{
    namespace parser{
        /**
         * @brief Функция для чтения переменных с обратным поряком байтов
         * 
         * @tparam T 
         * @param source Откуда
         * @param target Куда
         * @param in_out_offset Смещение от начала копируемого места, изменяется на величину sizeof(T) 
         */
        template <typename T>
        void read_be(char* source, T* target, size_t& in_out_offset){
            char* dest = reinterpret_cast<char*>(target);
            const size_t size = sizeof(T);
            constexpr size_t last = size - 1;
            for(int i = 0; i < T; i++)
            {
                dest[i] = source[last + offset - i];
            }
            offset += sizeof(T);
        }
    }
}

