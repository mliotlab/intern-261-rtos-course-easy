# Dự đoán — Week 4 / Ex2

> **Commit TRƯỚC khi nạp chương trình.**

`student_id`: ______

1. Lỗi gọi API queue không phải `FromISR` bên trong ISR sẽ gây ra hiện
   tượng gì khi chạy (configASSERT? treo? reset?). Giải thích bằng cơ chế
   (ngăn xếp ISR, gọi `vTaskSuspendAll`/scheduler từ ngữ cảnh ngắt), không
   chỉ "nó bị lỗi".
2. Sau khi sửa đúng API `FromISR`, dự đoán số mẫu ghi UART mỗi giây =
   `SAMPLE_RATE_HZ` / `LOG_BLOCK_SAMPLES` khối/giây. Tính ra con số.
3. Với `UART_BAUD` của bạn, một khối `LOG_BLOCK_SAMPLES` mẫu mất bao lâu để
   truyền xong? Có nguy cơ UART chưa gửi xong khối cũ mà khối mới đã sẵn
   sàng không?
