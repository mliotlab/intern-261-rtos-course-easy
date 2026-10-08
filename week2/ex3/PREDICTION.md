# Dự đoán — Week 2 / Ex3

> **Commit TRƯỚC khi nạp chương trình.**

`student_id`: ______    `LOW_HOLD_MS` = ____  `MID_WORK_MS` = ____
`HIGH_PERIOD_MS` = ____  `DEADLINE_MS` = ____

1. Cấu hình binary semaphore: thời gian `task_high` bị block dự đoán = ______ ms.
   Phép tính dựa trên đâu (liệt kê các thành phần cộng lại)?
2. `task_high` có đạt `DEADLINE_MS` ở cấu hình binary semaphore không? Vì sao?
3. Cấu hình mutex: thời gian `task_high` bị block dự đoán = ______ ms. Vì sao
   ngắn hơn (hoặc không) so với câu 1?
4. Trên ảnh logic analyzer ở cấu hình binary semaphore, kênh `task_mid` sẽ ở
   trạng thái nào trong lúc `task_high` bị chặn — chạy liên tục, chạy ngắt
   quãng, hay không chạy? Vì sao?
5. Nếu đổi `task_mid` sang ưu tiên **thấp hơn** `task_low`, inversion còn xảy ra
   không? Vì sao (đây là cách phân biệt priority inversion với việc chỉ đơn
   giản là "task_low chạy lâu").
