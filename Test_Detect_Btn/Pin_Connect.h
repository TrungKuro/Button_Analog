#ifndef _PIN_CONNECT_H_
#define _PIN_CONNECT_H_

/* ------------------------------------------------------------------------- */
/*                DEBUG (uncomment to open the Debug function)               */
/* ------------------------------------------------------------------------- */

#define ENABLE_DEBUG

#if defined(ENABLE_DEBUG)
#define Debug Serial
#define DEBUG_BEGIN(...) Debug.begin(__VA_ARGS__)
#define DEBUG_WRITE(...) Debug.write(__VA_ARGS__)
#define DEBUG_PRINT(...) Debug.print(__VA_ARGS__)
#define DEBUG_PRINTLN(...) Debug.println(__VA_ARGS__)
#else
#define DEBUG_BEGIN(...)
#define DEBUG_WRITE(...)
#define DEBUG_PRINT(...)
#define DEBUG_PRINTLN(...)
#endif

/* ------------------------------------------------------------------------- */
/*                                   BUTTON                                  */
/* ------------------------------------------------------------------------- */

#define PIN_BTN A0

/* ------------------------------- Nhấn 1 nút ------------------------------ */

#define BTN_1_MIN 501
#define BTN_1_MAX 522

#define BTN_2_MIN 675
#define BTN_2_MAX 696

#define BTN_3_MIN 757
#define BTN_3_MAX 777

#define BTN_4_MIN 808
#define BTN_4_MAX 829

/* --------------------------- Nhấn kết hợp 2 nút -------------------------- */

#define BTN_12_MIN 399
#define BTN_12_MAX 419

#define BTN_14_MIN 440
#define BTN_14_MAX 460

#define BTN_32_MIN 552
#define BTN_32_MAX 573

#define BTN_34_MIN 634
#define BTN_34_MAX 655

/* -------------------------- Phạm vi giá trị (%) -------------------------- */

/**
 * Giá trị (%) của điện áp nút nhấn dao động trong khoảng từ [39% - 81%]
 * Tức giá trị MIN là của BTN_12_MIN
 * Và giá trị MAX là của BTN_4_MAX
 */

#define BTN_MIN BTN_12_MIN
#define BTN_MAX BTN_4_MAX

/* ------------------------- Danh mục các nút nhấn ------------------------- */

#define NONE_BTN 0

#define BTN_1 1
#define BTN_2 2
#define BTN_3 3
#define BTN_4 4

#define BTN_12 12
#define BTN_14 14
#define BTN_32 32
#define BTN_34 34

/* ------------------------------------------------------------------------- */

#define DEBOUNCE 10 // Unit (ms)

#define TIME_CHECK_BTN 10 // Unit (ms)

/* ------------------------------------------------------------------------- */

#endif
