
#pragma once
#include "../tags.hh"
#include "../utils.hh"

/* Флаги шрифта
Бит 0: Базовая линия для шрифта при y=0.
Бит 1: Левая боковая точка при x= 0
Бит 2: Инструкции могут зависеть от размера точки.
Бит 3: Принудительно присваивает ppem целочисленные значения для всей внутренней математики масштабирования; может использовать дробные размеры ppem, если этот бит понятен. Настоятельно рекомендуется задать это значение шрифтами с подсказками.
Бит 4: Инструкции могут изменять предварительную ширину (предварительная ширина может не масштабироваться линейно).
Бит 11: Данные шрифта “без потерь” в результате того, что они были подвергнуты оптимизирующему преобразованию и/или сжатию (например, механизмам сжатия, определенным ISO/IEC 14496-18, MicroType Express, WOFF 2.0 или аналогичным), при которых функциональность исходного шрифта сохраняется, но двоичная совместимость между вводимыми и вывод файлов шрифтов не гарантируется. В результате примененного преобразования таблица DSIG также может быть признана недействительной.
Бит 12: Преобразован шрифт (для получения совместимых показателей).
Бит 13: Шрифт, оптимизированный для ClearType™. Обратите внимание, шрифты, которые для рендеринга используют встроенные растровые изображения (EBDT), не следует считать оптимизированными для ClearType, и поэтому этот бит следует оставить очищенным.
Бит 14: Шрифт последней инстанции. Если задано, указывает, что глифы, закодированные во вложенных таблицах 'cmap', являются просто общими символическими представлениями диапазонов кодовых точек и на самом деле не представляют поддержку этих кодовых точек. Если значение не задано, означает, что глифы, закодированные во вложенных таблицах 'cmap', представляют надлежащую поддержку этих кодовых точек.
*/

namespace otf{
  namespace parser{
    namespace tables{
      namespace head{
        enum class style_flags_bits : uint16_t {
          bold      = 1 << 0,
          italic    = 1 << 1,
          underline = 1 << 2,
          outline   = 1 << 3,
          shadow    = 1 << 4,
          condensed = 1 << 5,
          extended  = 1 << 6
        };
        using style_flags = flags<style_flags_bits>;

        enum class font_flags_bits : uint16_t {
          zero_y_base_line                     = 1 << 0,
          zero_x_left_side_point               = 1 << 1,
          instruction_depends_on_point_size    = 1 << 2,
          use_integer_scaling                  = 1 << 3,
          instructions_may_alter_advance_width = 1 << 4,
          may_compressed                       = 1 << 11,
          converted                            = 1 << 12,
          optimized_for_cleartype              = 1 << 13,
          last_resort                          = 1 << 14

        };
        using font_flags = flags<font_flags_bits>;
      }
      struct head{
        struct head_{
          uint16_t version_major;
          uint16_t version_minor;
          fixed_t font_revision;
          uint32_t checksum_adjustment;
          uint32_t magic_number;
          uint16_t flags;
          uint16_t units_per_em;
          long_data_time_t created;
          long_data_time_t modified;
          int16_t xMin;
          int16_t yMin;
          int16_t xMax;
          int16_t yMax;
          uint16_t mac_style;
          uint16_t lowest_per_PREM;
          int16_t font_direction_hint;
          int16_t index_to_loc_format;
          int16_t glyph_data_format;
        };

        head(char *read_buffer){
          table_data = reinterpret_cast<head_ *>(read_buffer);
          size_t offset = 0;
          swap_bytes(table_data->version_major);
          swap_bytes(table_data->version_minor);
          swap_bytes(table_data->font_revision);
          swap_bytes(table_data->checksum_adjustment);
          swap_bytes(table_data->magic_number);
          swap_bytes(table_data->flags);
          swap_bytes(table_data->units_per_em);
          swap_bytes(table_data->created);
          swap_bytes(table_data->modified);
          swap_bytes(table_data->xMin);
          swap_bytes(table_data->yMin);
          swap_bytes(table_data->xMax);
          swap_bytes(table_data->yMax);
          swap_bytes(table_data->mac_style);
          swap_bytes(table_data->lowest_per_PREM);
          swap_bytes(table_data->font_direction_hint);
          swap_bytes(table_data->index_to_loc_format);
          swap_bytes(table_data->glyph_data_format);
        };

        const head_& get_data() const noexcept {
          return *table_data;
        }

      private:
        head_* table_data;
      };
    }
  }
}