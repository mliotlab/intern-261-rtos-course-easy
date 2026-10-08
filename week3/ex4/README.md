# Week 3 — Ex4: Debug — CPU load, deadlock, watchdog

**Thời lượng dự kiến: 3 giờ**

## Mục tiêu
Dùng **công cụ**, không đoán: đo CPU % bằng run-time stats trên DWT CYCCNT,
tìm deadlock trong `app/deadlock_demo.c` (mentor đã cài lỗi sẵn — không sửa
bằng cách thử-sai, phải chỉ ra đúng bằng chứng), rồi thêm task giám sát +
IWDG để hệ thống tự phục hồi khi một tình huống tương tự xảy ra lần nữa.

## Đọc trước
- *Mastering the FreeRTOS Real Time Kernel* — mục Run-time Stats
- RM0008 — mục Independent Watchdog (IWDG)

## Việc cần làm
1. Cấu hình `configGENERATE_RUN_TIME_STATS` dùng DWT CYCCNT làm bộ đếm thời
   gian (điền `app/FreeRTOSConfig.deltas`). In bảng CPU % bằng
   `vTaskGetRunTimeStats` mỗi `STATS_WINDOW_MS`.
2. Build và chạy `app/deadlock_demo.c` **y nguyên như được cấp** — nó sẽ treo.
   **Không được đoán nguyên nhân.** Dùng `uxTaskGetSystemState` để liệt kê
   trạng thái (`eBlocked`/`eReady`/...) của từng task, chỉ ra chính xác 2 task
   nào đang `eBlocked` vĩnh viễn và đang chờ mutex nào — đây là bằng chứng bắt
   buộc phải có trong `REPORT.md`.
3. Sửa lỗi (thống nhất thứ tự lấy 2 mutex giữa 2 task). Xác nhận hết treo.
4. Thêm `supervisor_task`: mỗi task cần giám sát tự `xEventGroupSetBits` bit
   riêng của mình mỗi chu kỳ; `supervisor_task` dùng `xEventGroupWaitBits`
   chờ đủ `SUPERVISOR_BITS` bit trong một cửa sổ thời gian ngắn, nếu đủ thì
   `HAL_IWDG_Refresh`, nếu không đủ (nghi ngờ deadlock/treo) thì **không**
   refresh — để IWDG tự reset board sau `IWDG_TIMEOUT_MS`.
5. Chứng minh bằng demo: cố ý gây lại tình huống deadlock ở bước 2 (tạm thời,
   chỉ để quay video/chụp log), quan sát board tự reset qua IWDG, rồi khôi
   phục lại code đã sửa ở bước 3 trước khi nộp.

## Cần nộp
- `app/runtime_stats.c`, `app/deadlock_demo.c` (đã sửa), `app/supervisor.c`,
  `app/app_main.c`, `app/FreeRTOSConfig.deltas` (đã điền).
- Bảng CPU % từng task (ít nhất 2 lần đo, cách nhau vài giây).
- Bằng chứng tìm deadlock bằng `uxTaskGetSystemState` (log/ảnh) — **trước khi
  sửa**.
- Log/video board tự reset qua IWDG khi deadlock được tái tạo lại.
- `REPORT.md`, `PREDICTION.md` commit trước khi nạp.

## Đạt yêu cầu khi
- Tìm ra deadlock **bằng công cụ** (`uxTaskGetSystemState` chỉ đúng 2 task và
  2 mutex liên quan), không phải đoán hay đọc code suông.
- Bảng CPU % có số liệu thật, tổng gần 100% (giải thích phần Idle task).
- Demo watchdog reset hoạt động đúng khi deadlock được tái tạo.
