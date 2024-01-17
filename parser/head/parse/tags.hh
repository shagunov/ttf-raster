/**
 * @file tags.hh
 * @author shagunov evgenii (shagunov2012.bob@gmail.com)
 * @brief Файл, в котором определены числовые значения для таблиц
 * @version 0.1
 * @date 2024-01-17
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#pragma once
#include "types.hh"

namespace otf{
  namespace parser{
    /**
     * @brief Функция времени компиляции, вычисляющая значение тега по его имени
     * 
     * @param char1 Первый символ
     * @param char2 Второй символ
     * @param char3 Третий символ
     * @param char4 Четвёртый символ
     * @return Итоговое целочисленное 32-битное значение тэга
     */
    constexpr tag_t make_tag(char char1, char char2, char char3, char char4) noexcept {
      return (char1 << 0) | (char2 << 8) | (char3 << 16) | (char4 << 24);
    }

    /**
     * @brief Класс для строчного представления тэга 
     * 
     */
    struct char_tag_t{
    private:
      char name_tag[5];
    public:
      inline char_tag_t(tag_t int_tag) noexcept {
        name_tag[3] = (int_tag & 0xff000000) >> 24;
        name_tag[2] = (int_tag & 0x00ff0000) >> 16;
        name_tag[1] = (int_tag & 0x0000ff00) >> 8;
        name_tag[0] = (int_tag & 0x000000ff) >> 0;

        name_tag[4] = '\0';
      }

      inline const char* name() const noexcept {
        return name_tag;
      }
    };

    constexpr tag_t head_tag = make_tag('h', 'e', 'a', 'd');
    constexpr tag_t avar_tag = make_tag('a', 'v', 'a', 'r');
    constexpr tag_t BASE_tag = make_tag('B', 'A', 'S', 'E');
    constexpr tag_t CBDT_tag = make_tag('C', 'B', 'D', 'T');
    constexpr tag_t CBLC_tag = make_tag('C', 'B', 'L', 'C');
    constexpr tag_t CFF__tag = make_tag('C', 'F', 'F', ' ');
    constexpr tag_t CFF2_tag = make_tag('C', 'F', 'F', '2');
    constexpr tag_t cmap_tag = make_tag('c', 'm', 'a', 'p');
    constexpr tag_t COLR_tag = make_tag('C', 'O', 'L', 'R');
    constexpr tag_t CPAL_tag = make_tag('C', 'P', 'A', 'L');
    constexpr tag_t cvar_tag = make_tag('c', 'v', 'a', 'r');
    constexpr tag_t cvt__tag = make_tag('c', 'v', 't', ' ');
    constexpr tag_t DSIG_tag = make_tag('D', 'S', 'I', 'G');
    constexpr tag_t EBDT_tag = make_tag('E', 'B', 'D', 'T');
    constexpr tag_t EBLC_tag = make_tag('E', 'B', 'L', 'C');
    constexpr tag_t EBSC_tag = make_tag('E', 'B', 'S', 'C');
    constexpr tag_t fpgm_tag = make_tag('f', 'p', 'g', 'm');
    constexpr tag_t fvar_tag = make_tag('f', 'v', 'a', 'r');
    constexpr tag_t gasp_tag = make_tag('g', 'a', 's', 'p');
    constexpr tag_t CDEF_tag = make_tag('C', 'D', 'E', 'F');
    constexpr tag_t glyf_tag = make_tag('g', 'l', 'y', 'f');
    constexpr tag_t GPOS_tag = make_tag('G', 'P', 'O', 'S');
    constexpr tag_t GSUB_tag = make_tag('G', 'S', 'U', 'B');
    constexpr tag_t gvar_tag = make_tag('g', 'v', 'a', 'r');
    constexpr tag_t hdmx_tag = make_tag('h', 'd', 'm', 'x');
    constexpr tag_t hhea_tag = make_tag('h', 'h', 'e', 'a');
    constexpr tag_t hmtx_tag = make_tag('h', 'm', 't', 'x');
    constexpr tag_t HVAR_tag = make_tag('H', 'V', 'A', 'R');
    constexpr tag_t JSTF_tag = make_tag('J', 'S', 'T', 'F');
    constexpr tag_t kern_tag = make_tag('k', 'e', 'r', 'n');
    constexpr tag_t loca_tag = make_tag('l', 'o', 'c', 'a');
    constexpr tag_t LISH_tag = make_tag('L', 'I', 'S', 'H');
    constexpr tag_t MATH_tag = make_tag('M', 'A', 'T', 'H');
    constexpr tag_t maxp_tag = make_tag('m', 'a', 'x', 'p');
    constexpr tag_t MERG_tag = make_tag('M', 'E', 'R', 'G');
    constexpr tag_t meta_tag = make_tag('m', 'e', 't', 'a');
    constexpr tag_t MVAR_tag = make_tag('M', 'V', 'A', 'R');
    constexpr tag_t name_tag = make_tag('n', 'a', 'm', 'e');
    constexpr tag_t OS_2_tag = make_tag('O', 'S', '/', '2');
    constexpr tag_t PCLT_tag = make_tag('P', 'C', 'L', 'T');
    constexpr tag_t post_tag = make_tag('p', 'o', 's', 't');
    constexpr tag_t prep_tag = make_tag('p', 'r', 'e', 'p');
    constexpr tag_t sbix_tag = make_tag('s', 'b', 'i', 'x');
    constexpr tag_t STAT_tag = make_tag('S', 'T', 'A', 'T');
    constexpr tag_t SVG__tag = make_tag('S', 'V', 'G', ' ');
    constexpr tag_t VDMX_tag = make_tag('V', 'D', 'M', 'X');
    constexpr tag_t vhea_tag = make_tag('v', 'h', 'e', 'a');
    constexpr tag_t vmtx_tag = make_tag('v', 'm', 't', 'x');
    constexpr tag_t VORG_tag = make_tag('V', 'O', 'R', 'G');
    constexpr tag_t VVAR_tag = make_tag('V', 'V', 'A', 'R');
  }
}

