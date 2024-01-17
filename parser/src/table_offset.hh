#pragma once
#include <cstdint>
#include <string>
#include "types.hh"
#include <unordered_map>

namespace otf{
    namespace parser{

        class file{
        public:
            file(std::string filepath);     
        private:
            std::unordered_map<tag_t, offset32_t> table_entries;
        };


        class table_entry{
        public:
        private:
            tag_t tag;
            uint32_t checksum;
            uint32_t offset;
            uint32_t length;
        };

        class table_offset{
        public:
            table_offset();
        private:
            uint32_t sfnt_version;
            uint16_t number_tables;
            uint16_t search_range;
            uint16_t entry_selector;
            uint16_t range_shiht; 
        };

    }
}
