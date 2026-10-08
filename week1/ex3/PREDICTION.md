# Dự đoán — Week 1 / Ex3

> **Commit TRƯỚC khi nạp chương trình.**

`student_id`: ______    `PERIOD_MS` = ____    `WORK_JITTER_US` = ____    `SAMPLE_COUNT` = ____

1. Bảng dự đoán (điền trước khi đo):

| # | Delay | Tick | Chu kỳ tb (ms) | Jitter (us) | Drift tổng sau SAMPLE_COUNT (ms) |
|---|---|---|---|---|---|
| 1 | `vTaskDelay` | 1000 | | | |
| 2 | `xTaskDelayUntil` | 1000 | | | |
| 3 | `vTaskDelay` | 100 | | | |
| 4 | `xTaskDelayUntil` | 100 | | | |

2. Cấu hình nào có drift lớn nhất? Vì sao, viết bằng công thức có `WORK_JITTER_US`.
3. `PERIOD_MS` = ____ . Với tick 100 Hz, một tick = ____ ms, nên chu kỳ thực tế sẽ
   bị làm tròn thành ____ ms. Sai số hệ thống: ____ %.
4. Jitter ở tick 1000 Hz so với 100 Hz: lớn hơn / nhỏ hơn / bằng? Vì sao?
5. Nếu task này **không** phải ưu tiên cao nhất, đại lượng nào trong bảng bị ảnh hưởng
   nhiều nhất? ______
