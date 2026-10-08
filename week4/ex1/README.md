# Week 4 — Ex1: Thiết kế mini project

**Thời lượng dự kiến: 3 giờ**

## Mục tiêu
Thiết kế (trên giấy, trước khi viết code) một **data logger MPU6050** chạy
dưới FreeRTOS, lấy mẫu định kỳ bằng ISR, xử lý đúng **deadline cứng**
`ISR_TO_PROC_DEADLINE_US`, và xuất dữ liệu qua UART theo khối
`LOG_BLOCK_SAMPLES` mẫu — tất cả trong ngân sách `MAX_HEAP_BYTES`.
Đây là bài tổng hợp mọi kỹ thuật của tuần 1–3: task/priority, queue,
đồng bộ, ngắt→task, đo lường.

## Đọc trước
Tổng hợp tuần 1–3 của chính bạn — không có tài liệu mới. Cụ thể, xem lại:
- *Mastering the FreeRTOS Real Time Kernel* — Ch.4 (Task), Ch.5 (Queue),
  Ch.7 (Interrupt Management).
- `week1/ex4/REPORT.md` của bạn (ngân sách RAM) và `week3/ex1/REPORT.md`
  (latency ISR→task) — số liệu thật bạn đã đo sẽ dùng lại ở đây.

## Việc cần làm
1. Vẽ **task diagram**: ISR lấy mẫu MPU6050 (tần số `SAMPLE_RATE_HZ`) →
   hàng đợi → task xử lý (lọc/đóng gói) → task ghi UART theo khối
   `LOG_BLOCK_SAMPLES` mẫu. Ghi rõ priority từng task và vì sao.
2. Tính **timing budget**: với `SAMPLE_RATE_HZ`, chu kỳ lấy mẫu là bao
   nhiêu us? Thời gian xử lý một mẫu phải xong trong
   `ISR_TO_PROC_DEADLINE_US` kể từ lúc ISR nổ ra — chứng minh bằng số
   (không phải cảm tính) rằng thiết kế của bạn có thể đạt, dựa trên các số
   đo latency ISR→task thật bạn đã có ở tuần 3.
3. Tính **RAM budget**: kích thước queue × kích thước 1 phần tử, stack mỗi
   task (tối thiểu theo HWM đã đo ở các bài tương tự tuần 1–3), cộng lại
   phải nằm dưới `MAX_HEAP_BYTES` — trình bày bảng cộng dồn.
4. Chọn API đồng bộ (queue, event group, hay stream buffer) — giải thích
   tại sao, không chỉ "vì bài mẫu dùng cái này".
5. Liệt kê rủi ro: điều gì sẽ sai nếu ISR lấy mẫu nhanh hơn task xử lý kịp
   tiêu thụ? Thiết kế của bạn xử lý tình huống đó thế nào (queue đầy →
   drop mẫu mới hay mẫu cũ? có đo được không?).

## Cần nộp
- `REPORT.md` đóng vai trò **design doc** (2–3 trang quy đổi): điền đủ các
  mục 1–5 ở trên bằng số liệu, không mô tả chung chung.
- `PREDICTION.md` — dự đoán timing/RAM budget trước khi mentor duyệt.
- `app/datalogger_types.h` — khai báo kiểu dữ liệu 1 mẫu cảm biến
  (struct) dùng xuyên suốt ex2–ex4 (TODO trong file).
- **Mentor duyệt thiết kế trước khi bạn viết code ở ex2.**

## Đạt yêu cầu khi
- Timing budget có số liệu cụ thể (us, Hz), không chỉ mô tả định tính.
- RAM budget cộng dồn đúng và nằm dưới `MAX_HEAP_BYTES`.
- Giải thích priority hợp lý: task xử lý ưu tiên cao hơn task ghi UART
  (hoặc giải thích rõ nếu chọn ngược lại).
- Nêu được cơ chế xử lý khi queue đầy.
