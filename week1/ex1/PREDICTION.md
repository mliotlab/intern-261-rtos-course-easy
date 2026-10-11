# Dự đoán — Week 1 / Ex1

> **Commit file này TRƯỚC khi nạp chương trình lần đầu.** Report sẽ phải giải thích
> mọi chỗ dự đoán lệch so đo. Dự đoán sai không bị trừ điểm; dự đoán sau khi đo thì bị.

`student_id`: 2413505    Ngày/giờ commit: 21h00 ngày 11/10/2026

1. Chu kỳ LED tôi sẽ đo được sẽ khoảng: ~148 ms (`BLINK_PERIOD_MS` = 149 ms)
2. Sai số giữa chu kỳ đo được và `BLINK_PERIOD_MS`: ~1 ms. 
- Giải thích dự đoán: pdMS_TO_TICKS() chuyển thời gian sang số Tick nguyên, nên thay vì nửa chu kỳ là 74.5ms, thì giờ chỉ còn 74ms. Nên tổng lại, sai số chu kỳ sẽ lệch khoảng **0.5 * 2 = 1ms**.

- Ngoài ra, một số nguyên nhân có thể đến từ thời gian thực thi các lệnh trong Task, thời điểm Task được đánh thức và độ trễ khi lập lịch:
- Thời gian thực thi: Trước khi call API vTaskDelay(), bring-up task có gọi hàm HAL_GPIO_Toggle_Pin().
- Thời điểm Task được đánh thức: Nếu Task call API vTaskDelay() ngay giữa khúc chuyển giữa 2 tick, thì sai số có thể dao động **từ -1 đến 0 tick**. Theo cấu hình của em trong FreeRTOSConfig.h, mỗi tick tương ứng với 1ms, nên sai só sẽ dao động **từ 0 đến -1 (ms)**. Nếu lấy trung bình nhiều lần đo thì chắc sẽ khoảng là **-0.5ms.**
- Độ trễ lập lịch: Khi hết thời gian delay, Task chuyển từ Blocked sang Ready, Scheduler phải thực hiện lại việc chọn Task, dẫn đến phát sinh thêm 1 khoảng sai số nhỏ nữa.

3. Nếu để HAL timebase ở lại SysTick, điều gì sẽ xảy ra khi `vTaskDelay()` được gọi?
(chọn và giải thích: chạy bình thường / treo / tick sai nhịp / hard fault)
- vTaskDelay() chạy bình thường, nếu handler của HAL và RTOS cấu hình Systick giống nhau.
- Giải thích: vTaskDelay() dựa vào RTOS tick, tick này do xPortSysTickHandler() tăng, và nó được gọi từ SysTick_Handler trong stm32xxxx_it.c do CubeMX sinh ra. Khi đó HAL_IncTick() và xPortSysTickHandler() cùng chạy trong 1 handler nên cả 2 đều có tick giống nhau.

4. `BRINGUP_STACK_WORDS` = 112 words = 112*4 bytes = 448 bytes. Task này khả năng cao là đủ. Vì Task chỉ đơn giản là blink led, chỉ có vài lệnh, không có array lớn/ biến/ đệ quy,...nên không yêu cầu về stack cao.

5. Trước khi map handler, linker sẽ báo lỗi gì (đoạn nguyên văn thông báo):
Trích từ Terminal:
---
D:/DOCUMENT/STUDY - OTHERS/RTOS_INTERN/intern-261-rtos-course-easy/week1/ex1/app/app_main.c:31:(.text.vBringup_task+0x16): **undefined reference to `vTaskDelay'**
C:/PROGRA~2/ARMGNU~1/14EFD8~1.2RE/bin/../lib/gcc/arm-none-eabi/14.2.1/../../../../arm-none-eabi/bin/ld.exe: CMakeFiles/template.dir/D_/DOCUMENT/STUDY_-_OTHERS/RTOS_INTERN/intern-261-rtos-course-easy/week1/ex1/app/app_main.c.obj: in function `app_main':
D:/DOCUMENT/STUDY - OTHERS/RTOS_INTERN/intern-261-rtos-course-easy/week1/ex1/app/app_main.c:39:(.text.app_main+0x16): **undefined reference to `xTaskCreate'**
C:/PROGRA~2/ARMGNU~1/14EFD8~1.2RE/bin/../lib/gcc/arm-none-eabi/14.2.1/../../../../arm-none-eabi/bin/ld.exe: D:/DOCUMENT/STUDY - OTHERS/RTOS_INTERN/intern-261-rtos-course-easy/week1/ex1/app/app_main.c:48:(.text.app_main+0x30): **undefined reference to `vTaskStartScheduler'**
---

=> Linker không tìm thấy phần định nghĩa của ba hàm FreeRTOS trên trong các object file hoặc thư viện được liên kết.