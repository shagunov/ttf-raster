#pragma once
#include <cstdint>
#include <string>
#include "../types.hh"
#include "../tags.hh"
#include "../utils.hh"
#include <unordered_map>

namespace otf{
    namespace parser{

        
        class table_entry{
            struct table_entry_{
                tag_t tag;
                uint32_t checksum;
                uint32_t offset;
                uint32_t length;
            };
        public:
            table_entry(char* readded_buffer){
                data = reinterpret_cast<table_entry_ *>(readded_buffer);
                swap_bytes(data->checksum);
                swap_bytes(data->offset);
                swap_bytes(data->length);
                swap_bytes(data->tag);
            }
            void chek_checksum() const;
            uint32_t get_table_offset() const;
        private:
            table_entry_ * data;
        };

        class table_offset{
        public:
            struct table_offset_{
                uint32_t sfnt_version;
                uint16_t number_tables;
                uint16_t search_range;
                uint16_t entry_selector;
                uint16_t range_shift;
            };
            table_offset(char* readed_buffer) noexcept{
                data = reinterpret_cast<table_offset_ *>(readed_buffer);
                swap_bytes(data->sfnt_version);
                swap_bytes(data->number_tables);
                swap_bytes(data->search_range);
                swap_bytes(data->entry_selector);
                swap_bytes(data->range_shift);
            }
        private:
            table_offset_ *data;
        };
    }
}
