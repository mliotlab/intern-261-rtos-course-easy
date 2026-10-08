# Week 4 — Ex2: Hiện thực

**Thời lượng dự kiến: 5 giờ**

## Mục tiêu
Hiện thực đúng thiết kế đã được mentor duyệt ở `ex1`: data logger MPU6050
chạy dưới FreeRTOS, lấy mẫu bằng ISR ở `SAMPLE_RATE_HZ`, xử lý qua hàng
đợi, ghi UART theo khối `LOG_BLOCK_SAMPLES` mẫu. `check_api.sh` phải sạch,
`AI_LOG.md` phải đầy đủ (mọi prompt AI đã dùng).

## Đọc trước
Chính `REPORT.md` (design doc) của bạn ở `week4/ex1` — hiện thực phải khớp
thiết kế đã duyệt, không tự ý đổi kiến trúc.

## Việc cần làm
1. Dùng `sensor_sample_t` từ `week4/ex1/app/datalogger_types.h` xuyên suốt.
2. `sampler_isr.c`: timer ISR nổ ở `SAMPLE_RATE_HZ`, đọc MPU6050 qua I2C1
   (hoặc dữ liệu giả lập nếu I2C chưa sẵn sàng — ghi rõ trong REPORT.md),
   đẩy một `sensor_sample_t` vào hàng đợi.
3. `logger_task.c`: nhận mẫu từ hàng đợi, gom đủ `LOG_BLOCK_SAMPLES` mẫu
   rồi ghi ra UART (`UART_BAUD`) theo khối — không ghi từng mẫu một (tốn
   CPU, không khớp thiết kế).
4. `app_main.c`: tạo task theo đúng priority đã ghi trong design doc.
5. **File `app/sampler_isr.c` đã có sẵn một lỗi** gọi API hàng đợi **không
   phải bản `FromISR`** ngay trong ISR — đây là lỗi bắt buộc phải tự tìm
   và sửa (không phải lỗi ẩn bí mật, là một phần của bài). Tìm bằng
   `configASSERT` / hành vi treo máy, không đoán.
6. Chỉnh `configTOTAL_HEAP_SIZE` theo `MAX_HEAP_BYTES` trong
   `app/FreeRTOSConfig.deltas`.
7. Viết `AI_LOG.md` ở thư mục này: liệt kê mọi prompt AI đã dùng khi làm
   bài (bắt buộc — thiếu file này = vấn đáp bài này = 0 điểm, xem RUBRIC
   và SYLLABUS "Điểm liệt").

## Cần nộp
- Toàn bộ `app/` hoàn chỉnh + `AI_LOG.md`.
- `./tools/check_api.sh week4/ex2` in ra PASS.
- `REPORT.md`, `PREDICTION.md` commit trước khi nạp.

## Đạt yêu cầu khi
- Build CMake sạch, không có `cmsis_os*`/`os*`.
- Không còn lệnh queue non-`FromISR` nào bên trong ISR.
- Dữ liệu ra UART đúng khối `LOG_BLOCK_SAMPLES` mẫu, không rời rạc từng mẫu.
- `AI_LOG.md` tồn tại và đầy đủ.
