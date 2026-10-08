# Dự đoán — Week 1 / Ex1

> **Commit file này TRƯỚC khi nạp chương trình lần đầu.** Report sẽ phải giải thích
> mọi chỗ dự đoán lệch so đo. Dự đoán sai không bị trừ điểm; dự đoán sau khi đo thì bị.

`student_id`: ______    Ngày/giờ commit: ______

1. Chu kỳ LED tôi sẽ đo được: ______ ms (`BLINK_PERIOD_MS` = ______)
2. Sai số giữa chu kỳ đo được và `BLINK_PERIOD_MS`: ______ us. Vì sao?
3. Nếu để HAL timebase ở lại SysTick, điều gì sẽ xảy ra khi `vTaskDelay()` được gọi?
   (chọn và giải thích: chạy bình thường / treo / tick sai nhịp / hard fault)
4. `BRINGUP_STACK_WORDS` = ______ words = ______ bytes. Task này có đủ không? Vì sao?
5. Trước khi map handler, linker sẽ báo lỗi gì (đoạn nguyên văn thông báo):
