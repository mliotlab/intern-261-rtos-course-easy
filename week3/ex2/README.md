# Week 3 — Ex2: Software timer & debounce

**Thời lượng dự kiến: 2 giờ**

## Mục tiêu
Chống nảy phím bằng one-shot software timer thay vì busy-wait/delay, thêm
auto-reload timer cho long-press, rồi tự tay chứng minh callback bị block sẽ
làm hỏng **mọi** timer khác trong hệ thống.

## Đọc trước
- *Mastering the FreeRTOS Real Time Kernel* — Ch.6 (Software Timers)

## Việc cần làm
1. EXTI trên nút nhấn: mỗi cạnh (kể cả cạnh nảy) gọi `xTimerResetFromISR`
   trên `debounce_timer` (one-shot, chu kỳ `DEBOUNCE_MS`).
2. Callback của `debounce_timer` chỉ chạy khi KHÔNG còn cạnh nào mới trong
   `DEBOUNCE_MS` — đó chính là lúc phím được coi là đã ổn định. Callback in ra
   UART "PRESS" và timestamp (`xTaskGetTickCount()`).
3. Thêm `longpress_timer` (auto-reload, chu kỳ `LONGPRESS_MS`): bắt đầu khi
   phím xuống (trong ISR, `xTimerStartFromISR`), dừng khi phím lên
   (`xTimerStopFromISR`). Mỗi lần callback tự chạy nghĩa là phím đang được
   giữ — in "HELD".
4. **Thử nghiệm cố ý**: cho callback của `debounce_timer` gọi `vTaskDelay(50)`
   bên trong (mô phỏng một callback "chậm"). Quan sát điều gì xảy ra với
   `longpress_timer` trong lúc đó — cả hai đều chạy trên **timer daemon
   task**, dùng chung một queue lệnh.
5. Bỏ `vTaskDelay` đó đi (callback không bao giờ được block trong bản nộp
   cuối).

## Cần nộp
- `app/debounce.c`, `app/app_main.c`.
- Ảnh logic analyzer: nảy phím thô (trước debounce) so với tín hiệu sau khi
  qua `debounce_timer` (sạch).
- Mô tả quan sát được ở bước 4 (callback chậm ảnh hưởng `longpress_timer` thế
  nào, có log timestamp).
- `REPORT.md`, `PREDICTION.md` commit trước khi nạp.

## Đạt yêu cầu khi
- Tín hiệu sau debounce không còn cạnh giả trên logic analyzer.
- Giải thích đúng **vì sao callback timer không được block**: cả hai timer
  chạy trên cùng một daemon task, một callback block sẽ trễ/mất callback của
  timer khác đang chờ trong queue lệnh của daemon.
- Long-press được phát hiện đúng ngưỡng `LONGPRESS_MS` (có số đo thời gian
  giữ thực tế, không chỉ "có nhận long-press").
