# Week 2 — Ex2: Race condition & mutex

**Thời lượng dự kiến: 3 giờ**

## Mục tiêu
Tự tay **tái hiện ổn định** lỗi lẫn lộn ký tự khi nhiều task cùng `printf` ra
UART, rồi sửa bằng 3 cách khác nhau và so sánh bằng số đo, không bằng cảm giác.

## Đọc trước
- *Mastering the FreeRTOS Real Time Kernel* — Ch.8 (Resource Management)

## Việc cần làm
1. Tạo `WRITER_COUNT` task, mỗi task cứ mỗi `WRITER_PERIOD_MS` in ra UART một
   chuỗi dài `MSG_LEN` byte có định danh riêng (vd. task id + số thứ tự), **không
   có bảo vệ gì cả** (`UART_GUARD_MODE = 0`).
2. Chạy và chụp log UART. Chỉ ra **chính xác** vị trí ký tự bị lẫn lộn giữa 2
   writer khác nhau. Đây phải là lỗi tái hiện được, không phải một lần tình cờ.
3. Sửa bằng mutex (`xSemaphoreCreateMutex` quanh đoạn in) — `UART_GUARD_MODE = 1`.
4. Sửa bằng critical section (`taskENTER_CRITICAL`/`taskEXIT_CRITICAL` quanh
   đoạn in) — `UART_GUARD_MODE = 2`. Đo thời gian task khác bị trễ do mất ngắt.
5. Sửa bằng gatekeeper task (`GATEKEEPER_PRIO`): các writer gửi message qua
   queue, chỉ gatekeeper được gọi `HAL_UART_Transmit` — `UART_GUARD_MODE = 3`.
6. So sánh 3 cách: độ trễ in (latency từ lúc writer muốn in đến lúc in xong),
   ảnh hưởng đến các task khác, và RAM dùng thêm.

## Cần nộp
- `app/writer_task.c`, `app/uart_guard.c`, `app/app_main.c`.
- Log UART bước 2 (lỗi tái hiện được, chỉ rõ vị trí lẫn).
- Bảng so sánh 3 cách (độ trễ, ảnh hưởng task khác, RAM).
- `REPORT.md`, `PREDICTION.md` commit trước khi nạp.

## Đạt yêu cầu khi
- Tái hiện lỗi **ổn định** (chạy lại nhiều lần vẫn lẫn) trước khi sửa.
- Bảng so sánh có số đo thật cho cả 3 cách, không chỉ lý thuyết.
- Giải thích đúng vì sao critical section là cách **nguy hiểm nhất** trong 3 cách
  nếu đoạn in quá dài, và nêu được hệ quả cụ thể lên hệ thống.
