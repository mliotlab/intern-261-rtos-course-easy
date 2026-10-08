# Week 2 — Ex4: Event group & task notification

**Thời lượng dự kiến: 2 giờ**

## Mục tiêu
Đồng bộ nhiều task bằng event group, rồi thay **một** điểm đồng bộ semaphore
bằng task notification, và chứng minh bằng số đo RAM + tốc độ sự khác biệt —
không chỉ nêu lý thuyết.

## Đọc trước
- *Mastering the FreeRTOS Real Time Kernel* — Ch.9 (Event Groups), Ch.10
  (Task Notifications)

## Việc cần làm
1. Tạo 3 task sinh sự kiện (`producer_0/1/2`), mỗi task set một bit riêng của
   event group (`EVENT_BIT_COUNT` bit được dùng) theo chu kỳ ngẫu nhiên nhỏ.
2. Tạo `sync_task`: dùng `xEventGroupWaitBits` chờ **tất cả** `EVENT_BIT_COUNT`
   bit được set (clear-on-exit), sau đó in ra UART thời điểm đồng bộ và chu kỳ
   đồng bộ đo được. Timeout chờ = `SYNC_TIMEOUT_MS`.
3. Đo RAM: dùng `vTaskGetTaskInfo`/kích thước static của `EventGroupHandle_t`
   để tính byte thực tế event group chiếm.
4. Thay **1 trong 3** điểm đồng bộ (chọn `producer_0` → `sync_task`) bằng task
   notification (`xTaskNotifyGive` / `ulTaskNotifyTake`), 2 producer còn lại
   vẫn dùng event group. Đo lại RAM (so sánh notification value có sẵn trong
   TCB — không cấp phát thêm — với việc phải tạo thêm object cho semaphore).
5. Đo tốc độ: thời gian từ lúc `producer_0` gọi hàm báo hiệu đến lúc
   `sync_task` được đánh thức, so giữa event-group-bit và notification
   (dùng DWT cycle counter của week1/ex2).

## Cần nộp
- `app/sync_tasks.c`, `app/app_main.c`.
- Bảng so sánh RAM (bytes) và thời gian đánh thức (cycle/us) giữa 2 cách.
- `REPORT.md`, `PREDICTION.md` commit trước khi nạp.

## Đạt yêu cầu khi
- Bảng so sánh có số đo thật, không phải số lấy từ tài liệu.
- Nêu được **ít nhất một tình huống KHÔNG dùng được notification** để thay
  event group (ví dụ: cần đợi nhiều nguồn độc lập cùng lúc với rendezvous
  nhiều-nhiều, hoặc nhiều task cùng chờ cùng một bit).
- Giải thích đúng vì sao notification không cấp phát thêm RAM nhưng có giới
  hạn (mỗi task chỉ có 1 giá trị notification, trừ khi dùng notification index
  trên bản FreeRTOS hỗ trợ).
