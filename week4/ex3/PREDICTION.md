# Dự đoán — Week 4 / Ex3

> **Commit TRƯỚC khi đo tải cao nhất.**

`student_id`: ______

1. Dự đoán CPU% của `logger_task` khi hệ thống ở tải cao nhất — ước lượng
   dựa trên `SAMPLE_RATE_HZ` và thời gian xử lý 1 mẫu bạn đã ước lượng ở
   `week4/ex1`.
2. Dự đoán stack HWM (bytes còn trống) của từng task — task nào bạn nghĩ
   sẽ có margin thấp nhất? Vì sao?
3. Dự đoán latency ISR→xử lý ở worst-case có còn nằm trong
   `ISR_TO_PROC_DEADLINE_US` không khi có task nhiễu priority cao hơn
   chạy cùng? Nếu không đạt, bạn dự đoán lệch bao nhiêu %?
