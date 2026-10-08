# Week 2 — Ex3: Priority inversion

**Thời lượng dự kiến: 3 giờ**

## Mục tiêu
Tự tay tạo ra priority inversion **đo được trên logic analyzer**, rồi chứng
minh bằng số đo rằng mutex (priority inheritance) sửa được, binary semaphore
thì không.

## Đọc trước
- *Mastering the FreeRTOS Real Time Kernel* — Ch.8 (mục Priority Inversion,
  Priority Inheritance)

## Việc cần làm
1. Tạo 3 task: `task_low` (ưu tiên thấp nhất), `task_mid` (ưu tiên giữa),
   `task_high` (ưu tiên cao nhất). Chu kỳ `HIGH_PERIOD_MS` cho `task_high`.
2. `task_low` và `task_high` dùng chung một tài nguyên (biến/vùng nhớ giả lập
   SPI/I2C) bảo vệ bằng **binary semaphore** (`xSemaphoreCreateBinary`):
   `task_low` giữ tài nguyên `LOW_HOLD_MS`, `task_high` cần tài nguyên đó mỗi
   chu kỳ.
3. `task_mid` **không** đụng tài nguyên chung, chỉ chạy CPU-bound
   `MID_WORK_MS` mỗi khi nó được lịch — mục đích là chen vào giữa lúc
   `task_low` đang giữ tài nguyên, kéo dài thời gian `task_high` bị chặn.
4. Bật 3 kênh logic analyzer (low/mid/high). Chạy, chụp ảnh **inversion**: chỉ
   ra đúng khoảng thời gian `task_high` sẵn sàng chạy nhưng bị chặn gián tiếp
   bởi `task_mid` thông qua `task_low`.
5. Đổi sang **mutex** (`xSemaphoreCreateMutex`), giữ nguyên toàn bộ tham số.
   Chụp lại. Đo thời gian `task_high` bị block trong cả 2 cấu hình bằng
   `uxTaskPriorityGet()` lấy mẫu theo chu kỳ hoặc timestamp trên ảnh đo.
6. So với `DEADLINE_MS`: `task_high` có đạt deadline ở từng cấu hình không?

## Cần nộp
- `app/tasks_lmh.c`, `app/app_main.c`.
- 2 ảnh logic analyzer (binary semaphore / mutex), đủ 3 kênh, thấy rõ cạnh
  inversion.
- Bảng thời gian block của `task_high` ở cả 2 cấu hình.
- `REPORT.md`, `PREDICTION.md` commit trước khi nạp.

## Đạt yêu cầu khi
- Chỉ ra đúng trên ảnh đo **thời điểm bắt đầu và kết thúc** của inversion ở
  cấu hình binary semaphore.
- Thời gian block đo được ở cấu hình mutex ngắn hơn rõ rệt (giải thích bằng
  priority inheritance, không chỉ nói "mutex tốt hơn").
- Trả lời đúng `task_high` đạt/không đạt `DEADLINE_MS` ở từng cấu hình, dựa
  trên số đo của chính mình.
