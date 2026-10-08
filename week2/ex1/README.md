# Week 2 — Ex1: Queue — pipeline cảm biến

**Thời lượng dự kiến: 3 giờ**

## Mục tiêu
Dựng một pipeline 3 task nối nhau bằng 2 queue, và **tính trước** kích thước
queue tối thiểu bằng toán, trước khi đo để kiểm chứng.

## Đọc trước
- *Mastering the FreeRTOS Real Time Kernel* — Ch.5 (Queue Management)

## Việc cần làm
1. Task `sensor_task`: đọc MPU6050 qua I2C1 (HAL) mỗi `SAMPLE_PERIOD_MS`, gửi
   mẫu thô vào `queue_raw` (`xQueueSend`).
2. Task `filter_task`: `xQueueReceive` từ `queue_raw`, lọc bằng trung bình trượt
   cửa sổ `FILTER_WINDOW` mẫu, gửi kết quả vào `queue_filtered`.
3. Task `uart_task`: `xQueueReceive` từ `queue_filtered`, in ra USART1 ở
   `UART_BAUD`.
4. Cả 2 queue dài `QUEUE_LENGTH` phần tử.
5. **Trước khi đo**: tính bằng tay kích thước queue tối thiểu để không mất mẫu,
   dựa trên `SAMPLE_PERIOD_MS` và thời gian xử lý ước lượng của `filter_task` /
   `uart_task` (baud `UART_BAUD`). Ghi phép tính vào `PREDICTION.md`.
6. Đo độ đầy queue theo thời gian bằng `uxQueueMessagesWaiting()` lấy mẫu định kỳ
   (ghi ra mảng RAM hoặc UART riêng), vẽ đồ thị độ đầy theo thời gian.
7. Cố tình làm `uart_task` chậm lại (ví dụ hạ `UART_BAUD` bằng tay xuống 9600
   tạm thời) để quan sát queue đầy. Ghi lại điều gì xảy ra khi `xQueueSend` gặp
   queue đầy với từng kiểu timeout (0, `portMAX_DELAY`, giá trị hữu hạn).

## Cần nộp
- `app/sensor_task.c`, `app/filter_task.c`, `app/uart_task.c`, `app/app_main.c`.
- Đồ thị độ đầy `queue_raw` và `queue_filtered` theo thời gian (2 cấu hình:
  bình thường + UART chậm).
- `REPORT.md`, `PREDICTION.md` commit trước khi nạp.

## Đạt yêu cầu khi
- Có phép tính kích thước queue tối thiểu **trước khi đo**, và số đo thực tế
  khớp (hoặc giải thích được chỗ lệch).
- Giải thích đúng hành vi `xQueueSend` khi đầy với 3 kiểu timeout khác nhau.
- Không mất mẫu ở cấu hình bình thường (đếm được bằng số thứ tự mẫu).
