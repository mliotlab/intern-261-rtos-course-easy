# Week 1 — Ex1: Bring-up kernel bằng tay

**Thời lượng dự kiến: 3 giờ**

## Mục tiêu
Tự tay đưa FreeRTOS vào `template/` và chạy được task đầu tiên, không dùng
middleware FREERTOS của CubeMX. Hiểu **chính xác** ba handler nào kernel cần
chiếm và **tại sao** HAL timebase phải rời khỏi SysTick.

## Đọc trước
- *Mastering the FreeRTOS Real Time Kernel* — Ch.1 (Overview), Ch.3 (Task Management, mục 3.1–3.5)
- PM0056 (Cortex-M3 Programming Manual) — mục 4.4 System Control Block, 4.5 SysTick
- RM0008 — mục 10.1.2 Interrupt and exception vectors

## Việc cần làm
1. Thêm `third_party/FreeRTOS-Kernel` vào include path + source: port `GCC/ARM_CM3`, `heap_4.c`.
2. Đổi HAL timebase sang **TIM4** (CubeMX: System Core → SYS → Timebase Source = TIM4).
3. Map ba handler cho kernel. **Không** để `stm32f1xx_it.c` và port của FreeRTOS
   cùng định nghĩa một handler — chương trình sẽ không link được, và báo lỗi đó
   chính là bài học.
4. Đặt `NVIC_PRIORITYGROUP_4` trong `HAL_Init()`.
5. Tạo một task duy nhất, toggle `PA<BLINK_GPIO_PIN>` với chu kỳ `BLINK_PERIOD_MS`,
   stack `BRINGUP_STACK_WORDS` words. Dùng `vTaskDelay`.
6. Đo chu kỳ thực tế bằng logic analyzer.

## Cần nộp
- `app/app_main.c`, `app/FreeRTOSConfig.deltas` (đã điền).
- Ảnh chụp PulseView: >= 10 chu kỳ liên tiếp, có đọc được giá trị chu kỳ đo được.
- `REPORT.md` có: chu kỳ đo được (min/max/trung bình), sai số so với `BLINK_PERIOD_MS`,
  và **log lỗi link** bạn gặp ở bước 3 kèm cách sửa.
- `PREDICTION.md` **commit trước khi nạp chương trình**.

## Đạt yêu cầu khi
- `./tools/check_api.sh` trả về 0.
- Chu kỳ đo được lệch không quá 1 tick so với `BLINK_PERIOD_MS`.
- Giải thích đúng **tại sao** HAL timebase không thể ở lại SysTick (phải nói đến
  quan hệ giữa `configKERNEL_INTERRUPT_PRIORITY`, `HAL_IncTick()` và `vTaskDelay`),
  và nói đúng được ba handler là gì, mỗi handler làm gì.
- Nói đúng được `BRINGUP_STACK_WORDS` words bằng bao nhiêu **byte** trên Cortex-M3.
