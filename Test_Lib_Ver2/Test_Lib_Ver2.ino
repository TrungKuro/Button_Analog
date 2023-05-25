/**
 * @file Test_Lib_Ver2.ino
 * @author TrungKuro
 * @brief
 * @version 0.2
 * @date 2023-05-25
 *
 * @copyright Copyright (c) 2023
 *
 * Thư viện tham khảo:
 * https://github.com/mathertel/OneButton
 * https://github.com/rlogiacco/AnalogButtons
 *
 * Module này có tất cả 4 nút nhấn, với thứ tự là [1 - 2 - 3 - 4]
 * Tương ứng tên gọi là [A - B - C - D]
 *
 * Và được cấu trúc phần cứng theo bố trí thiết kế sau:
 *    [1]     |    [A]
 * [2] - [4]  | [B] - [D]
 *    [3]     |    [C]
 *
 * Các nút nhấn này thiết kế theo dạng "Pull-Up"
 * Tức khi không nhấn nút (Release), mức tín hiệu là HIGH, ở dạng Analog là 1023 (độ phân giải 10-bit)
 * Và khi nhấn nút (Push), tín hiệu trả về cũng dạng Analog, với các mức điện áp dựa theo thiết kế điện trở
 *
 * Trong phiên bản Ver2 này, ngoài nhận diện được từng Click một, của riêng từng nút một
 * Mình muốn nhận diện được Double Click, của riêng từng nút một
 */
/* ------------------------------------------------------------------------- */
/*                                  LIBRARY                                  */
/* ------------------------------------------------------------------------- */

#include "ABtn.h"

/* ------------------------------------------------------------------------- */
/*                                   DEFINE                                  */
/* ------------------------------------------------------------------------- */

#define BUTTON_PIN A0

/* ------------------------------------------------------------------------- */
/*                                  FUNCTION                                 */
/* ------------------------------------------------------------------------- */

void btnA_Click()
{
  Serial.println("1 Click A");
}
void btnA_DoubleClick()
{
  Serial.println("2 Click A");
}

void btnB_Click()
{
  Serial.println("1 Click B");
}
void btnB_DoubleClick()
{
  Serial.println("2 Click B");
}

void btnC_Click()
{
  Serial.println("1 Click C");
}
void btnC_DoubleClick()
{
  Serial.println("2 Click C");
}

void btnD_Click()
{
  Serial.println("1 Click D");
}
void btnD_DoubleClick()
{
  Serial.println("2 Click D");
}

/* ------------------------------------------------------------------------- */
/*                                   OBJECT                                  */
/* ------------------------------------------------------------------------- */

// ABtn myBtn(BUTTON_PIN);
ABtn myBtn;

/* ------------------------------------------------------------------------- */
/*                                   CONFIG                                  */
/* ------------------------------------------------------------------------- */

void setup()
{
  Serial.begin(115200);
  Serial.println("Testing my library, ver2");

  /**
   * Tạo liên kết chức năng của nút với các hàm
   */
  myBtn.attachClickA(btnA_Click);
  myBtn.attachDoubleClickA(btnA_DoubleClick);
  //
  myBtn.attachClickB(btnB_Click);
  myBtn.attachDoubleClickB(btnB_DoubleClick);
  //
  myBtn.attachClickC(btnC_Click);
  myBtn.attachDoubleClickC(btnC_DoubleClick);
  //
  myBtn.attachClickD(btnD_Click);
  myBtn.attachDoubleClickD(btnD_DoubleClick);
}

/* ------------------------------------------------------------------------- */
/*                                    MAIN                                   */
/* ------------------------------------------------------------------------- */

void loop()
{
  // Keep watching the push button
  myBtn.tick();

  // You can implement other code in here or just wait a while
  delay(10);
}