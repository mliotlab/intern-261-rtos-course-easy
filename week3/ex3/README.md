# Week 3 — Ex3: UART RX → stream buffer → parser

**Thời lượng dự kiến: 3 giờ**

## Mục tiêu
Đẩy byte từ ngắt UART RX vào stream buffer đúng cách, viết parser đổi
chu kỳ/priority/suspend một task khác tại runtime, và chứng minh bằng số đo là
không mất byte ở baud của chính bạn.

## Đọc trước
- *Mastering the FreeRTOS Real Time Kernel* — chương Stream Buffers

## Việc cần làm
1. Bật ngắt RX USART1 (`HAL_UART_Receive_IT`, 1 byte/lần, gọi lại trong
   callback để nhận byte tiếp theo). Trong `HAL_UART_RxCpltCallback`, đẩy byte
   vào `rx_stream` bằng `xStreamBufferSendFromISR`.
2. `parser_task`: `xStreamBufferReceive` (không timeout, chờ vô hạn), tích luỹ
   đến khi gặp `\r`, tối đa `MAX_CMD_LEN` byte/lệnh.
3. Hỗ trợ tối thiểu 3 lệnh text: `Pxx\r` (đổi chu kỳ `demo_task` thành xx ms,
   dùng `vTaskDelay` mới ngay vòng lặp kế), `Sxx\r` (đổi priority `demo_task`
   bằng `vTaskPrioritySet`), `Tx\r` (x=0 → `vTaskSuspend(demo_task)`, x=1 →
   `vTaskResume(demo_task)`).
4. `demo_task`: toggle 1 chân GPIO mỗi chu kỳ hiện tại — dùng để quan sát
   lệnh có áp dụng đúng không bằng logic analyzer.
5. Test gửi lệnh nhanh liên tục (script hoặc terminal gõ nhanh) ở `RX_BAUD`:
   đếm số lệnh gửi vs số lệnh parser nhận đúng (gắn số thứ tự vào mỗi lệnh,
   ví dụ `P10#42\r` với 42 là số thứ tự), báo cáo có mất byte không.

## Cần nộp
- `app/uart_rx.c`, `app/parser_task.c`, `app/app_main.c`.
- Demo: ảnh/log cho thấy từng lệnh áp dụng đúng lên `demo_task`.
- Kết quả test gửi nhanh: số lệnh gửi / nhận đúng / mất (nếu có).
- `REPORT.md`, `PREDICTION.md` commit trước khi nạp.

## Đạt yêu cầu khi
- Không mất byte ở `RX_BAUD` theo MSSV khi gửi lệnh ở tốc độ bình thường
  (người gõ tay).
- `demo_task` phản ứng đúng với cả 3 loại lệnh, chứng minh bằng logic
  analyzer/log.
- Giải thích đúng vì sao dùng stream buffer (byte stream) thay vì queue (bản
  ghi cố định) cho luồng UART RX này.
