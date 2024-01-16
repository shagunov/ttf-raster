#pragma once

#include <cstddef>
namespace otf{
    namespace parser{
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

