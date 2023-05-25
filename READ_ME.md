# Button Analog

> Module có thiết kế gồm 4 nút nhấn: **[ A - B - C - D ]** hoặc **[ 1 - 2 - 3 - 4 ]**.
>
> Module có tất cả `3` chân kết nối, gồm: `Sig ; (+) ; (-)`.
>
> Với thiết kế dạng *"trở kéo lên (Pull-Up)"*, dùng một điện trở kéo có giá trị `1kΩ`, tức khi các nút không được nhấn, mức điện áp rơi trên chân `Sig` là **[ HIGH ]**.

## Thiết kế phần cứng (bản demo)

> Khi không nhấn bất kì nút nào, mức điện áp là **100%**. Với bo Arduino tương ứng là `1023`.
>
> Mức **(%)** điện áp của mỗi nút khi nhấn, giả định *"độ sai số"* của R là tuyệt đối, tức không có sai số.

> Đây là giá trị R của riêng từng nút nhấn:
>
> - R<sub>btn1</sub> = 1kΩ
> - R<sub>btn2</sub> = 2kΩ
> - R<sub>btn3</sub> = 3kΩ
> - R<sub>btn4</sub> = 4kΩ
>
> Khi nhấn kết hợp các nút nhấn, sẽ tạo ra dạng *"điện trở song song"*, với các giá trị sau:
>
> - R<sub>btn1+2</sub> = (1k * 2k) / (1k + 2k) = (2000/3) = 666.67Ω
> - R<sub>btn1+4</sub> = (1k * 4k) / (1k + 4k) = 800Ω
> - R<sub>btn3+2</sub> = (3k * 2k) / (3k + 2k) = 1k2Ω
> - R<sub>btn3+4</sub> = (3k * 4k) / (3k + 4k) = (12000/7) = 1k714.28Ω

---

> Kết hợp giá trị R của riêng từng nút nhấn, mình tính được mức **(%)** điện áp rơi khi nhấn các nút:
>
> - U<sub>btn1</sub> : (100 * `1k`) / (1k + `1k`) = **50%**
> - U<sub>btn2</sub> : (100 * `2k`) / (1k + `2k`) = (200/3) = **66.67%**
> - U<sub>btn3</sub> : (100 * `3k`) / (1k + `3k`) = **75%**
> - U<sub>btn4</sub> : (100 * `4k`) / (1k + `4k`) = **80%**
>
> Còn đây là mức điện áp khi nhấn tổ hợp các nút với nhau:
>
> - U<sub>btn1+2</sub> : (100 * `666.67`) / (1k + `666.67`) = **40%**
> - U<sub>btn1+4</sub> : (100 * `800`) / (1k + `800`) = (400/9) = **44.44%**
> - U<sub>btn3+2</sub> : (100 * `1k2`) / (1k + `1k2`) = (600/11) = **54.54%**
> - U<sub>btn3+4</sub> : (100 * `1k714.28`) / (1k + `1k714.28`) = (1200/19) = **63.15%**

---

> Như vậy với mức điện áp **100%** tương ứng giá trị `1023`, bảng dưới đây là các giá trị tương ứng sẽ nhận được khi thao tác các nút:
>
> - Btn<sub>1</sub> = `511.5`
> - Btn<sub>2</sub> = `682`
> - Btn<sub>3</sub> = `767.25`
> - Btn<sub>4</sub> = `818.4`
> - Btn<sub>1+2</sub> = `409.2`
> - Btn<sub>1+4</sub> = `454.67`
> - Btn<sub>3+2</sub> = `558`
> - Btn<sub>3+4</sub> = `646.1`

## Test thực tế bản phần cứng (bản demo)

> Đây là bảng khảo sát kết quả đọc Analog thực tế đo được:
>
> - Btn<sub>1</sub> = `510 ~ 511`
> - Btn<sub>2</sub> = `681 ~ 682`
> - Btn<sub>3</sub> = `767 ~ 768`
> - Btn<sub>4</sub> = `818 ~ 820`
> - Btn<sub>1+2</sub> = `407 ~ 408`
> - Btn<sub>1+4</sub> = `453 ~ 454`
> - Btn<sub>3+2</sub> = `557 ~ 558`
> - Btn<sub>3+4</sub> = `645 ~ 646`

> Dựa theo các mốc giá trị **(%)** trong dãi điện áp, mình chọn độ dung sai trong sai số là `±1%`.
>
> Bảng sau đây, là phạm vi khoảng **(%)** của từng nút nhấn tương ứng:
>
> - Btn<sub>1</sub> : `[49% ~ 51%]`
> - Btn<sub>2</sub> : `[66% ~ 68%]`
> - Btn<sub>3</sub> : `[74% ~ 76%]`
> - Btn<sub>4</sub> : `[79% ~ 81%]`
> - Btn<sub>1+2</sub> : `[39% ~ 41%]`
> - Btn<sub>1+4</sub> : `[43% ~ 45%]`
> - Btn<sub>3+2</sub> : `[54% ~ 56%]`
> - Btn<sub>3+4</sub> : `[62% ~ 64%]`

> Dựa theo bảng giá trị khoảng **(%)** của từng nút, và mức giá trị Analog `1023` ở điện áp **100%**, mình đổi ra được các giá trị sau:
>
> - Btn<sub>1</sub> : `[501 ~ 522]`
> - Btn<sub>2</sub> : `[675 ~ 696]`
> - Btn<sub>3</sub> : `[757 ~ 777]`
> - Btn<sub>4</sub> : `[808 ~ 829]`
> - Btn<sub>1+2</sub> : `[399 ~ 419]`
> - Btn<sub>1+4</sub> : `[440 ~ 460]`
> - Btn<sub>3+2</sub> : `[552 ~ 573]`
> - Btn<sub>3+4</sub> : `[634 ~ 655]`

## Xét những trường hợp còn lại (phòng Debug)

> - R<sub>btn1+3</sub> = (1k * 3k) / (1k + 3k) = 750Ω
> - R<sub>btn2+4</sub> = (2k * 4k) / (2k + 4k) = (4000/3) = 1k333.33Ω
>
> ---
>
> - U<sub>btn1+3</sub> : (100 * `750`) / (1k + `750`) = (300/7) =  **42.85%**
> - U<sub>btn2+4</sub> : (100 * `1k333.33`) / (1k + `1k333.33`) = (400/7) = **57.14%**
>
> ---
>
> - Btn<sub>1+3</sub> : `[41% ~ 43%]`
> - Btn<sub>2+4</sub> : `[56% ~ 58%]`
