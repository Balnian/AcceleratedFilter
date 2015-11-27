#pragma once

#include <cstdint>

union Color
{
   uint32_t RGBA;
   struct
   {
      uint32_t B : 8;
      uint32_t G : 8;
      uint32_t R : 8;
      uint32_t A : 8;
   };
};