# Week 1 — Ex3: `vTaskDelay` vs `xTaskDelayUntil`, và tick rate

**Thời lượng dự kiến: 4 giờ**

## Mục tiêu
Đo **jitter** và **drift** của hai cách làm task tuần hoàn, rồi chứng minh bằng số
rằng chúng không tương đương. Thấy tick rate ảnh hưởng trực tiếp lên độ chính xác.

## Đọc trước
- *Mastering the FreeRTOS Real Time Kernel* — Ch.3 mục 3.8 (`vTaskDelay`), 3.9 (`xTaskDelayUntil`)
- Ch.2 mục 2.3 (Tick count, `configTICK_RATE_HZ`)
- RM0008 — mục 8.3 (SysTick không ở RM0008; tìm trong PM0056 mục 4.5)

## Việc cần làm
Một task tuần hoàn, chu kỳ `PERIOD_MS`, toggle `PA<PERIODIC_PIN>` mỗi chu kỳ.
Trong thân vòng lặp có **tải giả biến đổi**: busy-wait một số ngẫu nhiên trong
khoảng `[0, WORK_JITTER_US]` (dùng DWT như ex2, seed cố định để lặp lại được).

Đo **4 cấu hình**, mỗi cấu hình `SAMPLE_COUNT` chu kỳ:

| # | Hàm delay | `configTICK_RATE_HZ` |
|---|---|---|
| 1 | `vTaskDelay` | 1000 |
| 2 | `xTaskDelayUntil` | 1000 |
| 3 | `vTaskDelay` | 100 |
| 4 | `xTaskDelayUntil` | 100 |

Với mỗi cấu hình, từ ảnh/dữ liệu logic analyzer tính: **min, max, trung bình,
jitter (max−min), và drift tổng** sau `SAMPLE_COUNT` chu kỳ.

> Logic analyzer 8 kênh ghi được file; xuất CSV từ PulseView rồi tính bằng script
> của bạn. Không đọc tay `SAMPLE_COUNT` cạnh — đó là việc của máy.

## Cần nộp
- `app/app_main.c`, `app/periodic.c`.
- Script tính thống kê (`tools/` của riêng bạn hoặc trong `app/`), kèm CSV gốc.
- 4 ảnh PulseView (zoom đủ thấy jitter) + bảng thống kê đầy đủ.
- `PREDICTION.md` commit trước khi nạp.

## Đạt yêu cầu khi
- Bảng thống kê đầy đủ 4 cấu hình × 5 đại lượng, tính từ CSV thật.
- Drift đo được của `xTaskDelayUntil` xấp xỉ 0; của `vTaskDelay` **không** xấp xỉ 0,
  và bạn giải thích được tại sao bằng giá trị `WORK_JITTER_US` của mình.
- Giải thích được tại sao `PERIOD_MS` của bạn (không chia hết 10 ms) làm cấu hình
  100 Hz sai nhiều hơn hẳn — kèm sơ đồ.
