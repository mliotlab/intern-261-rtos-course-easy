# Week 4 — Ex3: Đo & chứng minh

**Thời lượng dự kiến: 2 giờ**

## Mục tiêu
Đo **worst-case** latency ISR→xử lý, CPU load từng task, và stack
high-water-mark của toàn bộ data logger (`week4/ex2`) khi tải cao nhất —
rồi chứng minh bằng số liệu rằng hệ thống đạt `ISR_TO_PROC_DEADLINE_US`.

## Đọc trước
- *Mastering the FreeRTOS Real Time Kernel* — mục `vTaskGetRunTimeStats`,
  `uxTaskGetStackHighWaterMark` (Ch.11, Debugging).
- `week3/ex4/app/runtime_stats.c` của bạn — tái dùng nguyên cơ chế DWT.

## Việc cần làm
1. Thêm `measure_task.c` vào project `week4/ex2`: in CPU% từng task
   (`vTaskGetRunTimeStats`) và stack HWM từng task
   (`uxTaskGetStackHighWaterMark`) ra UART mỗi `STATS_WINDOW_MS`
   (dùng lại giá trị từ `week3/ex4/app/params.h` nếu còn, hoặc chọn một
   giá trị hợp lý và ghi rõ trong REPORT.md).
2. **Tạo tải cao nhất**: tăng tốc độ tạo mẫu giả hoặc thêm một task
   "nhiễu" busy-loop ở priority cao hơn `logger_task` để ép hệ thống vào
   tình huống worst-case thực sự (không đo lúc hệ thống rảnh).
3. Đo latency ISR→xử lý ở điều kiện tải cao nhất bằng logic analyzer
   (cạnh ISR → cạnh task xử lý bắt đầu xử lý, như kỹ thuật ở `week3/ex1`).
4. So sánh latency đo được (worst-case) với `ISR_TO_PROC_DEADLINE_US`.
5. Nếu KHÔNG đạt: không được sửa code để "đạt cho đẹp" — ghi nhận thật,
   phân tích nguyên nhân (priority sai? queue quá ngắn? UART chặn quá
   lâu?) trong `REPORT.md`.

## Cần nộp
- `app/measure_task.c`, `app/measure_task.h`.
- Bảng kết quả CPU%/stack HWM cho mọi task.
- Ảnh logic analyzer: latency worst-case + chú thích cạnh đo.
- `REPORT.md`, `PREDICTION.md` commit trước khi đo.

## Đạt yêu cầu khi
- Có bảng CPU%/stack HWM đọc được từ UART thật (không phải số bịa).
- Ảnh đo latency ở ĐÚNG điều kiện tải cao nhất, không phải tải rảnh.
- Kết luận đạt/không đạt deadline rõ ràng, có số liệu đi kèm.
