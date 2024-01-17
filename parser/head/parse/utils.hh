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
#include <type_traits>
#include <concepts>
    

namespace otf{
    namespace parser{
        /**
         * @brief Функция для чтения переменных с обратным поряком байтов
         * 
         * @tparam T Тип должен быты фундаментальным
         * @param target Переменная, в которой изменяется порядок байт
         */
        template <typename T>
        requires std::is_fundamental_v<T>
        void swap_bytes(T& target) noexcept{
            T&& tmp = std::move(target);
            char* const src = reinterpret_cast<char* const>(tmp);
            char* const dst = reinterpret_cast<char* const>(target);
            for(int i = 0; i < sizeof(T); i++){
                dst[i] = src[sizeof(T) - 1 - i];
            }
        }

        template<typename T>
        concept enumerator = std::is_enum_v<T>;

        template<enumerator flags_bits_type, std::integral mask_type = std::underlying_type_t<flags_bits_type>>
        class flags{
        public:
            flags(storage_type value) : storage(value) {}
            flags(bit_type bit) : storage(value)       {}

            bool mask(storage_type value)                const noexcept;
            bool set_flag(bit_type value)    const noexcept;
            bool is_set_flag(bit_type value) const noexcept;

            flags operator|(storage_type value) const noexcept;
            flags operator|(bit_type bit)       const noexcept;
            flags operator^(storage_type value) const noexcept;
            flags operator^(bit_type bit)       const noexcept;
            flags operator&(storage_type value) const noexcept;
            flags operator&(bit_type bit)       const noexcept;

            flags operator|=(storage_type value) noexcept;
            flags operator|=(bit_type bit)       noexcept;
            flags operator^=(storage_type value) noexcept;
            flags operator^=(bit_type bit)       noexcept;
            flags operator&=(storage_type value) noexcept;
            flags operator&=(bit_type bit)       noexcept;            
        private:
            using bit_type = flags_bits_type;
            using storage_type = std::underlying_type_t<flags_bits_type>;
            storage_type storage;
        };
    }
}

