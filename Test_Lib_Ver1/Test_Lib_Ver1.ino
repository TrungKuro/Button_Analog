/**
 * @file Test_Lib_Ver1.ino
 * @author TrungKuro
 * @brief
 * @version 0.1
 * @date 2023-05-24
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
 * Trong phiên bản Ver1 này, mình chỉ cần nhận diện được từng Click một, của riêng từng nút một
 *
 * Ý tưởng thiết kế thư viện Ver1 là
 * Cấu trúc sử dụng code mình dựa theo thư viện "OneButton"
 * Còn phần xử lý Analog mình tham khảo theo thư viện "AnalogButtons"
 */
/* ------------------------------------------------------------------------- */
/*                                  LIBRARY                                  */
/* ------------------------------------------------------------------------- */

#include "ABtn.h"

/* ------------------------------------------------------------------------- */
/*                                   DEFINE                                  */
/* ------------------------------------------------------------------------- */

#define BUTTON_PIN A1

/* ------------------------------------------------------------------------- */
/*                                  FUNCTION                                 */
/* ------------------------------------------------------------------------- */

void btnA_Click()
{
  Serial.println("Btn A");
}

void btnB_Click()
{
  Serial.println("Btn B");
}

void btnC_Click()
{
  Serial.println("Btn C");
}

void btnD_Click()
{
  Serial.println("Btn D");
}

/* ------------------------------------------------------------------------- */
/*                                   OBJECT                                  */
/* ------------------------------------------------------------------------- */

/**
 * Ở thời điểm khởi tạo này, người dùng ko được nhấn bất kì nút nào
 * Vì chương trình tự động đo mức điện áp hiện tại
 * Tức mức HIGH, là mức Analog cao nhất
 *
 * Ý tưởng là vậy, nhưng thời điểm bản Ver1 này
 * Các giá trị Analog của các nút đều có mức giá trị cố định
 */
ABtn myBtn(BUTTON_PIN);

/* ------------------------------------------------------------------------- */
/*                                   CONFIG                                  */
/* ------------------------------------------------------------------------- */

void setup()
{
  Serial.begin(115200);
  Serial.println("Testing my library, ver1");

  /**
   * Tạo liên kết chức năng của nút với các hàm
   * Phiên bản hiện tại có tất cả 4 chức năng
   * Là xác nhận 1 Click của từng nút
   */
  myBtn.attachClickA(btnA_Click);
  myBtn.attachClickB(btnB_Click);
  myBtn.attachClickC(btnC_Click);
  myBtn.attachClickD(btnD_Click);
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